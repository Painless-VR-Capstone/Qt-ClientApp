#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QJsonDocument>
#include <QDataStream>
#include <QIODevice>
#include <QFileDialog>
#include <QMessageBox>
#include <QPalette>
#include <QDebug>

const QString FILENAME("preset.json");

/*
 * Sets up ui, sets
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->redSlider->setValue(175);
    ui->greenSlider->setValue(220);
    ui->blueSlider->setValue(136);
    ui->redLabel->setText("175");
    ui->greenLabel->setText("220");
    ui->blueLabel->setText("136");
    ui->task1Button->setChecked(true);
    setPreviewColor();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_saveButton_clicked()
{
    QString fileName(QDir::currentPath());
    fileName.append("/");
    fileName.append(FILENAME);
    QFile file(fileName);
    if (file.exists()) {
        QMessageBox messageBox;
        QString message("The file ");
        message.append(fileName);
        message.append(" already exists.");
        messageBox.setText(message);
        messageBox.setInformativeText("Do you want to overwrite it?");
        messageBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        messageBox.setDefaultButton(QMessageBox::Yes);
        int result = messageBox.exec();
        switch(result) {
            case QMessageBox::Yes:
                writeToFile(&file);
                break;
            case QMessageBox::No:
                break;
        }
    } else {
        writeToFile(&file);
    }
}

QJsonObject MainWindow::getJSONObject()
{
    QJsonObject json;
    json.insert("color", getColorFromSliders().name(QColor::HexArgb));
    QString taskValue;
    if (ui->task1Button->isChecked()) {
        taskValue = "task1";
    } else if (ui->task2Button->isChecked()) {
        taskValue = "task2";
    } else if (ui->task3Button->isChecked()) {
        taskValue = "task3";
    } else {
        taskValue = "task4";
    }
    json.insert("task", taskValue);
    return json;
}

void MainWindow::writeToFile(QFile *file)
{
    QJsonDocument doc(getJSONObject());
    file->open(QIODevice::WriteOnly);
    file->write(doc.toJson(QJsonDocument::Indented));
    QMessageBox box;
    QString message("Saved preset to ");
    message.append(file->fileName());
    box.setText(message);
    box.setStandardButtons(QMessageBox::Ok);
    box.setDefaultButton(QMessageBox::Ok);
    box.exec();
}

void MainWindow::on_blueSlider_sliderMoved(int position)
{
    ui->blueLabel->setText(QString::number(position));
    setPreviewColor();
}

void MainWindow::on_greenSlider_sliderMoved(int position)
{
    ui->greenLabel->setText(QString::number(position));
    setPreviewColor();
}

void MainWindow::on_redSlider_sliderMoved(int position)
{
    ui->redLabel->setText(QString::number(position));
    setPreviewColor();
}
void MainWindow::setPreviewColor()
{
    QPalette palette = ui->colorPreviewFrame->palette();
    palette.setColor(QPalette::Background, getColorFromSliders());
    ui->colorPreviewFrame->setAutoFillBackground(true);
    ui->colorPreviewFrame->setPalette(palette);
}

/*
 * Returns a QColor with the RGB values on the sliders and an alpha of 255
 */
QColor MainWindow::getColorFromSliders()
{
    return QColor(ui->redSlider->value(), ui->greenSlider->value(), ui->blueSlider->value());
}

void MainWindow::on_saveAsButton_clicked()
{
    QFileDialog dialog(this);
    dialog.setViewMode(QFileDialog::Detail);
    dialog.setAcceptMode(QFileDialog::AcceptSave);
    dialog.setFileMode(QFileDialog::AnyFile);
    dialog.setLabelText(QFileDialog::FileName, FILENAME);
    QStringList fileNames;
    if (dialog.exec()) {
        fileNames = dialog.selectedFiles();
        if (fileNames.size() > 0) {
            QFile file(fileNames.at(0));
            writeToFile(&file);
        }
    }
}

void MainWindow::on_logJSONButton_clicked()
{
    QJsonObject json = getJSONObject();
    qDebug() << "{";
    foreach (QString key, json.keys())
    {
        qDebug() << "   " << key << ":" << json.value(key).toString() << ",";
    }
    qDebug() << "}";
}
