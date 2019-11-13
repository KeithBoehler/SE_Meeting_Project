#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QMessageBox>

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}


void LoginWindow::on_pushButtonLogin_clicked()
{
    QString username = ui->lineEditUsername->text();
    QString password = ui->lineEditPassword->text();

    if(username == "test" && password == "test123"){
        QMessageBox::information(this,"Login", "Login Successful!");
        this->hide();
        mainWindow mainWindow;
        mainWindow.exec();

    }
    else{
        QMessageBox::warning(this, "Login", "Wrong username or password, please try again");
    }

}

void LoginWindow::on_pushButtonCreateAcc_clicked()
{

}
