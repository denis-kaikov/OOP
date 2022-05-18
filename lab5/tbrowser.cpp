#include "tbrowser.h"

TBrowser::TBrowser(QWidget* parent):QTextBrowser(parent)
{

}

void TBrowser::GreenText(QString text)

{
    auto color = this->textColor();
    this->setTextColor(Qt::green);
    this->append(text);
    this->setTextColor(color);
}


void TBrowser::RedText(QString text)

{
    auto color = this->textColor();
    this->setTextColor(Qt::red);
    this->append(text);
    this->setTextColor(color);
}
