#ifndef NOTEPAD_H
#define NOTEPAD_H

#include "ui_notepad.h"
#include "fonte.h"
#include "localizar.h"

#include <QMainWindow>
#include <QCloseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class Notepad; }
QT_END_NAMESPACE

class Notepad : public QMainWindow
{
    Q_OBJECT

public:
    Notepad(QWidget *parent = nullptr);
    ~Notepad();

private slots:
    // Arquivo
    void on_actionNovo_triggered();
    void on_actionNova_Janela_triggered();
    void on_actionAbrir_triggered();
    void on_actionSalvar_como_triggered();
    void on_actionSalvar_triggered();
    void on_actionSair_triggered(){this->close();};

    // Editar
    void on_actionDesfazer_triggered(){ui->texto->undo();};
    void on_actionRecortar_triggered(){ui->texto->cut();};
    void on_actionCopiar_triggered(){ui->texto->copy();};
    void on_actionColar_triggered(){ui->texto->paste();};
    void on_actionExcluir_triggered(){ui->texto->clear();}
    void on_actionLocalizar_triggered(){localizar->show();};

    // Formatar
    void on_actionFonte_triggered();

    // Eventos
    void closeEvent(QCloseEvent *event);
    void on_texto_textChanged();

private slots:
    void font_changed(QFont new_font);
    void search_slot(QString word, bool checkBox, bool up, bool around);

// Funções auxiliares
private:
    QString format_url(QString url) const;

public:
    QString file_path;
    QString file_name = "Sem título.txt";
    Ui::Notepad *ui;

    fonte *janela = new fonte;
    Localizar *localizar = new Localizar;
};
#endif // NOTEPAD_H
