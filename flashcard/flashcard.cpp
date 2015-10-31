#include "flashcard.h"
#include "ui_flashcard.h"

flashcard::flashcard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::flashcard)
{
    ui->setupUi(this);
}

flashcard::~flashcard()
{
    delete ui;
}
