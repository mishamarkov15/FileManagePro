//
// Created by Михаил Марков on 17/08/2023.
//

#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        centralWidget(new QWidget()),
        left(new FileStorage()),
        right(new TextFilePreview()),
        mainLayout(new QGridLayout()),
        splitter(new QSplitter()) {
    initWidgets();
    initLayout();
    initConnections();
    initStyles();
}

void MainWindow::initConnections() {
//    connect(left->getButtonByID(1), &QPushButton::clicked, right, &TextFilePreview::displayTextContent);
//    connect(left->getButtonByID(2), &QPushButton::clicked, right, &TextFilePreview::displayTextContent);
//    connect(left->getButtonByID(3), &QPushButton::clicked, right, &TextFilePreview::displayTextContent);
}

void MainWindow::initWidgets() {
    splitter->addWidget(left);
    splitter->addWidget(right);
}

void MainWindow::initStyles() {

}

void MainWindow::initLayout() {
    setCentralWidget(centralWidget);
    centralWidget->setLayout(mainLayout);

    mainLayout->addWidget(splitter);
}

