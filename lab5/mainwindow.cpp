#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "car.h"
#include "csvreader.h"
#include <jsonreader.h>

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
     CSVUploader newfile("fileName");
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
        if (csv.is_open()){

            //Чтение из файла в вектор
            cars = csv.readAll();
        }

    }
    if(fileName.right(1) == QString::fromStdString("n")){
        JsonReader json(fileName);
        if (json.is_open()){

            //Чтение из файла в вектор
            cars = json.readAll();
        }



    }

    // сортировка
        std::sort(cars.begin(), cars.end(), [](const Car &c1, const Car &c2){
            return c1.n < c2.n;;
        });

}
