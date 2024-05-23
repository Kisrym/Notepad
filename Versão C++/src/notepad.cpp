#include "notepad.h"
#include "./ui_notepad.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QTextDocument>

#include <fstream>
#include <sstream>
#include <iostream>

Notepad::Notepad(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Notepad)
{
    ui->setupUi(this);
    this->setWindowTitle(file_name + " - Notepad");

    connect(janela, SIGNAL(set_font(QFont)), this, SLOT(font_changed(QFont)));
    connect(localizar, &Localizar::search_signal, this, &Notepad::search_slot);
}

Notepad::~Notepad()
{
    delete ui;
    delete janela;
    delete localizar;
}

// Funções auxiliares
QString Notepad::format_url(QString url) const{
    QString new_name;
    for (QChar l : url){
        new_name.append(l);
        if (l == '/'){
            new_name = "";
        }
    }
    return new_name;
}

// Aba arquivo
void Notepad::on_actionNovo_triggered()
{
    if (ui->texto->toPlainText() != ""){
        QMessageBox::StandardButton resposta = QMessageBox::question(this, "Notepad", "Deseja salvar as alterações?", QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);

        if (resposta == QMessageBox::Save){this->on_actionSalvar_triggered();}
        else if (resposta == QMessageBox::Cancel){return;}
    }
    ui->texto->setText("");
    file_path = "";
    this->setWindowTitle(file_name + " - Notepad");
}


void Notepad::on_actionNova_Janela_triggered()
{
    Notepad *nova_janela = new Notepad;
    nova_janela->show();
}

void Notepad::on_actionAbrir_triggered()
{
    if (this->windowTitle().toStdString()[0] == '*' && ui->texto->toPlainText() != ""){
        QMessageBox::StandardButton resposta = QMessageBox::question(this, "Notepad", "Deseja salvar as alterações?", QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);

        if (resposta == QMessageBox::Save){this->on_actionSalvar_triggered();}
        if (resposta == QMessageBox::Cancel){return;}
    }

    file_path = QFileDialog::getOpenFileName(this, "Abrir arquivo", "", "Documentos de Texto (*.txt)");

    if (file_path.toStdString() != ""){
        std::ifstream f(file_path.toStdString());

        std::stringstream massa;
        massa << f.rdbuf();
        ui->texto->setText(QString::fromStdString(massa.str()));

        file_name = format_url(file_path);
        this->setWindowTitle(file_name + " - Notepad");

        massa.clear();
        f.close();
    }
}

void Notepad::on_actionSalvar_triggered()
{
    if (file_path == ""){
        this->on_actionSalvar_como_triggered();
    }
    else {
        std::ofstream f(file_path.toStdString());

        std::stringstream massa;
        massa << ui->texto->toPlainText().toStdString();
        f << massa.str();

        this->setWindowTitle(file_name + " - Notepad");

        massa.clear();
        f.clear();
    }
}

void Notepad::on_actionSalvar_como_triggered()
{
    file_path = QFileDialog::getSaveFileName(this, "Salvar Arquivo", "Sem Título.txt", "Documentos de Texto (*.txt)");

    if (file_path != ""){
        std::ofstream f(file_path.toStdString());

        std::stringstream massa;
        massa << ui->texto->toPlainText().toStdString();
        f << massa.str();

        file_name = file_name != "" ? format_url(file_path) : "Sem título.txt";
        this->setWindowTitle(file_name + " - Notepad");

        massa.clear();
        f.close();
    }
}
// Formatar
void Notepad::on_actionFonte_triggered(){
    janela->show();
}

// Eventos
void Notepad::closeEvent(QCloseEvent *event){
    if (ui->texto->toPlainText() != "" && this->windowTitle().toStdString()[0] == '*'){
        QMessageBox::StandardButton resposta = QMessageBox::question(this, "Bloco de Notas", "Deseja salvar as alterações?", QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);

        if (resposta == QMessageBox::Save){
            this->on_actionSalvar_triggered();
            event->accept();
        }
        else if (resposta == QMessageBox::Cancel){
            event->ignore();
            return;
        }
    }
    else {
        event->accept();
    }
}

void Notepad::on_texto_textChanged()
{
    if (this->windowTitle().at(0) != '*'){
        this->setWindowTitle("*" + file_name + " - Notepad");
    }
    if (ui->texto->toPlainText() == ""){
        this->setWindowTitle(file_name + " - Notepad");
    }
}

void Notepad::font_changed(QFont new_font){
    ui->texto->setFont(new_font);
}

void Notepad::search_slot(QString word, bool checkBox, bool up, bool around){
    bool p;
    if (checkBox){
        if (up){
            p = ui->texto->find(word, QTextDocument::FindBackward | QTextDocument::FindCaseSensitively);
        }
        else{
            p = ui->texto->find(word, QTextDocument::FindCaseSensitively);
        }
    }
    else {
        if (up){
            p = ui->texto->find(word, QTextDocument::FindBackward);
        }
        else {
            p = ui->texto->find(word);
        }
    }

    if (!p){
        if (!around){
            QMessageBox::information(this, "Notepad", "Não é possível encontrar \"" + word + "\"");
        }
        else if (around){
            if (up){ui->texto->moveCursor(QTextCursor::End);}
            else {ui->texto->moveCursor(QTextCursor::Start);}
        }
    }
}
