#ifndef VENTANAOK_H
#define VENTANAOK_H

#include <QDialog>

namespace Ui {
class ventanaok;
}

class ventanaok : public QDialog
{
    Q_OBJECT

public:
    explicit ventanaok(QWidget *parent = 0);
    ~ventanaok();

private:
    Ui::ventanaok *ui;
};

#endif // VENTANAOK_H
