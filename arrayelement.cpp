#include "arrayelement.h"

#include <QPainter>

ArrayElement::ArrayElement(int x, int y, qreal width, qreal height)
{
    this->x = x+1;
    this->y = y+1;
    this->height = (int)height;
    rect = QRectF((x)*(2 * width), 0, width, this->height);
    rec = rect;
    setHeight(qrand() % this->height);
}

QRectF ArrayElement::boundingRect() const
{
    return rect;
}

void ArrayElement::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->eraseRect(rect);

    QBrush brush(Qt::cyan);

    if(bSelected)
    {
        brush = Qt::red;
    }
    else
    {
        brush = Qt::black;
    }

    painter->fillRect(rec, brush);
    painter->drawRect(rec);
}

void ArrayElement::setSelected(bool cond)
{
    bSelected = cond;
    update();
}

void ArrayElement::setHeight(int height)
{
    this->height = height;
    rec.setHeight(height);
    //setSelected(true);
    update();
}

int ArrayElement::getHeight()
{
    return height;
}

void ArrayElement::swap(ArrayElement* &A)
{
    int temp = getHeight();
    setHeight(A->getHeight());
    A->setHeight(temp);
}
