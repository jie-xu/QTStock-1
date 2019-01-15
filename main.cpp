#include "mainwindow.h"
#include "login.h"
#include <QApplication>
#include "Helper.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Login *dlg=new Login();
    //MainWindow *w=new MainWindow();
	/*char test[] = "\\4e2d";
	qDebug(test);
	qDebug(Helper::unicodeDecoder(test).c_str());*/

    Login dlg;
	dlg.show();
	

    return a.exec();
}
