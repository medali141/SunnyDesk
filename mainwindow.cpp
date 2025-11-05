#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "matriel.h"
#include <QMessageBox>
#include <QRegularExpression>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTimer::singleShot(0, this, [this]() {
        ui->tabMAT->setModel(M.afficher());
        ui->tabMAT->resizeColumnsToContents();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::verifierChamps(QString id, QString nom, QString quantite, QString dispo)
{
    // Vérification des champs vides
    if (id.isEmpty() || nom.isEmpty() || quantite.isEmpty() || dispo.isEmpty())
    {
        QMessageBox::warning(this, "Champs manquants", "Veuillez remplir tous les champs.");
        return false;
    }

    // Vérification ID (lettres + chiffres autorisés)
    QRegularExpression regexId("^[A-Za-z0-9]+$");
    if (!regexId.match(id).hasMatch())
    {
        QMessageBox::warning(this, "ID invalide", "L'ID doit contenir uniquement des lettres et/ou chiffres.");
        return false;
    }

    // Vérification quantité (doit être un nombre)
    bool ok;
    int q = quantite.toInt(&ok);
    if (!ok || q < 0)
    {
        QMessageBox::warning(this, "Quantité invalide", "Veuillez entrer un nombre positif pour la quantité.");
        return false;
    }

    // Vérification disponibilité (Oui / Non ou similaire)
    QString dispoLower = dispo.toLower();
    if (dispoLower != "oui" && dispoLower != "non" && dispoLower != "disponible" && dispoLower != "indisponible")
    {
        QMessageBox::warning(this, "Disponibilité invalide", "La disponibilité doit être 'Oui' ou 'Non'.");
        return false;
    }

    return true;
}

// === AJOUT ===
void MainWindow::on_ajoutMat_clicked()
{
    QString id_mat = ui->idMat->text();
    QString nommat = ui->nomMat->text();
    QString quantite = ui->Quantite->text();
    QString disponibilite = ui->Dispo->text();

    if (!verifierChamps(id_mat, nommat, quantite, disponibilite))
        return; // Arrêter si la saisie est invalide

    Matriel M(id_mat, nommat, quantite, disponibilite);
    bool test = M.ajouter();

    if (test)
    {
        ui->tabMAT->setModel(M.afficher());
        QMessageBox::information(this, "Succès", "Matériel ajouté avec succès !");
    }
    else
    {
        QMessageBox::critical(this, "Erreur", "Échec de l’ajout du matériel.");
    }
}

// === MODIFICATION ===
void MainWindow::on_modifierMat_clicked()
{
    QString idMat = ui->idMat->text();
    QString nomMat = ui->nomMat->text();
    QString Quantite = ui->Quantite->text();
    QString Dispo = ui->Dispo->text();

    if (!verifierChamps(idMat, nomMat, Quantite, Dispo))
        return;

    Matriel M(idMat, nomMat, Quantite, Dispo);

    if (M.rech(idMat))
    {
        if (M.modifier(idMat, nomMat, Quantite, Dispo))
        {
            ui->tabMAT->setModel(M.afficher());
            QMessageBox::information(this, "Succès", "Matériel modifié avec succès !");
        }
        else
        {
            QMessageBox::critical(this, "Erreur", "Échec de la modification.");
        }
    }
    else
    {
        QMessageBox::critical(this, "Introuvable", "Aucun matériel trouvé avec cet ID.");
    }
}

// === SUPPRESSION ===
void MainWindow::on_supprimerMat_clicked()
{
    Matriel M;
    QString id_mat = ui->idMAT_Delete->text();

    if (id_mat.isEmpty())
    {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID à supprimer.");
        return;
    }

    if (M.rechercher(id_mat)->rowCount() > 0)
    {
        if (M.supprimer(id_mat))
        {
            ui->tabMAT->setModel(M.afficher());
            QMessageBox::information(this, "Succès", "Matériel supprimé avec succès !");
        }
        else
        {
            QMessageBox::critical(this, "Erreur", "Échec de la suppression.");
        }
    }
    else
    {
        QMessageBox::critical(this, "Introuvable", "Aucun matériel trouvé avec cet ID.");
    }
}

void MainWindow::on_afficherMar_clicked()
{
    Matriel M;
    ui->tabMAT->setModel(M.afficher());
}

void MainWindow::on_Rtri_clicked()
{
    Matriel M;
    ui->tabMAT->setModel(M.trierParqt());

     QMessageBox msgBox;



    QMessageBox::information(nullptr, QObject::tr("database is open"),
                     QObject::tr("tri successfully.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);



}


void MainWindow::on_Rtri_2_clicked()
{

    Matriel M;
    ui->tabMAT->setModel(M.trierNOMMAT());

    QMessageBox msgBox;



    QMessageBox::information(nullptr, QObject::tr("database is open"),
                             QObject::tr("tri successfully.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_rechID_clicked()
{
    Matriel M;
    QString id=ui->recherch_id->text();
    QSqlQueryModel *verif=M.rechercher(id);
    if(M.rech(id))
    {
        if (verif!=nullptr)
        {
            ui->tabMAT->setModel((verif));
            QMessageBox::information(this, QObject::tr("recherche successfully!"),
                                     QObject::tr("recherche successfully!.\n" "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
        {
            QMessageBox::information(this, QObject::tr("recherche failed!"),
                                     QObject::tr("recherche failed!.\n" "Click Cancel to exit."), QMessageBox::Cancel);
        }}
    else{ QMessageBox::critical(nullptr, QObject::tr("Not found"),
                              QObject::tr("Not found \n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

    }
}


