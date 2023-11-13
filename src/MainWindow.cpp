#include "../headers/MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        centralWidget(new QWidget()),
        left(new FileStorage()),
        right(new QWidget()),
        mainLayout(new QGridLayout()),
        splitter(new QSplitter()) {
    initWidgets();
    initLayout();
    initConnections();
    initStyles();
}

void MainWindow::initConnections() {
    connect(left->view, &MyTree::selectionChanged, this, &MainWindow::changeRightWidget);
}

void MainWindow::initWidgets() {
    splitter->addWidget(left);
    splitter->addWidget(right);
}

void MainWindow::initStyles() {
    setMinimumSize(1500, 500);
}

void MainWindow::initLayout() {
    setCentralWidget(centralWidget);
    centralWidget->setLayout(mainLayout);

    mainLayout->addWidget(splitter);
}


void MainWindow::changeRightWidget() {
    auto filepath = left->model->filePath(left->view->currentIndex());
    delete right;
    if (extensions::isText(filepath)) {
        right = new TextFilePreview(filepath);
    } else if (extensions::isImage(filepath)) {
        right = new ImageFilePreview(filepath);
    } else if (extensions::isAudio(filepath)) {
        right = new AudioFilePreview(filepath);
    } else if (extensions::isVideo(filepath)) {
        right = new VideoFilePreview(filepath);
    } else {
        right = new QWidget();
    }
    splitter->addWidget(right);
}

void MainWindow::openAfterAuth() {
    show();
}


bool extensions::isText(const QString &filepath) {
    QFileInfo fileInfo(filepath);
    return TEXT_EXTENSIONS.contains(fileInfo.suffix());
}

bool extensions::isImage(const QString &filepath) {
    QFileInfo fileInfo(filepath);
    return IMAGE_EXTENSIONS.contains(fileInfo.suffix());
}

bool extensions::isAudio(const QString &filepath) {
    QFileInfo fileInfo(filepath);
    return AUDIO_EXTENSIONS.contains(fileInfo.suffix());
}

bool extensions::isVideo(const QString &filepath) {
    QFileInfo fileInfo(filepath);
    return VIDEO_EXTENSIONS.contains(fileInfo.suffix());
}