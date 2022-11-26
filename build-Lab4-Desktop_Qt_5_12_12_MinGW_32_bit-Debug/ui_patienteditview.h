/********************************************************************************
** Form generated from reading UI file 'patienteditview.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATIENTEDITVIEW_H
#define UI_PATIENTEDITVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PatientEditView
{
public:
    QLabel *label_11;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QFormLayout *formLayout;
    QLabel *label_6;
    QLineEdit *dbEditID;
    QLabel *label_5;
    QLineEdit *dbEditName;
    QLabel *label_7;
    QLineEdit *dbEditIDCard;
    QLabel *label_8;
    QComboBox *dbComboSex;
    QLabel *label_10;
    QSpinBox *dbSpinAge;
    QLabel *label;
    QDateEdit *dbDateEditDOB;
    QLabel *label_2;
    QSpinBox *dbSpinHeight;
    QLabel *label_3;
    QSpinBox *dbSpinWeight;
    QLabel *label_4;
    QLineEdit *dbEditMobile;
    QLabel *label_9;
    QLineEdit *dbCreatedTimeStamp;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *btSave;
    QPushButton *btCancel;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *PatientEditView)
    {
        if (PatientEditView->objectName().isEmpty())
            PatientEditView->setObjectName(QString::fromUtf8("PatientEditView"));
        PatientEditView->resize(838, 477);
        label_11 = new QLabel(PatientEditView);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(20, 270, 201, 201));
        label_11->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/img/dp4.png);"));
        widget = new QWidget(PatientEditView);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 11, 776, 356));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_2 = new QSpacerItem(20, 22, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(280, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_6);

        dbEditID = new QLineEdit(widget);
        dbEditID->setObjectName(QString::fromUtf8("dbEditID"));
        dbEditID->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	padding: 1px 15px 1px 3px;\n"
"  border:1px  solid;\n"
"}\n"
""));

        formLayout->setWidget(0, QFormLayout::FieldRole, dbEditID);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_5);

        dbEditName = new QLineEdit(widget);
        dbEditName->setObjectName(QString::fromUtf8("dbEditName"));
        dbEditName->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	padding: 1px 15px 1px 3px;\n"
"  border:1px  solid;\n"
"}"));

        formLayout->setWidget(1, QFormLayout::FieldRole, dbEditName);

        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_7);

        dbEditIDCard = new QLineEdit(widget);
        dbEditIDCard->setObjectName(QString::fromUtf8("dbEditIDCard"));
        dbEditIDCard->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	padding: 1px 15px 1px 3px;\n"
"  border:1px  solid;\n"
"}"));

        formLayout->setWidget(2, QFormLayout::FieldRole, dbEditIDCard);

        label_8 = new QLabel(widget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_8);

        dbComboSex = new QComboBox(widget);
        dbComboSex->addItem(QString());
        dbComboSex->addItem(QString());
        dbComboSex->setObjectName(QString::fromUtf8("dbComboSex"));
        dbComboSex->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"  color:#666666;\n"
"  font-size:14px;\n"
"  padding: 1px 15px 1px 3px;\n"
"  border:1px  solid;\n"
"} \n"
"\n"
"QComboBox QAbstractItemView::item{\n"
"	height:36px;\n"
"	color:#666666;\n"
"	padding-left:9px;\n"
"	background-color:#FFFFFF;\n"
"}\n"
"QComboBox QAbstractItemView::item:hover{ //\346\202\254\346\265\256\n"
"  background-color:#409CE1;\n"
"  color:#ffffff;\n"
"}\n"
"QComboBox QAbstractItemView::item:selected{//\351\200\211\344\270\255\n"
"  background-color:#409CE1;\n"
"  color:#ffffff;\n"
"}\n"
"QComboBox:on { \n"
"      padding-top: 3px;\n"
"      padding-left: 4px;\n"
"  }\n"
"  QComboBox::down-arrow:on { \n"
"      top: 1px;\n"
"      left: 1px;\n"
"  }"));

        formLayout->setWidget(3, QFormLayout::FieldRole, dbComboSex);

        label_10 = new QLabel(widget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_10);

        dbSpinAge = new QSpinBox(widget);
        dbSpinAge->setObjectName(QString::fromUtf8("dbSpinAge"));
        dbSpinAge->setStyleSheet(QString::fromUtf8("QSpinBox\n"
" {\n"
"padding: 1px 15px 1px 3px;\n"
"  border:1px  solid;\n"
"}\n"
"\n"
"QSpinBox::up-button //QSpinBox\347\232\204\345\220\221\344\270\212\346\214\211\351\222\256\n"
"{\n"
"subcontrol-origin: border;//subcontrol-origin\346\214\207\345\256\232\345\216\237\345\247\213\347\237\251\345\275\242\345\206\205\345\255\220\346\216\247\344\273\266\347\232\204\345\257\271\351\275\220\346\226\271\345\274\217\n"
"subcontrol-position: top right; /* position at the top right corner */\n"
"width: 16px; \n"
"border-width: 1px;\n"
"}\n"
"\n"
"QSpinBox::up-arrow //\345\220\221\344\270\212\347\256\255\345\244\264\n"
"{\n"
"width: 7px;\n"
"height: 7px;\n"
"}\n"
"\n"
"QSpinBox::down-button //\345\220\221\344\270\213\346\214\211\351\222\256\n"
"{\n"
"subcontrol-origin: border;\n"
"subcontrol-position: bottom right; /* position at bottom right corner */\n"
"width: 16px;\n"
"border-width: 1px;//\350\276\271\347\225\214\345\256\275\345\272\246\n"
"border-top-width: 0;//\350\276\271\347\225\214\351\241\266\351\203\250\345\256"
                        "\275\345\272\246\n"
"}\n"
"\n"
"QSpinBox::down-arrow //\345\220\221\344\270\213\347\232\204\347\256\255\345\244\264\n"
"{\n"
"width: 7px;\n"
"height: 7px;\n"
"}\n"
"\n"
""));
        dbSpinAge->setMaximum(199);

        formLayout->setWidget(4, QFormLayout::FieldRole, dbSpinAge);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label);

        dbDateEditDOB = new QDateEdit(widget);
        dbDateEditDOB->setObjectName(QString::fromUtf8("dbDateEditDOB"));
        dbDateEditDOB->setStyleSheet(QString::fromUtf8("QDateEdit\n"
" {\n"
"padding: 1px 15px 1px 3px;\n"
"  border:1px  solid;\n"
"}\n"
"\n"
"QDateEdit::up-button //QSpinBox\347\232\204\345\220\221\344\270\212\346\214\211\351\222\256\n"
"{\n"
"subcontrol-origin: border;//subcontrol-origin\346\214\207\345\256\232\345\216\237\345\247\213\347\237\251\345\275\242\345\206\205\345\255\220\346\216\247\344\273\266\347\232\204\345\257\271\351\275\220\346\226\271\345\274\217\n"
"subcontrol-position: top right; /* position at the top right corner */\n"
"width: 16px; \n"
"border-width: 1px;\n"
"}\n"
"QDateEdit::up-arrow //\345\220\221\344\270\212\347\256\255\345\244\264\n"
"{\n"
"width: 7px;\n"
"height: 7px;\n"
"}\n"
"\n"
"QDateEdit::down-button //\345\220\221\344\270\213\346\214\211\351\222\256\n"
"{\n"
"subcontrol-origin: border;\n"
"subcontrol-position: bottom right; /* position at bottom right corner */\n"
"width: 16px;\n"
"border-width: 1px;//\350\276\271\347\225\214\345\256\275\345\272\246\n"
"border-top-width: 0;//\350\276\271\347\225\214\351\241\266\351\203\250\345\256"
                        "\275\345\272\246\n"
"}\n"
"\n"
"QDateEdit::down-arrow //\345\220\221\344\270\213\347\232\204\347\256\255\345\244\264\n"
"{\n"
"width: 7px;\n"
"height: 7px;\n"
"}\n"
"\n"
""));

        formLayout->setWidget(5, QFormLayout::FieldRole, dbDateEditDOB);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_2);

        dbSpinHeight = new QSpinBox(widget);
        dbSpinHeight->setObjectName(QString::fromUtf8("dbSpinHeight"));
        dbSpinHeight->setStyleSheet(QString::fromUtf8("QSpinBox\n"
" {\n"
"padding: 1px 15px 1px 3px;\n"
"  border:1px  solid;\n"
"}\n"
"\n"
"QSpinBox::up-button //QSpinBox\347\232\204\345\220\221\344\270\212\346\214\211\351\222\256\n"
"{\n"
"subcontrol-origin: border;//subcontrol-origin\346\214\207\345\256\232\345\216\237\345\247\213\347\237\251\345\275\242\345\206\205\345\255\220\346\216\247\344\273\266\347\232\204\345\257\271\351\275\220\346\226\271\345\274\217\n"
"subcontrol-position: top right; /* position at the top right corner */\n"
"width: 16px; \n"
"border-width: 1px;\n"
"}\n"
"\n"
"QSpinBox::up-arrow //\345\220\221\344\270\212\347\256\255\345\244\264\n"
"{\n"
"width: 7px;\n"
"height: 7px;\n"
"}\n"
"\n"
"QSpinBox::down-button //\345\220\221\344\270\213\346\214\211\351\222\256\n"
"{\n"
"subcontrol-origin: border;\n"
"subcontrol-position: bottom right; /* position at bottom right corner */\n"
"width: 16px;\n"
"border-width: 1px;//\350\276\271\347\225\214\345\256\275\345\272\246\n"
"border-top-width: 0;//\350\276\271\347\225\214\351\241\266\351\203\250\345\256"
                        "\275\345\272\246\n"
"}\n"
"\n"
"QSpinBox::down-arrow //\345\220\221\344\270\213\347\232\204\347\256\255\345\244\264\n"
"{\n"
"width: 7px;\n"
"height: 7px;\n"
"}\n"
"\n"
""));
        dbSpinHeight->setMaximum(299);
        dbSpinHeight->setSingleStep(5);

        formLayout->setWidget(6, QFormLayout::FieldRole, dbSpinHeight);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_3);

        dbSpinWeight = new QSpinBox(widget);
        dbSpinWeight->setObjectName(QString::fromUtf8("dbSpinWeight"));
        dbSpinWeight->setStyleSheet(QString::fromUtf8("QSpinBox\n"
" {\n"
"padding: 1px 15px 1px 3px;\n"
"  border:1px  solid;\n"
"}\n"
"\n"
"QSpinBox::up-button //QSpinBox\347\232\204\345\220\221\344\270\212\346\214\211\351\222\256\n"
"{\n"
"subcontrol-origin: border;//subcontrol-origin\346\214\207\345\256\232\345\216\237\345\247\213\347\237\251\345\275\242\345\206\205\345\255\220\346\216\247\344\273\266\347\232\204\345\257\271\351\275\220\346\226\271\345\274\217\n"
"subcontrol-position: top right; /* position at the top right corner */\n"
"width: 16px; \n"
"border-width: 1px;\n"
"}\n"
"\n"
"QSpinBox::up-arrow //\345\220\221\344\270\212\347\256\255\345\244\264\n"
"{\n"
"width: 7px;\n"
"height: 7px;\n"
"}\n"
"\n"
"QSpinBox::down-button //\345\220\221\344\270\213\346\214\211\351\222\256\n"
"{\n"
"subcontrol-origin: border;\n"
"subcontrol-position: bottom right; /* position at bottom right corner */\n"
"width: 16px;\n"
"border-width: 1px;//\350\276\271\347\225\214\345\256\275\345\272\246\n"
"border-top-width: 0;//\350\276\271\347\225\214\351\241\266\351\203\250\345\256"
                        "\275\345\272\246\n"
"}\n"
"\n"
"QSpinBox::down-arrow //\345\220\221\344\270\213\347\232\204\347\256\255\345\244\264\n"
"{\n"
"width: 7px;\n"
"height: 7px;\n"
"}\n"
"\n"
""));
        dbSpinWeight->setMaximum(699);

        formLayout->setWidget(7, QFormLayout::FieldRole, dbSpinWeight);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(8, QFormLayout::LabelRole, label_4);

        dbEditMobile = new QLineEdit(widget);
        dbEditMobile->setObjectName(QString::fromUtf8("dbEditMobile"));
        dbEditMobile->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	padding: 1px 15px 1px 3px;\n"
"  border:1px  solid;\n"
"}"));

        formLayout->setWidget(8, QFormLayout::FieldRole, dbEditMobile);

        label_9 = new QLabel(widget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        formLayout->setWidget(9, QFormLayout::LabelRole, label_9);

        dbCreatedTimeStamp = new QLineEdit(widget);
        dbCreatedTimeStamp->setObjectName(QString::fromUtf8("dbCreatedTimeStamp"));
        dbCreatedTimeStamp->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	padding: 1px 15px 1px 3px;\n"
"  border:1px  solid;\n"
"}"));

        formLayout->setWidget(9, QFormLayout::FieldRole, dbCreatedTimeStamp);


        horizontalLayout->addLayout(formLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        btSave = new QPushButton(widget);
        btSave->setObjectName(QString::fromUtf8("btSave"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/img/dbsave.png"), QSize(), QIcon::Normal, QIcon::Off);
        btSave->setIcon(icon);

        verticalLayout->addWidget(btSave);

        btCancel = new QPushButton(widget);
        btCancel->setObjectName(QString::fromUtf8("btCancel"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/img/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        btCancel->setIcon(icon1);

        verticalLayout->addWidget(btCancel);


        horizontalLayout->addLayout(verticalLayout);


        horizontalLayout_2->addLayout(horizontalLayout);

        horizontalSpacer_2 = new QSpacerItem(130, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);


        retranslateUi(PatientEditView);

        QMetaObject::connectSlotsByName(PatientEditView);
    } // setupUi

    void retranslateUi(QWidget *PatientEditView)
    {
        PatientEditView->setWindowTitle(QApplication::translate("PatientEditView", "\347\274\226\350\276\221\346\202\243\350\200\205\344\277\241\346\201\257", nullptr));
        label_11->setText(QString());
        label_6->setText(QApplication::translate("PatientEditView", "ID:", nullptr));
        label_5->setText(QApplication::translate("PatientEditView", "\345\247\223\345\220\215\357\274\232", nullptr));
        label_7->setText(QApplication::translate("PatientEditView", "\350\272\253\344\273\275\350\257\201\357\274\232", nullptr));
        label_8->setText(QApplication::translate("PatientEditView", "\346\200\247\345\210\253\357\274\232", nullptr));
        dbComboSex->setItemText(0, QApplication::translate("PatientEditView", "\347\224\267", nullptr));
        dbComboSex->setItemText(1, QApplication::translate("PatientEditView", "\345\245\263", nullptr));

        label_10->setText(QApplication::translate("PatientEditView", "\345\271\264\351\276\204\357\274\232", nullptr));
        label->setText(QApplication::translate("PatientEditView", "\345\207\272\347\224\237\346\227\245\346\234\237\357\274\232", nullptr));
        label_2->setText(QApplication::translate("PatientEditView", "\350\272\253\351\253\230\357\274\232", nullptr));
        dbSpinHeight->setSuffix(QApplication::translate("PatientEditView", "cm", nullptr));
        label_3->setText(QApplication::translate("PatientEditView", "\344\275\223\351\207\215\357\274\232", nullptr));
        dbSpinWeight->setSuffix(QApplication::translate("PatientEditView", "kg", nullptr));
        label_4->setText(QApplication::translate("PatientEditView", "\346\211\213\346\234\272\345\217\267\357\274\232", nullptr));
        label_9->setText(QApplication::translate("PatientEditView", "\345\210\233\345\273\272\346\227\266\351\227\264\357\274\232", nullptr));
        btSave->setText(QApplication::translate("PatientEditView", "\344\277\235\345\255\230", nullptr));
        btCancel->setText(QApplication::translate("PatientEditView", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PatientEditView: public Ui_PatientEditView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENTEDITVIEW_H
