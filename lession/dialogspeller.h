#ifndef DIALOGSPELLER_H
#define DIALOGSPELLER_H

#include <QDialog>
#include <QVector>
#include <QSqlDatabase>
#include <QtSql>
#include <QFileInfo>
#include <QDebug>
#include <QMessageBox>
#include <QTimer>
#include <QMediaPlayer>

#include "unitlession.h"

namespace Ui {
class DialogSpeller;
}

class DialogSpeller : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSpeller(QWidget *parent = 0);
    ~DialogSpeller();
    void spelling(QString _word);       //Phat am tu _word
    void checkAnswer();                 //Kiem tra ket qua dien vao


private slots:
    void on_pushNext_clicked();

    void on_pushRepeatAudio_clicked();

    void clearCheck();

    void on_pushCheck_clicked();

private:
    Ui::DialogSpeller *uispeller;
    QVector <QString> Term;                     //Doc term tu database
    QVector <QString> Definition;               //Doc definition tu database

    QSqlDatabase mydb;  //giao tiep voi CSDL chua cac cau hoi
    int numberOfQues;
    int answerremaining;
    int randomQues;
    QString currentQuestion;
    int correctAnswer;

    QTimer *timer;
    QMediaPlayer *player;
};

#endif // DIALOGSPELLER_H
