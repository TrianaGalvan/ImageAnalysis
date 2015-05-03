#ifndef DLGIMAGE_H
#define DLGIMAGE_H

#include <QDialog>
#include "mylabel.h"
#include <QStatusBar>

namespace Ui {
class dlgImage;
}

class dlgImage : public QDialog
{
    Q_OBJECT

public:
    explicit dlgImage(QWidget *parent = 0);
    ~dlgImage();

    void setFileName(QString file);
    void setStatusBar(QStatusBar *sb);
    QString getFileName();
    MyLabel *getImage();

private:
    Ui::dlgImage *ui;
    QString fileName;

};

#endif // DLGIMAGE_H
