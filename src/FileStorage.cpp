//
// Created by Михаил Марков on 17/08/2023.
//

#include "FileStorage.h"

FileStorage::FileStorage(QWidget *parent) :
        QWidget(parent),
        mainLayout(new QGridLayout()),
        model(new QFileSystemModel()),
        view(new QTreeView()){
    initWidgets();
    initLayout();
    initConnections();
    initStyles();
}

void FileStorage::initLayout() {
    setLayout(mainLayout);

    mainLayout->addWidget(view, 0, 0, 1, 1);
}

void FileStorage::initStyles() {

}

void FileStorage::initWidgets() {
    model->setRootPath("");

    view->setModel(model);
}

void FileStorage::initConnections() {
}
