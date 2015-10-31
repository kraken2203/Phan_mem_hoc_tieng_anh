/********************************************************************************
** Form generated from reading UI file 'flashcard.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FLASHCARD_H
#define UI_FLASHCARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_flashcard
{
public:

    void setupUi(QDialog *flashcard)
    {
        if (flashcard->objectName().isEmpty())
            flashcard->setObjectName(QStringLiteral("flashcard"));
        flashcard->resize(400, 300);

        retranslateUi(flashcard);

        QMetaObject::connectSlotsByName(flashcard);
    } // setupUi

    void retranslateUi(QDialog *flashcard)
    {
        flashcard->setWindowTitle(QApplication::translate("flashcard", "flashcard", 0));
    } // retranslateUi

};

namespace Ui {
    class flashcard: public Ui_flashcard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FLASHCARD_H
