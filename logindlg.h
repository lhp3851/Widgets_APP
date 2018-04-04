#ifndef LOGINDLG_H
#define LOGINDLG_H

#include <QDialog>

namespace Ui {
class Logindlg;
}

class Logindlg : public QDialog
{
    Q_OBJECT

public:
    explicit Logindlg(QWidget *parent = 0);
    ~Logindlg();

    void requestForDatas();

private slots:
    void on_loginBtn_clicked();


private:
    Ui::Logindlg *ui;
};

#endif // LOGINDLG_H
