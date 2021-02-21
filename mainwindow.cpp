#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QString>
#include<QJSEngine>
#include<QJSValue>
#include<QFile>
#include<QFileInfo>
#include<QIODevice>
#include<QTextStream>
#include<QMessageBox>


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



void MainWindow::on_pushButton_3_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->displayText()+"9");
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->displayText()+"8");
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->displayText()+"7");
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->displayText()+"6");
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->displayText()+"5");
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->displayText()+"4");
}

void MainWindow::on_pushButton_12_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->displayText()+"3");
}

void MainWindow::on_pushButton_11_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->displayText()+"2");
}

void MainWindow::on_pushButton_10_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->displayText()+"1");
}

void MainWindow::on_pushButton_16_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->displayText()+"0");
}

void MainWindow::on_pushButton_15_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->displayText()+".");
}

void MainWindow::on_pushButton_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->displayText()+"+");
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->displayText()+"-");
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->displayText()+"*");
}

void MainWindow::on_pushButton_13_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->displayText()+"/");
}



void MainWindow::on_pushButton_14_clicked()
{
    QJSEngine myEngine;
    QString ques = ui->lineEdit->displayText();
    QJSValue expr = myEngine.evaluate(ques);
    if (expr.isError()){
        ui->lineEdit->setText("Error");
    }
    else{
        ui->lineEdit->setText(expr.toString());

    }

    QString filename = "/Users/tanmay06daga/Documents/qtprojs/Calculator/history.txt";
    QFile file(filename);
    file.open(QIODevice::Append);
    QTextStream stream(&file);
    stream << ques << " = " << expr.toString()<<endl;
    file.close();
}

void MainWindow::on_pushButton_18_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->displayText()+"(");
}

void MainWindow::on_pushButton_19_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->displayText()+")");
}

void MainWindow::on_pushButton_17_clicked()
{
    ui->lineEdit->setText(QString());
}


void MainWindow::on_pushButton_20_clicked()
{
    QFile file("/Users/tanmay06daga/Documents/qtprojs/Calculator/history.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream stream(&file);
    QString his;
    while(! stream.readLine().isNull()){
        his.append(stream.readLine()+"\n");
    }
    QMessageBox::information(this,QString("History"),his);
}
