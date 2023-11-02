#ifndef FILEMANAGEPRO_IMAGEFILEPREVIEW_H
#define FILEMANAGEPRO_IMAGEFILEPREVIEW_H

#include "MainWindow.h"

class ImageFilePreview : public QWidget {
    Q_OBJECT;
public:
    explicit ImageFilePreview(const QString &filepath, QWidget *parent = nullptr);
private:
    void initLayout();

    void initStyles();

    void initWidgets();

    void initConnections();

    void show();

    QGridLayout *mainLayout;
    QLabel *filenameTitle;
    QString src_filepath;
    QLabel *Img;
    QPushButton *CopyBtn;
private slots:
    void CopyPhoto();
};


#endif //FILEMANAGEPRO_IMAGEFILEPREVIEW_H
