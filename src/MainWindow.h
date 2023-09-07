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

public slots:
    void changeRightWidget();

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

    void previewText();
};

namespace extensions {
    const QVector<QString> TEXT_EXTENSIONS = {"cpp", "h", "py", "js", "html", "css", "txt", "md"};

    bool isText(const QString& filepath);
};


#endif //FILEMANAGEPRO_MAINWINDOW_H
