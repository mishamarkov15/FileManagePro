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
    initLayout();
    initStyles();
    initConnections();
    setPhoto();
}

void ImageFilePreview::initLayout() {
    setLayout(mainLayout);

    mainLayout->addWidget(filenameTitle, 0, 0, 1, 9);
    mainLayout->addWidget(Img, 2, 0, 5, 9);
    mainLayout->addWidget(CopyBtn, 7, 7, 1, 1);

}

void ImageFilePreview::initConnections() {
    connect(CopyBtn, &QPushButton::clicked, this, &ImageFilePreview::CopyPhoto);
}

void ImageFilePreview::initStyles() {
    filenameTitle->setAlignment(Qt::AlignCenter);
    Img->setAlignment(Qt::AlignCenter);
    mainLayout->setColumnStretch(0, 1);
}

void ImageFilePreview::initWidgets() {
    QFileInfo fileInfo(src_filepath);
    filenameTitle->setText(fileInfo.baseName());
}

void ImageFilePreview::setPhoto() {
    QPixmap myPixmap(src_filepath);
    Img->setPixmap(myPixmap);
    Img->setScaledContents(true);
    int pixW = myPixmap.width();
    int ImgW = Img->width();
    double factor = double(ImgW)/pixW;
    Img->setFixedWidth((factor * Img->pixmap().width())/1.7);
    Img->setFixedHeight((factor * Img->pixmap().height())/1.7);
}

inline void ImageFilePreview::CopyPhoto() {
    clipboard->setImage(Img->pixmap().toImage());
}