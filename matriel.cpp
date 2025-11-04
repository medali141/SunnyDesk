#include "matriel.h"

Matriel::Matriel()
{
    id_mat = "";
    nommat = "";
    quantite = "";
    disponibilite = "";
}

Matriel::Matriel(QString id_mat, QString nommat, QString quantite, QString disponibilite)
{
    this->id_mat = id_mat;
    this->nommat = nommat;
    this->quantite = quantite;
    this->disponibilite = disponibilite;
}

// --- GETTERS ---
QString Matriel::getIdMat() { return id_mat; }
QString Matriel::getNomMat() { return nommat; }
QString Matriel::getQuantite() { return quantite; }
QString Matriel::getDisponibilite() { return disponibilite; }

// --- SETTERS ---
void Matriel::setIdMat(QString id_mat) { this->id_mat = id_mat; }
void Matriel::setNomMat(QString nommat) { this->nommat = nommat; }
void Matriel::setQuantite(QString quantite) { this->quantite = quantite; }
void Matriel::setDisponibilite(QString disponibilite) { this->disponibilite = disponibilite; }

// --- AJOUT ---
bool Matriel::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO MATRIEL (ID_MAT, NOMMAT, QUANTITE, DISPONIBILITE) "
                  "VALUES (:id_mat, :nommat, :quantite, :disponibilite)");
    query.bindValue(":id_mat", id_mat);
    query.bindValue(":nommat", nommat);
    query.bindValue(":quantite", quantite);
    query.bindValue(":disponibilite", disponibilite);

    return query.exec();
}

// --- AFFICHAGE ---
QSqlQueryModel* Matriel::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM MATRIEL");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_MAT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMMAT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("QUANTITE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DISPONIBILITE"));

    return model;
}

// --- SUPPRIMER ---
bool Matriel::supprimer(QString id_mat)
{
    QSqlQuery query;
    query.prepare("DELETE FROM MATRIEL WHERE ID_MAT = :id_mat");
    query.bindValue(":id_mat", id_mat);
    return query.exec();
}

// --- MODIFIER ---
bool Matriel::modifier(QString id_mat, QString nommat, QString quantite, QString disponibilite)
{
    QSqlQuery query;
    query.prepare("UPDATE MATRIEL SET NOMMAT = :nommat, QUANTITE = :quantite, DISPONIBILITE = :disponibilite "
                  "WHERE ID_MAT = :id_mat");

    query.bindValue(":id_mat", id_mat);
    query.bindValue(":nommat", nommat);
    query.bindValue(":quantite", quantite);
    query.bindValue(":disponibilite", disponibilite);

    return query.exec();
}

// --- RECHERCHE ---
QSqlQueryModel* Matriel::rechercher(QString id_mat)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * FROM MATRIEL WHERE ID_MAT LIKE :id_mat");
    query.bindValue(":id_mat", "%" + id_mat + "%");
    query.exec();
    model->setQuery(query);
    return model;
}
//rech
bool Matriel::rech(QString idMat)
{
    QSqlQuery query;
    query.prepare("SELECT ID_MAT FROM MATRIEL WHERE ID_MAT = :id_Mat");
    query.bindValue(":id_Mat", idMat);

    if (query.exec() && query.next())
        return true;
    else
        return false;
}



// --- TRI ---
QSqlQueryModel* Matriel::trierParNom()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM MATRIEL ORDER BY NOMMAT ASC");
    return model;
}

QSqlQueryModel* Matriel::trierParQuantite()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM MATRIEL ORDER BY QUANTITE ASC");
    return model;
}

