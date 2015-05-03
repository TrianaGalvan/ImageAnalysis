#include "mylabel.h"
#include <QMouseEvent>
#include <QImage>
#include <QPixmap>

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








