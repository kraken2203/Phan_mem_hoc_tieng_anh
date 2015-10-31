#ifndef FLASHCARD_H
#define FLASHCARD_H

#include <QDialog>

namespace Ui {
class flashcard;
}

class flashcard : public QDialog
{
    Q_OBJECT

public:
    explicit flashcard(QWidget *parent = 0);
    ~flashcard();

private:
    Ui::flashcard *ui;
};

#endif // FLASHCARD_H
