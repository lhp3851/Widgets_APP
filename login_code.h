#ifndef LOGIN_CODE_H
#define LOGIN_CODE_H
#include <QDialog>

class QLabel;
class QLineEdit;
class QPushButton;

class login_code :public QDialog
{
    Q_OBJECT
public:
    explicit login_code(QWidget *parent = 0);
    ~login_code();

private slots:
    void login();


private:
    QLabel *userLabel;
    QLabel *pwdLabel;
    QLineEdit *userLineEdit;
    QLineEdit *pwdLineEdit;
    QPushButton *loginBtn;
    QPushButton *exitBtn;

};

#endif // LOGIN_CODE_H
