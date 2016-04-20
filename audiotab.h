#ifndef AUDIOTAB_H
#define AUDIOTAB_H

#include <QWidget>

namespace Ui {
class AudioTab;
}

class AudioTab : public QWidget
{
    Q_OBJECT

public:
    explicit AudioTab(QWidget *parent = 0);
    ~AudioTab();

//private slots:
//    void on_thunderOnOffButton_toggled(bool checked);
    
//    void on_windOnOffButton_toggled(bool checked);
    
//    void on_rainOnOffButton_toggled(bool checked);
    
private:
    Ui::AudioTab *audioTabUi;
};

#endif // AUDIOTAB_H
