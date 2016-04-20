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
#include <QWidget>

const QString FILENAME("preset.json");

/*
 * Sets up ui, sets
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    mainWindowUi(new Ui::MainWindow)
{
    mainWindowUi->setupUi(this);
    taskTab = new TaskTab;
    mainWindowUi->tabWidget->removeTab(0);
    mainWindowUi->tabWidget->removeTab(0);
    mainWindowUi->tabWidget->addTab(taskTab, "Task");
//    tabWidget.addTab(&audioTab, "Audio");
}

MainWindow::~MainWindow()
{
    delete mainWindowUi;
    delete taskTab;
}

//void MainWindow::on_saveButton_clicked()
//{
//    QString fileName(QDir::currentPath());
//    fileName.append("/");
//    fileName.append(FILENAME);
//    QFile file(fileName);
//    if (file.exists()) {
//        QMessageBox messageBox;
//        QString message("The file ");
//        message.append(fileName);
//        message.append(" already exists.");
//        messageBox.setText(message);
//        messageBox.setInformativeText("Do you want to overwrite it?");
//        messageBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
//        messageBox.setDefaultButton(QMessageBox::Yes);
//        int result = messageBox.exec();
//        switch(result) {
//            case QMessageBox::Yes:
//                writeToFile(&file);
//                break;
//            case QMessageBox::No:
//                break;
//        }
//    } else {
//        writeToFile(&file);
//    }
//}

QJsonObject MainWindow::getJSONObject()
{
    QJsonObject json;
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

//void MainWindow::on_saveAsButton_clicked()
//{
//    QFileDialog dialog(this);
//    dialog.setViewMode(QFileDialog::Detail);
//    dialog.setAcceptMode(QFileDialog::AcceptSave);
//    dialog.setFileMode(QFileDialog::AnyFile);
//    dialog.setLabelText(QFileDialog::FileName, FILENAME);
//    QStringList fileNames;
//    if (dialog.exec()) {
//        fileNames = dialog.selectedFiles();
//        if (fileNames.size() > 0) {
//            QFile file(fileNames.at(0));
//            writeToFile(&file);
//        }
//    }
//}

//void MainWindow::on_logJSONButton_clicked()
//{
//    QJsonObject json = getJSONObject();
//    qDebug() << "{";
//    foreach (QString key, json.keys())
//    {
//        qDebug() << "   " << key << ":" << json.value(key).toString() << ",";
//    }
//    qDebug() << "}";
//}
