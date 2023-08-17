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
    filenameTitle->setAlignment(Qt::AlignCenter);

    content->setReadOnly(true);
}

void TextFilePreview::initConnections() {

}

void TextFilePreview::displayTextContent() {
    auto* senderButton = dynamic_cast<QPushButton*>(sender());

    QFile file(senderButton->text());

    filenameTitle->setText(file.fileName());

    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream in(&file);

    content->setText(in.readAll());

    file.close();
}
