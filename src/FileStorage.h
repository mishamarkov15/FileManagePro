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

const QString RootDirectoryPath("/Users/mikhaiil/.EgorFileManager/");

class MyTree : public QTreeView {
Q_OBJECT;
public:
    void setModel(QAbstractItemModel *model) override {
        QTreeView::setModel(model);
    }

signals:

    void selectionChanged(const QItemSelection &selected, const QItemSelection &deselected) override;
};

class FileStorage : public QWidget {
Q_OBJECT;
public:
    explicit FileStorage(QWidget *parent = nullptr);

public:
    MyTree *view;
    QFileSystemModel *model;

private:
    void initLayout();

    void initStyles();

    void initWidgets();

    void initConnections();

    QGridLayout *mainLayout;
};


#endif //FILEMANAGEPRO_FILESTORAGE_H
