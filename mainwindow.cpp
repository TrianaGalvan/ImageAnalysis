#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QErrorMessage>
#include "dlgimage.h"
#include <QWidget>
#include <QMdiSubWindow>
#include "histdialog.h"
#include "histogramadata.h"
#include "convolution.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionOpen,SIGNAL(triggered()),this,SLOT(open()));
    connect(ui->actionSave_As,SIGNAL(triggered()),this,SLOT(save_as()));
    connect(ui->actionGrayscale,SIGNAL(triggered()),this,SLOT(grayscale()));
    connect(ui->actionHistograma, SIGNAL(triggered()), this, SLOT(histograma()));
    connect(ui->actionConvolucion, SIGNAL(triggered()), this, SLOT(convolucion()));
    h = new HistDialog(this);
    connect(h,&HistDialog::senal_clickEscalar,this,&MainWindow::escalarImagen);
    c = new Convolution(this);
    connect(c,&Convolution::signal_convolucion,this,&MainWindow::aplicarConvolucion);

    setCentralWidget(&mdiArea);

    showMaximized();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::open() {
    //QPixmap pix;
    QString fileName;

    fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), "/", tr("Image Files (*.png *.jpg *.bmp)"));

    //pix.load(fileName);
    //ui->label->setPixmap(pix);

    ui->statusBar->showMessage(fileName);

    dlgImage *w;
    w=new dlgImage(&mdiArea);
    w->setFileName(fileName);
    w->setStatusBar(ui->statusBar);

    mdiArea.addSubWindow(w);
    w->show();
}

void MainWindow::save_as() {
    QString fileName;

    fileName = QFileDialog::getSaveFileName(this, tr("Save Image"), "/", tr("Image Files (*.png *.jpg *.bmp)"));

    ui->statusBar->showMessage(fileName);
    //ui->label->pixmap()->save(fileName);
}

MyLabel *MainWindow::activeImage() {
    QMdiSubWindow *s;
    s=mdiArea.activeSubWindow();
    if (s!=NULL) {
        const QWidget *w=s->widget();
        dlgImage *i=(dlgImage*)w;
        ui->statusBar->showMessage("Image "+i->getFileName()+" selected..");
        return i->getImage();
    }
    else
        ui->statusBar->showMessage("No Image selected...");
    return NULL;
}

void MainWindow::grayscale() {
    MyLabel *image=activeImage();

    if (image!=NULL) {
        image->grayscale();
    }
}

void MainWindow::histograma(){

    MyLabel *image = activeImage();

    if(image != NULL){
        HistogramaData *hData = image->calcularHistograma();
        HistogramaData *hDataG = image->calcularHistogramaGris();

        h->set_histogramaData(hData);
        h->set_histogramaDataGris(hDataG);
        h->set_checkboxes();
        h->show();
    }
}

void MainWindow::escalarImagen(int xmin,int xmax){
    MyLabel* image = activeImage();

    if(xmin > xmax){
            QErrorMessage *error = new QErrorMessage(this);
            error->showMessage("Valores no válidos","ERROR");
    }else{
        if(image != NULL){
            image->escalamientoHistograma(xmin,xmax);
            this->histograma();
        }
    }
}

void MainWindow::convolucion(){
    MyLabel *image = activeImage();
    c = new Convolution(this);

        c->show();

}

void MainWindow::aplicarConvolucion(Mascara* mask){
        MyLabel* image = activeImage();

        //aplicar mascara a la imagen
        image->aplicarMascara(mask);

}
