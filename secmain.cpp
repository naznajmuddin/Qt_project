#include "secmain.h"
#include "ui_secmain.h"

secmain::secmain(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secmain)
{
    ui->setupUi(this);
}

secmain::~secmain()
{
    delete ui;
}
