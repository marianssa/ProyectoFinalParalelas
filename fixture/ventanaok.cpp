#include "ventanaok.h"
#include "ui_ventanaok.h"

ventanaok::ventanaok(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ventanaok)
{
    ui->setupUi(this);
}

ventanaok::~ventanaok()
{
    delete ui;
}
