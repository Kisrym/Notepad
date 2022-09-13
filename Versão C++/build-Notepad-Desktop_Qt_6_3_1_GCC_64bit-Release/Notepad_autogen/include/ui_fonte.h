/********************************************************************************
** Form generated from reading UI file 'fonte.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FONTE_H
#define UI_FONTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_fonte
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QFontComboBox *fonte1;
    QLabel *label_2;
    QComboBox *estilo;
    QLabel *label_3;
    QComboBox *tamanho;
    QGroupBox *groupBox;
    QLabel *exemplo;

    void setupUi(QMainWindow *fonte)
    {
        if (fonte->objectName().isEmpty())
            fonte->setObjectName(QString::fromUtf8("fonte"));
        fonte->resize(518, 400);
        fonte->setAutoFillBackground(false);
        fonte->setDocumentMode(true);
        fonte->setTabShape(QTabWidget::Rounded);
        centralwidget = new QWidget(fonte);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 47, 13));
        QFont font;
        font.setPointSize(9);
        label->setFont(font);
        fonte1 = new QFontComboBox(centralwidget);
        fonte1->setObjectName(QString::fromUtf8("fonte1"));
        fonte1->setGeometry(QRect(10, 40, 187, 22));
        fonte1->setStyleSheet(QString::fromUtf8(""));
        fonte1->setFontFilters(QFontComboBox::AllFonts);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Ubuntu")});
        fonte1->setCurrentFont(font1);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(210, 20, 101, 16));
        label_2->setFont(font);
        estilo = new QComboBox(centralwidget);
        estilo->addItem(QString());
        estilo->addItem(QString());
        estilo->addItem(QString());
        estilo->addItem(QString());
        estilo->setObjectName(QString::fromUtf8("estilo"));
        estilo->setEnabled(true);
        estilo->setGeometry(QRect(210, 40, 151, 22));
        QFont font2;
        font2.setPointSize(10);
        font2.setItalic(false);
        font2.setKerning(true);
        estilo->setFont(font2);
        estilo->setContextMenuPolicy(Qt::DefaultContextMenu);
        estilo->setAcceptDrops(false);
        estilo->setAutoFillBackground(true);
        estilo->setStyleSheet(QString::fromUtf8(""));
        estilo->setEditable(true);
        estilo->setInsertPolicy(QComboBox::InsertAtCurrent);
        estilo->setFrame(true);
        estilo->setModelColumn(0);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(370, 20, 81, 16));
        label_3->setFont(font);
        tamanho = new QComboBox(centralwidget);
        tamanho->setObjectName(QString::fromUtf8("tamanho"));
        tamanho->setGeometry(QRect(370, 40, 69, 22));
        tamanho->setEditable(true);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(260, 230, 231, 131));
        groupBox->setFont(font);
        exemplo = new QLabel(groupBox);
        exemplo->setObjectName(QString::fromUtf8("exemplo"));
        exemplo->setGeometry(QRect(0, 12, 231, 111));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Ubuntu")});
        font3.setPointSize(10);
        exemplo->setFont(font3);
        exemplo->setLayoutDirection(Qt::LeftToRight);
        exemplo->setAlignment(Qt::AlignCenter);
        fonte->setCentralWidget(centralwidget);

        retranslateUi(fonte);

        QMetaObject::connectSlotsByName(fonte);
    } // setupUi

    void retranslateUi(QMainWindow *fonte)
    {
        fonte->setWindowTitle(QCoreApplication::translate("fonte", "Fonte", nullptr));
        label->setText(QCoreApplication::translate("fonte", "Fonte:", nullptr));
        fonte1->setCurrentText(QCoreApplication::translate("fonte", "Ubuntu", nullptr));
        label_2->setText(QCoreApplication::translate("fonte", "Estilo da Fonte:", nullptr));
        estilo->setItemText(0, QCoreApplication::translate("fonte", "Regular", nullptr));
        estilo->setItemText(1, QCoreApplication::translate("fonte", "It\303\241lico", nullptr));
        estilo->setItemText(2, QCoreApplication::translate("fonte", "Negrito", nullptr));
        estilo->setItemText(3, QCoreApplication::translate("fonte", "It\303\241lico e Negrito", nullptr));

        label_3->setText(QCoreApplication::translate("fonte", "Tamanho:", nullptr));
        groupBox->setTitle(QCoreApplication::translate("fonte", "Exemplo", nullptr));
        exemplo->setText(QCoreApplication::translate("fonte", "AaBbYyZz", nullptr));
    } // retranslateUi

};

namespace Ui {
    class fonte: public Ui_fonte {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FONTE_H
