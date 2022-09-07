#ifndef LOCALIZAR_H
#define LOCALIZAR_H

#include <QMainWindow>

namespace Ui {
class Localizar;
}

class Localizar : public QMainWindow
{
    Q_OBJECT

public:
    explicit Localizar(QWidget *parent = nullptr);
    ~Localizar();

private slots:
    void on_buscar_clicked();
    void on_cancelar_clicked(){this->close();}

signals:
    void search_signal(QString text, bool checkBox, bool up, bool around);

private:
    Ui::Localizar *ui;
    QString text;
};

#endif // LOCALIZAR_H
