#include "../headers/TextFilePreview.h"


TextFilePreview::TextFilePreview(const QString& filepath, QWidget *parent) :
        QWidget(parent),
        mainLayout(new QGridLayout()),
        filenameTitle(new QLabel()),
        content(new QTextEdit()),
        src_filepath(filepath) {
    initWidgets();
    initLayout();
    initConnections();
    initStyles();
}

void TextFilePreview::initLayout() {
    setLayout(mainLayout);

    mainLayout->addWidget(filenameTitle, 0, 0, 1, 1);
    mainLayout->addWidget(content, 1, 0, 5, 1);
}

void TextFilePreview::initStyles() {
    setStyleSheet("color: black");
}

void TextFilePreview::initWidgets() {
    QFileInfo fileInfo(src_filepath);

    filenameTitle->setText(fileInfo.fileName());
    filenameTitle->setAlignment(Qt::AlignCenter);

    QFile f(src_filepath);
    f.open(QIODevice::ReadOnly);
    content->setText(f.readAll());
    f.close();
    content->setReadOnly(true);
}

void TextFilePreview::initConnections() {

}
