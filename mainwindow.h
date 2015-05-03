#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMdiArea>
#include <dlgimage.h>
#include "mylabel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void open();
    void save_as();
    void grayscale();

    MyLabel *activeImage();

private:
    Ui::MainWindow *ui;
    QMdiArea mdiArea;
};

#endif // MAINWINDOW_H
