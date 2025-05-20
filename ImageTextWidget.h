/*
#ifndef IMAGETEXTWIDGET_H
#define IMAGETEXTWIDGET_H

#include <QWidget>
#include <QImage>
#include <QTextCharFormat>
#include <QLineEdit>
#include <QPushButton>
class ImageTextBox : public QWidget {
    Q_OBJECT
public:
    ImageTextBox(QWidget *parent = nullptr);
    void setImage(const QImage& image);
    void setTextFormat(const QTextCharFormat& format);
    void setTextPosition(const QPoint& pos); // 新增函数，用于设置文本位置
    QImage getImage() const;
signals:
    void imageUpdated(const QImage& image);
private slots:
    void addText();
private:
    QImage image;
    QTextCharFormat textFormat;
    QLineEdit *textInput;
    QPushButton *addButton;
    QPoint textPosition; // 新增成员变量
};

#endif // IMAGETEXTWIDGET_H
*/
/*
#ifndef IMAGETEXTWIDGET_H
#define IMAGETEXTWIDGET_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QImage>
#include <QTextCursor>
#include <QTextDocument>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QFocusEvent>
#include <QTextCharFormat>

class ImageTextWidget : public QGraphicsItem
{
public:
    ImageTextWidget(QImage *image, QGraphicsScene *scene, QGraphicsItem *parent = nullptr);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void focusOutEvent(QFocusEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

    void setTextFormat(const QTextCharFormat &format);
    void setPosition(const QPointF &pos);

private:
    QImage *targetImage;
    QTextDocument document;
    QTextCursor cursor;
    QTextCharFormat currentFormat;
    bool isResizing;
    QPointF resizeStartPos;
    QPointF initialPos;
    QGraphicsScene *parentScene;

    // 将文本绘制到目标图像上
    void drawTextOnImage();
};

#endif // IMAGETEXTWIDGET_H
*/
