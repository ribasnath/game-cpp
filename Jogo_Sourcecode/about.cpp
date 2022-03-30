#include "about.h"
#include "ui_about.h"

About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
    this->setWindowTitle("About");

    QPixmap pix(":/src/imagem.png");
    int w = ui->img->width();
    int h = ui->img->height();
    ui->img->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

About::~About()
{
    delete ui;
}
