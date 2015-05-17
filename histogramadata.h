#ifndef HISTDATA_H
#define HISTDATA_H

#include <QVector>

class HistogramaData
{
private:
    QVector<double> *rojo;
    QVector<double> *verde;
    QVector<double> *azul;
    QVector<double> *gray;

    double rMax;
    double vMax;
    double aMax;
    double gMax;

public:
    HistogramaData();

    typedef enum {
        ROJO,
        VERDE,
        AZUL,
        GRAY
    } COLOR;

    void set_rojo(QVector<double>* rojo);
    void set_verde(QVector<double>* verde);
    void set_azul(QVector<double>* azul);
    void set_gray(QVector<double>* gray);

    QVector<double>* get_rojo();
    QVector<double>* get_verde();
    QVector<double>* get_azul();
    QVector<double>* get_gray();

    void actualizarValor(COLOR c, int indice);

    double get_rMax();
    double get_vMax();
    double get_aMax();
    double get_gMax();

    double get_max_range();

};

#endif // HISTDATA_H
