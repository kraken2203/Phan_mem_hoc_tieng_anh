/********************************************************************************
** Form generated from reading UI file 'learndialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEARNDIALOG_H
#define UI_LEARNDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_learndialog
{
public:
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *le_remaining;
    QLabel *label_2;
    QLineEdit *le_incorrect;
    QLabel *label_3;
    QLineEdit *le_correct;
    QSpacerItem *verticalSpacer_4;
    QFrame *line;
    QSpacerItem *verticalSpacer;
    QPushButton *push_startover;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *Term;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer_2;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *le_definition;
    QPushButton *pushButton_2;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QDialog *learndialog)
    {
        if (learndialog->objectName().isEmpty())
            learndialog->setObjectName(QStringLiteral("learndialog"));
        learndialog->resize(688, 231);
        horizontalLayout_3 = new QHBoxLayout(learndialog);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(learndialog);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        le_remaining = new QLineEdit(learndialog);
        le_remaining->setObjectName(QStringLiteral("le_remaining"));
        le_remaining->setEnabled(false);

        verticalLayout->addWidget(le_remaining);

        label_2 = new QLabel(learndialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        le_incorrect = new QLineEdit(learndialog);
        le_incorrect->setObjectName(QStringLiteral("le_incorrect"));
        le_incorrect->setEnabled(false);

        verticalLayout->addWidget(le_incorrect);

        label_3 = new QLabel(learndialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        le_correct = new QLineEdit(learndialog);
        le_correct->setObjectName(QStringLiteral("le_correct"));
        le_correct->setEnabled(false);

        verticalLayout->addWidget(le_correct);

        verticalSpacer_4 = new QSpacerItem(20, 17, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        line = new QFrame(learndialog);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        verticalSpacer = new QSpacerItem(207, 17, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        push_startover = new QPushButton(learndialog);
        push_startover->setObjectName(QStringLiteral("push_startover"));

        verticalLayout->addWidget(push_startover);


        horizontalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        Term = new QLabel(learndialog);
        Term->setObjectName(QStringLiteral("Term"));
        QFont font;
        font.setPointSize(22);
        Term->setFont(font);

        horizontalLayout->addWidget(Term);

        horizontalSpacer = new QSpacerItem(238, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(learndialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(17, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        line_2 = new QFrame(learndialog);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        le_definition = new QLineEdit(learndialog);
        le_definition->setObjectName(QStringLiteral("le_definition"));
        QFont font1;
        font1.setPointSize(16);
        le_definition->setFont(font1);

        horizontalLayout_2->addWidget(le_definition);

        pushButton_2 = new QPushButton(learndialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalSpacer_3 = new QSpacerItem(20, 108, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);


        horizontalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(learndialog);

        QMetaObject::connectSlotsByName(learndialog);
    } // setupUi

    void retranslateUi(QDialog *learndialog)
    {
        learndialog->setWindowTitle(QApplication::translate("learndialog", "Dialog", 0));
        label->setText(QApplication::translate("learndialog", "Remaining", 0));
        label_2->setText(QApplication::translate("learndialog", "Incorrect", 0));
        label_3->setText(QApplication::translate("learndialog", "Correct", 0));
        push_startover->setText(QApplication::translate("learndialog", "Start Over", 0));
        Term->setText(QApplication::translate("learndialog", "TextLabel", 0));
        pushButton->setText(QApplication::translate("learndialog", "Don't Know", 0));
        le_definition->setText(QString());
        pushButton_2->setText(QApplication::translate("learndialog", "ANSWER", 0));
    } // retranslateUi

};

namespace Ui {
    class learndialog: public Ui_learndialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEARNDIALOG_H
