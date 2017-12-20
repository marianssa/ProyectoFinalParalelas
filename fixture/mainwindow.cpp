#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileSystemModel"
#include "QDir"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    //Creando y populando el modelo seleccionar el archivo

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


    //Creando y populando el modelo para la seleccion de carperta al guardar

    model2 = new QDirModel(this);
    model2->setReadOnly(false);
    model2->setSorting(QDir::DirsFirst |
                          QDir::IgnoreCase |
                          QDir::Name);
    ui->treeView_2->setModel(model2);
     index = model2->index("/home/");
    ui->treeView_2->expand(index);
    ui->treeView_2->scrollTo(index);
    ui->treeView_2->setCurrentIndex(index);
    ui->treeView_2->resizeColumnToContents(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnsubir_clicked()
{

    //ventana.show();
}

void MainWindow::on_treeView_2_activated(const QModelIndex &)
{
    QModelIndex index2 = ui->treeView_2->currentIndex();
        if(!index2.isValid()) return;

        QString name  = QInputDialog::getText(this, "Name", "Enter a name");

        if(name.isEmpty()) return;

}

void MainWindow::on_treeView_activated(const QModelIndex &)
{
    QModelIndex index = ui->treeView->currentIndex();
        if(!index.isValid()) return;

        QString name  = QInputDialog::getText(this, "Name", "Enter a name");

        if(name.isEmpty()) return;

}
