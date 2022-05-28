#ifndef FIGURES_H
#define FIGURES_H
#include <array>
#include <QPainter>
#include <Qpoint>
struct Figures
{
    virtual ~Figures(){};
    virtual void draw(QPainter &painter)=0;

};


struct Cirle: public Figures
{

    Cirle(QPoint center, int radius ): center_(center), radius_(radius){}
    QPoint center_;
    int radius_;
    void draw(QPainter &painter) override{
      painter.drawEllipse(center_, radius_,radius_);

    };
};

struct Trig: public Figures
{

    Trig(QPoint a,QPoint b, QPoint c);
    std::array<QPoint, 3> vects;
    void draw(QPainter &painter) override{
    painter.drawLine(vects.at(0),vects.at(1));
    painter.drawLine(vects.at(1),vects.at(2));
    painter.drawLine(vects.at(0),vects.at(2));
    };
};

struct Square: public Figures
{

    Square(QPoint center, int hight): center_(center), hight_(hight){}
    QPoint center_;
    int hight_;
    void draw(QPainter &painter) override{
      painter.drawRect(center_.x()-hight_/2,center_.y()-hight_/2,hight_,hight_);

    };
};
#endif // FIGURES_H
