/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QVBoxLayout *verticalLayout_3;
    QFrame *frameLogin;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *labelUserName;
    QLineEdit *lineEditUserName;
    QHBoxLayout *horizontalLayout_9;
    QLabel *labelPassword_2;
    QLineEdit *lineEditPassword;
    QFrame *frameConnect;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *labelIP;
    QLineEdit *lineEditIP;
    QHBoxLayout *horizontalLayout_8;
    QLabel *labelPort;
    QLineEdit *lineEditPort;
    QFrame *buttonFrame;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(400, 350);
        Login->setStyleSheet(QLatin1String("#frameConnect{\n"
"border-left: 1px solid gray;\n"
"border-right: 1px solid gray;\n"
"border-top: 1px solid gray;\n"
"border-bottom: 1px solid gray;\n"
"}\n"
"#frameLogin{\n"
"border-left: 1px solid gray;\n"
"border-right: 1px solid gray;\n"
"border-top: 1px solid gray;\n"
"border-bottom: 1px solid gray;\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(Login);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        frameLogin = new QFrame(Login);
        frameLogin->setObjectName(QStringLiteral("frameLogin"));
        frameLogin->setFrameShape(QFrame::StyledPanel);
        frameLogin->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frameLogin);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        labelUserName = new QLabel(frameLogin);
        labelUserName->setObjectName(QStringLiteral("labelUserName"));

        horizontalLayout_5->addWidget(labelUserName);

        lineEditUserName = new QLineEdit(frameLogin);
        lineEditUserName->setObjectName(QStringLiteral("lineEditUserName"));

        horizontalLayout_5->addWidget(lineEditUserName);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        labelPassword_2 = new QLabel(frameLogin);
        labelPassword_2->setObjectName(QStringLiteral("labelPassword_2"));

        horizontalLayout_9->addWidget(labelPassword_2);

        lineEditPassword = new QLineEdit(frameLogin);
        lineEditPassword->setObjectName(QStringLiteral("lineEditPassword"));
        lineEditPassword->setEchoMode(QLineEdit::Password);

        horizontalLayout_9->addWidget(lineEditPassword);


        verticalLayout->addLayout(horizontalLayout_9);


        verticalLayout_3->addWidget(frameLogin);

        frameConnect = new QFrame(Login);
        frameConnect->setObjectName(QStringLiteral("frameConnect"));
        frameConnect->setStyleSheet(QStringLiteral(""));
        frameConnect->setFrameShape(QFrame::StyledPanel);
        frameConnect->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frameConnect);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        labelIP = new QLabel(frameConnect);
        labelIP->setObjectName(QStringLiteral("labelIP"));

        horizontalLayout_7->addWidget(labelIP);

        lineEditIP = new QLineEdit(frameConnect);
        lineEditIP->setObjectName(QStringLiteral("lineEditIP"));

        horizontalLayout_7->addWidget(lineEditIP);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        labelPort = new QLabel(frameConnect);
        labelPort->setObjectName(QStringLiteral("labelPort"));

        horizontalLayout_8->addWidget(labelPort);

        lineEditPort = new QLineEdit(frameConnect);
        lineEditPort->setObjectName(QStringLiteral("lineEditPort"));

        horizontalLayout_8->addWidget(lineEditPort);


        verticalLayout_2->addLayout(horizontalLayout_8);


        verticalLayout_3->addWidget(frameConnect);

        buttonFrame = new QFrame(Login);
        buttonFrame->setObjectName(QStringLiteral("buttonFrame"));
        buttonFrame->setMaximumSize(QSize(16777215, 50));
        buttonFrame->setFrameShape(QFrame::StyledPanel);
        buttonFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(buttonFrame);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton = new QPushButton(buttonFrame);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(buttonFrame);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);


        verticalLayout_3->addWidget(buttonFrame);


        retranslateUi(Login);
        QObject::connect(pushButton, SIGNAL(clicked()), Login, SLOT(on_buttonBox_accepted()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), Login, SLOT(onCancelClicked()));

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "\347\231\273\345\275\225", Q_NULLPTR));
        labelUserName->setText(QApplication::translate("Login", "\347\224\250\346\210\267\345\220\215:", Q_NULLPTR));
        labelPassword_2->setText(QApplication::translate("Login", "\345\257\206  \347\240\201:", Q_NULLPTR));
        labelIP->setText(QApplication::translate("Login", "IP\345\234\260\345\235\200:", Q_NULLPTR));
        labelPort->setText(QApplication::translate("Login", "\347\253\257  \345\217\243:", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Login", "\347\231\273\345\275\225", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Login", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
