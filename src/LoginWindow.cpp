#include "../headers/LoginWindow.h"

LoginWindow::LoginWindow(MainWindow *windowToShow, QWidget *parent) :
        QWidget(parent),
        layout(new QGridLayout()),
        main_title(new QLabel()),
        username_label(new QLabel()),
        password_label(new QLabel()),
        username_input(new QLineEdit()),
        password_input(new QLineEdit()),
        authorize_btn(new QPushButton()),
        window(windowToShow) {
    initWidgets();
    initStyles();
    initLayout();
    initConnections();
}

void LoginWindow::initLayout() {
    setLayout(layout);

    layout->addWidget(main_title, 0, 0, 1, 3);
    layout->addWidget(username_label, 2, 0, 1, 1);
    layout->addWidget(password_label, 3, 0, 1, 1);

    layout->addWidget(username_input, 2, 1, 1, 2);
    layout->addWidget(password_input, 3, 1, 1, 2);

    layout->addWidget(authorize_btn, 4, 2, 1, 1);
}

void LoginWindow::initStyles() {
    setFixedSize(250,200);


}

void LoginWindow::initWidgets() {
    main_title->setText("Авторизация");
    main_title->setAlignment(Qt::AlignCenter);

    username_label->setText("Логин:");
    password_label->setText("Пароль:");

    username_input->setPlaceholderText("Ваш логин...");
    password_input->setPlaceholderText("Ваш пароль...");
    password_input->setEchoMode(QLineEdit::Password);

    authorize_btn->setText("Вход");
}

void LoginWindow::initConnections() {
    connect(authorize_btn, &QPushButton::clicked, this, &LoginWindow::prepareToOpenMainWindow);
}

bool LoginWindow::checkAuthData() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../passwords.db");
    bool ok = db.open();
    if (ok) {
        QDebug d(QtMsgType::QtInfoMsg);
        d << "Success!\n";

        QSqlQuery query;
        query.prepare("SELECT id FROM passwords WHERE username = (:login) AND hash_password = (:hash);");
        query.bindValue(":login", username_input->text());
        query.bindValue(":hash", QCryptographicHash::hash(password_input->text().toStdString().c_str(),
                                                          QCryptographicHash::Sha256).toHex(0));
        if (query.exec()) {
            if (query.next()) {
                db.close();
                return true;
            } else {
                d << "No such user\n";
                db.close();
                return false;
            }
        }
        db.close();

    } else {
        QDebug d(QtMsgType::QtCriticalMsg);
        d << "Fail!";
    }
    db.close();
    return false;
}

void LoginWindow::prepareToOpenMainWindow() {
    if (checkAuthData()) {
        window->show();
        close();
    }
}
