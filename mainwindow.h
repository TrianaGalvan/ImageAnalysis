#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMdiArea>
#include <dlgimage.h>
#include "mylabel.h"
#include "histdialog.h"
#include "convolution.h"
#include "mascara.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    MyLabel *activeImage();

private slots:
    void open();
    void save_as();
    void grayscale();
    void histograma();
    void escalarImagen(int xmin,int xmax);
    void convolucion();
    void aplicarConvolucion(Mascara* mask);

private:
    Ui::MainWindow *ui;
    QMdiArea mdiArea;
    HistDialog* h;
    Convolution *c;

};

#endif // MAINWINDOW_H
