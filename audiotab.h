#ifndef AUDIOTAB_H
#define AUDIOTAB_H

#include <QWidget>
#include <QString>
#include <QList>
#include <QLabel>
#include <QPushButton>

namespace Ui {
class AudioTab;
}

class AudioTab : public QWidget
{
    Q_OBJECT

public:
    explicit AudioTab(QWidget *parent = 0);
    ~AudioTab();
    void addValuesToJson(QJsonObject *json);
    void setValuesFromJson(QJsonObject json);

    
private slots:
    void on_musicSelectFIleButton_clicked();

    void on_fireSelectFIleButton_clicked();

    void on_hitSelectFIleButton_clicked();

    void on_scoreSelectFIleButton_clicked();

    void on_winSelectFIleButton_clicked();

    void on_loseSelectFIleButton_clicked();

    void on_ambient1SelectFIleButton_clicked();

    void on_ambient2SelectFIleButton_clicked();

    void on_ambient3SelectFIleButton_clicked();

    void on_ambient1ClearButton_clicked();

    void on_ambient2ClearButton_clicked();

    void on_ambient3ClearButton_clicked();

private:
    Ui::AudioTab *audioTabUi;
    QString greenBackground;
    QString whiteBackground;
    QString buttonBackground;
    QString musicFilePath;
    QString fireFilePath;
    QString hitFilePath;
    QString scoreFilePath;
    QString winFilePath;
    QString loseFilePath;
    QString ambient1FilePath;
    QString ambient2FilePath;
    QString ambient3FilePath;

    void readInStyleSheets();
    int findMaxLabelWidth(QList<QLabel *> labels);
    void batchSetLabelMinimumWidth(QList<QLabel *> labels, int minWidth);
    QList<QLabel *> getLabels();
    QString getFilePathFromFileFinder(QPushButton *button);
};

#endif // AUDIOTAB_H
