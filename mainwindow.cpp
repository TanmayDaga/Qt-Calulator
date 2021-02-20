#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ButtonClicked(int num)
{
    ui->lineEdit->setText(QString(ui->lineEdit->displayText()+QString(num)));
}

void MainWindow::on_pushButton_3_clicked()
{
    ButtonClicked(ui->pushButton_3->text().toInt());
}
