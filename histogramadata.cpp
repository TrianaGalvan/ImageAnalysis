#include "histogramadata.h"

HistogramaData::HistogramaData()
{
    rojo = new QVector<double>(256, 0);
    verde = new QVector<double>(256, 0);
    azul = new QVector<double>(256, 0);
    gray = new QVector<double>(256, 0);

    rMax = 0;
    vMax = 0;
    aMax = 0;
    gMax = 0;
}

void HistogramaData::set_rojo(QVector<double> *rojo){
    this->rojo = rojo;
}

void HistogramaData::set_verde(QVector<double> *verde){
    this->verde = verde;
}

void HistogramaData::set_gray(QVector<double> *gray){
    this->gray = gray;
}

void HistogramaData::set_azul(QVector<double> *azul){
    this->azul = azul;
}

QVector<double>* HistogramaData::get_rojo(){
    return this->rojo;
}

QVector<double>* HistogramaData::get_verde(){
    return this->verde;
}

QVector<double>* HistogramaData::get_gray(){
    return this->gray;
}

QVector<double>* HistogramaData::get_azul(){
    return this->azul;
}

double HistogramaData::get_rMax(){
    return rMax;
}

double HistogramaData::get_vMax(){
    return vMax;
}

double HistogramaData::get_aMax(){
    return aMax;
}

void HistogramaData::actualizarValor(COLOR c, int indice){
    QVector<double> *vectorSeleccionado = NULL;
    double *maxSeleccionado;
    switch (c) {
    case ROJO:
        vectorSeleccionado = rojo;
        maxSeleccionado = &rMax;
        break;
    case VERDE:
        vectorSeleccionado = verde;
        maxSeleccionado = &vMax;
        break;
    case AZUL:
        vectorSeleccionado = azul;
        maxSeleccionado = &aMax;
        break;
    case GRAY:
        vectorSeleccionado = gray;
        maxSeleccionado = &gMax;
    default:
        break;
    }
    // Obtener el valor actual
    int vColor = vectorSeleccionado->at(indice);
    vColor += 1;
    vectorSeleccionado->replace(indice, vColor);

    if(vColor > *maxSeleccionado){
        *maxSeleccionado = vColor;
    }    
}

double HistogramaData::get_max_range(){
    double maxRange = 0;
    if(rMax > maxRange){
        maxRange = rMax;
    }
    if(vMax > maxRange){
        maxRange = vMax;
    }
    if(aMax > maxRange){
        maxRange = aMax;
    }

    return maxRange;
}
