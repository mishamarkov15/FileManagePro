#ifndef FILEMANAGEPRO_LOGINWINDOW_H
#define FILEMANAGEPRO_LOGINWINDOW_H

#include <QWidget>
#include <QGridLayout>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QErrorMessage>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QCryptographicHash>
#include "MainWindow.h"

class LoginWindow : public QWidget {
Q_OBJECT;
public:
    explicit LoginWindow(MainWindow* windowToShow, QWidget* parent = nullptr);
public slots:
    void prepareToOpenMainWindow();
private:
    bool checkAuthData();

    void initLayout();

    void initStyles();

    void initWidgets();

    void initConnections();

    QGridLayout* layout;

    QLabel* main_title;
    QLabel* username_label;
    QLabel* password_label;

    QLineEdit* username_input;
    QLineEdit* password_input;

    QPushButton* authorize_btn;

    MainWindow* window;
};


#endif //FILEMANAGEPRO_LOGINWINDOW_H
