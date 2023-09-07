//
// Created by Михаил Марков on 17/08/2023.
//

#ifndef FILEMANAGEPRO_TEXTFILEPREVIEW_H
#define FILEMANAGEPRO_TEXTFILEPREVIEW_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QTextEdit>
#include <QPushButton>
#include <QFile>
#include <QMessageBox>

class TextFilePreview : public QWidget {
Q_OBJECT;
public:
    explicit TextFilePreview(QWidget *parent = nullptr);

public slots:
    void displayTextContent();

private:
    void initLayout();

    void initStyles();

    void initWidgets();

    void initConnections();

    QGridLayout *mainLayout;
    QLabel *filenameTitle;
    QTextEdit *content;
};


#endif //FILEMANAGEPRO_TEXTFILEPREVIEW_H
