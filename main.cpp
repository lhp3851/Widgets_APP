#include "mainwindow.h"
#include <QApplication>
#include "logindlg.h"
#include "login_code.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Logindlg dlg;

    dlg.requestForDatas();

    if(dlg.exec() == QDialog::Accepted){
       w.show();
        return a.exec();
    }
     return 0;
}
