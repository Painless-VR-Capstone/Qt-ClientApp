#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    void writeToFile(QFile *file);

    ~MainWindow();

private slots:
    void on_saveButton_clicked();

    void on_blueSlider_sliderMoved(int position);

    void on_greenSlider_sliderMoved(int position);

    void on_redSlider_sliderMoved(int position);

    void on_saveAsButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
