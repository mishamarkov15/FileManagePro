#ifndef FILEMANAGEPRO_MAINWINDOW_H
#define FILEMANAGEPRO_MAINWINDOW_H

#include "TextFilePreview.h"
#include "FileStorage.h"
#include <QMainWindow>
#include <QGridLayout>
#include <QWidget>
#include <QSplitter>


class MainWindow : public QMainWindow {
Q_OBJECT;
public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    void initLayout();

    void initStyles();

    void initWidgets();

    void initConnections();

    QWidget *centralWidget;
    FileStorage *left;
    TextFilePreview *right;

    QGridLayout *mainLayout;
    QSplitter *splitter;
};


#endif //FILEMANAGEPRO_MAINWINDOW_H
