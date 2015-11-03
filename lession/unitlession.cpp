#include "unitlession.h"
#include "ui_unitlession.h"
#define Path_to_db "F:/GITHUB/Phan_mem_hoc_tieng_anh/lession/database.db"

unitlession::unitlession(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::unitlession)
{
    ui->setupUi(this);
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
        QMessageBox::warning(this,"Unconnected","No found database");
    }


    if(!mydb.isOpen())
    {
        qDebug() << "No connection to database";
        return;
    }

    QSqlQuery query;
    if(query.exec("SELECT term, definition FROM vocab"))
    {
        if(query.next())
        {
            qDebug() << "query.next() is successful";
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
    QSqlQueryModel *modal = new QSqlQueryModel();
    modal->setQuery(query);
    ui->tableView->setModel(modal);
    ui->tableView->resizeColumnToContents(0);
    for (int c = 1; c < ui->tableView->horizontalHeader()->count(); ++c)
    {
        ui->tableView->horizontalHeader()->setSectionResizeMode(c, QHeaderView::Stretch);
    }
}

unitlession::~unitlession()
{
    delete ui;
}

void unitlession::on_pushTest_clicked()
{
    TestDialog openTestDialog;
    openTestDialog.setModal(true);
    openTestDialog.exec();
}

void unitlession::on_pushLearn_clicked()
{
    learndialog openLearnDialog;
    openLearnDialog.setModal(true);
    openLearnDialog.exec();
}


void unitlession::on_pushButton_clicked()
{
    DialogSpeller openSpellerDialog;
    openSpellerDialog.setModal(true);
    openSpellerDialog.exec();
}
