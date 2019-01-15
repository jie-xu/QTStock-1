#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Chart.h"
#include <qtcpsocket.h>
#include "CSV.h"
#include "KLine.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(CSV* csvPointer1, CSV* csvPointer2, CSV* csvPointer3,QWidget *parent = 0);
	//MainWindow(QTcpSocket* socket);
	void setSocket(QTcpSocket* socket);
    ~MainWindow();
public slots:
    void slotLoginInfo(QString token);

private slots:
	void slotViewHistory(const QString& code);
	void slotViewHistoryFinish();
	void slotListClicked();
	void slotHistoryClicked();
	void slotKlineClicked();
	void readTcp();

signals:
	void viewHistory(const QString& code);

protected:
	void keyPressEvent(QKeyEvent *event) override;

private:
    Ui::MainWindow *ui;
    QString token;
	Chart* historyChart_;
	KLine* kLineChart_;
	void createUI();
	void createList();
	QTcpSocket* tcpSocket_ = nullptr;
	void readFromHost();
	CSV* listCsv_;
	CSV* historyCsv_;
	CSV* kLineCsv_;

	bool receiving = false;
	int fileLine=-1;
	bool complete = false;
};

#endif // MAINWINDOW_H
