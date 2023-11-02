#ifndef FILEMANAGEPRO_VIDEOFILEPREVIEW_H
#define FILEMANAGEPRO_VIDEOFILEPREVIEW_H

#include <QWidget>
#include <QLabel>
#include <QFileInfo>
#include <QGridLayout>
#include <QPushButton>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QAudioOutput>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QSlider>

class VideoFilePreview : public QWidget {
Q_OBJECT;
public:
    explicit VideoFilePreview(const QString &filepath, QWidget *parent = nullptr);

public slots:

    void VideoStateManage();

    void UpdateSlider();

    void SetVideoPosition();

    void MuteUnmute();

    void SetVolume();

private:
    void initLayout();

    void initStyles();

    void initWidgets();

    void initConnections();

    QGridLayout *mainLayout;
    QLabel *filenameTitle;
    QMediaPlayer *player;
    QAudioOutput *audio;
    QVideoWidget *videoWidget;
    QString src_filepath;
    QPushButton *play_pause;
    QPushButton *mute_btn;
    QSlider* videoSlider;
    QSlider* volumeSlider;

    const QIcon PLAY_ICON;
    const QIcon PAUSE_ICON;
    const QIcon MUTED_ICON;
    const QIcon UNMUTED_ICON;
};


#endif //FILEMANAGEPRO_VIDEOFILEPREVIEW_H
