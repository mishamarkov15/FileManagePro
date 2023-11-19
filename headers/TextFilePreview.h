#ifndef FILEMANAGEPRO_TEXTFILEPREVIEW_H
#define FILEMANAGEPRO_TEXTFILEPREVIEW_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QTextEdit>
#include <QPushButton>
#include <QFile>
#include <QMessageBox>
#include <QFileInfo>

class TextFilePreview : public QWidget {
Q_OBJECT;
public:
    explicit TextFilePreview(const QString& filepath, QWidget *parent = nullptr);

private slots:
    void colorchange();

private:
    void initLayout();

    void initStyles();

    void initWidgets();

    void initConnections();

    QString colorStatus;

    QGridLayout *mainLayout;
    QLabel *filenameTitle;
    QTextEdit *content;
    QString src_filepath;
    QPushButton* color_btn;
};


#endif //FILEMANAGEPRO_TEXTFILEPREVIEW_H
