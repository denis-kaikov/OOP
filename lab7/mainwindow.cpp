#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "car.h"
#include "csvreader.h"
#include <jsonreader.h>
#include <iostream>

#include "csvuploader.h"
#include "tbrowser.h"
#include <QFileDialog>
#include "QString"

using namespace std;
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

void MainWindow::FindCar()
{
    ui->textBrowser->clear();
    ui->textBrowser->GreenText("Поиск..");

    bool flag=0;
    for (auto &c: cars){
        if(ui->editSearch->text().isEmpty()){
            flag=1;
            ui->textBrowser->append(c.to_string());
        }else if(c.model==ui->editSearch->text()){
        ui->textBrowser->append(c.to_string());
        flag=1;
        }
    }
    if(!flag)
           ui->textBrowser->RedText("Нет такой записи!");
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
     CSVUploader newfile(fileName);
     if(newfile.is_open())
     {
       newfile.addAll(cars);

     }
}

void MainWindow::on_toolButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                      "/home",
                                                      tr("Base (*.csv *.json)"));
    this->fileName= fileName;
    //Открытие файла
    if(fileName.right(1) == QString::fromStdString("v")){
        CSVReader csv(fileName);
        read(csv);

    }
    if(fileName.right(1) == QString::fromStdString("n")){
        JsonReader json(fileName);
        read(json);
    }

    // сортировка
        std::sort(cars.begin(), cars.end());

}





void MainWindow::read(AbstractReader& reader){

    if (reader.is_open()){
        //Чтение из файла в вектор
        reader.count_line=0;

        //cars = reader.readAll();
        cars.clear();
        Car car;
        while(true){
        reader.count_line++;
        try {
        if(!(reader >> car))break;
        cout << car << endl;
        cars.push_back(car);
        }  catch (CSVException &c) {
            std::cerr<< "Error in line " << c.GetLine()<<endl;
        }
        }

    }

}
