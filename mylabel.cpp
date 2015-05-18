#include "mylabel.h"
#include <QMouseEvent>
#include <QImage>
#include <QPixmap>
#include "histogramadata.h"

MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{
    statusBar=NULL;
}

MyLabel::~MyLabel()
{

}

void MyLabel::setStatusBar(QStatusBar *sb) {
    statusBar=sb;
}

void MyLabel::mouseMoveEvent(QMouseEvent * ev) {
    int x=ev->x();
    int y=ev->y();

    QRgb pixel=pixmap()->toImage().pixel(x,y);

    int r=qRed(pixel);
    int g=qGreen(pixel);
    int b=qBlue(pixel);
    QString text;

    text.sprintf("[X=%d, Y=%d] R=%d G=%d B=%d",x,y,r,g,b);

    statusBar->showMessage(text);
}


void MyLabel::grayscale() {
    //aqui va la funcionalidad
    int x,y;

    int Width=pixmap()->width();
    int Height=pixmap()->height();
    QImage img(pixmap()->toImage());

    for (y=0;y<Height;y++) {
       for (x=0;x<Width;x++) {
           QRgb pixel=img.pixel(x,y);

           int r=qRed(pixel);
           int g=qGreen(pixel);
           int b=qBlue(pixel);

           int gray=(int)(0.30*(float)r+0.59*(float)g+0.11*(float)b);

           img.setPixel(x,y,qRgb(gray,gray,gray));
       }
    }

    setPixmap(QPixmap::fromImage(img));
}

HistogramaData* MyLabel::calcularHistograma(){
    int x,y;

    int Width=pixmap()->width();
    int Height=pixmap()->height();
    QImage img(pixmap()->toImage());
    HistogramaData *hdata = new HistogramaData();

    for (y=0;y<Height;y++) {
       for (x=0;x<Width;x++) {
           QRgb pixel=img.pixel(x,y);

           int r=qRed(pixel);
           int g=qGreen(pixel);
           int b=qBlue(pixel);

           hdata->actualizarValor(HistogramaData::ROJO, r);
           hdata->actualizarValor(HistogramaData::VERDE, g);
           hdata->actualizarValor(HistogramaData::AZUL, b);

       }
    }

    return hdata;
}

HistogramaData* MyLabel::calcularHistogramaGris(){
    int x,y;

    int Width=pixmap()->width();
    int Height=pixmap()->height();
    QImage img(pixmap()->toImage());
    HistogramaData *hdata = new HistogramaData();

    for (y=0;y<Height;y++) {
       for (x=0;x<Width;x++) {
           QRgb pixel=img.pixel(x,y);

           int r=qRed(pixel);
           int g=qGreen(pixel);
           int b=qBlue(pixel);

           int gray=(int)(0.30*(float)r+0.59*(float)g+0.11*(float)b);

           hdata->actualizarValor(HistogramaData::GRAY, gray);
       }
    }

    return hdata;
}

void MyLabel::escalamientoHistograma(int min, int max){
    int x,y;

    int Width=pixmap()->width();
    int Height=pixmap()->height();
    QImage img(pixmap()->toImage());

    for (y=0;y<Height;y++) {
       for (x=0;x<Width;x++) {
           QRgb pixel=img.pixel(x,y);

           int r=qRed(pixel);
           int g=qGreen(pixel);
           int b=qBlue(pixel);


           if( r >= min && r <= max ){
                r = (255*(r - min))/(max - min);
           }
           if( g >= min && g <= max ){
                g = (255*(g - min))/(max - min);
           }if( b >= min && b <= max ){
                b = (255*(b - min))/(max - min);
           }
           img.setPixel(x,y,qRgb(r,g,b));
       }
    }

    setPixmap(QPixmap::fromImage(img));
}

void MyLabel::aplicarMascara(Mascara* mask){
    int x,y;
    int m,n;
    int xc = 0,yc = 0;
    int xini = 0, xfin = 0;
    int yini = 0, yfin = 0;
    int valorAcumuladoR = 0, valorAcumuadoA = 0, valorAcumuladoV = 0;

    //recorrer la imagen
    int Width=pixmap()->width();
    int Height=pixmap()->height();
    QImage img(pixmap()->toImage());
    int valAcumulado = 0;

    for(y = 0; y< Height;y++){
        for(x = 0; x < Width;x++){
            valAcumulado = 0;
            xini = mask->obtenerXInicial(x);
            xfin = mask->obtenerXFinal(x);
            yini = mask->obtenerYInicial(y);
            yfin = mask->obtenerYFinal(y);

            for(xc = xini ; xc <= xfin; xc++){
                //verificar si esta dentro de los limites de la imagen
                if(xc < 0 || xc > Width-1){
                    continue;
                }
                for(yc = yini ; yc <= yfin; yc++){
                    //verificar si esta dentro de los limites de la imagen
                    if(yc < 0 || yc > Height-1){
                        continue;
                    }

                    QRgb pixel=img.pixel(x,y);

                    int r=qRed(pixel);
                    int g=qGreen(pixel);
                    int b=qBlue(pixel);

                    //obtener el valor de la matriz
                    int valorMask = mask->getValorMascara(x-xc,y-yc);

                    valorAcumuladoR = valorMask*r;
                    valorAcumuladoV = valorMask*g;
                    valorAcumuadoA = valorMask*b;
                }
            }
            img.setPixel(x,y,qRgb(valorAcumuladoR,valorAcumuladoV,valorAcumuadoA));
            valorAcumuadoA = 0;
            valorAcumuladoR = 0;
            valorAcumuladoV = 0;
        }
    }
}
