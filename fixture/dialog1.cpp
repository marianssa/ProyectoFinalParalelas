#include "dialog1.h"
#include "ui_dialog1.h"
#include "QFileSystemModel"
#include "QDir"


Dialog1::Dialog1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog1)
{
    ui->setupUi(this);

    //Creando y populando el modelo

    model = new QDirModel(this);
    model->setReadOnly(false);
    model->setSorting(QDir::DirsFirst |
                          QDir::IgnoreCase |
                          QDir::Name);
    ui->treeView->setModel(model);
    QModelIndex index = model->index("/home/");
    ui->treeView->expand(index);
    ui->treeView->scrollTo(index);
    ui->treeView->setCurrentIndex(index);
    ui->treeView->resizeColumnToContents(0);
}

Dialog1::~Dialog1()
{

    delete ui;
}



void Dialog1::on_treeView_activated(const QModelIndex &)
{
    QModelIndex index = ui->treeView->currentIndex();
        if(!index.isValid()) return;

        QString name  = QInputDialog::getText(this, "Name", "Enter a name");

        if(name.isEmpty()) return;


}
