#include "dialogspeller.h"
#include "ui_dialogspeller.h"
#define directory_dic "G:/Cac phan mem/Dictionary/lingoes/lingoes_portable_2.9.1/user_data/speech/American Package"

DialogSpeller::DialogSpeller(QWidget *parent) :
    QDialog(parent),
    uispeller(new Ui::DialogSpeller)
{
    uispeller->setupUi(this);
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    correctAnswer = 0;
    clearCheck();
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(clearCheck()));
    timer->setSingleShot(true);
    QList<int> heights;
    heights.push_back(150);
    heights.push_back(600);
    uispeller->splitter->setSizes(heights);
    player = new QMediaPlayer(0);

    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName(Path_to_db);
    mydb.open();

    QSqlQuery query;
    query.exec("SELECT COUNT(*) FROM vocab");
    if (query.next()) {
        numberOfQues = query.value(0).toInt();
    }
    qDebug() << numberOfQues;
    answerremaining = numberOfQues;
    for (int i = 0; i < numberOfQues; i++)
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

    uispeller->pB_answer->setMaximum(numberOfQues);
    uispeller->pB_answer->setValue(numberOfQues - answerremaining);
    this->setWindowFlags(Qt::WindowCloseButtonHint|Qt::WindowMaximizeButtonHint|Qt::WindowMinimizeButtonHint);

    //Setup current question
    randomQues = qrand()%answerremaining;
    uispeller->labelQuestion->setText(Definition[randomQues]);
    currentQuestion = Term[randomQues];
    spelling(currentQuestion);
}

DialogSpeller::~DialogSpeller()
{
    delete uispeller;
}

void DialogSpeller::on_pushNext_clicked()
{
    answerremaining--;
    uispeller->pB_answer->setValue(numberOfQues - answerremaining);
    qDebug() <<answerremaining;
    if (answerremaining == 0)
    {
        QMessageBox::warning(this,"Total Score",QString("Your Score: %1").arg(correctAnswer));
        this->close();
        return;
    }
    Term.removeAt(randomQues);
    Definition.removeAt(randomQues);
    randomQues = qrand()%answerremaining;
    uispeller->labelQuestion->setText(Definition[randomQues]);
    currentQuestion = Term[randomQues];
    spelling(currentQuestion);
}

void DialogSpeller::on_pushRepeatAudio_clicked()
{
    spelling(currentQuestion);
}

void DialogSpeller::spelling(QString _word)     //Phat am tu _word
{
    qDebug() << _word;
    QString filePath = directory_dic;
    filePath += QString("/%1/%2.mp3").arg(_word[0].toUpper()).arg(_word);
    player->setMedia(QUrl::fromLocalFile(filePath));
    player->play();
}

void DialogSpeller::checkAnswer()                 //Kiem tra ket qua dien vao
{
    QString answer = uispeller->le_answer->text();
    if (answer != "")
    {
        while (answer[0] == ' ') answer.remove(0,1);
        while (answer[answer.length() - 1] == ' ') answer.remove(answer.length() - 1,1);
        if (uispeller->le_answer->text() == Term[randomQues])
        {
            uispeller->flagCheck->setText("True !!!");
            correctAnswer++;
            on_pushNext_clicked();
            timer->start(3000); //time specified in ms
        }
        else
        {
            uispeller->flagCheck->setText("False !!!");
            timer->start(3000); //time specified in ms
        }
    }
}
//Xoa nhan kiem tra dung/sai
void DialogSpeller::clearCheck()
{
    uispeller->flagCheck->setText("             ");
}

void DialogSpeller::on_pushCheck_clicked()
{
    checkAnswer();
}
