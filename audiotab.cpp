#include "audiotab.h"
#include "ui_audiotab.h"

AudioTab::AudioTab(QWidget *parent) :
    QWidget(parent),
    audioTabUi(new Ui::AudioTab)
{
    audioTabUi->setupUi(this);
    
}

AudioTab::~AudioTab()
{
    delete audioTabUi;
}
