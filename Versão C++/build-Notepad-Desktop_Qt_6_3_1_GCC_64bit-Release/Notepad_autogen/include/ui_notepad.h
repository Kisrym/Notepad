/********************************************************************************
** Form generated from reading UI file 'notepad.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTEPAD_H
#define UI_NOTEPAD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Notepad
{
public:
    QAction *actionSalvar;
    QAction *actionAbrir;
    QAction *actionNovo;
    QAction *actionNova_Janela;
    QAction *actionSalvar_como;
    QAction *actionSair;
    QAction *actionDesfazer;
    QAction *actionRecortar;
    QAction *actionCopiar;
    QAction *actionColar;
    QAction *actionExcluir;
    QAction *actionLocalizar;
    QAction *actionFonte;
    QWidget *centralwidget;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QTextEdit *texto;
    QMenuBar *menuBar;
    QMenu *menuArquivo;
    QMenu *menuEditar;
    QMenu *menuFormatar;

    void setupUi(QMainWindow *Notepad)
    {
        if (Notepad->objectName().isEmpty())
            Notepad->setObjectName(QString::fromUtf8("Notepad"));
        Notepad->resize(919, 631);
        actionSalvar = new QAction(Notepad);
        actionSalvar->setObjectName(QString::fromUtf8("actionSalvar"));
        actionAbrir = new QAction(Notepad);
        actionAbrir->setObjectName(QString::fromUtf8("actionAbrir"));
        actionNovo = new QAction(Notepad);
        actionNovo->setObjectName(QString::fromUtf8("actionNovo"));
        actionNova_Janela = new QAction(Notepad);
        actionNova_Janela->setObjectName(QString::fromUtf8("actionNova_Janela"));
        actionSalvar_como = new QAction(Notepad);
        actionSalvar_como->setObjectName(QString::fromUtf8("actionSalvar_como"));
        actionSair = new QAction(Notepad);
        actionSair->setObjectName(QString::fromUtf8("actionSair"));
        actionDesfazer = new QAction(Notepad);
        actionDesfazer->setObjectName(QString::fromUtf8("actionDesfazer"));
        actionRecortar = new QAction(Notepad);
        actionRecortar->setObjectName(QString::fromUtf8("actionRecortar"));
        actionCopiar = new QAction(Notepad);
        actionCopiar->setObjectName(QString::fromUtf8("actionCopiar"));
        actionColar = new QAction(Notepad);
        actionColar->setObjectName(QString::fromUtf8("actionColar"));
        actionExcluir = new QAction(Notepad);
        actionExcluir->setObjectName(QString::fromUtf8("actionExcluir"));
        actionLocalizar = new QAction(Notepad);
        actionLocalizar->setObjectName(QString::fromUtf8("actionLocalizar"));
        actionFonte = new QAction(Notepad);
        actionFonte->setObjectName(QString::fromUtf8("actionFonte"));
        centralwidget = new QWidget(Notepad);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        gridLayout_4 = new QGridLayout(centralwidget);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        texto = new QTextEdit(centralwidget);
        texto->setObjectName(QString::fromUtf8("texto"));
        QFont font;
        font.setFamilies({QString::fromUtf8("Consolas")});
        font.setPointSize(10);
        texto->setFont(font);
        texto->setStyleSheet(QString::fromUtf8("margin: -200;"));

        gridLayout_3->addWidget(texto, 0, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 0, 0, 1, 1);

        Notepad->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(Notepad);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 919, 20));
        menuArquivo = new QMenu(menuBar);
        menuArquivo->setObjectName(QString::fromUtf8("menuArquivo"));
        menuArquivo->setTearOffEnabled(false);
        menuEditar = new QMenu(menuBar);
        menuEditar->setObjectName(QString::fromUtf8("menuEditar"));
        menuFormatar = new QMenu(menuBar);
        menuFormatar->setObjectName(QString::fromUtf8("menuFormatar"));
        Notepad->setMenuBar(menuBar);

        menuBar->addAction(menuArquivo->menuAction());
        menuBar->addAction(menuEditar->menuAction());
        menuBar->addAction(menuFormatar->menuAction());
        menuArquivo->addAction(actionNovo);
        menuArquivo->addAction(actionNova_Janela);
        menuArquivo->addAction(actionAbrir);
        menuArquivo->addAction(actionSalvar);
        menuArquivo->addAction(actionSalvar_como);
        menuArquivo->addSeparator();
        menuArquivo->addAction(actionSair);
        menuEditar->addAction(actionDesfazer);
        menuEditar->addSeparator();
        menuEditar->addAction(actionRecortar);
        menuEditar->addAction(actionCopiar);
        menuEditar->addAction(actionColar);
        menuEditar->addAction(actionExcluir);
        menuEditar->addSeparator();
        menuEditar->addAction(actionLocalizar);
        menuFormatar->addAction(actionFonte);

        retranslateUi(Notepad);

        QMetaObject::connectSlotsByName(Notepad);
    } // setupUi

    void retranslateUi(QMainWindow *Notepad)
    {
        Notepad->setWindowTitle(QCoreApplication::translate("Notepad", "Notepad", nullptr));
        actionSalvar->setText(QCoreApplication::translate("Notepad", "Salvar", nullptr));
#if QT_CONFIG(shortcut)
        actionSalvar->setShortcut(QCoreApplication::translate("Notepad", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAbrir->setText(QCoreApplication::translate("Notepad", "Abrir...", nullptr));
#if QT_CONFIG(shortcut)
        actionAbrir->setShortcut(QCoreApplication::translate("Notepad", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionNovo->setText(QCoreApplication::translate("Notepad", "Novo", nullptr));
#if QT_CONFIG(shortcut)
        actionNovo->setShortcut(QCoreApplication::translate("Notepad", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionNova_Janela->setText(QCoreApplication::translate("Notepad", "Nova Janela", nullptr));
#if QT_CONFIG(shortcut)
        actionNova_Janela->setShortcut(QCoreApplication::translate("Notepad", "Ctrl+Shift+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSalvar_como->setText(QCoreApplication::translate("Notepad", "Salvar como...", nullptr));
#if QT_CONFIG(shortcut)
        actionSalvar_como->setShortcut(QCoreApplication::translate("Notepad", "Ctrl+Shift+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSair->setText(QCoreApplication::translate("Notepad", "Sair", nullptr));
        actionDesfazer->setText(QCoreApplication::translate("Notepad", "Desfazer", nullptr));
#if QT_CONFIG(shortcut)
        actionDesfazer->setShortcut(QCoreApplication::translate("Notepad", "Ctrl+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        actionRecortar->setText(QCoreApplication::translate("Notepad", "Recortar", nullptr));
#if QT_CONFIG(shortcut)
        actionRecortar->setShortcut(QCoreApplication::translate("Notepad", "Ctrl+X", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCopiar->setText(QCoreApplication::translate("Notepad", "Copiar", nullptr));
#if QT_CONFIG(shortcut)
        actionCopiar->setShortcut(QCoreApplication::translate("Notepad", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        actionColar->setText(QCoreApplication::translate("Notepad", "Colar", nullptr));
#if QT_CONFIG(shortcut)
        actionColar->setShortcut(QCoreApplication::translate("Notepad", "Ctrl+V", nullptr));
#endif // QT_CONFIG(shortcut)
        actionExcluir->setText(QCoreApplication::translate("Notepad", "Excluir", nullptr));
#if QT_CONFIG(shortcut)
        actionExcluir->setShortcut(QCoreApplication::translate("Notepad", "Del", nullptr));
#endif // QT_CONFIG(shortcut)
        actionLocalizar->setText(QCoreApplication::translate("Notepad", "Localizar...", nullptr));
#if QT_CONFIG(shortcut)
        actionLocalizar->setShortcut(QCoreApplication::translate("Notepad", "Ctrl+F", nullptr));
#endif // QT_CONFIG(shortcut)
        actionFonte->setText(QCoreApplication::translate("Notepad", "Fonte...", nullptr));
        menuArquivo->setTitle(QCoreApplication::translate("Notepad", "Arquivo", nullptr));
        menuEditar->setTitle(QCoreApplication::translate("Notepad", "Editar", nullptr));
        menuFormatar->setTitle(QCoreApplication::translate("Notepad", "Formatar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Notepad: public Ui_Notepad {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTEPAD_H
