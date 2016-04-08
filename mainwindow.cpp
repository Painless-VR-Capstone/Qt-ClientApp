#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QJsonObject>
#include <QFile>
#include <QJsonDocument>
#include <QDataStream>
#include <QIODevice>
#include <QFileDialog>
#include <QMessageBox>

const QString FILENAME("preset.json");

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

void MainWindow::writeToFile(QFile *file)
{
    QJsonObject json;
    json.insert("red", ui->redSlider->value());
    json.insert("green", ui->greenSlider->value());
    json.insert("blue", ui->blueSlider->value());
    QJsonDocument doc(json);
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
}

void MainWindow::on_greenSlider_sliderMoved(int position)
{
    ui->greenLabel->setText(QString::number(position));
}

void MainWindow::on_redSlider_sliderMoved(int position)
{
    ui->redLabel->setText(QString::number(position));
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
