#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QAction>
#include <QIcon>
#include <QMenu>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QAction *openAction = new QAction();
    QIcon icon(":/myimages/WechatIMG165.jpeg");
    openAction->setIcon(icon);
    openAction->setShortcut(QKeySequence("Ctrl+0"));
    ui->menuHomepage->addAction(openAction);

     QMenu *menu_E = ui->menuBar->addMenu("编辑(&E)");
     QAction *findAction = new QAction("&Find",this);
     QIcon icon2(":/myimages/rose.jpg");
     findAction->setIcon(icon2);
     findAction->setShortcut(QKeySequence("Ctrl+F"));
     menu_E->addAction(openAction);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QDialog *dlg = new QDialog(this);
     dlg->show();
}


//#include "mainwindow.h"

//MainWindow::MainWindow(QWidget *parent)
//    : QMainWindow(parent)
//{
//}

//MainWindow::~MainWindow()
//{

//}
