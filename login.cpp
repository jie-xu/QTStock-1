#include "login.h"
#include "ui_login.h"
//#include <qtcpsocket.h>
//#include <qhostaddress.h>
#include <QtNetwork/qtcpsocket.h>
#include <QtNetwork/qhostaddress.h>
#include <QDebug>

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
	csv1_ = new CSV();
	csv2_ = new CSV();
	csv3_ = new CSV();
    ui->setupUi(this);
    createUI();
}

Login::~Login()
{
    delete ui;
	tcpSocket_->disconnectFromHost();
	tcpSocket_->close();
	delete mainWindow_;
}

void Login::createUI(){
    QRegExp regIP("\\b(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\b");
    QRegExpValidator *latitudeIP = new QRegExpValidator(regIP, this);
    ui->lineEditIP->setValidator(latitudeIP);
    QRegExp regPort("([0-9]|[1-9]\\d{1,3}|[1-5]\\d{4}|6[0-5]{2}[0-3][0-5])");
    QRegExpValidator *latitudePort = new QRegExpValidator(regPort, this);
    ui->lineEditPort->setValidator(latitudePort);

/*    connect(ui->buttonBox->button(QDialogButtonBox::Cancel),
        SIGNAL(clicked()),
        this,
        SLOT(close())
    );

    connect(ui->buttonBox->button(QDialogButtonBox::Ok),
        SIGNAL(clicked()),
        this,
        SLOT(slotAcceptLogin()));
    connect(ui->buttonBox->button(QDialogButtonBox::Ok),
        SIGNAL(clicked()),
        this,
        SLOT(accept()));*/
}


void Login::on_buttonBox_accepted()
{
	/*if (tcpSocket_ != nullptr&&!connectedFlag)
	{
		delete tcpSocket_;
		QMessageBox::information(NULL, u8"警告", u8"未成功建立连接", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
	}*/
	if(logged)
	{
		QString str = u8"正在加载第";
		str += QString::number(progress);
		str += u8"个文件，请稍候";
		QMessageBox::information(NULL, u8"警告", str, QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
		return;
	}
	if(tcpSocket_==nullptr||!connectedFlag)
	{
		if (tcpSocket_ != nullptr)delete tcpSocket_;
		tcpSocket_ = new QTcpSocket(this);
		connect(tcpSocket_, static_cast<void(QAbstractSocket::*)(QAbstractSocket::SocketError)>(&QAbstractSocket::error),
			[=](QAbstractSocket::SocketError socketError) { 
			delete tcpSocket_;
			tcpSocket_ == nullptr;
			});

		connect(tcpSocket_,&QTcpSocket::connected,[=]()
		{
			connectedFlag = true;
		});
		//tcpSocket_->connectToHost(QHostAddress("172.22.205.192"), 9925);
		tcpSocket_->connectToHost(QHostAddress(ui->lineEditIP->text()), ui->lineEditPort->text().toInt());
	}
	QString login = ui->lineEditUserName->text();
	login += ':';
	login += ui->lineEditPassword->text();
	tcpSocket_->write(login.toUtf8());

	connect(tcpSocket_, &QTcpSocket::readyRead,
		[=]() {
		if(!logged)
		{
			//获取对方发送的内容
			if (tcpSocket_->canReadLine())qDebug("can readline");
			QByteArray array = tcpSocket_->readLine();

			QString qstr;
			qstr.prepend(array);
			if (qstr == "ok\n")
			{
				logged = true;
				QMessageBox message(QMessageBox::NoIcon, u8"请稍等", u8"登陆成功！加载中。");
				message.open();
				/*mainWindow_ = new MainWindow(tcpSocket_);
				mainWindow_->show();
				this->hide();*/
			}
			else if (qstr == "denied\n")
			{
				QMessageBox::information(NULL, u8"警告", u8"用户名或密码错误", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
			}
			//qDebug(array);
		}
		else
		{
			readBuff();
			while(tcpSocket_->canReadLine())
			{
				readBuff();
			}
		}
	}
	);
	

	//tcpSocket->disconnectFromHost();
	//tcpSocket->close();

    emit signalLoginInfo(ui->lineEditUserName->text());
}


void Login::readBuff()
{
	QByteArray array;
	QString qstr;
	
	if (!receiving)
	{
		array = tcpSocket_->readLine();
		qstr.clear();
		qstr.prepend(array);
		if (qstr == "sending\n")
		{
			//读取文件名
			array = tcpSocket_->readLine();
			qstr.clear();
			qstr.prepend(array);
			if (qstr == "data2000.csv\n")
			{
				csv_ = csv1_;
				progress = 1;
			}
			if (qstr == "data3000.csv\n")
			{
				csv_ = csv2_;
				progress = 2;
			}
			if (qstr == "data3001.csv\n")
			{
				csv_ = csv3_;
				progress = 3;
			}
			//读取行数
			array = tcpSocket_->readLine();
			qstr.clear();
			qstr.prepend(array);
			csvLine = qstr.toInt();
			receiving = true;
		}
	}
	else
	{

		/*csv_->data.push_back(CSVRow(qstr.toStdString()));
		csvLine--;*/
		//qDebug(array);
		while (tcpSocket_->canReadLine())
		{
			array = tcpSocket_->readLine();
			qstr.clear();
			qstr.prepend(array);
			csv_->data.push_back(CSVRow(qstr.toStdString()));
			qDebug(array);
			csvLine--;
			if (csvLine <= 0)
			{
				if (progress == 3)
				{
					mainWindow_ = new MainWindow(csv1_, csv2_, csv3_);
					mainWindow_->show();
					this->hide();
				}
				array = tcpSocket_->readLine();
				qstr.clear();
				qstr.prepend(array);
				receiving = false;
				return;
			}
		}

	}
}

void Login::onCancelClicked()
{
	exit(0);
}
