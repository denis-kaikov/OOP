#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "car.h"
#include "csvreader.h"
#include "QString"
#include "csvuploader.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    CSVReader csv("C:\\Users\\kaiko\\Desktop\\prog\\lab3\\newcars.csv");
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
        if(ui->editSearch->text().isEmpty()){
            flag=1;
            ui->textBrowser->append(QString::number(c.n)+ ","+c.model+","+QString::fromStdString(to_string(c.color))+", "+ QString::number(c.year));
        }else if(c.model==ui->editSearch->text()){
        ui->textBrowser->append(QString::number(c.n)+ ","+c.model+","+QString::fromStdString(to_string(c.color))+", "+ QString::number(c.year));
        flag=1;
        }
    }
    if(!flag)
           ui->textBrowser->append("нет такой записи");
}
// static_cast<color>(comboColor->currentIndex())
void MainWindow::AddCar()
{

        Car car;
        car.n=ui->editID->text().toInt();
        car.model=ui->editModel->text();
        car.color=static_cast<Color>(ui->comboColor->currentIndex());
        car.year=ui->editYear->text().toInt();
        cars.push_back(car);
}
void MainWindow::UploadCar(){
     CSVUploader newfile("C:\\Users\\kaiko\\Desktop\\prog\\lab3\\newcars.csv");
     if(newfile.is_open())
     {
       newfile.addAll(cars);

     }
}
