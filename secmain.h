#ifndef SECMAIN_H
#define SECMAIN_H

#include <QDialog>

namespace Ui {
class secmain;
}

class secmain : public QDialog
{
    Q_OBJECT

public:
    explicit secmain(QWidget *parent = 0);
    ~secmain();

private:
    Ui::secmain *ui;
};

#endif // SECMAIN_H
