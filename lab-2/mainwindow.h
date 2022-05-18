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
    vector <Car> cars;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void FindCar();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
