#ifndef HISTDATA_H
#define HISTDATA_H

#include <QVector>

class HistogramaData
{
private:
    QVector<double> *rojo;
    QVector<double> *verde;
    QVector<double> *azul;

    double rMax;
    double vMax;
    double aMax;

public:
    HistogramaData();

    typedef enum {
        ROJO,
        VERDE,
        AZUL
    } COLOR;

    void set_rojo(QVector<double>* rojo);
    void set_verde(QVector<double>* verde);
    void set_azul(QVector<double>* azul);

    QVector<double>* get_rojo();
    QVector<double>* get_verde();
    QVector<double>* get_azul();

    void actualizarValor(COLOR c, int indice);

    double get_rMax();
    double get_vMax();
    double get_aMax();

    double get_max_range();

};

#endif // HISTDATA_H
