//
// Created by Михаил Марков on 17/08/2023.
//

#ifndef FILEMANAGEPRO_FILESTORAGE_H
#define FILEMANAGEPRO_FILESTORAGE_H

#include <QWidget>
#include <QGridLayout>
#include <QFileSystemModel>
#include <QTreeView>
#include <QPushButton>

class FileStorage : public QWidget {
Q_OBJECT;
public:
    explicit FileStorage(QWidget *parent = nullptr);

private:
    void initLayout();

    void initStyles();

    void initWidgets();

    void initConnections();

    QGridLayout *mainLayout;
    QFileSystemModel* model;
    QTreeView *view;
};


#endif //FILEMANAGEPRO_FILESTORAGE_H
