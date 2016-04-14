#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QColor>
#include <QJsonObject>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

private slots:
    void on_saveButton_clicked();

    void on_blueSlider_sliderMoved(int position);

    void on_greenSlider_sliderMoved(int position);

    void on_redSlider_sliderMoved(int position);

    void on_saveAsButton_clicked();

    void on_logJSONButton_clicked();

private:
    Ui::MainWindow *ui;

    void writeToFile(QFile *file);

    void setPreviewColor();

    QColor getColorFromSliders();

    QJsonObject getJSONObject();
};

#endif // MAINWINDOW_H
