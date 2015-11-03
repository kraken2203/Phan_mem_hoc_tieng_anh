/********************************************************************************
** Form generated from reading UI file 'dialogspeller.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGSPELLER_H
#define UI_DIALOGSPELLER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogSpeller
{
public:
    QVBoxLayout *verticalLayout_3;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QProgressBar *pB_answer;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushRepeatAudio;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushNext;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelQuestion;
    QLabel *flagCheck;
    QSpacerItem *verticalSpacer;
    QLineEdit *le_answer;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushCheck;

    void setupUi(QDialog *DialogSpeller)
    {
        if (DialogSpeller->objectName().isEmpty())
            DialogSpeller->setObjectName(QStringLiteral("DialogSpeller"));
        DialogSpeller->resize(670, 202);
        verticalLayout_3 = new QVBoxLayout(DialogSpeller);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        splitter = new QSplitter(DialogSpeller);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pB_answer = new QProgressBar(layoutWidget);
        pB_answer->setObjectName(QStringLiteral("pB_answer"));
        pB_answer->setValue(2);

        verticalLayout->addWidget(pB_answer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushRepeatAudio = new QPushButton(layoutWidget);
        pushRepeatAudio->setObjectName(QStringLiteral("pushRepeatAudio"));

        horizontalLayout->addWidget(pushRepeatAudio);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushNext = new QPushButton(layoutWidget);
        pushNext->setObjectName(QStringLiteral("pushNext"));

        horizontalLayout->addWidget(pushNext);


        verticalLayout->addLayout(horizontalLayout);

        splitter->addWidget(layoutWidget);
        layoutWidget1 = new QWidget(splitter);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        labelQuestion = new QLabel(layoutWidget1);
        labelQuestion->setObjectName(QStringLiteral("labelQuestion"));
        labelQuestion->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        labelQuestion->setFont(font);
        labelQuestion->setWordWrap(true);

        horizontalLayout_2->addWidget(labelQuestion);

        flagCheck = new QLabel(layoutWidget1);
        flagCheck->setObjectName(QStringLiteral("flagCheck"));
        flagCheck->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(flagCheck);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        le_answer = new QLineEdit(layoutWidget1);
        le_answer->setObjectName(QStringLiteral("le_answer"));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(false);
        font1.setWeight(50);
        le_answer->setFont(font1);

        verticalLayout_2->addWidget(le_answer);

        splitter->addWidget(layoutWidget1);

        verticalLayout_3->addWidget(splitter);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(538, 17, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        pushCheck = new QPushButton(DialogSpeller);
        pushCheck->setObjectName(QStringLiteral("pushCheck"));

        horizontalLayout_3->addWidget(pushCheck);


        verticalLayout_3->addLayout(horizontalLayout_3);


        retranslateUi(DialogSpeller);

        QMetaObject::connectSlotsByName(DialogSpeller);
    } // setupUi

    void retranslateUi(QDialog *DialogSpeller)
    {
        DialogSpeller->setWindowTitle(QApplication::translate("DialogSpeller", "Dialog", 0));
        pB_answer->setFormat(QApplication::translate("DialogSpeller", "%v/%m", 0));
        pushRepeatAudio->setText(QApplication::translate("DialogSpeller", "Repeat Audio", 0));
        pushNext->setText(QApplication::translate("DialogSpeller", "Next", 0));
        labelQuestion->setText(QApplication::translate("DialogSpeller", "TextLabel", 0));
        flagCheck->setText(QApplication::translate("DialogSpeller", "TextLabel", 0));
        pushCheck->setText(QApplication::translate("DialogSpeller", "Check", 0));
    } // retranslateUi

};

namespace Ui {
    class DialogSpeller: public Ui_DialogSpeller {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSPELLER_H
