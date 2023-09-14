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
        videoSlider(new QSlider(Qt::Horizontal)),
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

    mainLayout->addWidget(filenameTitle, 0, 0, 1, 7);
    mainLayout->addWidget(videoWidget, 1, 0, 5, 7);
    mainLayout->addWidget(videoSlider, 6, 0, 1, 6);
    mainLayout->addWidget(play_pause, 6, 6, 1, 1);
}

void VideoFilePreview::initStyles() {
    filenameTitle->setAlignment(Qt::AlignCenter);
}

void VideoFilePreview::initWidgets() {
    play_pause->setIcon(PLAY_ICON);
    QFileInfo fileInfo(src_filepath);
    filenameTitle->setText(fileInfo.baseName());

    player->setSource(QUrl::fromLocalFile(src_filepath));

    player->setVideoOutput(videoWidget);
    player->setAudioOutput(audio);

    videoSlider->setMinimum(0);
    videoSlider->setValue(0);
    videoSlider->setMaximum(100);
}

void VideoFilePreview::initConnections() {
    connect(play_pause, &QPushButton::clicked, this, &VideoFilePreview::VideoStateManage);
    connect(player, &QMediaPlayer::positionChanged, this, &VideoFilePreview::UpdateSlider);
    connect(videoSlider, &QSlider::valueChanged, this, &VideoFilePreview::SetVideoPosition);
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

void VideoFilePreview::UpdateSlider() {
    videoSlider->blockSignals(true);
    videoSlider->setValue(static_cast<qint64>(
            (static_cast<double>(player->position()) / static_cast<double>(player->duration()) * 100)));
    videoSlider->blockSignals(false);
}

void VideoFilePreview::SetVideoPosition() {
    player->setPosition(static_cast<qint64>(
            (static_cast<double>(videoSlider->value()) / 100.0) * static_cast<long double>(player->duration())));
}
