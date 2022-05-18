#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "QString"
#include "car.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    vector <Car> cars;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void FindCar();
    void AddCar();
    void UploadCar();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
