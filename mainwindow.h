#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "matriel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ajoutMat_clicked();

    void on_modifierMat_clicked();

    void on_supprimerMat_clicked();

    void on_afficherMar_clicked();
    bool verifierChamps(QString , QString , QString,  QString );


private:
    Ui::MainWindow *ui;
    Matriel M;

};

#endif // MAINWINDOW_H
