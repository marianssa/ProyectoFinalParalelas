#ifndef VENTANAERROR_H
#define VENTANAERROR_H

#include <QDialog>

namespace Ui {
class ventanaerror;
}

class ventanaerror : public QDialog
{
    Q_OBJECT

public:
    explicit ventanaerror(QWidget *parent = 0);
    ~ventanaerror();

private:
    Ui::ventanaerror *ui;
};

#endif // VENTANAERROR_H
