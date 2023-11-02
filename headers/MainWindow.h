#ifndef FILEMANAGEPRO_MAINWINDOW_H
#define FILEMANAGEPRO_MAINWINDOW_H

#include "TextFilePreview.h"
#include "VideoFilePreview.h"
#include "FileStorage.h"
#include "ImageFilePreview.h"
#include <QMainWindow>
#include <QGridLayout>
#include <QWidget>
#include <QSplitter>


class MainWindow : public QMainWindow {
Q_OBJECT;
public:
    explicit MainWindow(QWidget *parent = nullptr);

public slots:

    void changeRightWidget();

    void openAfterAuth();

private:
    void initLayout();

    void initStyles();

    void initWidgets();

    void initConnections();

    QWidget *centralWidget;
    FileStorage *left;
    QWidget *right;

    QGridLayout *mainLayout;
    QSplitter *splitter;
};

namespace extensions {
    const QVector<QString> TEXT_EXTENSIONS = {"cpp", "h", "py", "js", "html", "css", "txt", "md"};
    const QVector<QString> IMAGE_EXTENSIONS = {"jpg", "jpeg", "png", "bmp", "heic", "webp", "svg"};
    const QVector<QString> AUDIO_EXTENSIONS = {"mp3", "wav"};
    const QVector<QString> VIDEO_EXTENSIONS = {"mp4", "mov", "mpeg", "mpg"};

    bool isText(const QString &filepath);

    bool isImage(const QString &filepath);

    bool isAudio(const QString &filepath);

    bool isVideo(const QString &filepath);
};


#endif //FILEMANAGEPRO_MAINWINDOW_H
