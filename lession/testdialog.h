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
#include <QLayoutItem>
#include <QFont>
#include <QHBoxLayout>
#include <QSpacerItem>

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
    //Control for Written
    QVector <QLabel*> questionWritten;          //Quan ly cau hoi duoc sinh ra cua written
    QVector <QLineEdit*> answerWritten;         //Quan ly phan dien cau tra loi duoc sinh ra cua written

    //Control for Matching
    QVector <QLabel*> sttMatching;              //Quan ly so thu tu cua cau hoi duoc sinh ra cua matching
    QVector <QLabel*> questionMatching;         //Quan ly cau hoi duoc sinh ra cua matching
    QVector <QLabel*> selectMatching;           //Quan ly phuong an duoc sinh ra cua matching
    QVector <QLineEdit*> answerMatching;        //Quan ly phan dien cau tra loi duoc sinh ra cua matching
    QVector <QHBoxLayout*> hlayout_cauhoi;
    QVBoxLayout *vlayout_dapan;

    QVector <QLabel*> questionMultipleChoice;   //Quan ly cau hoi duoc sinh ra cua MultipleChoice
    QVector <QLineEdit*> answerMultipleChoice;  //Quan ly phan dien cau tra loi duoc sinh ra cua MultipleChoice

    QVector <QLabel*> questionTrueFalse;        //Quan ly cau hoi duoc sinh ra cua TrueFalse
    QVector <QLineEdit*> answerTrueFalse;       //Quan ly phan dien cau tra loi duoc sinh ra cua TrueFalse

    QVector <QString> Term;                     //Doc term tu database
    QVector <QString> Definition;               //Doc definition tu database

    QSqlDatabase mydb;  //giao tiep voi CSDL chua cac cau hoi

    int numberOfQues;   //So cau hoi toi da duoc sinh ra trong ngan hang cau hoi
    int numbOfChecked;  //So phan checked de sinh ra cau hoi

};

#endif // TESTDIALOG_H
