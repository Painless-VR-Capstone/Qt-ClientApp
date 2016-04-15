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

private:
    Ui::AudioTab *ui;
};

#endif // AUDIOTAB_H
