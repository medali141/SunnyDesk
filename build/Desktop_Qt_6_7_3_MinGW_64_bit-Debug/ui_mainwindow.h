/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *idMat;
    QLineEdit *nomMat;
    QLineEdit *Quantite;
    QLabel *label_4;
    QLineEdit *Dispo;
    QPushButton *ajoutMat;
    QPushButton *modifierMat;
    QPushButton *supprimerMat;
    QTableView *tabMAT;
    QLineEdit *idMAT_Delete;
    QPushButton *afficherMar;
    QRadioButton *Rtri;
    QRadioButton *Rtri_2;
    QLineEdit *recherch_id;
    QPushButton *rechID;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1134, 699);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(30, 20, 351, 271));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 33, 61, 20));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 73, 61, 20));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 110, 61, 21));
        idMat = new QLineEdit(groupBox);
        idMat->setObjectName("idMat");
        idMat->setGeometry(QRect(140, 40, 113, 20));
        nomMat = new QLineEdit(groupBox);
        nomMat->setObjectName("nomMat");
        nomMat->setGeometry(QRect(140, 80, 113, 20));
        Quantite = new QLineEdit(groupBox);
        Quantite->setObjectName("Quantite");
        Quantite->setGeometry(QRect(140, 120, 113, 20));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 151, 91, 20));
        Dispo = new QLineEdit(groupBox);
        Dispo->setObjectName("Dispo");
        Dispo->setGeometry(QRect(140, 160, 113, 20));
        ajoutMat = new QPushButton(centralWidget);
        ajoutMat->setObjectName("ajoutMat");
        ajoutMat->setGeometry(QRect(50, 320, 131, 61));
        modifierMat = new QPushButton(centralWidget);
        modifierMat->setObjectName("modifierMat");
        modifierMat->setGeometry(QRect(200, 320, 131, 61));
        supprimerMat = new QPushButton(centralWidget);
        supprimerMat->setObjectName("supprimerMat");
        supprimerMat->setGeometry(QRect(190, 460, 131, 61));
        tabMAT = new QTableView(centralWidget);
        tabMAT->setObjectName("tabMAT");
        tabMAT->setGeometry(QRect(450, 40, 611, 401));
        idMAT_Delete = new QLineEdit(centralWidget);
        idMAT_Delete->setObjectName("idMAT_Delete");
        idMAT_Delete->setGeometry(QRect(30, 470, 131, 31));
        afficherMar = new QPushButton(centralWidget);
        afficherMar->setObjectName("afficherMar");
        afficherMar->setGeometry(QRect(450, 450, 131, 61));
        Rtri = new QRadioButton(centralWidget);
        Rtri->setObjectName("Rtri");
        Rtri->setGeometry(QRect(600, 470, 141, 25));
        Rtri_2 = new QRadioButton(centralWidget);
        Rtri_2->setObjectName("Rtri_2");
        Rtri_2->setGeometry(QRect(600, 490, 191, 25));
        recherch_id = new QLineEdit(centralWidget);
        recherch_id->setObjectName("recherch_id");
        recherch_id->setGeometry(QRect(800, 480, 131, 31));
        rechID = new QPushButton(centralWidget);
        rechID->setObjectName("rechID");
        rechID->setGeometry(QRect(940, 460, 131, 61));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1134, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Gestion des Clients", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Ajouter/Modifier  Matriel", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "idMAT", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "nomMAT", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Quantite", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Disponibilite", nullptr));
        ajoutMat->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        modifierMat->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        supprimerMat->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        afficherMar->setText(QCoreApplication::translate("MainWindow", "Affichage", nullptr));
        Rtri->setText(QCoreApplication::translate("MainWindow", "tri par % Quantite", nullptr));
        Rtri_2->setText(QCoreApplication::translate("MainWindow", "tri par % Nom Matricule ", nullptr));
        rechID->setText(QCoreApplication::translate("MainWindow", "Rechercher par ID", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
