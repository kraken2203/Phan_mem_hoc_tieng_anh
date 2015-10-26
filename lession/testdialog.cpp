#include "testdialog.h"
#include "ui_testdialog.h"
#define Path_to_db "/home/luutung/data/database.db"

TestDialog::TestDialog(QWidget *parent) :
    QDialog(parent),
    uitest(new Ui::TestDialog)
{
    uitest->setupUi(this);
    counterQues = 0;
    QList<int> heights;
    heights.push_back(600);
    heights.push_back(300);
    uitest->splitter->setSizes(heights);
    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName(Path_to_db);
    QFileInfo checkFile(Path_to_db);

    if(checkFile.isFile())
    {
        if(mydb.open())
        {
            qDebug() << "Connected to DataBase";
        }
    }
    else
    {
        qDebug() << "Unconnected to DataBase";
    }


    if(!mydb.isOpen())
    {
        qDebug() << "No connection to database";
        return;
    }

    QSqlQuery query;
    query.exec("SELECT COUNT(*) FROM vocab");
    if (query.next()) {
        numberOfQues = query.value(0).toInt();
    }
    uitest->numbOfQues_label->setText(QString("of %1 available terms").arg(numberOfQues));
}

TestDialog::~TestDialog()
{
    delete uitest;
}

void TestDialog::on_pushButton_clicked()
{
    QSqlQuery query;
    QString label_Question;
    int numberofques = uitest->numbOfQues->text().toInt();
    if (numberofques <= numberOfQues)
        for (int i = 0; i < numberofques; i++)
        {
            if(query.exec(QString("SELECT term, definition FROM vocab WHERE rowid = %1").arg(i+1)))
            {
                if(query.next())
                {
                    qDebug() << "query.next() is successful";
                    label_Question = query.value(1).toString();
                }
                else
                {
                    qDebug() << "query.next() is false";
                }
            }
            else
            {
                qDebug() << "query SELECT is false";
            }
            QLabel *label = new QLabel(QString("%1. "+label_Question).arg(i+1));
            QLineEdit *lineedit = new QLineEdit;
            question.insert(counterQues,label);
            answer.insert(counterQues,lineedit);
            uitest->queslayout->addWidget(question.at(counterQues),Qt::AlignLeft);
            uitest->queslayout->addWidget(answer.at(counterQues),Qt::AlignLeft);
            counterQues++;
        }
    else
        QMessageBox::warning(this,"Warning","Over number of question!");
}
