/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLineEdit *right;
    QLineEdit *top;
    QTableWidget *tableStars;
    QLineEdit *left;
    QLineEdit *bottom;
    QPushButton *pushQuery;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(727, 489);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        right = new QLineEdit(centralwidget);
        right->setObjectName(QString::fromUtf8("right"));

        gridLayout->addWidget(right, 1, 2, 1, 1);

        top = new QLineEdit(centralwidget);
        top->setObjectName(QString::fromUtf8("top"));

        gridLayout->addWidget(top, 1, 4, 1, 1);

        tableStars = new QTableWidget(centralwidget);
        tableStars->setObjectName(QString::fromUtf8("tableStars"));

        gridLayout->addWidget(tableStars, 2, 0, 1, 5);

        left = new QLineEdit(centralwidget);
        left->setObjectName(QString::fromUtf8("left"));

        gridLayout->addWidget(left, 1, 1, 1, 1);

        bottom = new QLineEdit(centralwidget);
        bottom->setObjectName(QString::fromUtf8("bottom"));

        gridLayout->addWidget(bottom, 1, 3, 1, 1);

        pushQuery = new QPushButton(centralwidget);
        pushQuery->setObjectName(QString::fromUtf8("pushQuery"));

        gridLayout->addWidget(pushQuery, 1, 0, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 1, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 3, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 4, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 727, 22));
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
        pushQuery->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\321\200\320\276\321\201", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Left", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Right", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Bottom", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Top", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
