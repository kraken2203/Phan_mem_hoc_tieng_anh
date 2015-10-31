/********************************************************************************
** Form generated from reading UI file 'testdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTDIALOG_H
#define UI_TESTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestDialog
{
public:
    QHBoxLayout *horizontalLayout_3;
    QSplitter *splitter;
    QScrollArea *scrollArea;
    QWidget *scrollQues;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *queslayout;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QCheckBox *checkWritten;
    QCheckBox *checkMatching;
    QCheckBox *checkMultipleChoice;
    QCheckBox *checkTrueFalse;
    QLabel *label_2;
    QRadioButton *rbTerm;
    QRadioButton *rbDefinition;
    QRadioButton *rbBoth;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout;
    QLineEdit *numbOfQues;
    QLabel *numbOfQues_label;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *TestDialog)
    {
        if (TestDialog->objectName().isEmpty())
            TestDialog->setObjectName(QStringLiteral("TestDialog"));
        TestDialog->resize(708, 451);
        horizontalLayout_3 = new QHBoxLayout(TestDialog);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        splitter = new QSplitter(TestDialog);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        scrollArea = new QScrollArea(splitter);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setLayoutDirection(Qt::LeftToRight);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea->setWidgetResizable(true);
        scrollQues = new QWidget();
        scrollQues->setObjectName(QStringLiteral("scrollQues"));
        scrollQues->setGeometry(QRect(0, 0, 69, 414));
        verticalLayout_5 = new QVBoxLayout(scrollQues);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        queslayout = new QVBoxLayout();
        queslayout->setObjectName(QStringLiteral("queslayout"));

        verticalLayout_5->addLayout(queslayout);

        scrollArea->setWidget(scrollQues);
        splitter->addWidget(scrollArea);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(layoutWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(13);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        verticalLayout->addWidget(label);

        checkWritten = new QCheckBox(frame);
        checkWritten->setObjectName(QStringLiteral("checkWritten"));

        verticalLayout->addWidget(checkWritten);

        checkMatching = new QCheckBox(frame);
        checkMatching->setObjectName(QStringLiteral("checkMatching"));

        verticalLayout->addWidget(checkMatching);

        checkMultipleChoice = new QCheckBox(frame);
        checkMultipleChoice->setObjectName(QStringLiteral("checkMultipleChoice"));

        verticalLayout->addWidget(checkMultipleChoice);

        checkTrueFalse = new QCheckBox(frame);
        checkTrueFalse->setObjectName(QStringLiteral("checkTrueFalse"));

        verticalLayout->addWidget(checkTrueFalse);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        verticalLayout->addWidget(label_2);

        rbTerm = new QRadioButton(frame);
        rbTerm->setObjectName(QStringLiteral("rbTerm"));

        verticalLayout->addWidget(rbTerm);

        rbDefinition = new QRadioButton(frame);
        rbDefinition->setObjectName(QStringLiteral("rbDefinition"));

        verticalLayout->addWidget(rbDefinition);

        rbBoth = new QRadioButton(frame);
        rbBoth->setObjectName(QStringLiteral("rbBoth"));

        verticalLayout->addWidget(rbBoth);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        verticalLayout->addWidget(label_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        numbOfQues = new QLineEdit(frame);
        numbOfQues->setObjectName(QStringLiteral("numbOfQues"));

        horizontalLayout->addWidget(numbOfQues);

        numbOfQues_label = new QLabel(frame);
        numbOfQues_label->setObjectName(QStringLiteral("numbOfQues_label"));

        horizontalLayout->addWidget(numbOfQues_label);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(100, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addWidget(frame);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        splitter->addWidget(layoutWidget);

        horizontalLayout_3->addWidget(splitter);


        retranslateUi(TestDialog);

        QMetaObject::connectSlotsByName(TestDialog);
    } // setupUi

    void retranslateUi(QDialog *TestDialog)
    {
        TestDialog->setWindowTitle(QApplication::translate("TestDialog", "Dialog", 0));
        label->setText(QApplication::translate("TestDialog", "Question Types", 0));
        checkWritten->setText(QApplication::translate("TestDialog", "Written", 0));
        checkMatching->setText(QApplication::translate("TestDialog", "Matching", 0));
        checkMultipleChoice->setText(QApplication::translate("TestDialog", "Multiple choice", 0));
        checkTrueFalse->setText(QApplication::translate("TestDialog", "True/False", 0));
        label_2->setText(QApplication::translate("TestDialog", "Start with", 0));
        rbTerm->setText(QApplication::translate("TestDialog", "Term", 0));
        rbDefinition->setText(QApplication::translate("TestDialog", "Definition", 0));
        rbBoth->setText(QApplication::translate("TestDialog", "Both", 0));
        label_3->setText(QApplication::translate("TestDialog", "Question limit", 0));
        numbOfQues_label->setText(QApplication::translate("TestDialog", "of x available terms", 0));
        pushButton->setText(QApplication::translate("TestDialog", "Create new test", 0));
    } // retranslateUi

};

namespace Ui {
    class TestDialog: public Ui_TestDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTDIALOG_H
