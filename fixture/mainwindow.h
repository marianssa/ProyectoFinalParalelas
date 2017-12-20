#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QDialog>
#include <QDirModel>
#include <QTreeView>
#include <QInputDialog>
#include <QMainWindow>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btnsubir_clicked();

    void on_treeView_2_activated(const QModelIndex &index);

    void on_treeView_activated(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
     QDirModel *model;
     QDirModel *model2;
    // Dialog1 ventana;
};

#endif // MAINWINDOW_H
