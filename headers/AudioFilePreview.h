#ifndef FILEMANAGEPRO_AudioFilePreview_H
#define FILEMANAGEPRO_AudioFilePreview_H

#include <QWidget>
#include <QLabel>
#include <QFileInfo>
#include <QGridLayout>
#include <QPushButton>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QAudioOutput>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QSlider>

class AudioFilePreview : public QWidget {
Q_OBJECT;
public:
    explicit AudioFilePreview(const QString &filepath, QWidget *parent = nullptr);

public slots:

    void AudioStateManage();

    void UpdateSlider();

    void SetAudioPosition();

    void MuteUnmute();

    void SetVolume();

private:
    void initLayout();

    void initStyles();

    void initWidgets();

    void initConnections();

    QGridLayout *mainLayout;
    QLabel *filenameTitle;
    QLabel *audioPhoto;
    QMediaPlayer *player;
    QAudioOutput *audio;
    QString src_filepath;
    QPushButton *play_pause;
    QPushButton *mute_btn;
    QSlider* audioSlider;
    QSlider* volumeSlider;

    const QIcon PLAY_ICON;
    const QIcon PAUSE_ICON;
    const QIcon MUTED_ICON;
    const QIcon UNMUTED_ICON;
};


#endif //FILEMANAGEPRO_AudioFilePreview_H
