#ifndef LEARNDIALOG_H
#define LEARNDIALOG_H

#include <QDialog>
#include <QFileInfo>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include "unitlession.h"


namespace Ui {
class learndialog;
}

class learndialog : public QDialog
{
    Q_OBJECT

public:
    explicit learndialog(QWidget *parent = 0);
    ~learndialog();

private:
    Ui::learndialog *uilearn;
    int answerremaining;    //So cau hoi con lai
    int answerincorrect;    //So cau hoi tra loi sai
    int answercorrect;      //So cau hoi tra loi dung
    QSqlDatabase mydb;      //giao tiep voi CSDL chua cac cau hoi
    int numberOfQues;   //So cau hoi toi da duoc sinh ra
};

#endif // LEARNDIALOG_H
