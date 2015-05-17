#ifndef HISTDIALOG_H
#define HISTDIALOG_H

#include <QDialog>
#include "histogramadata.h"
#include "qdialog.h"
#include <QSlider>
#include <QGroupBox>

namespace Ui {
class HistDialog;
}

class HistDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HistDialog(QWidget *parent = 0);
    ~HistDialog();

    void set_histogramaData(HistogramaData* hData);
    void set_histogramaDataGris(HistogramaData* hData);
    void set_checkboxes();

    //void modificar(hi);

private slots:
    void on_chk_red_stateChanged(int arg1);

    void on_checkBox_2_stateChanged(int arg1);

    void on_checkBox_3_stateChanged(int arg1);

    void on_checkBox_4_stateChanged(int arg1);

    void on_slide_xmin_sliderMoved(int action);

    void on_slide_xmax_sliderMoved(int position);

    void click_escalar();

signals:
    void senal_clickEscalar(int xmin,int xmax);
private:
    Ui::HistDialog *ui;    


};

#endif // HISTDIALOG_H
