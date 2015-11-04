#ifndef UNITLESSION_H
#define UNITLESSION_H

#include <QDialog>
#include "testdialog.h"
#include "learndialog.h"
#include "dialogspeller.h"

#include <QtSql>
#include <QFileInfo>
#include <QDebug>
#include <QSqlQueryModel>
#include <QMessageBox>

#define Path_to_db "F:/GITHUB/Phan_mem_hoc_tieng_anh/lession/database.db"

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
    void on_pushTest_clicked();

    void on_pushLearn_clicked();

    void on_pushButton_clicked();

private:
    Ui::unitlession *ui;
    QSqlDatabase mydb;
};

#endif // UNITLESSION_H
