/********************************************************************************
** Form generated from reading UI file 'unitlession.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UNITLESSION_H
#define UI_UNITLESSION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_unitlession
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushTest;
    QPushButton *pushButton_3;
    QPushButton *pushLearn;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_7;
    QSpacerItem *horizontalSpacer_5;

    void setupUi(QDialog *unitlession)
    {
        if (unitlession->objectName().isEmpty())
            unitlession->setObjectName(QStringLiteral("unitlession"));
        unitlession->resize(654, 479);
        verticalLayout_2 = new QVBoxLayout(unitlession);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label = new QLabel(unitlession);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        label->setFont(font);

        horizontalLayout_4->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_2 = new QLabel(unitlession);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_5->addWidget(label_2);

        horizontalSpacer_3 = new QSpacerItem(448, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        label_3 = new QLabel(unitlession);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_5->addWidget(label_3);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton = new QPushButton(unitlession);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushTest = new QPushButton(unitlession);
        pushTest->setObjectName(QStringLiteral("pushTest"));

        horizontalLayout->addWidget(pushTest);

        pushButton_3 = new QPushButton(unitlession);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);

        pushLearn = new QPushButton(unitlession);
        pushLearn->setObjectName(QStringLiteral("pushLearn"));

        horizontalLayout->addWidget(pushLearn);


        horizontalLayout_3->addLayout(horizontalLayout);

        horizontalSpacer = new QSpacerItem(88, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_5 = new QPushButton(unitlession);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        horizontalLayout_2->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(unitlession);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        horizontalLayout_2->addWidget(pushButton_6);


        horizontalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);

        tableView = new QTableView(unitlession);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setAutoFillBackground(false);
        tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tableView->setGridStyle(Qt::DashLine);

        verticalLayout_2->addWidget(tableView);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_4 = new QSpacerItem(238, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);

        pushButton_7 = new QPushButton(unitlession);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        horizontalLayout_6->addWidget(pushButton_7);

        horizontalSpacer_5 = new QSpacerItem(278, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_5);


        verticalLayout_2->addLayout(horizontalLayout_6);


        retranslateUi(unitlession);

        QMetaObject::connectSlotsByName(unitlession);
    } // setupUi

    void retranslateUi(QDialog *unitlession)
    {
        unitlession->setWindowTitle(QApplication::translate("unitlession", "unitlession", 0));
        label->setText(QApplication::translate("unitlession", "Lession", 0));
        label_2->setText(QApplication::translate("unitlession", "Study", 0));
        label_3->setText(QApplication::translate("unitlession", "Game", 0));
        pushButton->setText(QApplication::translate("unitlession", "Speller", 0));
        pushTest->setText(QApplication::translate("unitlession", "Test", 0));
        pushButton_3->setText(QApplication::translate("unitlession", "FlashCards", 0));
        pushLearn->setText(QApplication::translate("unitlession", "Learn", 0));
        pushButton_5->setText(QApplication::translate("unitlession", "Scartter", 0));
        pushButton_6->setText(QApplication::translate("unitlession", "Space Racer", 0));
        pushButton_7->setText(QApplication::translate("unitlession", "Import", 0));
    } // retranslateUi

};

namespace Ui {
    class unitlession: public Ui_unitlession {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UNITLESSION_H
