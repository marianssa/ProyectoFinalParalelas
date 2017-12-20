#include "ventanaerror.h"
#include "ui_ventanaerror.h"

ventanaerror::ventanaerror(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ventanaerror)
{
    ui->setupUi(this);
}

ventanaerror::~ventanaerror()
{
    delete ui;
}
