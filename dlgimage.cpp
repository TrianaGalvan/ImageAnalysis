#include "dlgimage.h"
#include "ui_dlgimage.h"

dlgImage::dlgImage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlgImage)
{
    ui->setupUi(this);
    fileName="";
}

dlgImage::~dlgImage()
{
    delete ui;
}


void dlgImage::setFileName(QString file) {
    QPixmap pix;

    pix.load(file);
    ui->label->setPixmap(pix);

    fileName=file;
}

QString dlgImage::getFileName() {
    return fileName;
}

void dlgImage::setStatusBar(QStatusBar *sb) {
    ui->label->setStatusBar(sb);
}

MyLabel *dlgImage::getImage() {
    return ui->label;
}







