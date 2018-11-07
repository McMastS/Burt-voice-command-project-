#ifndef BURTWINDOW_H
#define BURTWINDOW_H

#include <QMainWindow>
#include <QMediaRecorder>
#include <QUrl>

QT_BEGIN_NAMESPACE
namespace Ui { class burtWindow; }
class QAudioRecorder;
class QAudioProbe;
class QAudioBuffer;
QT_END_NAMESPACE

namespace Ui {
class burtWindow;
}

class burtWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit burtWindow(QWidget *parent = 0);
    ~burtWindow();

private slots:
    void on_pushStart_clicked();
    void onStateChanged(QMediaRecorder::State);
private:
    Ui::burtWindow *ui;
    QAudioRecorder *audioRecorder;
};

#endif // BURTWINDOW_H
