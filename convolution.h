#ifndef CONVOLUTION_H
#define CONVOLUTION_H
#include "armadillo"
#include <QDialog>
#include "mascara.h"

namespace Ui {
class convolution;
}

class Convolution : public QDialog
{
    Q_OBJECT

public:
    explicit Convolution(QWidget *parent = 0);

    ~Convolution();

signals:
    void signal_convolucion(Mascara* mask);

private slots:
    void on_combo_ancho_currentIndexChanged(int index);
    void on_combo_alto_currentIndexChanged(int index);
    void click_convolucion();
    void on_combo_columna_centro_activated(const QString &arg1);
    void on_combo_fila_centro_activated(const QString &arg1);
    int** crearArregloBidimensional(int col,int rows);


private:
    Ui::convolution *ui;
};

#endif // CONVOLUTION_H
