#include "switch.h"
#include "ui_switch.h"

Switch::Switch(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Switch)
{
    ui->setupUi(this);
}

Switch::~Switch()
{
    delete ui;
}
