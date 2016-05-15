#include "audiotab.h"
#include "ui_audiotab.h"
#include "utils.h"
#include <QFileDialog>
#include <QDir>
#include <QDebug>

static const QString NAME_FILTER_AUDIO = "Audio files (*.mp3 *.mp4 *.wpl *.wma *.wav"
                                         "*.m4a *.mp4 *mka *.midi)";
static const QString NAME_FILTER_ANY = "Any files (*)";
static const QString FILE_DIALOG_PATH = "../Resources/SharedSounds";
static const QString KEY_MUSIC_PATH = "musicFilePath";
static const QString KEY_FIRE_PATH = "fireFilePath";
static const QString KEY_HIT_PATH = "hitFilePath";
static const QString KEY_SCORE_PATH = "scoreFilePath";
static const QString KEY_WIN_PATH = "winFilePath";
static const QString KEY_LOSE_PATH = "loseFilePath";
static const QString KEY_AMBIENT1_PATH = "ambient1FilePath";
static const QString KEY_AMBIENT2_PATH = "ambien2FilePath";
static const QString KEY_AMBIENT3_PATH = "ambient3FilePath";
static const QString KEY_MUSIC_VOUME = "musicVolume";
static const QString KEY_AMBIENT_VOLUME = "ambientTracksVolume";
static const QString KEY_SOUND_EFFECTS = "soundEffectsVolume";
static const QString KEY_MUSIC_PITCH = "musicPitch";
static const QString KEY_MUSIC_SPEED = "musicSpeed";
static const QString KEY_FIRE_PITCH = "firePitch";
static const QString KEY_SCORE_PITCH = "scorePitch";
static const QString KEY_HIT_PITCH = "hitPitch";
static const QString KEY_WIN_PITCH = "winPitch";
static const QString KEY_LOSE_PITCH = "losePitch";

AudioTab::AudioTab(QWidget *parent) :
    QWidget(parent),
    audioTabUi(new Ui::AudioTab)
{
    audioTabUi->setupUi(this);
    readInStyleSheets();

    // Set box style sheets
    audioTabUi->ambient1Box->setStyleSheet(whiteBackground);
    audioTabUi->ambient2Box->setStyleSheet(whiteBackground);
    audioTabUi->ambient3Box->setStyleSheet(whiteBackground);
    audioTabUi->ambientBox->setStyleSheet(greenBackground);
    audioTabUi->fireBox->setStyleSheet(whiteBackground);
    audioTabUi->hitBox->setStyleSheet(whiteBackground);
    audioTabUi->loseBox->setStyleSheet(whiteBackground);
    audioTabUi->musicFileBox->setStyleSheet(greenBackground);
    audioTabUi->musicFileInnerBox->setStyleSheet(whiteBackground);
    audioTabUi->musicPitchInnerBox->setStyleSheet(whiteBackground);
    audioTabUi->scoreBox->setStyleSheet(whiteBackground);
    audioTabUi->soundEffectsBox->setStyleSheet(greenBackground);
    audioTabUi->volumeBox->setStyleSheet(greenBackground);
    audioTabUi->volumeInnerBox->setStyleSheet(whiteBackground);
    audioTabUi->winBox->setStyleSheet(whiteBackground);

    // Set button style sheets
    audioTabUi->ambient1SelectFIleButton->setStyleSheet(buttonBackground);
    audioTabUi->ambient1ClearButton->setStyleSheet(buttonBackground);
    audioTabUi->ambient2SelectFIleButton->setStyleSheet(buttonBackground);
    audioTabUi->ambient2ClearButton->setStyleSheet(buttonBackground);
    audioTabUi->ambient3SelectFIleButton->setStyleSheet(buttonBackground);
    audioTabUi->ambient3ClearButton->setStyleSheet(buttonBackground);
    audioTabUi->fireSelectFIleButton->setStyleSheet(buttonBackground);
    audioTabUi->hitSelectFIleButton->setStyleSheet(buttonBackground);
    audioTabUi->loseSelectFIleButton->setStyleSheet(buttonBackground);
    audioTabUi->musicSelectFIleButton->setStyleSheet(buttonBackground);
    audioTabUi->scoreSelectFIleButton->setStyleSheet(buttonBackground);
    audioTabUi->winSelectFIleButton->setStyleSheet(buttonBackground);

    // Set Min Label width in Sound Effects Box to make colums look right
    QList<QLabel *> labels = getLabels();
    int minWidth = findMaxLabelWidth(labels);
    batchSetLabelMinimumWidth(labels, minWidth);


}

QList<QLabel *> AudioTab::getLabels()
{
    QList<QLabel *> result;
    result.append(audioTabUi->fireLabel);
    result.append(audioTabUi->firePitchLabel);
    result.append(audioTabUi->hitLabel);
    result.append(audioTabUi->hitPitchLabel);
    result.append(audioTabUi->scoreLabel);
    result.append(audioTabUi->scorePitchLabel);
    result.append(audioTabUi->winLabel);
    result.append(audioTabUi->winPitchLabel);
    result.append(audioTabUi->loseLabel);
    result.append(audioTabUi->losePitchLabel);
    return result;
}

int AudioTab::findMaxLabelWidth(QList<QLabel *> labels)
{
    int result = -1;
    foreach(QLabel *label, labels)
    {
        result = qMax(result, label->width());
    }
    return result;
}

void AudioTab::batchSetLabelMinimumWidth(QList<QLabel *> labels, int minWidth)
{
    foreach(QLabel *label, labels)
    {
        label->setMinimumWidth(minWidth);
    }
}

void AudioTab::readInStyleSheets()
{
    greenBackground = Utils::readInStyleSheet("task_options_background_green.style");
    whiteBackground = Utils::readInStyleSheet("task_options_background_white.style");
    buttonBackground = Utils::readInStyleSheet("task_button.style");
}

void AudioTab::addValuesToJson(QJsonObject *json)
{
    json->insert(KEY_MUSIC_PATH, musicFilePath);
    json->insert(KEY_FIRE_PATH, fireFilePath);
    json->insert(KEY_SCORE_PATH, scoreFilePath);
    json->insert(KEY_HIT_PATH, hitFilePath);
    json->insert(KEY_WIN_PATH, winFilePath);
    json->insert(KEY_LOSE_PATH, loseFilePath);
    json->insert(KEY_AMBIENT1_PATH, ambient1FilePath);
    json->insert(KEY_AMBIENT2_PATH, ambient2FilePath);
    json->insert(KEY_AMBIENT3_PATH, ambient3FilePath);
    json->insert(KEY_MUSIC_VOUME, Utils::getJsonValueFromSlider(
                     audioTabUi->MusicVolumeSlider));
    json->insert(KEY_AMBIENT_VOLUME, Utils::getJsonValueFromSlider(
                     audioTabUi->ambientVolumeSlider));
    json->insert(KEY_SOUND_EFFECTS, Utils::getJsonValueFromSlider(
                     audioTabUi->soundEffectsSlider));
    json->insert(KEY_MUSIC_PITCH, Utils::getJsonValueFromSlider(
                     audioTabUi->musicPitchShiftSlider));
    json->insert(KEY_MUSIC_SPEED, Utils::getJsonValueFromSlider(
                     audioTabUi->musicSpeedSlider));
    json->insert(KEY_FIRE_PITCH, Utils::getJsonValueFromSlider(
                     audioTabUi->firePitchShiftSlider));
    json->insert(KEY_SCORE_PITCH, Utils::getJsonValueFromSlider(
                     audioTabUi->scorePitchShiftSlider));
    json->insert(KEY_HIT_PITCH, Utils::getJsonValueFromSlider(
                     audioTabUi->hitPitchShiftSlider));
    json->insert(KEY_WIN_PITCH, Utils::getJsonValueFromSlider(
                     audioTabUi->winPitchShiftSlider));
    json->insert(KEY_LOSE_PITCH, Utils::getJsonValueFromSlider(
                     audioTabUi->losePitchShiftSlider));
}

AudioTab::~AudioTab()
{
    delete audioTabUi;
}

void AudioTab::on_musicSelectFIleButton_clicked()
{
    musicFilePath = getFilePathFromFileFinder(audioTabUi->musicSelectFIleButton);
}

void AudioTab::on_fireSelectFIleButton_clicked()
{
    fireFilePath = getFilePathFromFileFinder(audioTabUi->fireSelectFIleButton);
}

void AudioTab::on_hitSelectFIleButton_clicked()
{
    hitFilePath = getFilePathFromFileFinder(audioTabUi->hitSelectFIleButton);
}

void AudioTab::on_scoreSelectFIleButton_clicked()
{
    scoreFilePath = getFilePathFromFileFinder(audioTabUi->scoreSelectFIleButton);
}

void AudioTab::on_winSelectFIleButton_clicked()
{
    winFilePath = getFilePathFromFileFinder(audioTabUi->winSelectFIleButton);
}

void AudioTab::on_loseSelectFIleButton_clicked()
{
    loseFilePath = getFilePathFromFileFinder(audioTabUi->loseSelectFIleButton);
}

void AudioTab::on_ambient1SelectFIleButton_clicked()
{
    ambient1FilePath = getFilePathFromFileFinder(audioTabUi->ambient1SelectFIleButton);
}

void AudioTab::on_ambient2SelectFIleButton_clicked()
{
    ambient2FilePath = getFilePathFromFileFinder(audioTabUi->ambient2SelectFIleButton);
}

void AudioTab::on_ambient3SelectFIleButton_clicked()
{
    ambient3FilePath = getFilePathFromFileFinder(audioTabUi->ambient3SelectFIleButton);
}

QString AudioTab::getFilePathFromFileFinder(QPushButton *button)
{
    QString result;
    QFileDialog dialog(this);
    dialog.setViewMode(QFileDialog::Detail);
    dialog.setAcceptMode(QFileDialog::AcceptOpen);
    dialog.setFileMode(QFileDialog::ExistingFile);
    dialog.setFilter(QDir::Readable | QDir::Dirs | QDir::Files);
    QStringList filters;
    filters << NAME_FILTER_AUDIO
            << NAME_FILTER_ANY;
    dialog.setNameFilters(filters);
    QDir dir(FILE_DIALOG_PATH);
    if (dir.exists())
    {
        dialog.setDirectory(FILE_DIALOG_PATH);
    }

    QStringList files;
    if (dialog.exec())
    {
        files = dialog.selectedFiles();
        if (files.size() > 0)
        {
            QFile file(files.at(0));
            if (file.exists())
            {
                result = files.at(0);
                qDebug() << "audio file path:" << result;
                button->setText(QFileInfo(file).fileName());
            }
        }
        else
        {
            qDebug() << "Problem finding audio file path";
        }
    }
    return result;
}

void AudioTab::on_ambient1ClearButton_clicked()
{
    ambient1FilePath = "";
    audioTabUi->ambient1SelectFIleButton->setText("");
}

void AudioTab::on_ambient2ClearButton_clicked()
{
    ambient2FilePath = "";
    audioTabUi->ambient2SelectFIleButton->setText("");
}

void AudioTab::on_ambient3ClearButton_clicked()
{
    ambient3FilePath = "";
    audioTabUi->ambient3SelectFIleButton->setText("");
}

void AudioTab::setValuesFromJson(QJsonObject json)
{
    if (json.contains(KEY_MUSIC_PATH))
    {
        musicFilePath = json.value(KEY_MUSIC_PATH).toString();
        audioTabUi->musicSelectFIleButton->setText(musicFilePath);
    }
    if (json.contains(KEY_FIRE_PATH))
    {
        fireFilePath = json.value(KEY_FIRE_PATH).toString();
        audioTabUi->fireSelectFIleButton->setText(fireFilePath);
    }
    if (json.contains(KEY_SCORE_PATH))
    {
        scoreFilePath = json.value(KEY_SCORE_PATH).toString();
        audioTabUi->scoreSelectFIleButton->setText(scoreFilePath);
    }
    if (json.contains(KEY_HIT_PATH))
    {
        hitFilePath = json.value(KEY_HIT_PATH).toString();
        audioTabUi->hitSelectFIleButton->setText(hitFilePath);
    }
    if (json.contains(KEY_WIN_PATH))
    {
        winFilePath = json.value(KEY_WIN_PATH).toString();
        audioTabUi->winSelectFIleButton->setText(winFilePath);
    }
    if (json.contains(KEY_LOSE_PATH))
    {
        loseFilePath = json.value(KEY_MUSIC_PATH).toString();
        audioTabUi->loseSelectFIleButton->setText(loseFilePath);
    }
    if (json.contains(KEY_AMBIENT1_PATH))
    {
        ambient1FilePath = json.value(KEY_AMBIENT1_PATH).toString();
        audioTabUi->ambient1SelectFIleButton->setText(ambient1FilePath);
    }
    if (json.contains(KEY_AMBIENT2_PATH))
    {
        ambient2FilePath = json.value(KEY_AMBIENT2_PATH).toString();
        audioTabUi->ambient2SelectFIleButton->setText(ambient2FilePath);
    }
    if (json.contains(KEY_AMBIENT3_PATH))
    {
        ambient3FilePath = json.value(KEY_AMBIENT3_PATH).toString();
        audioTabUi->ambient3SelectFIleButton->setText(ambient3FilePath);
    }
    if (json.contains(KEY_MUSIC_VOUME))
    {
        audioTabUi->MusicVolumeSlider->setValue(
                    Utils::sliderValueForJsonValue(
                        json.value(KEY_MUSIC_VOUME).toDouble(),
                        audioTabUi->MusicVolumeSlider)
                    );
    }
    if (json.contains(KEY_AMBIENT_VOLUME))
    {
        audioTabUi->ambientVolumeSlider->setValue(
                    Utils::sliderValueForJsonValue(
                        json.value(KEY_AMBIENT_VOLUME).toDouble(),
                        audioTabUi->ambientVolumeSlider)
                    );
    }
    if (json.contains(KEY_SOUND_EFFECTS))
    {
        audioTabUi->soundEffectsSlider->setValue(
                    Utils::sliderValueForJsonValue(
                        json.value(KEY_SOUND_EFFECTS).toDouble(),
                        audioTabUi->soundEffectsSlider)
                    );
    }
    if (json.contains(KEY_MUSIC_PITCH))
    {
        audioTabUi->musicPitchShiftSlider->setValue(
                    Utils::sliderValueForJsonValue(
                        json.value(KEY_MUSIC_PITCH).toDouble(),
                        audioTabUi->musicPitchShiftSlider)
                    );
    }
    if (json.contains(KEY_MUSIC_SPEED))
    {
        audioTabUi->musicSpeedSlider->setValue(
                    Utils::sliderValueForJsonValue(
                        json.value(KEY_MUSIC_SPEED).toDouble(),
                        audioTabUi->musicSpeedSlider)
                    );
    }
    if (json.contains(KEY_FIRE_PITCH))
    {
        audioTabUi->firePitchShiftSlider->setValue(
                    Utils::sliderValueForJsonValue(
                        json.value(KEY_FIRE_PITCH).toDouble(),
                        audioTabUi->firePitchShiftSlider)
                    );
    }
    if (json.contains(KEY_SCORE_PITCH))
    {
        audioTabUi->scorePitchShiftSlider->setValue(
                    Utils::sliderValueForJsonValue(
                        json.value(KEY_SCORE_PITCH).toDouble(),
                        audioTabUi->scorePitchShiftSlider)
                    );
    }
    if (json.contains(KEY_HIT_PITCH))
    {
        audioTabUi->hitPitchShiftSlider->setValue(
                    Utils::sliderValueForJsonValue(
                        json.value(KEY_HIT_PITCH).toDouble(),
                        audioTabUi->hitPitchShiftSlider)
                    );
    }
    if (json.contains(KEY_WIN_PITCH))
    {
        audioTabUi->winPitchShiftSlider->setValue(
                    Utils::sliderValueForJsonValue(
                        json.value(KEY_WIN_PITCH).toDouble(),
                        audioTabUi->winPitchShiftSlider)
                    );
    }
    if (json.contains(KEY_LOSE_PITCH))
    {
        audioTabUi->losePitchShiftSlider->setValue(
                    Utils::sliderValueForJsonValue(
                        json.value(KEY_LOSE_PITCH).toDouble(),
                        audioTabUi->losePitchShiftSlider)
                    );
    }
}











