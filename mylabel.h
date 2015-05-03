#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include <QStatusBar>
#include <QPixmap>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = 0);
    ~MyLabel();

    void setStatusBar(QStatusBar *sb);
    void grayscale();

protected:
    void mouseMoveEvent(QMouseEvent * ev);

private:
    QStatusBar *statusBar;


signals:

public slots:
};

#endif // MYLABEL_H
