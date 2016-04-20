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

//void AudioTab::on_thunderOnOffButton_toggled(bool checked)
//{
    
//}

//void AudioTab::on_windOnOffButton_toggled(bool checked)
//{
    
//}

//void AudioTab::on_rainOnOffButton_toggled(bool checked)
//{
    
//}
