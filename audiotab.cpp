#include "audiotab.h"
#include "ui_audiotab.h"

AudioTab::AudioTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AudioTab)
{
    ui->setupUi(this);
}

AudioTab::~AudioTab()
{
    delete ui;
}
