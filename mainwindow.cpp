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
#include <QProcess>

static const QString FILENAME = "preset.preset";
static const QString NAME_FILTER_PRESET = "Preset files (*.preset)";
static const QString NAME_FILTER_ANY = "Any files (*)";

/*
 * Sets up ui, sets
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    mainWindowUi(new Ui::MainWindow)
{
    mainWindowUi->setupUi(this);
    taskTab = new TaskTab;
    audioTab = new AudioTab;
    visualTab = new VisualTab;
    mainWindowUi->tabWidget->removeTab(0);
    mainWindowUi->tabWidget->removeTab(0);
    mainWindowUi->tabWidget->addTab(taskTab, "Task");
    mainWindowUi->tabWidget->addTab(audioTab, "Audio");
    mainWindowUi->tabWidget->addTab(visualTab, "Visual");
    currentTab = Task;
}

MainWindow::~MainWindow()
{
    delete mainWindowUi;
    delete taskTab;
}

QJsonObject MainWindow::getJSONObject()
{
    QJsonObject json;
    taskTab->addValuesToJson(&json);
    audioTab->addValuesToJson(&json);
    visualTab->addValuesToJson(&json);
    return json;
}

void MainWindow::writeToFile(QFile *file, bool withMessage = true)
{
    QJsonDocument doc(getJSONObject());
    file->open(QIODevice::WriteOnly);
    file->write(doc.toJson(QJsonDocument::Indented));
    if (withMessage)
    {
        QMessageBox box;
        QString message("Saved preset to ");
        message.append(file->fileName());
        box.setText(message);
        box.setStandardButtons(QMessageBox::Ok);
        box.setDefaultButton(QMessageBox::Ok);
        box.exec();
    }
}

void MainWindow::on_actionSave_triggered()
{

}

void MainWindow::on_actionSave_Preset_As_Stand_Alone_triggered()
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

void MainWindow::on_actionOpen_Preset_triggered()
{
    QFileDialog dialog(this);
    dialog.setViewMode(QFileDialog::Detail);
    dialog.setAcceptMode(QFileDialog::AcceptOpen);
    dialog.setFileMode(QFileDialog::AnyFile);
    QStringList filters;
    filters << NAME_FILTER_PRESET
            << NAME_FILTER_ANY;
    dialog.setNameFilters(filters);
    QString file;
    if (dialog.exec())
    {
        QFile file(dialog.selectedFiles().at(0));
        if (file.exists())
        {
            QJsonDocument doc = QJsonDocument::fromBinaryData(file.readAll());
            if (doc.isNull())
            {
                QMessageBox box;
                QString boxText;
                boxText.append("It appears that ")
                       .append(QFileInfo(file).fileName())
                       .append("is not a valid preset file");
                box.setText("It appears that file is not a valid preset");
                box.setStandardButtons(QMessageBox::Ok);
            }
            else
            {
                QJsonObject json = doc.object();
                taskTab->setValuesFromJson(json);
                audioTab->setValuesFromJson(json);
                visualTab->setValuesFromJson(json);
            }
        }

    }
}

void MainWindow::on_actionRun_on_Monitor_triggered()
{

}

void MainWindow::on_actionRun_on_HMD_triggered()
{

}

void MainWindow::on_actionNew_Preset_triggered()
{

}
