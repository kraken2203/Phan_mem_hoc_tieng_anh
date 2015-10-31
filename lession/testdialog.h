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
#include <QRadioButton>
#include <QButtonGroup>

namespace Ui {
class TestDialog;
}

class TestDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TestDialog(QWidget *parent = 0);
    ~TestDialog();
    void clearLayout(QLayout *layout);          //Xoa tat ca cac item layout va widget trong parent layout

private slots:
    void on_pushButton_clicked();

private:
    Ui::TestDialog *uitest;

    //Manager Written
    QVector <QLabel*> questionWritten;          //Quan ly cau hoi duoc sinh ra cua written
    QVector <QLineEdit*> answerWritten;         //Quan ly phan dien cau tra loi duoc sinh ra cua written
    //Ngan hang cau hoi cho Written
    QVector <QString> termWritten;
    QVector <QString> definitionWritten;

    //Manager Matching
    QVector <QLabel*> questionMatching;         //Quan ly cau hoi duoc sinh ra cua matching
    QVector <QLabel*> selectMatching;           //Quan ly phuong an duoc sinh ra cua matching
    QVector <QLineEdit*> answerMatching;        //Quan ly phan dien cau tra loi duoc sinh ra cua matching
    //Ngan hang cau hoi cho Matching
    QVector <QString> termMatching;
    QVector <QString> definitionMatching;

    //Manager MultipleChoice
    QVector <QLabel*> questionMultipleChoice;   //Quan ly cau hoi duoc sinh ra cua MultipleChoice
    QVector <QLineEdit*> answerMultipleChoice;  //Quan ly phan dien cau tra loi duoc sinh ra cua MultipleChoice
    QVector <QRadioButton*> selectMultipleChoice; //Quan ly cac phuong an lua chon duoc tao ra
    //Ngan hang cau hoi cho MultipleChoice
    QVector <QString> termMultipleChoice;
    QVector <QString> definitionMultipleChoice;

    //Manager TrueFalse
    QVector <QLabel*> questionTrueFalse;        //Quan ly cau hoi duoc sinh ra cua TrueFalse
    QVector <bool> answerTrueFalse;       //Quan ly phan dien cau tra loi duoc sinh ra cua TrueFalse
    QVector <QRadioButton*> selectTrueFalse;    //Quan ly cac phuong an duoc chon
    //Ngan hang cau hoi cho TrueFalse
    QVector <QString> termTrueFalse;
    QVector <QString> definitionTrueFalse;

    QVector <QString> Term;                     //Doc term tu database
    QVector <QString> Definition;               //Doc definition tu database

    QSqlDatabase mydb;  //giao tiep voi CSDL chua cac cau hoi

    int numberOfQues;   //So cau hoi toi da duoc sinh ra trong ngan hang cau hoi
    int numbOfChecked;  //So phan checked de sinh ra cau hoi

};

#endif // TESTDIALOG_H
