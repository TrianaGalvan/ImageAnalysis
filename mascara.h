#ifndef MASCARA_H
#define MASCARA_H
#include "armadillo"

class Mascara
{
public:
    Mascara();
    Mascara(int dimx, int dimy);
    int obtenerXFinal(int coorX);
    int obtenerXInicial(int coorX);
    int obtenerYInicial(int coorY);
    int obtenerYFinal(int coorY);
    void setValorCelda(int xcor, int ycor, int valor);
    void inversaMascara();
    void setCoordenadasCentro(int xcor,int ycor);
    int getValorMascara(int difx,int dify);

    ~Mascara();

private:
    arma::mat mascara;
    int xcentro;
    int ycentro;
};

#endif // MASCARA_H
