#ifndef TBROWSER_H
#define TBROWSER_H
#include <QMainWindow>

#include "mainwindow.h"
#include <QTextBrowser>

namespace Ui { class MainWindow; }
class TBrowser: public QTextBrowser
{
public:
    TBrowser(QWidget* parent);

    void GreenText(QString text);
    void RedText(QString text);
};

#endif // TBROWSER_H
