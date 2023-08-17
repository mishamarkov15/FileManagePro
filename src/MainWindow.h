#ifndef FILEMANAGEPRO_MAINWINDOW_H
#define FILEMANAGEPRO_MAINWINDOW_H

#include "TextFilePreview.h"
#include <QMainWindow>
#include <QGridLayout>
#include <QWidget>


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
    QWidget *left;
    TextFilePreview *right;

    QGridLayout *mainLayout;
};


#endif //FILEMANAGEPRO_MAINWINDOW_H
