#ifndef HISTDIALOG_H
#define HISTDIALOG_H

#include <QDialog>
#include "histogramadata.h"

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

private:
    Ui::HistDialog *ui;
};

#endif // HISTDIALOG_H
