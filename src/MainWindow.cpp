//
// Created by Михаил Марков on 17/08/2023.
//

#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        centralWidget(new QWidget()),
        left(new QWidget()),
        right(new TextFilePreview()),
        mainLayout(new QGridLayout()) {
    initWidgets();
    initLayout();
    initConnections();
    initStyles();
}

void MainWindow::initConnections() {

}

void MainWindow::initWidgets() {

}

void MainWindow::initStyles() {

}

void MainWindow::initLayout() {
    setCentralWidget(centralWidget);
    centralWidget->setLayout(mainLayout);

    mainLayout->addWidget(left, 0, 0, 1, 1);
    mainLayout->addWidget(right, 0, 1, 1, 1);
}
