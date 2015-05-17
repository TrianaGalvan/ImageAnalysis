#include "histdialog.h"
#include "ui_histdialog.h"
#include <QErrorMessage>

HistDialog::HistDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HistDialog)
{
    ui->setupUi(this);
    connect(ui->btn_escalar,SIGNAL(clicked()),this,SLOT(click_escalar()));
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

    ui->histograma->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

    // Configurar la grafica
    ui->histograma->addGraph();
    ui->histograma->graph(0)->setData(x, *(hData->get_rojo()));
    ui->histograma->graph(0)->setPen(QPen(Qt::red));
    ui->histograma->graph(0)->setBrush(QBrush(QColor(255, 0, 0, 20))); // first graph will be filled with translucent blue
    ui->histograma->graph(0);
    //modificar(ui->histograma);

    ui->histograma->addGraph();
    ui->histograma->graph(1)->setData(x, *(hData->get_verde()));
    ui->histograma->graph(1)->setPen(QPen(Qt::green));
    ui->histograma->graph(1)->setBrush(QBrush(QColor(0, 255, 0, 20))); // first graph will be filled with translucent blue

    ui->histograma->addGraph();
    ui->histograma->graph(2)->setData(x, *(hData->get_azul()));
    ui->histograma->graph(2)->setPen(QPen(Qt::blue));
    ui->histograma->graph(2)->setBrush(QBrush(QColor(0, 0, 255, 20))); // first graph will be filled with translucent blue
    ui->histograma->graph(2)->setVisible(true);

    ui->histograma->xAxis2->setTickLabels(false);
    ui->histograma->yAxis2->setVisible(true);
    ui->histograma->yAxis2->setTickLabels(false);

    ui->histograma->xAxis->setRange(2, 255);
    ui->histograma->yAxis->setRange(2, hData->get_max_range());

    ui->histograma->graph(0)->rescaleAxes(true);
    // same thing for graph 1, but only enlarge ranges (in case graph 1 is smaller than graph 0):
    ui->histograma->graph(1)->rescaleAxes(true);
    ui->histograma->graph(2)->rescaleAxes(true);
    // Note: we could have also just called customPlot->rescaleAxes(); instead
    // Allow user to drag axis ranges with mouse, zoom with mouse wheel and select graphs by clicking:

}


void HistDialog::on_chk_red_stateChanged(int arg1)
{
    if(arg1 > 0){
        ui->histograma->graph(0)->setVisible(true);
    }
    else{
        ui->histograma->graph(0)->setVisible(false);
    }
    ui->histograma->replot();
}


void HistDialog::on_checkBox_2_stateChanged(int arg1)
{
    if(arg1 > 0){
        ui->histograma->graph(1)->setVisible(true);
    }
    else{
        ui->histograma->graph(1)->setVisible(false);
    }
    ui->histograma->replot();
}

void HistDialog::on_checkBox_3_stateChanged(int arg1)
{
    if(arg1 > 0){
        ui->histograma->graph(2)->setVisible(true);
    }
    else{
        ui->histograma->graph(2)->setVisible(false);
    }
    ui->histograma->replot();
}

void HistDialog::on_checkBox_4_stateChanged(int arg1)
{
    if(arg1 > 0){
        ui->histograma->graph(3)->setVisible(true);
    }
    else{
        ui->histograma->graph(3)->setVisible(false);
    }
    ui->histograma->replot();
}

void HistDialog::set_checkboxes(){
    ui->chk_red->setCheckState(Qt::Checked);
    ui->checkBox_2->setCheckState(Qt::Checked);
    ui->checkBox_3->setCheckState(Qt::Checked);
    ui->checkBox_4->setCheckState(Qt::Checked);
}

void HistDialog::set_histogramaDataGris(HistogramaData* hData){

    QVector<double> x(256);
    for(int i = 0; i< 256 ; i++){
        x.replace(i, i+1);
    }

    // Configurar la grafica
    ui->histograma->addGraph();
    ui->histograma->graph(3)->setData(x, *(hData->get_gray()));
    ui->histograma->graph(3)->setPen(QPen(Qt::gray));
    ui->histograma->graph(3)->setBrush(QBrush(QColor(26,26,26, 20))); // first graph will be filled with translucent blue
    ui->histograma->graph(3)->rescaleAxes(true);

    ui->histograma->replot();

}

void HistDialog::on_slide_xmin_sliderMoved(int action)
{
    ui->lbl_xmin->setText(QString::number(action));
}

void HistDialog::on_slide_xmax_sliderMoved(int position)
{

    ui->lbl_xmax->setText(QString::number(position));
}

void HistDialog::click_escalar(){

    int valxmin = ui->slide_xmin->value();
    int valxmax = ui->slide_xmax->value();

    emit senal_clickEscalar(valxmin,valxmax);
}

