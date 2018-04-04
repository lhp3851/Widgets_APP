#include "login_code.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>


login_code::login_code(QWidget *parent) : QDialog(parent)
{
    userLabel = new QLabel(this);
    userLabel-> move(70,80);
    userLabel ->setText("用户名");

    userLineEdit = new QLineEdit(this);
    userLineEdit ->move(140,80);
    userLineEdit ->setPlaceholderText("请输入用户名");

    pwdLabel = new QLabel(this);
    pwdLabel ->move(70,130);
    pwdLabel ->setText("密码");

    pwdLineEdit = new QLineEdit(this);
    pwdLineEdit ->move(140,130);
    pwdLineEdit ->setPlaceholderText("请输入密码");
    pwdLineEdit->setEchoMode(QLineEdit::Password);

    loginBtn = new QPushButton(this);
    loginBtn->move(50,200);
    loginBtn->setText("登录");

    exitBtn = new QPushButton(this);
    exitBtn ->move(210,200);
    exitBtn ->setText("退出");

    connect(loginBtn,&QPushButton::clicked,this,&login_code::login);
    connect(exitBtn, &QPushButton::clicked,this,&login_code::close);
}


void login_code::login(){
    if (userLineEdit->text().trimmed() == tr("linux") && pwdLineEdit->text() == tr("123456")) {
        accept();
    }
    else {
        QMessageBox::warning(this,tr("警告"),
                tr("用户名或密码错误"),
                QMessageBox::Yes);
        userLineEdit->clear();
        pwdLineEdit->clear();
        userLineEdit->setFocus();
    }
}

login_code::~login_code(){

}
