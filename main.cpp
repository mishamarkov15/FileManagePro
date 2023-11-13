#include <QApplication>
#include "headers/LoginWindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    MainWindow mainWindow;

    LoginWindow w(&mainWindow);
    w.show();

    return QApplication::exec();
}
