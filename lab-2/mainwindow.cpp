#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "car.h"
#include "csvreader.h"
#include "QString"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    CSVReader csv("C:\\Users\\kaiko\\Desktop\\prog\\lab1\\cars.csv");
    if(csv.is_open())
    {
      cars = csv.readAll();

    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::FindCar()
{
    bool flag=0;
    for (const auto &c: cars){
        if(ui->editSearch->text().isEmpty())
        {
            flag=1;
            ui->textBrowser->append(QString::number(c.n)+ ", "+QString::fromStdString(string(c.model))+","+QString::fromStdString(to_string(c.color))+", "+QString::number(c.year));
        }
        else if(c.model==ui->editSearch->text().toStdString())
        {
        ui->textBrowser->append(QString::number(c.n)+ ", "+QString::fromStdString(string(c.model))+","+QString::fromStdString(to_string(c.color))+", "+ QString::number(c.year));
        flag=1;
        }
    }
    if(!flag){
        ui->textBrowser->append("нет такой записи");
    }
}
