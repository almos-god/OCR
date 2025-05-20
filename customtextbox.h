#ifndef CUSTOMTEXTBOX_H
#define CUSTOMTEXTBOX_H
/*
#include <QGraphicsItem>
#include <QPainter>
#include <QTextDocument>
#include <QTextCursor>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QFocusEvent>
#include <QTextCharFormat>
#include <QImage>
#include <QGraphicsItem>
#include <QTextDocument> // 添加这一行
#include <QGraphicsScene> // 添加这一行
#include <QTextBlock> // 新增这一行
#include <QGraphicsTextItem> // 确保包含这个头文件
class CustomTextBox : public QGraphicsItem
{
    Q_OBJECT
public:
    CustomTextBox(QImage *targetImage, QGraphicsItem *parent = nullptr);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void focusOutEvent(QFocusEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

    void setTextFormat(const QTextCharFormat &format);

private:
    QTextDocument document;
    QTextCursor cursor;
    QImage *image;
    bool isResizing;
    QPointF resizeStartPos;
    QTextCharFormat currentFormat;
};
*/
#endif // CUSTOMTEXTBOX_H
