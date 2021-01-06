#ifndef ARRAYELEMENT_H
#define ARRAYELEMENT_H

#include <QGraphicsItem>

class ArrayElement : public QGraphicsItem
{
public:
    ArrayElement(int x, int y, qreal width, qreal height);

    QRectF boundingRect() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

    void setSelected(bool cond);

    void setHeight(int height);

    int getHeight();

    void swap(ArrayElement*& A);

//    int operator=(ArrayElement*& A);

//    bool operator>(ArrayElement*& A);

private:

    int x;
    int y;

    QRectF rect;
    QRectF rec;

    int height = 30;

    bool bSelected = false;
};

#endif // ARRAYELEMENT_H
