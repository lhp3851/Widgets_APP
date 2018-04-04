#include "logindlg.h"
#include "ui_logindlg.h"
#include <QByteArray>
#include <QMessageBox>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QJsonDocument>

Logindlg::Logindlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Logindlg)
{
    ui->setupUi(this);
}

Logindlg::~Logindlg()
{
    delete ui;
}

void Logindlg::on_loginBtn_clicked()
{
    if (ui->userLineEdit->text().trimmed() == tr("linux") && ui->pwdLineEdit->text() == tr("123456")) {
        accept();
    }
    else {
        QMessageBox::warning(this,tr("警告"),
                tr("用户名或密码错误"),
                QMessageBox::Yes);
        ui->userLineEdit->clear();
        ui->pwdLineEdit->clear();
        ui->userLineEdit->setFocus();
    }
}


void Logindlg::requestForDatas(){
    // URL
    QString baseUrl = "https://httpbin.org/get";

    // 构造请求
    QNetworkRequest request;
    request.setUrl(QUrl(baseUrl));

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    // 发送请求
    QNetworkReply *pReplay = manager->get(request);

    // 开启一个局部的事件循环，等待响应结束，退出
    QEventLoop eventLoop;
    QObject::connect(manager, &QNetworkAccessManager::finished, &eventLoop, &QEventLoop::quit);
    eventLoop.exec();

    // 获取响应信息
    QByteArray bytes = pReplay->readAll();
    QJsonParseError jsonError;
    QJsonDocument json = QJsonDocument::fromJson(bytes, &jsonError);
    qDebug("Debug");
    qWarning("Warning");
//    qFatal("Fatal");
//    qErrnoWarning("ErrnoWarning");
//    qCritical("Critical");
    qDebug() << bytes;
    qDebug() << json;
}
