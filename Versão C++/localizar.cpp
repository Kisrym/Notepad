#include "localizar.h"
#include "ui_localizar.h"

Localizar::Localizar(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Localizar)
{
    ui->setupUi(this);
}

Localizar::~Localizar()
{
    delete ui;
}

void Localizar::on_buscar_clicked()
{
    emit search_signal(ui->word->text(), ui->checkBox->isChecked(), ui->up->isChecked(), ui->around->isChecked());
}
