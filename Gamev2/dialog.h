#ifndef DIALOG_H
#define DIALOG_H

#include <QWidget>
#include <QDialog>
#include <QApplication>
#include <QtSql/QSqlDatabase>
#include <QtDebug>
#include <QtSql/QSqlQuery>
#include <QTableView>
#include <QtGui>
#include <QApplication>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QBoxLayout>
#include <QPushButton>
#include <QSqlError>

QT_BEGIN_NAMESPACE
namespace Ui {
class Dialog;
}
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
public slots:
    void ShowStats();                   // Création d'une méthode slot en mode public de type void

private slots:
    void on_QAddnotes_clicked();        // Création d'une méthode slot en mode privé de type void

    void on_Qquit_clicked();

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
