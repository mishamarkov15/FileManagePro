#include "../headers/ImageFilePreview.h"
#include <QClipboard>

ImageFilePreview::ImageFilePreview(const QString &filepath, QWidget *parent) :
    mainLayout(new QGridLayout()),
    filenameTitle(new QLabel()),
    src_filepath(filepath),
    CopyBtn(new QPushButton("Copy Image")),
    Img(new QLabel()),
    clipboard(QGuiApplication::clipboard())
{
    initWidgets();
    setPhoto();
    initLayout();
    initStyles();
    initConnections();
}

void ImageFilePreview::initLayout() {
    setLayout(mainLayout);

    mainLayout->addWidget(filenameTitle, 0, 0, 1, 9);
    mainLayout->addWidget(Img, 1, 0, 5, 9);
    mainLayout->addWidget(CopyBtn, 6, 8, 1, 1);

}

void ImageFilePreview::initConnections() {
    connect(CopyBtn, &QPushButton::clicked, this, &ImageFilePreview::CopyPhoto);
}

void ImageFilePreview::initStyles() {
    filenameTitle->setAlignment(Qt::AlignCenter);
    Img->setAlignment(Qt::AlignCenter);
}

void ImageFilePreview::initWidgets() {
    QFileInfo fileInfo(src_filepath);
    filenameTitle->setText(fileInfo.baseName());
}

void ImageFilePreview::setPhoto() {
    Img->setPixmap(QPixmap(src_filepath).scaled(Img->width(), Img->height(), Qt::KeepAspectRatio,Qt::SmoothTransformation));

}

inline void ImageFilePreview::CopyPhoto() {
    clipboard->setImage(Img->pixmap().toImage());
}