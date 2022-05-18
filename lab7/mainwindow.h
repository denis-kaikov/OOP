#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "QString"
#include "car.h"
#include <abstractreader.h>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QString fileName;


public:
    vector <Car> cars;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void read(AbstractReader& reader);
public slots:
    void FindCar();
    void AddCar();
    void UploadCar();

private slots:
    void on_toolButton_clicked();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
