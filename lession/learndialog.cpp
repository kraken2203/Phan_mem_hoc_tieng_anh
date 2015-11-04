#include "learndialog.h"
#include "ui_learndialog.h"

learndialog::learndialog(QWidget *parent) :
    QDialog(parent),
    uilearn(new Ui::learndialog)
{
    uilearn->setupUi(this);

    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName(Path_to_db);
    QFileInfo checkFile(Path_to_db);

    if(checkFile.isFile())
    {
        if(mydb.open())
        {
            qDebug() << "Connected to DataBase - learn";
        }
    }
    else
    {
        qDebug() << "Unconnected to DataBase - learn";
    }


    if(!mydb.isOpen())
    {
        qDebug() << "No connection to database - learn";
        return;
    }

    QSqlQuery query;
    query.exec("SELECT COUNT(*) FROM vocab");
    if (query.next()) {
        numberOfQues = query.value(0).toInt();
    }
    answerremaining = numberOfQues;
    answerincorrect = 0;
    answercorrect = 0;
    uilearn->le_remaining->setText(QString("%1").arg(answerremaining));
    uilearn->le_incorrect->setText(QString("%1").arg(answerincorrect));
    uilearn->le_correct->setText(QString("%1").arg(answercorrect));

    this->setWindowFlags(Qt::WindowCloseButtonHint|Qt::WindowMaximizeButtonHint|Qt::WindowMinimizeButtonHint);
}

learndialog::~learndialog()
{
    delete uilearn;
}
