/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *historyButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *klineButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *listButton;
    QStackedWidget *stackedWidget;
    QWidget *listPage;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *tableWidget;
    QWidget *chartPage;
    QWidget *klinePage;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        historyButton = new QPushButton(centralWidget);
        historyButton->setObjectName(QStringLiteral("historyButton"));

        horizontalLayout->addWidget(historyButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        klineButton = new QPushButton(centralWidget);
        klineButton->setObjectName(QStringLiteral("klineButton"));

        horizontalLayout->addWidget(klineButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        listButton = new QPushButton(centralWidget);
        listButton->setObjectName(QStringLiteral("listButton"));

        horizontalLayout->addWidget(listButton);


        verticalLayout->addLayout(horizontalLayout);

        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        listPage = new QWidget();
        listPage->setObjectName(QStringLiteral("listPage"));
        verticalLayout_2 = new QVBoxLayout(listPage);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        tableWidget = new QTableWidget(listPage);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setSortingEnabled(true);

        verticalLayout_2->addWidget(tableWidget);

        stackedWidget->addWidget(listPage);
        chartPage = new QWidget();
        chartPage->setObjectName(QStringLiteral("chartPage"));
        stackedWidget->addWidget(chartPage);
        klinePage = new QWidget();
        klinePage->setObjectName(QStringLiteral("klinePage"));
        stackedWidget->addWidget(klinePage);

        verticalLayout->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);
        QObject::connect(historyButton, SIGNAL(clicked()), MainWindow, SLOT(slotListClicked()));
        QObject::connect(klineButton, SIGNAL(clicked()), MainWindow, SLOT(slotHistoryClicked()));
        QObject::connect(listButton, SIGNAL(clicked()), MainWindow, SLOT(slotKlineClicked()));

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        historyButton->setText(QApplication::translate("MainWindow", "\350\202\241\347\245\250\345\210\227\350\241\250", Q_NULLPTR));
        klineButton->setText(QApplication::translate("MainWindow", "\345\210\206\346\227\266\345\233\276", Q_NULLPTR));
        listButton->setText(QApplication::translate("MainWindow", "K\347\272\277\345\233\276", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
