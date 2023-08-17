//
// Created by Михаил Марков on 17/08/2023.
//

#include "TextFilePreview.h"


TextFilePreview::TextFilePreview(QWidget *parent) :
        QWidget(parent),
        mainLayout(new QGridLayout()),
        filenameTitle(new QLabel()),
        content(new QTextEdit()) {
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

}

void TextFilePreview::initWidgets() {
    filenameTitle->setText("click button to preview file");
}

void TextFilePreview::initConnections() {

}
