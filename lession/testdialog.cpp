#include "testdialog.h"
#include "ui_testdialog.h"
#define Path_to_db "F:/GITHUB/Phan_mem_hoc_tieng_anh/lession/database.db"

TestDialog::TestDialog(QWidget *parent) :
    QDialog(parent),
    uitest(new Ui::TestDialog)
{
    uitest->setupUi(this);
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
    this->setWindowFlags(Qt::WindowCloseButtonHint|Qt::WindowMaximizeButtonHint|Qt::WindowMinimizeButtonHint);
}

TestDialog::~TestDialog()
{
    delete uitest;
}

void TestDialog::on_pushButton_clicked()
{
    QSqlQuery query;
    //Lay du lieu tu database cho vao 2 vector: Term & Definition
    for (int i = 0; i < numberOfQues; i++)
    {
        if(query.exec(QString("SELECT term, definition FROM vocab WHERE rowid = %1").arg(i+1)))
        {
            if(query.next())
            {
                qDebug() << "query.next() is successful111111";
                Term.append(query.value(0).toString());
                Definition.append(query.value(1).toString());
            }
            else
            {
                qDebug() << "query.next() is false111111111";
            }
        }
        else
        {
            qDebug() << "query SELECT is false111111111111111";
        }
    }
    //Setup for Starting
    numbOfChecked = 0;                  //Setup ban dau so checked = 0
    //Xoa tat ca cac cau hoi cu, truoc khi generate cau hoi moi
    clearLayout(uitest->queslayout);

    questionWritten.clear();
    answerWritten.clear();
    questionMatching.clear();
    answerMatching.clear();
    selectMatching.clear();


    //Kiem tra xem loai cau hoi nao se duoc generate
    if (uitest->checkWritten->isChecked()) numbOfChecked++;
    if (uitest->checkMatching->isChecked()) numbOfChecked++;
    if (uitest->checkMultipleChoice->isChecked()) numbOfChecked++;
    if (uitest->checkTrueFalse->isChecked()) numbOfChecked++;
    QString label_Question;
    int numberofques = uitest->numbOfQues->text().toInt();  //So cau hoi se duoc sinh ra theo yeu cau
    int sodu = numberofques%numbOfChecked;                  //So cau hoi du ra sau khi chia deu
    int remainQuestion = numberOfQues;                      //So cau hoi con lai trong ngan hang cau hoi
    if (numberofques <= numberOfQues)
    {
        //Generate for Written Question
        if (uitest->checkWritten->isChecked())
        {
            //Ngan hang cau hoi cho Written
            QVector <QString> termWritten;
            QVector <QString> definitionWritten;


            //Tinh toan so cau hoi trong phan written
            int numberOfWritten = numberofques/numbOfChecked;
            if(sodu>0) numberOfWritten++;
            sodu--;

            //Nap so cau hoi cho ngan hang written
            for(int i = 0; i < numberOfWritten; i++)
            {
                int tmp = rand()%remainQuestion;
                termWritten.append(Term.at(tmp));
                Term.remove(tmp);           //Loai bo du lieu da lay
                definitionWritten.append(Definition.at(tmp));
                Definition.remove(tmp);     //Loai bo du lieu da lay
                remainQuestion--;
            }

            //Tao cac format cau hoi trong muc Written Question
            QLabel *labelCategories = new QLabel(QString("%1 Written questions").arg(numberOfWritten));
            QFont font;
            font.setPointSize(13);
            font.setBold(true);
            labelCategories->setFont(font);
            uitest->queslayout->addWidget(labelCategories);
            for (int i = 0; i < numberOfWritten; i++)
            {
                label_Question = termWritten.at(i);
                QLabel *label = new QLabel(QString("%1. "+label_Question).arg(i+1));
                QLineEdit *lineedit = new QLineEdit;
                questionWritten.insert(i,label);
                answerWritten.insert(i,lineedit);
                uitest->queslayout->addWidget(questionWritten.at(i),Qt::AlignLeft);
                uitest->queslayout->addWidget(answerWritten.at(i),Qt::AlignLeft);
            }
        }
        uitest->queslayout->addSpacing(15);
        //Generate for Matching Question
        if (uitest->checkMatching->isChecked())
        {
            //Ngan hang cau hoi cho Matching
            QVector <QString> termMatching;
            QVector <QString> definitionMatching;

            //Tinh toan so cau hoi trong phan Matching
            int numberOfMatching = numberofques/numbOfChecked;
            if(sodu>0) numberOfMatching++;
            sodu--;

            //Nap so cau hoi cho ngan hang Matching
            for(int i = 0; i < numberOfMatching; i++)
            {
                int tmp = rand()%remainQuestion;
                termMatching.append(Term.at(tmp));
                Term.remove(tmp);           //Loai bo du lieu da lay
                definitionMatching.append(Definition.at(tmp));
                Definition.remove(tmp);     //Loai bo du lieu da lay
                remainQuestion--;
            }

            QVector <QString> templateMatching(definitionMatching);
            int remainMatching = numberOfMatching;

            //Tao cac format cau hoi trong muc Matching Question
            QLabel *labelCategories = new QLabel(QString("%1 Matching questions").arg(numberOfMatching));
            QFont font;
            font.setPointSize(13);
            font.setBold(true);
            labelCategories->setFont(font);
            uitest->queslayout->addWidget(labelCategories);

            QVBoxLayout *vlayout_cauhoi = new QVBoxLayout;      //Layout chua cau hoi
            QVBoxLayout *vlayout_dapan = new QVBoxLayout;       //Layout chua dap an
            for(int i = 0; i < numberOfMatching; i++)
            {
                label_Question = termMatching.at(i);
                //Cac thanh phan trong layout chua cau hoi
                QHBoxLayout *hlayout_cauhoi = new QHBoxLayout;
                QLabel *stt = new QLabel(QString("%1. ").arg(i+1));
                QLineEdit *dapan = new QLineEdit;
                QLabel *cauhoi = new QLabel(label_Question);

                hlayout_cauhoi->addWidget(stt);
                hlayout_cauhoi->addWidget(dapan,Qt::AlignLeft);
                hlayout_cauhoi->addWidget(cauhoi,Qt::AlignRight);
                vlayout_cauhoi->addLayout(hlayout_cauhoi);

                //Cac thanh phan trong layout chua dap an
                font.setPointSize(8);
                int tmp_pos = rand()%remainMatching;
                QLabel *phuongan = new QLabel(QString("%1. %2").arg(i+1).arg(templateMatching.at(tmp_pos)));
                phuongan->setFont(font);
                templateMatching.remove(tmp_pos);
                remainMatching--;
                vlayout_dapan->addWidget(phuongan);

                //Quan ly cac cau hoi & dap an duoc sinh ra, de so sanh ket qua
                questionMatching.append(cauhoi);
                answerMatching.append(dapan);
                selectMatching.append(phuongan);
            }
            QHBoxLayout *hlayout = new QHBoxLayout;
            hlayout->addLayout(vlayout_cauhoi);
            hlayout->addSpacing(20);
            hlayout->addLayout(vlayout_dapan);
            uitest->queslayout->addLayout(hlayout);
        }
        uitest->queslayout->addSpacing(15);
        //Generate for MultipleChoice Question
        if (uitest->checkMultipleChoice->isChecked())
        {
            //Ngan hang cau hoi cho MultipleChoice
            QVector <QString> termMultipleChoice;
            QVector <QString> definitionMultipleChoice;

            //Tinh toan so cau hoi trong phan MultipleChoice
            int numberOfMultipleChoice = numberofques/numbOfChecked;
            if(sodu>0) numberOfMultipleChoice++;
            sodu--;

            //Nap so cau hoi cho ngan hang MultipleChoice
            for(int i = 0; i < numberOfMultipleChoice; i++)
            {
                int tmp = rand()%remainQuestion;
                termMultipleChoice.append(Term.at(tmp));
                Term.remove(tmp);           //Loai bo du lieu da lay
                definitionMultipleChoice.append(Definition.at(tmp));
                Definition.remove(tmp);     //Loai bo du lieu da lay
                remainQuestion--;
            }
            //Tao cac format cau hoi trong muc MultipleChoice Question

        }
        uitest->queslayout->addSpacing(15);
        //Generate for True/False Question
        if (uitest->checkTrueFalse->isChecked())
        {
            //Ngan hang cau hoi cho TrueFalse
            QVector <QString> termTrueFalse;
            QVector <QString> definitionTrueFalse;

            int counterQuesTrueFalse = 0; //Dem so cau hoi dang sinh ra trong TrueFalse

            //Tinh toan so cau hoi trong phan TrueFalse
            int numberOfTrueFalse = numberofques/numbOfChecked;
            if(sodu>0) numberOfTrueFalse++;
            sodu--;

            //Nap so cau hoi cho ngan hang TrueFalse
            for(int i = 0; i < numberOfTrueFalse; i++)
            {
                int tmp = rand()%remainQuestion;
                termTrueFalse.append(Term.at(tmp));
                Term.remove(tmp);           //Loai bo du lieu da lay
                definitionTrueFalse.append(Definition.at(tmp));
                Definition.remove(tmp);     //Loai bo du lieu da lay
                remainQuestion--;
            }
            //Tao cac format cau hoi trong muc TrueFalse Question
        }
    }
    else
        QMessageBox::warning(this,"Warning","Over number of question!");
}
void TestDialog::clearLayout(QLayout *layout)
{
    QLayoutItem *child;
    while ((child = layout->takeAt(0)) != 0)
    {
        if(child->layout() != 0)
            clearLayout( child->layout() );
        else if(child->widget() != 0)
            delete child->widget();
        delete child;
    }
}
