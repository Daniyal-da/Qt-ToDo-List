/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *inputTask;
    QPushButton *btnAdd;
    QListWidget *listTasks;
    QPushButton *btnDeleteSelected;
    QPushButton *btnClearAll;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        inputTask = new QLineEdit(centralwidget);
        inputTask->setObjectName(QString::fromUtf8("inputTask"));
        inputTask->setGeometry(QRect(430, 230, 113, 28));
        btnAdd = new QPushButton(centralwidget);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));
        btnAdd->setGeometry(QRect(470, 150, 90, 29));
        listTasks = new QListWidget(centralwidget);
        listTasks->setObjectName(QString::fromUtf8("listTasks"));
        listTasks->setGeometry(QRect(110, 100, 256, 192));
        btnDeleteSelected = new QPushButton(centralwidget);
        btnDeleteSelected->setObjectName(QString::fromUtf8("btnDeleteSelected"));
        btnDeleteSelected->setGeometry(QRect(390, 390, 90, 29));
        btnClearAll = new QPushButton(centralwidget);
        btnClearAll->setObjectName(QString::fromUtf8("btnClearAll"));
        btnClearAll->setGeometry(QRect(160, 440, 90, 29));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btnAdd->setText(QCoreApplication::translate("MainWindow", "add", nullptr));
        btnDeleteSelected->setText(QCoreApplication::translate("MainWindow", "delete", nullptr));
        btnClearAll->setText(QCoreApplication::translate("MainWindow", "del all", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
