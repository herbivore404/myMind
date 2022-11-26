/********************************************************************************
** Form generated from reading UI file 'welcomeview.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOMEVIEW_H
#define UI_WELCOMEVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WelcomeView
{
public:
    QFormLayout *formLayout;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btDepartment;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btDoctor;
    QSpacerItem *horizontalSpacer;
    QPushButton *btPatient;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_2;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *WelcomeView)
    {
        if (WelcomeView->objectName().isEmpty())
            WelcomeView->setObjectName(QString::fromUtf8("WelcomeView"));
        WelcomeView->resize(840, 442);
        WelcomeView->setMinimumSize(QSize(840, 442));
        QFont font;
        font.setPointSize(10);
        WelcomeView->setFont(font);
        WelcomeView->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color:rgba(255,255,255,200);      //\350\203\214\346\231\257\351\242\234\350\211\262\345\222\214\351\200\217\346\230\216\345\272\246                      \n"
"border-radius:6px;                           //\350\276\271\346\241\206\345\234\206\350\247\222\n"
"}\n"
" \n"
""));
        formLayout = new QFormLayout(WelcomeView);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(17, 141, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        btDepartment = new QPushButton(WelcomeView);
        btDepartment->setObjectName(QString::fromUtf8("btDepartment"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btDepartment->sizePolicy().hasHeightForWidth());
        btDepartment->setSizePolicy(sizePolicy);
        btDepartment->setMinimumSize(QSize(100, 100));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\230\277\351\207\214\345\267\264\345\267\264\346\231\256\346\203\240\344\275\223 R"));
        font1.setPointSize(11);
        btDepartment->setFont(font1);
        btDepartment->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color:rgba(255,255,255,200);      //\350\203\214\346\231\257\351\242\234\350\211\262\345\222\214\351\200\217\346\230\216\345\272\246\n"
"color:rgb(0,0,0);                            //\345\255\227\344\275\223\351\242\234\350\211\262\n"
"border-radius:6px;                           //\350\276\271\346\241\206\345\234\206\350\247\222\n"
"border: 3px outset rgb(128,128,128);         //\350\276\271\346\241\206\345\256\275\345\272\246\343\200\201\346\240\267\345\274\217\344\273\245\345\217\212\351\242\234\350\211\262\n"
"}\n"
" \n"
"//\350\256\276\347\275\256\346\202\254\345\201\234\347\212\266\346\200\201\346\240\267\345\274\217\n"
"QPushButton:hover{\n"
"background-color:rgba(150,150,150,200);\n"
"color:rgb(0,255\357\274\214255);\n"
"}\n"
" \n"
"QPushButton:pressed{\n"
"background-color:rgba(0,0,0,200);\n"
"color:rgb(0,255\357\274\214255);\n"
"}\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/img/department.png"), QSize(), QIcon::Normal, QIcon::Off);
        btDepartment->setIcon(icon);

        horizontalLayout->addWidget(btDepartment);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btDoctor = new QPushButton(WelcomeView);
        btDoctor->setObjectName(QString::fromUtf8("btDoctor"));
        sizePolicy.setHeightForWidth(btDoctor->sizePolicy().hasHeightForWidth());
        btDoctor->setSizePolicy(sizePolicy);
        btDoctor->setMinimumSize(QSize(100, 100));
        btDoctor->setFont(font1);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/img/doctor.png"), QSize(), QIcon::Normal, QIcon::Off);
        btDoctor->setIcon(icon1);

        horizontalLayout->addWidget(btDoctor);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btPatient = new QPushButton(WelcomeView);
        btPatient->setObjectName(QString::fromUtf8("btPatient"));
        sizePolicy.setHeightForWidth(btPatient->sizePolicy().hasHeightForWidth());
        btPatient->setSizePolicy(sizePolicy);
        btPatient->setMinimumSize(QSize(100, 100));
        btPatient->setFont(font1);
        btPatient->setStyleSheet(QString::fromUtf8(""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/img/patient.png"), QSize(), QIcon::Normal, QIcon::Off);
        btPatient->setIcon(icon2);

        horizontalLayout->addWidget(btPatient);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(17, 141, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        label = new QLabel(WelcomeView);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\200\235\346\272\220\345\256\213\344\275\223 CN SemiBold"));
        font2.setPointSize(9);
        font2.setBold(false);
        font2.setWeight(50);
        label->setFont(font2);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(label);


        formLayout->setLayout(1, QFormLayout::LabelRole, verticalLayout);

        label_2 = new QLabel(WelcomeView);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(140, 120));
        label_2->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/img/dp1.png);"));

        formLayout->setWidget(1, QFormLayout::FieldRole, label_2);


        retranslateUi(WelcomeView);

        QMetaObject::connectSlotsByName(WelcomeView);
    } // setupUi

    void retranslateUi(QWidget *WelcomeView)
    {
        WelcomeView->setWindowTitle(QApplication::translate("WelcomeView", "\346\254\242\350\277\216", nullptr));
        btDepartment->setText(QApplication::translate("WelcomeView", "\347\247\221\345\256\244\347\256\241\347\220\206", nullptr));
        btDoctor->setText(QApplication::translate("WelcomeView", "\345\214\273\347\224\237\347\256\241\347\220\206", nullptr));
        btPatient->setText(QApplication::translate("WelcomeView", "\346\202\243\350\200\205\347\256\241\347\220\206", nullptr));
        label->setText(QApplication::translate("WelcomeView", "Code by: 202041404104-chenzhicong", nullptr));
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WelcomeView: public Ui_WelcomeView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOMEVIEW_H
