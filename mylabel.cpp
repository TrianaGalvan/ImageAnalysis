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

void MyLabel::aplicarMascara(int **mask, int rowCentro, int colCentro,int numCols,int numRows){
    int x,y;
    int m,n;
    //recorrer la imagen
    int Width=pixmap()->width();
    int Height=pixmap()->height();
    QImage img(pixmap()->toImage());


    for(y = 0; y< Height;y++){
        for(x = 0; x < Width;x++){
            //recorer la mascara
            for(m = 0 ; m < numRows ; m++){
                for(n = 0; n < numCols;n++){

                }
            }
        }
    }
}
