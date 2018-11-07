#include "burtwindow.h"
#include "ui_burtwindow.h"
#include <QAudioProbe>
#include <QAudioRecorder>
#include <QDir>
#include <QFileDialog>
#include <QMediaRecorder>
#include <QStandardPaths>

burtWindow::burtWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::burtWindow)
{
    ui->setupUi(this);
    audioRecorder = new QAudioRecorder(this);
    QStringList inputs = audioRecorder->audioInputs();
    QString selectedInput = audioRecorder->defaultAudioInput();
    ui->audioDeviceBox->addItem(tr("Default"), QVariant(QString()));
    foreach (const QString &device, audioRecorder->audioInputs()) {
        ui->audioDeviceBox->addItem(device, QVariant(device));
    }
}

burtWindow::~burtWindow()
{
    delete ui;
}

static QVariant boxValue(const QComboBox *box)
{
    int idx = box->currentIndex();
    if (idx == -1)
        return QVariant();

    return box->itemData(idx);
}

void burtWindow::onStateChanged(QMediaRecorder::State state)
{
    switch (state) {
    case QMediaRecorder::RecordingState:
        ui->pushStart->setText(tr("Stop"));
        break;
    case QMediaRecorder::StoppedState:
        ui->pushStart->setText(tr("Record"));
        break;
    case QMediaRecorder::PausedState:
        ui->pushStart->setText(tr("Pause"));
        break;
    }
}

void burtWindow::on_pushStart_clicked()
{
    if (audioRecorder->state() == QMediaRecorder::StoppedState) {

            QAudioEncoderSettings settings;
            settings.setCodec("audio/pcm");
            settings.setQuality(QMultimedia::NormalQuality);
            QString container = "audo/x-wav";
            audioRecorder->setEncodingSettings(settings);
            audioRecorder->record();
        }
        else {
            audioRecorder->stop();
        }
}

