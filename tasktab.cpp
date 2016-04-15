#include "tasktab.h"
#include "ui_tasktab.h"

TaskTab::TaskTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TaskTab)
{
    ui->setupUi(this);
}

TaskTab::~TaskTab()
{
    delete ui;
}
