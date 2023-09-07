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
    connect(left->view, &MyTree::selectionChanged, this, &MainWindow::changeRightWidget);
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

void MainWindow::previewText() {
}

void MainWindow::changeRightWidget() {
    auto filepath = left->model->filePath(left->view->currentIndex());
    if (extensions::isText(filepath)) {
        QDebug d(QtMsgType::QtInfoMsg);
        d << "I'm text!\n";
    }
}


bool extensions::isText(const QString &filepath) {
    QFileInfo fileInfo(filepath);
    return TEXT_EXTENSIONS.contains(fileInfo.suffix());
}

