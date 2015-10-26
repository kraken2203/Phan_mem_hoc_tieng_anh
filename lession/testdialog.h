#ifndef TESTDIALOG_H
#define TESTDIALOG_H

#include <QDialog>
#include <QVector>
#include <QLabel>
#include <QLineEdit>
#include <QSqlDatabase>
#include <QtSql>
#include <QFileInfo>
#include <QDebug>
#include <QMessageBox>
#include <QScrollArea>

namespace Ui {
class TestDialog;
}

class TestDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TestDialog(QWidget *parent = 0);
    ~TestDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::TestDialog *uitest;
    QVector <QLabel*> question;     //Quan ly cau hoi duoc sinh ra
    QVector <QLineEdit*> answer;    //Quan ly phan dien cau tra loi duoc sinh ra
    int counterQues;    //Dem so cau hoi se duoc sinh ra theo yeu cau
    QSqlDatabase mydb;  //giao tiep voi CSDL luu cac cau hoi
    int numberOfQues;   //So cau hoi toi da duoc sinh ra


};

#endif // TESTDIALOG_H
