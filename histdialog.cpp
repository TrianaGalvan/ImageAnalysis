#include "histdialog.h"
#include "ui_histdialog.h"

HistDialog::HistDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HistDialog)
{
    ui->setupUi(this);
}

HistDialog::~HistDialog()
{
    delete ui;
}

void HistDialog::set_histogramaData(HistogramaData* hData){

    QVector<double> x(256);
    for(int i = 0; i< 256 ; i++){
        x.replace(i, i+1);
    }

    // Configurar la grafica
    ui->histograma->addGraph();
    ui->histograma->graph(0)->setData(x, *(hData->get_rojo()));
    ui->histograma->graph(0)->setPen(QPen(Qt::red));

    ui->histograma->addGraph();
    ui->histograma->graph(1)->setData(x, *(hData->get_verde()));
    ui->histograma->graph(1)->setPen(QPen(Qt::green));

    ui->histograma->addGraph();
    ui->histograma->graph(2)->setData(x, *(hData->get_azul()));
    ui->histograma->graph(2)->setPen(QPen(Qt::blue));

    ui->histograma->xAxis->setRange(2, 255);
    ui->histograma->yAxis->setRange(2, hData->get_max_range());
}
