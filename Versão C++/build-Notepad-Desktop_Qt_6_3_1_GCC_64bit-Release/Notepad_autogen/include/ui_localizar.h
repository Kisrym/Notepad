/********************************************************************************
** Form generated from reading UI file 'localizar.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOCALIZAR_H
#define UI_LOCALIZAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Localizar
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLineEdit *word;
    QPushButton *buscar;
    QPushButton *cancelar;
    QGroupBox *groupBox;
    QRadioButton *up;
    QRadioButton *down;
    QCheckBox *checkBox;
    QCheckBox *around;

    void setupUi(QMainWindow *Localizar)
    {
        if (Localizar->objectName().isEmpty())
            Localizar->setObjectName(QString::fromUtf8("Localizar"));
        Localizar->resize(558, 156);
        centralwidget = new QWidget(Localizar);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 15, 51, 16));
        QFont font;
        font.setPointSize(9);
        label->setFont(font);
        word = new QLineEdit(centralwidget);
        word->setObjectName(QString::fromUtf8("word"));
        word->setGeometry(QRect(90, 13, 271, 20));
        buscar = new QPushButton(centralwidget);
        buscar->setObjectName(QString::fromUtf8("buscar"));
        buscar->setGeometry(QRect(380, 10, 111, 23));
        buscar->setAutoDefault(false);
        cancelar = new QPushButton(centralwidget);
        cancelar->setObjectName(QString::fromUtf8("cancelar"));
        cancelar->setGeometry(QRect(380, 40, 111, 23));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(240, 60, 131, 51));
        groupBox->setFont(font);
        up = new QRadioButton(groupBox);
        up->setObjectName(QString::fromUtf8("up"));
        up->setGeometry(QRect(10, 20, 82, 17));
        QFont font1;
        font1.setPointSize(8);
        up->setFont(font1);
        down = new QRadioButton(groupBox);
        down->setObjectName(QString::fromUtf8("down"));
        down->setGeometry(QRect(70, 20, 82, 17));
        down->setFont(font1);
        down->setChecked(true);
        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(10, 110, 211, 17));
        around = new QCheckBox(centralwidget);
        around->setObjectName(QString::fromUtf8("around"));
        around->setGeometry(QRect(10, 130, 70, 17));
        Localizar->setCentralWidget(centralwidget);

        retranslateUi(Localizar);

        buscar->setDefault(true);


        QMetaObject::connectSlotsByName(Localizar);
    } // setupUi

    void retranslateUi(QMainWindow *Localizar)
    {
        Localizar->setWindowTitle(QCoreApplication::translate("Localizar", "Localizar", nullptr));
        label->setText(QCoreApplication::translate("Localizar", "Localizar:", nullptr));
        buscar->setText(QCoreApplication::translate("Localizar", "Localizar Pr\303\263xima", nullptr));
        cancelar->setText(QCoreApplication::translate("Localizar", "Cancelar", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Localizar", "Dire\303\247\303\243o", nullptr));
        up->setText(QCoreApplication::translate("Localizar", "Acima", nullptr));
        down->setText(QCoreApplication::translate("Localizar", "Abaixo", nullptr));
        checkBox->setText(QCoreApplication::translate("Localizar", "Diferenciar mai\303\272sculas de min\303\272sculas", nullptr));
        around->setText(QCoreApplication::translate("Localizar", "Ao redor", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Localizar: public Ui_Localizar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOCALIZAR_H
