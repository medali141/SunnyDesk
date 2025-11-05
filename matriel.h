#ifndef MATRIEL_H
#define MATRIEL_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>

class Matriel
{
public:
    Matriel();
    Matriel(QString id_mat, QString nommat, QString quantite, QString disponibilite);

    // Getters
    QString getIdMat();
    QString getNomMat();
    QString getQuantite();
    QString getDisponibilite();

    // Setters
    void setIdMat(QString id_mat);
    void setNomMat(QString nommat);
    void setQuantite(QString quantite);
    void setDisponibilite(QString disponibilite);

    // CRUD
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(QString id_mat);
    bool modifier(QString id_mat, QString nommat, QString quantite, QString disponibilite);

    // Recherche et Tri
    QSqlQueryModel* rechercher(QString id_mat);
    bool rech(QString idMat);
    QSqlQueryModel* trierParqt();
    QSqlQueryModel* trierNOMMAT();

private:
    QString id_mat;
    QString nommat;
    QString quantite;
    QString disponibilite;
};

#endif // MATRIEL_H
