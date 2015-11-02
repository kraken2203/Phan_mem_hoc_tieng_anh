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
    correctAnswer = 0;
    this->setWindowFlags(Qt::WindowCloseButtonHint|Qt::WindowMaximizeButtonHint|Qt::WindowMinimizeButtonHint);
}

TestDialog::~TestDialog()
{
    delete uitest;
}

void TestDialog::on_pushButton_clicked()
{
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    if (!(uitest->checkWritten->isChecked() || uitest->checkMatching->isChecked() ||
         uitest->checkMultipleChoice->isChecked() || uitest->checkTrueFalse->isChecked())) return;
    if (uitest->numbOfQues->text() == "") return;
    QSqlQuery query;
    //Lay du lieu tu database cho vao 2 vector: Term & Definition
    for (int i = 0; i < numberOfQues; i++)
    {
        if (uitest->rbTerm->isChecked())
        {
            if(query.exec(QString("SELECT term, definition FROM vocab WHERE rowid = %1").arg(i+1)))
            {
                if(query.next())
                {
                    Term.append(query.value(0).toString());
                    Definition.append(query.value(1).toString());
                }
            }
        }
        else if (uitest->rbDefinition->isChecked())
        {
            if(query.exec(QString("SELECT term, definition FROM vocab WHERE rowid = %1").arg(i+1)))
            {
                if(query.next())
                {
                    Term.append(query.value(1).toString());
                    Definition.append(query.value(0).toString());
                }
            }
        }
    }

    //Phuc vu cho Multiple Choice
    QVector <QString> tempTerm(Term);               //Bien tam luu term

    //Setup for Starting
    numbOfChecked = 0;                  //Setup ban dau so checked = 0
    //Xoa tat ca cac cau hoi cu, truoc khi generate cau hoi moi
    clearLayout(uitest->queslayout);

    questionWritten.clear();
    answerWritten.clear();
    termWritten.clear();
    definitionWritten.clear();

    questionMatching.clear();
    answerMatching.clear();
    selectMatching.clear();
    termMatching.clear();
    definitionMatching.clear();

    questionMultipleChoice.clear();
    answerMultipleChoice.clear();
    selectMultipleChoice.clear();
    termMultipleChoice.clear();
    definitionMultipleChoice.clear();

    questionTrueFalse.clear();
    answerMultipleChoice.clear();
    selectTrueFalse.clear();
    termTrueFalse.clear();
    definitionTrueFalse.clear();

    //Kiem tra xem loai cau hoi nao se duoc generate
    if (uitest->checkWritten->isChecked()) numbOfChecked++;
    if (uitest->checkMatching->isChecked()) numbOfChecked++;
    if (uitest->checkMultipleChoice->isChecked()) numbOfChecked++;
    if (uitest->checkTrueFalse->isChecked()) numbOfChecked++;
    int numberofques = uitest->numbOfQues->text().toInt();  //So cau hoi se duoc sinh ra theo yeu cau
    int sodu = numberofques%numbOfChecked;                  //So cau hoi du ra sau khi chia deu
    int remainQuestion = numberOfQues;                      //So cau hoi con lai trong ngan hang cau hoi
    if (numberofques <= numberOfQues)
    {
        //Generate for Written Question
        if (uitest->checkWritten->isChecked())
        {
            QString label_Question;
            //Tinh toan so cau hoi trong phan written
            int numberOfWritten = numberofques/numbOfChecked;
            if(sodu>0) numberOfWritten++;
            sodu--;

            //Nap so cau hoi cho ngan hang written
            for(int i = 0; i < numberOfWritten; i++)
            {
                int tmp = qrand()%remainQuestion;
                termWritten.append(Term.at(tmp));
                Term.remove(tmp);           //Loai bo du lieu da lay
                definitionWritten.append(Definition.at(tmp));
                Definition.remove(tmp);     //Loai bo du lieu da lay
                remainQuestion--;
            }

            //=====Tao cac format cau hoi trong muc Written Question
            //Tao Categorise
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
        //Generate for Matching Question
        if (uitest->checkMatching->isChecked())
        {
            QString label_Question;
            uitest->queslayout->addSpacing(15);
            //Tinh toan so cau hoi trong phan Matching
            int numberOfMatching = numberofques/numbOfChecked;
            if(sodu>0) numberOfMatching++;
            sodu--;

            //Nap so cau hoi cho ngan hang Matching
            for(int i = 0; i < numberOfMatching; i++)
            {
                int tmp = qrand()%remainQuestion;
                termMatching.append(Term.at(tmp));
                Term.remove(tmp);           //Loai bo du lieu da lay
                definitionMatching.append(Definition.at(tmp));
                Definition.remove(tmp);     //Loai bo du lieu da lay
                remainQuestion--;
            }

            QVector <QString> templateMatching(definitionMatching);
            int remainMatching = numberOfMatching;

            //=====Tao cac format cau hoi trong muc Matching Question
            //Tao Categorise
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
                int tmp_pos = qrand()%remainMatching;
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
        //Generate for MultipleChoice Question
        if (uitest->checkMultipleChoice->isChecked())
        {
            uitest->queslayout->addSpacing(15);
            //Tinh toan so cau hoi trong phan MultipleChoice
            int numberOfMultipleChoice = numberofques/numbOfChecked;
            if(sodu>0) numberOfMultipleChoice++;
            sodu--;

            //Nap so cau hoi cho ngan hang MultipleChoice
            for(int i = 0; i < numberOfMultipleChoice; i++)
            {
                int tmp = qrand()%remainQuestion;
                termMultipleChoice.append(Term.at(tmp));
                Term.remove(tmp);           //Loai bo du lieu da lay
                definitionMultipleChoice.append(Definition.at(tmp));
                Definition.remove(tmp);     //Loai bo du lieu da lay
                remainQuestion--;
            }
            //=====Tao cac format cau hoi trong muc MultipleChoice Question
            //Tao Categorise
            QLabel *labelCategories = new QLabel(QString("%1 Multiple Choice questions").arg(numberOfMultipleChoice));
            QFont font;
            font.setPointSize(13);
            font.setBold(true);
            labelCategories->setFont(font);
            uitest->queslayout->addWidget(labelCategories);

            //int remainQuesMultipleChoice = numberOfQues;
            for (int i = 0; i < numberOfMultipleChoice; i++)
            {
                QLabel *labelQuestion = new QLabel(QString("%1. %2").arg(i+1).arg(termMultipleChoice.at(i)));
                QVBoxLayout *choiceLayout = new QVBoxLayout;
                //Choice 1
                int tmp = qrand()%numberOfQues;
                QRadioButton *phuongan1 = new QRadioButton(QString("%1").arg(tempTerm[tmp]));
                choiceLayout->addWidget(phuongan1);
                //Choice 2
                QRadioButton *phuongan2 = new QRadioButton;
                do
                {
                    tmp = qrand()%numberOfQues;
                    phuongan2->setText(QString("%1").arg(tempTerm[tmp]));

                }while(tempTerm[tmp]== phuongan1->text());
                choiceLayout->addWidget(phuongan2);
                //Choice 3
                QRadioButton *phuongan3 = new QRadioButton;
                do
                {
                    tmp = qrand()%numberOfQues;
                    phuongan3->setText(QString("%1").arg(tempTerm[tmp]));
                }while((tempTerm[tmp]==phuongan1->text()) || (tempTerm[tmp]==phuongan2->text()));
                //Choice 4
                QRadioButton *phuongan4 = new QRadioButton;
                do
                {
                    tmp = qrand()%numberOfQues;
                    phuongan4->setText(QString("%1").arg(tempTerm[tmp]));
                }while((tempTerm[tmp]==phuongan1->text())||(tempTerm[tmp]==phuongan2->text())||(tempTerm[tmp]==phuongan3->text()));


                QButtonGroup *group = new QButtonGroup;
                group->addButton(phuongan1);
                group->addButton(phuongan2);
                group->addButton(phuongan3);
                group->addButton(phuongan4);
                group->setExclusive(true);


                choiceLayout->addWidget(phuongan3);
                choiceLayout->addWidget(phuongan4);
                questionMultipleChoice.append(labelQuestion);
                selectMultipleChoice.append(phuongan1);
                selectMultipleChoice.append(phuongan2);
                selectMultipleChoice.append(phuongan3);
                selectMultipleChoice.append(phuongan4);
                bool flag = false;
                //Kiem tra xem phan choice lay ra co ton tai correct answer chua ?
                for (int j = 0; j < 4; j++)
                {
                    if (selectMultipleChoice[i+j]->text() == definitionMultipleChoice[i]) flag = true;
                }
                if(!flag)
                {
                    tmp = qrand()%4;
                    selectMultipleChoice[i*4 + tmp]->setText(definitionMultipleChoice[i]);
                }
                uitest->queslayout->addWidget(labelQuestion);
                uitest->queslayout->addLayout(choiceLayout);
            }
        }
        //Generate for True/False Question
        if (uitest->checkTrueFalse->isChecked())
        {
            uitest->queslayout->addSpacing(15);
            //Tinh toan so cau hoi trong phan TrueFalse
            int numberOfTrueFalse = numberofques/numbOfChecked;
            if(sodu>0) numberOfTrueFalse++;
            sodu--;

            //Nap so cau hoi cho ngan hang TrueFalse
            for(int i = 0; i < numberOfTrueFalse; i++)
            {
                int tmp = qrand()%remainQuestion;
                termTrueFalse.append(Term.at(tmp));
                Term.remove(tmp);           //Loai bo du lieu da lay
                definitionTrueFalse.append(Definition.at(tmp));
                Definition.remove(tmp);     //Loai bo du lieu da lay
                remainQuestion--;
            }
            QVector <QString> tempDefinitionTF(definitionTrueFalse); //Bien tam luu definition

            //Tao cac format cau hoi trong muc TrueFalse Question
            //Tao Categorise
            QLabel *labelCategories = new QLabel(QString("%1 True/False questions").arg(numberOfTrueFalse));
            QFont font;
            font.setPointSize(13);
            font.setBold(true);
            labelCategories->setFont(font);
            uitest->queslayout->addWidget(labelCategories);
            int remainQuesTrueFalse = numberOfTrueFalse;
            for(int i = 0; i < numberOfTrueFalse; i++)
            {
                int tmp = qrand()%remainQuesTrueFalse;
                QLabel *labelQuestion = new QLabel(QString("%1. %2 -> %3").arg(i+1).arg(termTrueFalse[i]).arg(tempDefinitionTF[tmp]));
                if (tempDefinitionTF[tmp] == definitionTrueFalse[i]) answerTrueFalse.append(true);
                else answerTrueFalse.append(false);
                QHBoxLayout *layout_dapan = new QHBoxLayout;
                QRadioButton *True = new QRadioButton("True");
                QRadioButton *False = new QRadioButton("Flase");
                QButtonGroup *group = new QButtonGroup;
                group->addButton(True);
                group->addButton(False);
                group->setExclusive(true);
                layout_dapan->addSpacing(50);
                layout_dapan->addWidget(True,Qt::AlignLeft);
                layout_dapan->addSpacing(10);
                layout_dapan->addWidget(False,Qt::AlignLeft);
                uitest->queslayout->addWidget(labelQuestion);
                uitest->queslayout->addLayout(layout_dapan);
                selectTrueFalse.append(True);
                selectTrueFalse.append(False);
                questionTrueFalse.append(labelQuestion);
                remainQuesTrueFalse--;
            }
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

void TestDialog::on_pushButton_2_clicked()
{
    correctAnswer = 0;
    //Kiem tra tinh diem
    if (uitest->checkWritten->isChecked())
    {
        QString answer;
        //kiem tra so cau dung trong written
        for (int i = 0; i < termWritten.size(); i++)
        {
            answer = answerWritten[i]->text();
            if (answer != NULL)
            {
                while (answer[0] == ' ') answer.remove(0,1);
                while (answer[answer.length() - 1] == ' ') answer.remove(answer.length() - 1,1);
                if(answer == definitionWritten[i]) correctAnswer++;
            }
        }
    }
    if (uitest->checkMatching->isChecked())
    {
        QString answer;
        //kiem tra so cau dung trong matching
        for (int i = 0; i < termMatching.size(); i++)
        {
            answer = answerMatching[i]->text();
            if(!(answer == NULL || answer.toInt() > answerMatching.size() || answer.toInt() < 0))
            {
                while (answer[0] == ' ') answer.remove(0,1);
                while (answer[answer.length() - 1] == ' ') answer.remove(answer.length() - 1,1);
                QString select_tmp = selectMatching[answer.toInt()-1]->text();
                select_tmp.remove(0,select_tmp.indexOf('.')+2);
                if(definitionMatching[i] == select_tmp) correctAnswer++;
            }
        }
    }
    if (uitest->checkMultipleChoice->isChecked())
    {
        //kiem tra so cau dung trong multiple choice
        for (int i = 0; i < termMultipleChoice.size(); i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (selectMultipleChoice[i*4+j]->isChecked())
                    if (selectMultipleChoice[i*4+j]->text() == definitionMultipleChoice[i])
                    {
                        qDebug() << i + j;
                        correctAnswer++;
                    }
            }
        }

    }
    if (uitest->checkTrueFalse->isChecked())
    {
        //kiem tra so cau dung trong true false
        for (int i = 0; i < termTrueFalse.size(); i++)
        {
            for (int j = 0; j < 2; j++)
            {
                if(selectTrueFalse[i*2+j]->isChecked())
                {
                    bool flag = (j == 0) ? true : false;
                    if (answerTrueFalse[i] == flag) correctAnswer++;
                }
            }
        }
    }
    QMessageBox::warning(this,"Total Score",QString("Your score is %1").arg(correctAnswer));
}
