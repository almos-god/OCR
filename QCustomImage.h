#ifndef QCUSTOMIMAGE_H
#define QCUSTOMIMAGE_H

#include <QImage>
#include <QColor>
#include <QPainter>
#include <QGraphicsObject>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <size_dialog.h>
#include <qstack.h>
#include <QQueue>
#include <QWidget>
#include <QVector>
#include <QFileDialog>
#include <QMessageBox>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <map>
#include "enum_mappings.h"

class QCustomImage : public QGraphicsObject
{
    Q_OBJECT

public:
    explicit QCustomImage(int width = 800, int height = 600);

    // 图像管理
    int addimage();
    int undoimage();
    int redoimage();

    // 设置属性
    void set_expansion(bool expand);
    void imageredraw();
    void changefunction(all_my_function function);
    void changegraphics(all_my_graphics graphics);
    void setforegroundColor(QColor color, bool foregroundcolor);
    QColor getforegroundColor();
    void setbackgroundColor(QColor color, bool backgroundcolor);
    QColor getbackgroundColr();
    void setborderWidth(int width);
    void setimage(QImage newimage);
    void doScaling(qreal factor);

    // 图形绘制方法
    void painting_basic(QGraphicsSceneMouseEvent *event, int mouse);
    void painting_straight_line(QGraphicsSceneMouseEvent *event, int mouse);
    void painting_right_circle(QGraphicsSceneMouseEvent *event, int mouse);
    void painting_ellipse(QGraphicsSceneMouseEvent *event, int mouse);
    void painting_isosceles_triangle(QGraphicsSceneMouseEvent *event, int mouse);
    void painting_right_triangle(QGraphicsSceneMouseEvent *event, int mouse);
    void painting_right_rectangle(QGraphicsSceneMouseEvent *event, int mouse);
    void painting_rounded_rectangle(QGraphicsSceneMouseEvent *event, int mouse);
    void painting_diamond(QGraphicsSceneMouseEvent *event, int mouse);
    void painting_hexagon(QGraphicsSceneMouseEvent *event, int mouse);
    void painting_four_pointed_star(QGraphicsSceneMouseEvent *event, int mouse);
    void painting_five_pointed_star(QGraphicsSceneMouseEvent *event, int mouse);
    void painting_six_pointed_star(QGraphicsSceneMouseEvent *event, int mouse);
    void painting_lightning(QGraphicsSceneMouseEvent *event, int mouse);
    void painting_left(QGraphicsSceneMouseEvent *event, int mouse);
    void painting_right(QGraphicsSceneMouseEvent *event, int mouse);
    void painting_top(QGraphicsSceneMouseEvent *event, int mouse);
    void painting_bottom(QGraphicsSceneMouseEvent *event, int mouse);
    void painting_rounded_rectangle_annotation(QGraphicsSceneMouseEvent *event, int mouse);
    void painting_cloud_annotation(QGraphicsSceneMouseEvent *event, int mouse);
    void printing_circle_annotation(QGraphicsSceneMouseEvent *event, int mouse);

    // 图像处理功能
    void size();
    void color_extractor(QGraphicsSceneMouseEvent *event, int mouse);
    void my_erase(QGraphicsSceneMouseEvent *event, int mouse);
    void fill(QGraphicsSceneMouseEvent *event, int mouse);
    void crop(QGraphicsSceneMouseEvent *event, int mouse);
    void right_rotation();
    void left_rotation();
    void flip_vertically();
    void flip_horizontally();

    // 功能选择
    void choice_painting(QGraphicsSceneMouseEvent *event, int mouse);
    void choice_function(QGraphicsSceneMouseEvent *event, int mouse);

    // 图像操作
    void changeImageSize(int newWidth, int newHeight);
    void drawPoint(QPointF point, QColor color, int diameter);
    void drawLine(QPointF startPoint, QPointF endPoint, QColor color, int width);
    void setGeometry(int x, int y);

    // 获取属性
    int getwidth();
    int getheight();
    QImage getImage() const;

    // QGraphicsItem 重写
    QPainterPath shape() const override;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option = nullptr,
               QWidget *widget = nullptr) override;

    // 辅助函数
    void updateRect();
    bool isPointNearLine(const QPointF &point, const QLineF &line, qreal threshold = 10.0) const;

signals:
    void change_color_signals(const QColor& c);
    void refresh_signals();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
    // 显示图像
    QImage image;
    // 实际图像
    QImage originalImage;
    // 备份图形
    QImage backup;
    // 前景色
    QColor foregroundColor;
    // 背景色
    QColor backgroundColor;
    // 线宽
    int borderWidth;
    // 位置范围
    QRectF rect;
    // 宽
    int width;
    // 高
    int height;
    // 缩放比例
    qreal image_factor;

    // Graphics function map
    std::map<all_my_graphics, void (QCustomImage::*)(QGraphicsSceneMouseEvent *, int)> graphicsFunctionMap;

    // Function map
    std::map<all_my_function, void (QCustomImage::*)(QGraphicsSceneMouseEvent *, int)> functionFunctionMap;

    // 功能变量
    all_my_function function1;
    // 图形变量
    all_my_graphics graphics1;
    // 涂改位置
    QPointF erase_location;
    // 裁剪矩形
    QRect r;
    // 缓存文件
    QVector<QImage> buffer;
    // 当前文件
    int now;

    QLine up_line, down_line, left_line, right_line;
    int offset;
    bool expand;
    QPointF Point1;
    QPointF Point2;
    qreal up_move_component = 0;
    qreal down_move_component = 0;
    qreal left_move_component = 0;
    qreal right_move_component = 0;
    int selectedLine = 0;

    // 初始化函数
    void initializeGraphicsFunctionMap();
    void initializeFunctionFunctionMap();
};

#endif // QCUSTOMIMAGE_H
