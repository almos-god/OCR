#ifndef CUSTOMSCENE_H
#define CUSTOMSCENE_H

#include <QGraphicsScene>
#include <QPainter>
#include <QGraphicsitem>
class CustomScene : public QGraphicsScene
{
public:
    CustomScene(QObject *parent = nullptr) : QGraphicsScene(parent) {}

protected:
    void drawBackground(QPainter *painter, const QRectF &rect) override
    {
        QGraphicsScene::drawBackground(painter, rect);

        foreach (QGraphicsItem *item, items()) {
            if (item->isVisible()) {
                QRectF itemRect = item->boundingRect();
                qreal x = itemRect.x();
                qreal y = itemRect.y();
                qreal w = itemRect.width();
                qreal h = itemRect.height();

                int m=20;
                //int ply=5;
                // 绘制四条直线
                painter->setPen(QPen(Qt::black, 5));
                painter->drawLine(x+w/4, y-m, x + w/4*3, y-m);
                painter->drawLine(x+w+m,y+h/4,x+w+m,y+h/4*3);
                painter->drawLine(x+w/4,y+m+h,x+w/4*3,y+m+h);
                painter->drawLine(x-m,y+h/4,x-m,y+h/4*3);

                // 绘制四个圆点
                painter->setPen(QPen(Qt::black));
                painter->setBrush(Qt::black);
                painter->drawEllipse(QPointF(x-m, y-m), 5, 5);
                painter->drawEllipse(QPointF(x + w+m, y-m), 5, 5);
                painter->drawEllipse(QPointF(x + w+m, y + h+m), 5, 5);
                painter->drawEllipse(QPointF(x-m, y + h+m), 5, 5);
            }
        }
    }
};
#endif // CUSTOMSCENE_H
