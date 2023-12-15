#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);


    QSqlDatabase db;                                                    // Instantiation d'un objet privé de la classe QSqlDatabase
    db = QSqlDatabase::addDatabase("QMYSQL");                           // Connecteur Mysql
    db.setDatabaseName("Jeu");                                          // Le nom de Base de données
    db.setUserName("student");                                           // User de Mysql
    db.setPassword("crif2024sn");                                                // Mot de passe de user Mysql
    connect(ui->BShow1, SIGNAL(clicked()), this, SLOT(ShowStats()));    // BShow1 est la bouton a fait graphiquement quand cliquez
}                                                                       // va lancer la methode SLOT ShowStats


void Dialog::ShowStats()
{
    if(db.open())                                                       // Condition si Le Base de Données est ouvert
    {
        qDebug() << "You are now connected to your database.";          // Affichage dans le terminal de qt

        QSqlQuery query;                                                // Instantiation d'une objet de la classe QSqlQuery

        query.exec("SELECT * FROM Playersv2");                            // Objet qui appel la fonction exec avec une ligne de commande Sql
                                                                        // qui vas selectionner toutes les valeur dans la base de données
                                                                        // de la table Players

        while(query.next())
        {

            QSqlTableModel *Model;                                      // Instantiation d'un pointer privé de la classe QSqlTableModel
            Model = new QSqlTableModel();                               // Affectation d'une objet avec une nouvelle méthode
            Model->setTable("Playersv2");                                 // Pointer dans une méthode avec une paramétre de la nom de table
            Model->select();                                            // Pointer pour remplir la table model qui est sélectionner
                                                                        // dans setTable()

            ui->tableView->setModel(Model);                             // Interface qui pointer dans une table qui est créer graphiquement
                                                                        // qui point encore dans setModel qui contient la table Players dans
                                                                        // le fonction select()
        }
    }

}



Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_QAddnotes_clicked()
{

    if(db.open())                                                         // Condition si Le Base de Données est ouvert
    {
        QSqlQuery Updatequery;                                            // Instantiation d'une objet de la classe QSqlQuery
        Updatequery.prepare("UPDATE Playersv2 SET Notes=:Notes WHERE ID = 1");// Preparation d'une query pour être executer par exec()
        Updatequery.bindValue(":Notes", ui->lineEdit->text());            // Pointer dans une widget qui est fait graphiquement qui
                                                                          // pointer dans une fonction text() qui contient le texte
                                                                          // taper dans le Widget lineEdit qui vas affecter :Notes
        Updatequery.exec();                                               // Execution des fonctions appelée dans les lignes
                                                                          // précédent

        qDebug() << "Update Error: " << Updatequery.lastError();          // Affichage d'erreur
        db.close();                                                       // Fermeture de base de données
    }
}


void Dialog::on_Qquit_clicked()
{
    close();                                                              // Fermeture de la fenêtre
}

