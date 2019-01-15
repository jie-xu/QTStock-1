#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QtCore>
#include "mainwindow.h"
#include <qtcpsocket.h>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

signals:
    void signalLoginInfo(QString token);

private slots:

    void on_buttonBox_accepted();
	void onCancelClicked();

private:
    Ui::Login *ui;
    void createUI();
	void readBuff();

	MainWindow* w;
	QTcpSocket* tcpSocket_ = nullptr;
	MainWindow* mainWindow_ = nullptr;
	bool logged = false;
	bool receiving = false;
	CSV* csv_ = nullptr;
	CSV* csv1_ = nullptr;
	CSV* csv2_ = nullptr;
	CSV* csv3_ = nullptr;
	int csvLine = -1;
	int progress=-1;
	bool connectedFlag = false;
};

#endif // LOGIN_H
