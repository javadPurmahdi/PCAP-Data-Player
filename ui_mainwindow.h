/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout;
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QComboBox *cmbConnectiontype;
    QLabel *label_3;
    QLineEdit *txtPort;
    QLineEdit *txtIp;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QSpinBox *txtStartPacket;
    QSpinBox *txtEndPacket;
    QLabel *label_8;
    QLabel *label_5;
    QSpinBox *txtTimerSpeed;
    QSpinBox *spinBox_2;
    QLabel *label_6;
    QLabel *label_7;
    QCheckBox *repeat;
    QPushButton *btnPlay;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QLineEdit *txtFilePath;
    QPushButton *btnFilePath;
    QPushButton *btnReset;
    QToolBar *toolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuHelp;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(389, 292);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 10, 198, 161));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        cmbConnectiontype = new QComboBox(groupBox);
        cmbConnectiontype->setObjectName(QStringLiteral("cmbConnectiontype"));

        gridLayout->addWidget(cmbConnectiontype, 0, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        txtPort = new QLineEdit(groupBox);
        txtPort->setObjectName(QStringLiteral("txtPort"));
        txtPort->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(txtPort, 2, 1, 1, 1);

        txtIp = new QLineEdit(groupBox);
        txtIp->setObjectName(QStringLiteral("txtIp"));
        txtIp->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(txtIp, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 1, 1, 1);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 4, 1, 1, 1);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(210, 10, 171, 161));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        txtStartPacket = new QSpinBox(groupBox_2);
        txtStartPacket->setObjectName(QStringLiteral("txtStartPacket"));
        txtStartPacket->setMinimum(1);
        txtStartPacket->setMaximum(4000);

        gridLayout_2->addWidget(txtStartPacket, 2, 1, 1, 1);

        txtEndPacket = new QSpinBox(groupBox_2);
        txtEndPacket->setObjectName(QStringLiteral("txtEndPacket"));
        txtEndPacket->setMinimum(0);
        txtEndPacket->setMaximum(4000);
        txtEndPacket->setSingleStep(1);
        txtEndPacket->setValue(0);

        gridLayout_2->addWidget(txtEndPacket, 3, 1, 1, 1);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_8, 3, 0, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_5, 0, 0, 1, 1);

        txtTimerSpeed = new QSpinBox(groupBox_2);
        txtTimerSpeed->setObjectName(QStringLiteral("txtTimerSpeed"));
        txtTimerSpeed->setMinimum(1);
        txtTimerSpeed->setMaximum(40000);
        txtTimerSpeed->setValue(10);

        gridLayout_2->addWidget(txtTimerSpeed, 0, 1, 1, 1);

        spinBox_2 = new QSpinBox(groupBox_2);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setMinimum(1);
        spinBox_2->setMaximum(4000);

        gridLayout_2->addWidget(spinBox_2, 1, 1, 1, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_6, 1, 0, 1, 1);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_7, 2, 0, 1, 1);

        repeat = new QCheckBox(groupBox_2);
        repeat->setObjectName(QStringLiteral("repeat"));

        gridLayout_2->addWidget(repeat, 4, 1, 1, 1);

        btnPlay = new QPushButton(centralWidget);
        btnPlay->setObjectName(QStringLiteral("btnPlay"));
        btnPlay->setGeometry(QRect(250, 210, 133, 23));
        btnPlay->setCheckable(true);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 174, 371, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_4);

        txtFilePath = new QLineEdit(layoutWidget);
        txtFilePath->setObjectName(QStringLiteral("txtFilePath"));
        txtFilePath->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(txtFilePath);

        btnFilePath = new QPushButton(layoutWidget);
        btnFilePath->setObjectName(QStringLiteral("btnFilePath"));

        horizontalLayout->addWidget(btnFilePath);

        btnReset = new QPushButton(centralWidget);
        btnReset->setObjectName(QStringLiteral("btnReset"));
        btnReset->setGeometry(QRect(110, 210, 133, 23));
        btnReset->setCheckable(false);
        MainWindow->setCentralWidget(centralWidget);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 389, 21));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuHelp->menuAction());
        menuHelp->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "PCAP Data Player", Q_NULLPTR));
        actionAbout->setText(QApplication::translate("MainWindow", "About", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Connection Option", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Protocol", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "IP", Q_NULLPTR));
        cmbConnectiontype->clear();
        cmbConnectiontype->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "TCP/Server", Q_NULLPTR)
         << QApplication::translate("MainWindow", "TCP/Client", Q_NULLPTR)
         << QApplication::translate("MainWindow", "UDP", Q_NULLPTR)
        );
        label_3->setText(QApplication::translate("MainWindow", "Port", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Connect", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Send Option", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "End Packet", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Timer Tick", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Send Count", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Start Packet", Q_NULLPTR));
        repeat->setText(QApplication::translate("MainWindow", "Repeat", Q_NULLPTR));
        btnPlay->setText(QApplication::translate("MainWindow", "Play", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "File Path", Q_NULLPTR));
        btnFilePath->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        btnReset->setText(QApplication::translate("MainWindow", "Reset", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
