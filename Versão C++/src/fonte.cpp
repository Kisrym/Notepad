#include "fonte.h"
#include "ui_fonte.h"

#include <variant>

fonte::fonte(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::fonte)
{
    ui->setupUi(this);

    // Adicionando os tamanhos de fonte
    int i = 8;
    while (true){
        ui->tamanho->addItem(QString::fromStdString(std::to_string(i)));
        if (i < 12){i++;}
        else if (i >= 12 && i < 28){i+=2;}
        else {
            QStringList a = {"36", "48", "72"};
            ui->tamanho->addItems(a);
            break;
        }
    }
    ui->tamanho->setCurrentIndex(2);

}

fonte::~fonte()
{
    delete ui;
}

void fonte::on_tamanho_currentIndexChanged(int index)
{
    ui->estilo->setCurrentIndex(0);
    emit set_font(QFont(ui->fonte1->currentText(), ui->tamanho->currentText().toInt()));
    ui->exemplo->setFont(QFont(ui->fonte1->currentText(), ui->tamanho->currentText().toInt()));
}


void fonte::on_fonte1_currentIndexChanged(int index)
{
    ui->estilo->setCurrentIndex(0);
    emit set_font(QFont(ui->fonte1->currentText(), ui->tamanho->currentText().toInt()));
    ui->exemplo->setFont(QFont(ui->fonte1->currentText(), ui->tamanho->currentText().toInt()));
}

void fonte::on_estilo_currentIndexChanged(int index){
    QFont estilo(QFont(ui->fonte1->currentText(), ui->tamanho->currentText().toInt()));

    switch (index){
        case 0:
            emit set_font(estilo);
            break;
        case 1:
            estilo.setItalic(true);
            break;
        case 2:
            estilo.setBold(true);
            break;
        case 3:
            estilo.setBold(true);
            estilo.setItalic(true);
            break;
        }
    emit set_font(estilo);
    ui->exemplo->setFont(estilo);
}
