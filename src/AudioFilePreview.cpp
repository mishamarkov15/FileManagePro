#include "../headers/AudioFilePreview.h"


AudioFilePreview::AudioFilePreview(const QString &filepath, QWidget *parent) :
        QWidget(parent),
        mainLayout(new QGridLayout()),
        filenameTitle(new QLabel()),
        player(new QMediaPlayer()),
        audioPhoto(new QLabel()),
        audio(new QAudioOutput()),
        play_pause(new QPushButton()),
        mute_btn(new QPushButton()),
        audioSlider(new QSlider(Qt::Horizontal)),
        volumeSlider(new QSlider(Qt::Horizontal)),
        PLAY_ICON(QPixmap("../assets/play.png")),
        PAUSE_ICON(QPixmap("../assets/pause.png")),
        MUTED_ICON(QPixmap("../assets/mute.png")),
        UNMUTED_ICON(QPixmap("../assets/unmute.png")),
        src_filepath(filepath) {
    initWidgets();
    initLayout();
    initStyles();
    initConnections();
}

void AudioFilePreview::initLayout() {
    setLayout(mainLayout);

    mainLayout->addWidget(filenameTitle, 0, 0, 1, 9);
    mainLayout->addWidget(audioPhoto, 1, 0, 5, 9);
    mainLayout->addWidget(audioSlider, 6, 0, 1, 6);
    mainLayout->addWidget(play_pause, 6, 6, 1, 1);
    mainLayout->addWidget(volumeSlider, 6, 7, 1, 1);
    mainLayout->addWidget(mute_btn, 6, 8, 1, 1);
}

void AudioFilePreview::initStyles() {

    filenameTitle->setAlignment(Qt::AlignCenter);
    mainLayout->setColumnStretch(0, 1);
}

void AudioFilePreview::initWidgets() {
    // buttons
    play_pause->setIcon(PLAY_ICON);
    mute_btn->setIcon(UNMUTED_ICON);

    // titles
    QFileInfo fileInfo(src_filepath);
    filenameTitle->setText(fileInfo.baseName());

    // audios
    player->setSource(QUrl::fromLocalFile(src_filepath));
    player->setAudioOutput(audio);

    audio->setVolume(0.2);

    // sliders
    audioSlider->setMinimum(0);
    audioSlider->setValue(0);
    audioSlider->setMaximum(100);

    volumeSlider->setMinimum(0);
    volumeSlider->setValue(20);
    volumeSlider->setMaximum(100);
}

void AudioFilePreview::initConnections() {
    connect(play_pause, &QPushButton::clicked, this, &AudioFilePreview::AudioStateManage);
    connect(mute_btn, &QPushButton::clicked, this, &AudioFilePreview::MuteUnmute);
    connect(player, &QMediaPlayer::positionChanged, this, &AudioFilePreview::UpdateSlider);
    connect(audioSlider, &QSlider::valueChanged, this, &AudioFilePreview::SetAudioPosition);
    connect(volumeSlider, &QSlider::valueChanged, this, &AudioFilePreview::SetVolume);
}

void AudioFilePreview::AudioStateManage() {
    if (player->isPlaying()) {
        play_pause->setIcon(PLAY_ICON);
        player->pause();
    } else {
        play_pause->setIcon(PAUSE_ICON);
        player->play();
    }
}

void AudioFilePreview::UpdateSlider() {
    audioSlider->blockSignals(true);
    audioSlider->setValue(static_cast<qint64>(
                                  (static_cast<double>(player->position()) / static_cast<double>(player->duration()) * 100)));
    audioSlider->blockSignals(false);
}

void AudioFilePreview::SetAudioPosition() {
    player->setPosition(static_cast<qint64>(
                                (static_cast<double>(audioSlider->value()) / 100.0) * static_cast<long double>(player->duration())));
}

void AudioFilePreview::MuteUnmute() {
    if (audio->isMuted()) {
        audio->setMuted(false);
        mute_btn->setIcon(UNMUTED_ICON);
    } else {
        audio->setMuted(true);
        mute_btn->setIcon(MUTED_ICON);
    }
}

void AudioFilePreview::SetVolume() {
    audio->setVolume(static_cast<float>(volumeSlider->value()) / static_cast<float>(100.0));
}
