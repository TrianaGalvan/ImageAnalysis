#ifndef CONVOLUTION_H
#define CONVOLUTION_H

#include <QDialog>

namespace Ui {
class convolution;
}

class Convolution : public QDialog
{
    Q_OBJECT

public:
    explicit Convolution(QWidget *parent = 0);

    ~Convolution();

private slots:
    void on_combo_ancho_currentIndexChanged(int index);
    void on_combo_alto_currentIndexChanged(int index);
    void on_btn_convolucion_clicked();
    void on_combo_columna_centro_activated(const QString &arg1);
    void on_combo_fila_centro_activated(const QString &arg1);
    int** crearArregloBidimensional(int col,int rows);

signals:
    void signal_convolucion(int** array,int colOrigen,int rowOrigen,int numCols,int numRows);

private:
    Ui::convolution *ui;
};

#endif // CONVOLUTION_H
