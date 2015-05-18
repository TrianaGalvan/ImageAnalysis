#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include <QStatusBar>
#include <QPixmap>
#include "histogramadata.h"
#include "mascara.h"

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = 0);
    ~MyLabel();

    void setStatusBar(QStatusBar *sb);
    void grayscale();
    HistogramaData* calcularHistograma();
    HistogramaData* calcularHistogramaGris();
    void escalamientoHistograma(int,int);
    void aplicarMascara(Mascara* mask);
protected:
    void mouseMoveEvent(QMouseEvent * ev);

private:
    QStatusBar *statusBar;


signals:

public slots:
};

#endif // MYLABEL_H
