#include "convolution.h"
#include "ui_convolution.h"
#include <QErrorMessage>

Convolution::Convolution(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::convolution)
{
    ui->setupUi(this);

}

Convolution::~Convolution()
{
    delete ui;
}

void Convolution::on_combo_ancho_currentIndexChanged(int index)
{
    ui->tbl_convolucion->setRowCount(index+1);
    ui->tbl_convolucion->rowHeight(5);

}

void Convolution::on_combo_alto_currentIndexChanged(int index)
{
    QStringList *list = new QStringList();
    ui->tbl_convolucion->setColumnCount(index+1);

    for (int var = -(index)/2; var <= 0; var++) {
            QString s = QString::number(var);
            list->append(s);
     }

    if(index % 2 == 0){
        for (int var = 1; var <= ((index)/2); var++) {
                int num = var;
                QString s = QString::number(num);
                list->append(s);
         }
    }else{
        for (int var = 1; var <= (index)/2 ; var++) {
                int num = var;
                QString s = QString::number(num);
                list->append(s);
         }
    }

    ui->tbl_convolucion->setHorizontalHeaderLabels(*list);
    ui->tbl_convolucion->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

}

void Convolution::on_btn_convolucion_clicked()
{
    QErrorMessage message;
    int rows = ui->tbl_convolucion->rowCount();
    int cols = ui->tbl_convolucion->columnCount();

    int **arrtable = crearArregloBidimensional(rows,cols);

    //crear el arreglo de la tabla
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < cols ; c++){
            QTableWidgetItem * data = ui->tbl_convolucion->item(r,c);
            if(data != NULL){
                QString item = data->text();
                int itemInt = item.toInt();
                arrtable[r][c] = itemInt;
            }else{
                message.showMessage("No hay valores");
                break;
            }
        }
    }

    //obtener el centro
    QString fila = ui->combo_fila_centro->currentText();
    int filaInt = fila.toInt()-1;

    //obtener el centro
    QString col = ui->combo_columna_centro->currentText();
    int ColInt = col.toInt()-1;
    emit signal_convolucion(arrtable,ColInt,filaInt);
}

int ** Convolution::crearArregloBidimensional(int cols,int rows){
    int **tableArray = (int**) malloc(sizeof(int*)*rows);
    int i = 0;
    //pedir memoria para el arreglo bidimensional
    for(i = 0; i < rows; i++){
        tableArray[i] = (int*)malloc(sizeof(int)*cols);
    }
    return tableArray;
}

void Convolution::on_combo_columna_centro_activated(const QString &arg1)
{
    QString fila = ui->combo_fila_centro->currentText();
    int filaInt = fila.toInt()-1;
    int colInt = arg1.toInt()-1;

    QTableWidgetItem * data = ui->tbl_convolucion->item(filaInt,colInt);
    QString item = data->text();
    //int itemInt = item.toInt();

    ui->tbl_convolucion->setItem(filaInt,colInt, new QTableWidgetItem);
    ui->tbl_convolucion->item(filaInt,colInt)->setBackground(Qt::red);

    QTableWidgetItem *twi ;
    twi= ui->tbl_convolucion->item(filaInt, colInt) ;
    twi->setText(item) ;

}

void Convolution::on_combo_fila_centro_activated(const QString &arg1)
{
//    QString fila = ui->combo_fila_centro->currentText();
//    int filaInt = fila.toInt()-1;
}
