#include "mascara.h"

Mascara::Mascara()
{

}

Mascara::Mascara(int dimx, int dimy)
{
    mascara = arma::mat(dimx,dimy);
}

Mascara::~Mascara()
{

}

void Mascara::setValorCelda(int xcor, int ycor, int valor){
    mascara(xcor,ycor) = valor;
}

int Mascara::obtenerXFinal(int coorX){
    return coorX + (xcentro-(mascara.n_cols-1));
}

int Mascara::obtenerXInicial(int coorX){
    return coorX-xcentro;
}

int Mascara::obtenerYFinal(int coorY){
    return coorY + (ycentro-(mascara.n_rows-1));
}

int Mascara::obtenerYInicial(int coorY){
    return coorY - ycentro;
}

void Mascara::inversaMascara(){
    int determinante = det(mascara);
    if(determinante != 0){
        mascara = mascara.i();
    }
}

void Mascara::setCoordenadasCentro(int xcor, int ycor){
    xcentro = xcor;
    ycentro = ycor;
}

int Mascara::getValorMascara(int difx, int dify){
    int corx = difx+xcentro;
    int cory = dify+ycentro;
    return mascara(corx,cory);
}
