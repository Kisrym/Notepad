#ifndef FONTE_H
#define FONTE_H

#include <QMainWindow>

namespace Ui {
class fonte;
}

class fonte : public QMainWindow
{
    Q_OBJECT

public:
    explicit fonte(QWidget *parent = nullptr);
    ~fonte();

private slots:
    void on_tamanho_currentIndexChanged(int index);
    void on_fonte1_currentIndexChanged(int index);
    void on_estilo_currentIndexChanged(int index);

signals:
    void set_font(QFont new_font);

private:
    Ui::fonte *ui;
};

#endif // FONTE_H
