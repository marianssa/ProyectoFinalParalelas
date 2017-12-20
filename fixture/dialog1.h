#ifndef DIALOG1_H
#define DIALOG1_H
#include <QDialog>
#include <QDirModel>
#include <QTreeView>
#include <QInputDialog>
#include <dialog1.h>

namespace Ui {
class Dialog1;
}

class Dialog1 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog1(QWidget *parent = 0);
    ~Dialog1();

private slots:


    void on_treeView_activated(const QModelIndex &index);

private:
    Ui::Dialog1 *ui;
    QDirModel *model;
};

#endif // DIALOG1_H
