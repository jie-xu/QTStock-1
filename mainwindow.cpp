#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Helper.h"
#include <QString>
#include <boost/filesystem/fstream.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <boost/lexical_cast.hpp>
#include <vector>


MainWindow::MainWindow(CSV* csvPointer1, CSV* csvPointer2, CSV* csvPointer3, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
	listCsv_ = csvPointer1;
	historyCsv_ = csvPointer2;
	kLineCsv_ = csvPointer3;
	//connect(tcpSocket_, &QTcpSocket::readyRead,this,&MainWindow::readTcp );
    ui->setupUi(this);
	createUI();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotLoginInfo(QString token){
    this->token=token;
}

void MainWindow::createUI()
{
	resize(1000, 800);
	//ui->tableWidget->showGrid();

	//添加列表
	createList();

	//添加图表
	historyChart_ = new Chart(historyCsv_);
	ui->stackedWidget->insertWidget(1,historyChart_);

	//添加K线
	kLineChart_ = new KLine(kLineCsv_);
	ui->stackedWidget->insertWidget(2, kLineChart_);

	connect(this, &MainWindow::viewHistory, this, &MainWindow::slotViewHistory);
	connect(historyChart_, &Chart::viewFinish, this, &MainWindow::slotViewHistoryFinish);
}

void MainWindow::slotViewHistory(const QString& code)
{
	ui->stackedWidget->setCurrentIndex(1);
}
void MainWindow::slotViewHistoryFinish()
{
	ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::keyPressEvent(QKeyEvent* event)
{
	//QTableWidget::keyPressEvent(event);
	//ui->tableWidget->keyPressEvent(event);
	if (ui->tableWidget->rowCount() <= 0)
		return;

	auto row = ui->tableWidget->currentRow();
	auto* codeItem = ui->tableWidget->item(row, 0);
	if (codeItem && (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)) {
		emit viewHistory(codeItem->text());
	}
}
void MainWindow::createList()
{
	ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui->tableWidget->setColumnCount(7);

	//设置表头
	auto* heads = new QStringList();
	heads->push_back(u8"合约代码");
	heads->push_back(u8"合约名称");
	heads->push_back(u8"前收");
	heads->push_back(u8"涨停价");
	heads->push_back(u8"跌停价");
	heads->push_back(u8"股本");
	heads->push_back(u8"流通盘");

	ui->tableWidget->setHorizontalHeaderLabels(*heads);

	//ui->tableWidget->setRowCount(50);

	//ui->tableWidget->setItem(0, 0, new QTableWidgetItem("RZRK-001"));


	//auto csv = Helper::readFile();
	//readFromHost();
	auto csv = listCsv_;


	ui->tableWidget->setRowCount(csv->data.size()-2);
	int maximum = csv->data.size() - 2;
	for (int i = 0; i<maximum; i++)
	{
		//ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(i)));
		//ui->tableWidget->setItem(i, 0, new QTableWidgetItem(csv->data[i].rowData[0]));
		//ui->tableWidget->setItem(i, 1, new QTableWidgetItem(csv->data[i].rowData[1]));
		//ui->tableWidget->setItem(i, 2, new QTableWidgetItem(csv->data[i].rowData[6]));
		//ui->tableWidget->setItem(i, 3, new QTableWidgetItem(csv->data[i].rowData[16]));
		//ui->tableWidget->setItem(i, 4, new QTableWidgetItem(csv->data[i].rowData[19]));
		//ui->tableWidget->setItem(i, 5, new QTableWidgetItem(csv->data[i].rowData[21]));
		auto p = new QTableWidgetItem();//QString::fromStdString(csv->data[i + 1].rowData[0])
		p->setData(Qt::DisplayRole, QString::fromStdString(csv->data[i + 1].rowData[0]).toInt());
		ui->tableWidget->setItem(i, 0, p);

		//ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(csv->data[i+1].rowData[1])));
		//const char *tmp = csv->data[i + 1].rowData[1].c_str();
		//auto kkk = Helper::unicodeDecoder(csv->data[i + 1].rowData[1].c_str()).c_str();
		//qDebug(kkk.c_str());
		//auto kkkk = QString::fromUtf16(Helper::unicodeDecoder(csv->data[i + 1].rowData[1].c_str());
		//ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(Helper::unicodeDecoder(csv->data[i + 1].rowData[1].c_str()))));
		ui->tableWidget->setItem(i, 1, new QTableWidgetItem(Helper::unicodeDecoder(csv->data[i + 1].rowData[1].c_str())));

		p = new QTableWidgetItem();
		p->setData(Qt::DisplayRole, QString::fromStdString(csv->data[i + 1].rowData[6]).toFloat());
		ui->tableWidget->setItem(i, 2, p);

		p = new QTableWidgetItem();
		p->setData(Qt::DisplayRole, QString::fromStdString(csv->data[i + 1].rowData[16]).toDouble());
		ui->tableWidget->setItem(i, 3, p);

		p = new QTableWidgetItem();
		p->setData(Qt::DisplayRole, QString::fromStdString(csv->data[i + 1].rowData[19]).toDouble());
		ui->tableWidget->setItem(i, 4, p);

		p = new QTableWidgetItem();
		std::string str = csv->data[i + 1].rowData[21];
		str = str.substr(0, str.length() - 1);
		p->setData(Qt::DisplayRole, QString::fromStdString(str).toLongLong());
		ui->tableWidget->setItem(i, 5, p);

		std::string str2 = csv->data[i + 1].rowData[21];
		str2 = str2.substr(0, str.length() - 1);
		p = new QTableWidgetItem();
		p->setData(Qt::DisplayRole, QString::fromStdString(str2).toLongLong());
		ui->tableWidget->setItem(i, 6, p);

		//qDebug(std::to_string(i).c_str());
		//QString str = QString::fromStdString(csv->data[i + 1].rowData[1]);
		//char* temp = str.toUtf8();;
	}
	ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	//ui->tableWidget->setContextMenuPolicy(Qt::CustomContextMenu);
	//ui->tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void MainWindow::slotListClicked()
{
	ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::slotHistoryClicked()
{
	ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::slotKlineClicked()
{
	ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::setSocket(QTcpSocket* socket)
{
	tcpSocket_ = socket;
}

void MainWindow::readFromHost()
{
	if (tcpSocket_!=nullptr)
	{

	
		
		//获取对方发送的内容
			QByteArray array = tcpSocket_->readLine();
			QString qstr;
			qstr.prepend(array);
			if (qstr == "sending\n")
			{
				//qDebug("receive");
				listCsv_ = new CSV();
				array = tcpSocket_->readLine();
				qstr.clear();
				qstr.prepend(array);
				int num = qstr.toInt();
				for(int i=0;i<num&&tcpSocket_->canReadLine();i++)
				{
					array = tcpSocket_->readLine();
					qstr.clear();
					qstr.prepend(array);
					listCsv_->data.push_back(CSVRow(qstr.toStdString()));
					qDebug(array);
				}
				array = tcpSocket_->readLine();
				qstr.clear();
				qstr.prepend(array);
				if(qstr=="complete")
				{
					qDebug("complete");
				}
			}



		auto csv_ = new CSV();
		
		tcpSocket_->readLine();
	}
}

void MainWindow::readTcp()
{
	QByteArray array = tcpSocket_->readLine();
	QString qstr;
	qstr.prepend(array);
	if(!receiving)
	{
		if (qstr == "sending\n")
		{
			array = tcpSocket_->readLine();
			qstr.clear();
			qstr.prepend(array);
			listCsv_ = new CSV();
			fileLine = qstr.toInt();
			receiving = true;
		}
	}
	else
	{
		array = tcpSocket_->readLine();
		qstr.clear();
		qstr.prepend(array);
		listCsv_->data.push_back(CSVRow(qstr.toStdString()));
		fileLine--;
		if(fileLine==0)
		{
			array = tcpSocket_->readLine();
			qstr.clear();
			qstr.prepend(array);
			qDebug(array);
			receiving = false;
			createUI();
		}
	}
}
