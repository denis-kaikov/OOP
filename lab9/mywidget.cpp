#include "mywidget.h"
#include <Qpainter>

MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
    figures.push_back(new Cirle({30, 40}, 20));
    figures.push_back(new Square({30, 40}, 20));
    figures.push_back(new Trig({30, 40},{390, 50},{100, 500} ));
}
MyWidget::~MyWidget(){
  for (auto & f: figures)  {
      delete f;
  }
}
void MyWidget::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.setPen(Qt::blue);
    for (const auto& f: figures){
        f->draw(painter);
    }

}
