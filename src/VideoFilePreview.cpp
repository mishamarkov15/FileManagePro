//
// Created by Михаил Марков on 07/09/2023.
//

#include "../headers/VideoFilePreview.h"

VideoFilePreview::VideoFilePreview(const QString &filepath, QWidget *parent) :
        QWidget(parent),
        mainLayout(new QGridLayout()),
        filenameTitle(new QLabel()),
        player(new QMediaPlayer()),
        videoWidget(new QVideoWidget()),
        audio(new QAudioOutput()),
        play_pause(new QPushButton()),
        PLAY_ICON(QPixmap("../assets/play.png")),
        PAUSE_ICON(QPixmap("../assets/pause.png")),
        src_filepath(filepath) {
    initWidgets();
    initLayout();
    initStyles();
    initConnections();
}

void VideoFilePreview::initLayout() {
    setLayout(mainLayout);

    mainLayout->addWidget(filenameTitle, 0, 0, 1, 1);
    mainLayout->addWidget(videoWidget, 1, 0, 5, 1);
    mainLayout->addWidget(play_pause, 6, 0, 1, 1);
}

void VideoFilePreview::initStyles() {

}

void VideoFilePreview::initWidgets() {
    play_pause->setIcon(PLAY_ICON);

    player->setSource(QUrl::fromLocalFile(src_filepath));

    player->setVideoOutput(videoWidget);
    player->setAudioOutput(audio);
}

void VideoFilePreview::initConnections() {
    connect(play_pause, &QPushButton::clicked, this, &VideoFilePreview::VideoStateManage);
}

void VideoFilePreview::VideoStateManage() {
    if (player->isPlaying()) {
        play_pause->setIcon(PLAY_ICON);
        player->pause();
    } else {
        play_pause->setIcon(PAUSE_ICON);
        player->play();
    }
}
