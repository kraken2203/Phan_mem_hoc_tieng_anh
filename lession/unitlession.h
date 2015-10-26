#ifndef UNITLESSION_H
#define UNITLESSION_H

#include <QDialog>
#include "testdialog.h"
#include <QtSql>
#include <QFileInfo>
#include <QDebug>
#include <QSqlQueryModel>

namespace Ui {
class unitlession;
}

class unitlession : public QDialog
{
    Q_OBJECT

public:
    explicit unitlession(QWidget *parent = 0);
    ~unitlession();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::unitlession *ui;
    QSqlDatabase mydb;
};

#endif // UNITLESSION_H
