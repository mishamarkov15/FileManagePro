//
// Created by Михаил Марков on 07/09/2023.
//

#ifndef FILEMANAGEPRO_VIDEOFILEPREVIEW_H
#define FILEMANAGEPRO_VIDEOFILEPREVIEW_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QAudioOutput>
#include <QtMultimediaWidgets/QVideoWidget>

class VideoFilePreview : public QWidget {
Q_OBJECT;
public:
    explicit VideoFilePreview(const QString &filepath, QWidget *parent = nullptr);

public slots:

    void VideoStateManage();

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

    const QIcon PLAY_ICON;
    const QIcon PAUSE_ICON;
};


#endif //FILEMANAGEPRO_VIDEOFILEPREVIEW_H
