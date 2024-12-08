#ifndef QCUSTOMIMAGE_H
#define QCUSTOMIMAGE_H

#include <QImage>
#include <QColor>
#include <QPainter>
#include <QGraphicsObject>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsView>
#include <CustomTextBox.h>
#include <QGraphicsItem>
#include <QGraphicsItem>
#include <size_dialog.h>
#include <qstack.h>
#include <QQueue>
#include <QWidget>
#include <QVector>
#include <QFileDialog>
#include <QMessageBox>
#include <cstdlib> // 添加这个头文件以使用 rand() 和 srand()
#include <ctime>   // 添加这个头文件以使用 time()
#include <iostream>
enum all_my_function{
    painting, size,color_extractor, my_erase, fill, crop
};
enum all_my_graphics{
    basic, straight_line, right_circle, ellipse, isosceles_triangle, right_triangle, right_rectangle,
    rounded_rectangle,diamond, hexagon, four_pointed_star, five_pointed_star, six_pointed_star,
    lightning, left,right, top, bottom,rounded_rectangle_annotation, cloud_annotation, circle_annotation
};

class QCustomImage : public QGraphicsObject
{
     Q_OBJECT
public:
    QCustomImage(int width = 800, int height = 600)
        : rect(QRectF(0, 0, width, height))
    {
        this->width = width;
        this->height = height;
        // 图像初始化设置为灰色
        originalImage = QImage(width, height, QImage::Format_ARGB32);
        originalImage.fill(Qt::white);

        image = QImage(width, height, QImage::Format_ARGB32);
        image.fill(Qt::white);
        foregroundColor = QColor(0, 0, 0);
        backgroundColor = QColor(0, 0, 0);
        borderWidth = 1;
        image_factor=1;
        function1=painting;
        graphics1=basic;

        erase_location.setX(-100);
        erase_location.setY(-100);
        r.setTopLeft(QPoint(1000,1000));
        rect.setRect(0,0,100,60);
        now=0;
        buffer.reserve(50);
        buffer.push_back(originalImage);
    }
    //添加新文件
    int addimage()
    {
        if (now == 49)
        {
            for (int i = 0; i < 49; i++)
            {
                buffer[i] = buffer[i + 1]; // 每个元素向前移动一位
            }
            buffer.pop_back();
            now--;
        }
        buffer.push_back(originalImage);
        width=originalImage.width();
        height=originalImage.height();
        rect.setSize(QSizeF(width, height));
        qDebug() << "纳入新文件";
        now++;
        return 0;
    }
    //撤销
    int undoimage()
    {
        if(now!=0)
        {
            originalImage=buffer[--now];
            width=originalImage.width();
            height=originalImage.height();
            rect.setSize(QSizeF(width, height));
            int newWidth = static_cast<int>(this->width * image_factor);
            int newHeight = static_cast<int>(this->height * image_factor);
            image = originalImage.scaled(newWidth, newHeight, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
            update();
            emit refresh_signals();
            qDebug()<<"前一个文件";
            return 0;
        }
        return -1;
    }
    //重做
    int redoimage()
    {
        if(now < buffer.size()-1&&now<49)
        {
            originalImage = buffer[++now];
            width = originalImage.width();
            height = originalImage.height();
            rect.setSize(QSizeF(width, height));
            int newWidth = static_cast<int>(this->width * image_factor);
            int newHeight = static_cast<int>(this->height * image_factor);
            image = originalImage.scaled(newWidth, newHeight, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
            update();
            emit refresh_signals();
            qDebug()<<"后一个文件";
            return 0;
        }
        return -1;
    }
    //保存
    void imageredraw()
    {
        image=image.scaled(width*image_factor, height*image_factor, Qt::IgnoreAspectRatio, Qt::SmoothTransformation); // Update the image reference
    }
    //改变功能
    void changefunction(all_my_function function)
    {
        this->function1=function;
        if(this->function1==all_my_function::size)
        {
            size();
        }
    }
    //改变图形
    void changegraphics(all_my_graphics graphics)
    {
        this->graphics1=graphics;
        this->function1=painting;
    }
    void setforegroundColor(QColor color,bool foregroundcolor)
    {
        foregroundColor = color;
        if(foregroundcolor==false)
            foregroundColor.setAlpha(0); // 设置为透明
        else
            foregroundColor.setAlpha(255); //
        qDebug() << "修改前景色";
    }
    QColor getforegroundColor()
    {
        return foregroundColor;
    }
    void setbackgroundColor(QColor color,bool backgroundcolor)
    {
        backgroundColor = color;
        if(backgroundcolor==false)
            backgroundColor.setAlpha(0); // 设置为透明
        else
            backgroundColor.setAlpha(255); //
        qDebug() << "修改背景色";
    }
    QColor getbackgroundColr()
    {
        return backgroundColor;
    }
    void setborderWidth(int width)
    {
        borderWidth = width;
    }
    void setimage(QImage newimage)
    {
        this->originalImage = newimage;
        buffer.clear();
        now=0;
        buffer.push_back(originalImage);
        width = originalImage.width();
        height = originalImage.height();
        int newWidth = static_cast<int>(this->width * image_factor);
        int newHeight = static_cast<int>(this->height * image_factor);

        // 添加错误处理，检查缩放是否成功
        QImage scaledImage = newimage.scaled(newWidth, newHeight, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        if (!scaledImage.isNull()) {
            this->image = scaledImage;
            rect.setSize(QSizeF(newWidth, newHeight));
            update();
            emit refresh_signals();
        } else {
            // 处理缩放失败的情况，比如显示错误信息
            qDebug() << "图像缩放失败";
            // 可以选择显示默认图像或者采取其他措施
        }
    }
    // 进行缩放
    void doScaling(qreal factor)
    {
        if (!originalImage.isNull())
        {
            image_factor=factor;
            int newWidth = static_cast<int>(this->width* factor);
            int newHeight = static_cast<int>(this->height* factor);
            image=originalImage.scaled(newWidth,newHeight,Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
            // 更新矩形尺寸
            rect.setSize(QSizeF(newWidth, newHeight));
            emit refresh_signals();

        }
    }
    void painting_basic(QGraphicsSceneMouseEvent *event,int mouse)
    {
        event->accept();
        if(mouse==1)
        {
            QPointF point = event->scenePos();

            // 获取当前图像和原始图像的尺寸
            QSize currentSize = image.size();
            QSize originalSize = originalImage.size();

            // 计算当前图像和原始图像的中心点坐标
            QPointF currentCenter(currentSize.width() / 2.0, currentSize.height() / 2.0);
            QPointF originalCenter(originalSize.width() / 2.0, originalSize.height() / 2.0);

            // 计算鼠标点击位置距离当前图像中心点的距离
            QPointF distanceToCurrentCenter = point - currentCenter;

            // 将距离除以 image_factor
            QPointF adjustedDistance(distanceToCurrentCenter.x() / image_factor, distanceToCurrentCenter.y() / image_factor);

            // 计算真实坐标，即减去原始图像中心点坐标
            QPointF realPoint = adjustedDistance + originalCenter;
            drawPoint(realPoint, foregroundColor, borderWidth);

        }
        else if(mouse==2)
        {

            QPointF startPoint, endPoint;
            startPoint = event->lastScenePos();
            endPoint = event->scenePos();

            // 获取当前图像和原始图像的尺寸
            QSize currentSize = image.size();
            QSize originalSize = originalImage.size();

            // 计算当前图像和原始图像的中心点坐标
            QPointF currentCenter(currentSize.width() / 2.0, currentSize.height() / 2.0);
            QPointF originalCenter(originalSize.width() / 2.0, originalSize.height() / 2.0);

            // 计算鼠标移动起始位置距离当前图像中心点的距离
            QPointF startDistanceToCurrentCenter = startPoint - currentCenter;
            // 将距离除以 image_factor
            QPointF startAdjustedDistance(startDistanceToCurrentCenter.x() / image_factor, startDistanceToCurrentCenter.y() / image_factor);
            // 计算真实起始坐标，即减去原始图像中心点坐标
            QPointF realStartPoint = startAdjustedDistance + originalCenter;

            // 计算鼠标移动结束位置距离当前图像中心点的距离
            QPointF endDistanceToCurrentCenter = endPoint - currentCenter;
            // 将距离除以 image_factor
            QPointF endAdjustedDistance(endDistanceToCurrentCenter.x() / image_factor, endDistanceToCurrentCenter.y() / image_factor);
            // 计算真实结束坐标，即减去原始图像中心点坐标
            QPointF realEndPoint = endAdjustedDistance + originalCenter;

            drawLine(realStartPoint, realEndPoint, foregroundColor, borderWidth);
        }
        else if(mouse==3)
        {
            addimage();
        }
    }
    void painting_straight_line(QGraphicsSceneMouseEvent *event,int mouse)
    {
        static QPointF startPoint;

        if (mouse == 1)
        {
            startPoint = event->pos() / image_factor;  // 将坐标除以 image_factor
            backup = originalImage;
        }
        else if (mouse == 2)
        {
            QPointF endPoint = event->scenePos() / image_factor;  // 将坐标除以 image_factor
            originalImage=backup;
            drawLine(startPoint, endPoint, foregroundColor, borderWidth);
            //update();
        } else if (mouse == 3) {
            backup=originalImage;
            addimage();
        }
        qDebug()<<"画直线";
    }
    void painting_right_circle(QGraphicsSceneMouseEvent *event, int mouse)
    {
        static QPointF startPoint;
        static QImage tempImage;

        if (mouse == 1)
        {
            startPoint = event->pos()/image_factor;
            backup = originalImage;
        }
        else if (mouse == 2)
        {
            QPointF endPoint = event->scenePos()/image_factor;
            originalImage = backup;

            // 计算边长
            qreal width = qAbs(endPoint.x() - startPoint.x());
            qreal height = qAbs(endPoint.y() - startPoint.y());
            qreal sideLength = qMin(width, height);

            // 创建临时图像并绘制矩形和圆
            tempImage = QImage(sideLength + borderWidth * 2, sideLength + borderWidth * 2, QImage::Format_ARGB32);
            tempImage.fill(Qt::transparent);
            QPainter painter(&tempImage);

            QPen pen = QPen(foregroundColor, borderWidth);
            // 改为实线
            pen.setStyle(Qt::SolidLine);
            painter.setPen(pen);

            qreal radius = sideLength / 2;
            // 设置填充颜色为 backgroundColor
            painter.setBrush(backgroundColor);
            painter.drawEllipse(radius - radius + borderWidth / 2, radius - radius + borderWidth / 2, radius * 2, radius * 2);

            // 将临时图像绘制到原始图像上，相对于 startPoint 的位置
            QPainter oriPainter(&originalImage);
            oriPainter.drawImage(startPoint.x(), startPoint.y(), tempImage);

            //update();
        }
        else if (mouse == 3)
        {
            backup = originalImage;
            addimage();
            update();
        }
        qDebug() << "画正圆（现在是随矩形边长变化且位置在左上角与边相切的圆）";
    }
    void painting_ellipse(QGraphicsSceneMouseEvent *event, int mouse)
    {
        static QPointF startPoint;
        static QImage tempImage;

        if (mouse == 1)
        {
            startPoint = event->pos()/image_factor;
            backup = originalImage;
        }
        else if (mouse == 2)
        {
            QPointF endPoint = event->pos()/image_factor;
            originalImage = backup;

            // 计算矩形范围
            qreal left = qMin(startPoint.x(), endPoint.x());
            qreal top = qMin(startPoint.y(), endPoint.y());
            qreal right = qMax(startPoint.x(), endPoint.x());
            qreal bottom = qMax(startPoint.y(), endPoint.y());

            qreal width = right - left;
            qreal height = bottom - top;

            // 创建临时图像并绘制椭圆
            tempImage = QImage(width+borderWidth * 2, height+borderWidth * 2, QImage::Format_ARGB32);
            tempImage.fill(Qt::transparent);
            QPainter painter(&tempImage);

            QPen pen = QPen(foregroundColor, borderWidth);
            pen.setStyle(Qt::SolidLine);
            painter.setPen(pen);

            // 设置画刷为背景颜色，用于填充椭圆
            painter.setBrush(backgroundColor);

            // 绘制内切椭圆
            painter.drawEllipse(0+borderWidth / 2, 0+borderWidth / 2, width, height);

            // 将临时图像绘制到原始图像上，相对于 startPoint 的位置
            QPainter oriPainter(&originalImage);
            oriPainter.drawImage(left, top, tempImage);

            //update();
        }
        else if (mouse == 3)
        {
            backup = originalImage;
            addimage();
        }
        qDebug() << "画椭圆";
    }
    void painting_isosceles_triangle(QGraphicsSceneMouseEvent *event, int mouse)
    {
        static QPointF startPoint;
        static QImage tempImage;

        if (mouse == 1)
        {
            startPoint = event->pos()/image_factor;
            backup = originalImage;
        }
        else if (mouse == 2)
        {
            QPointF endPoint = event->pos()/image_factor;
            originalImage = backup;

            // 计算矩形范围
            qreal left = qMin(startPoint.x(), endPoint.x());
            qreal top = qMin(startPoint.y(), endPoint.y());
            qreal right = qMax(startPoint.x(), endPoint.x());
            qreal bottom = qMax(startPoint.y(), endPoint.y());

            qreal width = right - left;
            qreal height = bottom - top;

            // 创建临时图像并绘制等腰三角形
            tempImage = QImage(width + borderWidth * 2, height + borderWidth * 2, QImage::Format_ARGB32);
            tempImage.fill(Qt::transparent);
            QPainter painter(&tempImage);

            QPen pen = QPen(foregroundColor, borderWidth);
            pen.setStyle(Qt::SolidLine);
            painter.setPen(pen);

            // 设置画刷为背景颜色，用于填充三角形
            painter.setBrush(backgroundColor);

            QPointF trianglePoints[3];
            trianglePoints[0] = QPointF(width / 2 + borderWidth / 2, borderWidth / 2);
            trianglePoints[1] = QPointF(borderWidth / 2, height + borderWidth / 2);
            trianglePoints[2] = QPointF(width + borderWidth / 2, height + borderWidth / 2);

            painter.drawPolygon(trianglePoints, 3);

            // 将临时图像绘制到原始图像上，相对于 startPoint 的位置
            QPainter oriPainter(&originalImage);
            oriPainter.drawImage(left, top, tempImage);

            //update();
        }
        else if (mouse == 3)
        {
            backup = originalImage;
            addimage();
        }
        qDebug() << "画等腰三角形";
    }
    void painting_right_triangle(QGraphicsSceneMouseEvent *event, int mouse)
    {
        static QPointF startPoint;
        static QImage tempImage;

        if (mouse == 1)
        {
            startPoint = event->pos()/image_factor;
            backup = originalImage;
        }
        else if (mouse == 2)
        {
            QPointF endPoint = event->pos()/image_factor;
            originalImage = backup;

            // 计算矩形范围
            qreal left = qMin(startPoint.x(), endPoint.x());
            qreal top = qMin(startPoint.y(), endPoint.y());
            qreal right = qMax(startPoint.x(), endPoint.x());
            qreal bottom = qMax(startPoint.y(), endPoint.y());

            qreal width = right - left;
            qreal height = bottom - top;

            // 创建临时图像并绘制直角三角形
            tempImage = QImage(width + borderWidth * 2, height + borderWidth * 2, QImage::Format_ARGB32);
            tempImage.fill(Qt::transparent);
            QPainter painter(&tempImage);

            QPen pen = QPen(foregroundColor, borderWidth);
            pen.setStyle(Qt::SolidLine);
            painter.setPen(pen);

            // 设置画刷为背景颜色，用于填充三角形
            painter.setBrush(backgroundColor);

            QPointF trianglePoints[3];
            trianglePoints[0] = QPointF(borderWidth / 2, height + borderWidth / 2);
            trianglePoints[1] = QPointF(width + borderWidth / 2, height + borderWidth / 2);
            trianglePoints[2] = QPointF(width + borderWidth / 2, borderWidth / 2);

            painter.drawPolygon(trianglePoints, 3);

            // 将临时图像绘制到原始图像上，相对于 startPoint 的位置
            QPainter oriPainter(&originalImage);
            oriPainter.drawImage(left, top, tempImage);

            //update();
        }
        else if (mouse == 3)
        {
            backup = originalImage;
            addimage();
        }
        qDebug() << "画直角三角形";
    }
    void painting_right_rectangle(QGraphicsSceneMouseEvent *event, int mouse)
    {
        static QPointF startPoint;
        static QImage tempImage;

        if (mouse == 1)
        {
            startPoint = event->pos()/image_factor;
            backup = originalImage;
        }
        else if (mouse == 2)
        {
            QPointF endPoint = event->pos()/image_factor;
            originalImage = backup;

            // 计算矩形范围
            qreal left = qMin(startPoint.x(), endPoint.x());
            qreal top = qMin(startPoint.y(), endPoint.y());
            qreal right = qMax(startPoint.x(), endPoint.x());
            qreal bottom = qMax(startPoint.y(), endPoint.y());

            qreal width = right - left;
            qreal height = bottom - top;

            // 创建临时图像并绘制直角矩形
            tempImage = QImage(width + borderWidth * 2, height + borderWidth * 2, QImage::Format_ARGB32);
            tempImage.fill(Qt::transparent);
            QPainter painter(&tempImage);

            QPen pen = QPen(foregroundColor, borderWidth);
            pen.setStyle(Qt::SolidLine);
            painter.setPen(pen);

            // 设置画刷为背景颜色，用于填充矩形
            painter.setBrush(backgroundColor);

            painter.drawRect(borderWidth / 2, borderWidth / 2, width, height);

            // 将临时图像绘制到原始图像上，相对于 startPoint 的位置
            QPainter oriPainter(&originalImage);
            oriPainter.drawImage(left, top, tempImage);

           // update();
        }
        else if (mouse == 3)
        {
            backup = originalImage;
            addimage();
        }
        qDebug() << "画直角矩形";
    }
    void painting_rounded_rectangle(QGraphicsSceneMouseEvent *event, int mouse)
    {
        static QPointF startPoint;
        static QImage tempImage;

        if (mouse == 1)
        {
            startPoint = event->pos()/image_factor;
            backup = originalImage;
        }
        else if (mouse == 2)
        {
            QPointF endPoint = event->pos()/image_factor;
            originalImage = backup;

            // 计算矩形范围
            qreal left = qMin(startPoint.x(), endPoint.x());
            qreal top = qMin(startPoint.y(), endPoint.y());
            qreal right = qMax(startPoint.x(), endPoint.x());
            qreal bottom = qMax(startPoint.y(), endPoint.y());

            qreal width = right - left;
            qreal height = bottom - top;

            // 创建临时图像并绘制圆角矩形
            tempImage = QImage(width + borderWidth * 2, height + borderWidth * 2, QImage::Format_ARGB32);
            tempImage.fill(Qt::transparent);
            QPainter painter(&tempImage);

            QPen pen = QPen(foregroundColor, borderWidth);
            pen.setStyle(Qt::SolidLine);
            painter.setPen(pen);

            // 设置画刷为背景颜色，用于填充矩形
            painter.setBrush(backgroundColor);

            painter.drawRoundedRect(borderWidth / 2, borderWidth / 2, width, height, 10, 10);

            // 将临时图像绘制到原始图像上，相对于 startPoint 的位置
            QPainter oriPainter(&originalImage);
            oriPainter.drawImage(left, top, tempImage);

            //update();
        }
        else if (mouse == 3)
        {
            backup = originalImage;
            addimage();
        }
        qDebug() << "画圆角矩形";
    }
    void painting_diamond(QGraphicsSceneMouseEvent *event, int mouse)
    {
        static QPointF startPoint;
        static QImage tempImage;

        if (mouse == 1)
        {
            startPoint = event->pos()/image_factor;
            backup = originalImage;
        }
        else if (mouse == 2)
        {
            QPointF endPoint = event->pos()/image_factor;
            originalImage = backup;

            // 计算矩形范围
            qreal left = qMin(startPoint.x(), endPoint.x());
            qreal top = qMin(startPoint.y(), endPoint.y());
            qreal right = qMax(startPoint.x(), endPoint.x());
            qreal bottom = qMax(startPoint.y(), endPoint.y());

            qreal width = right - left;
            qreal height = bottom - top;

            // 创建临时图像并绘制菱形
            tempImage = QImage(width + borderWidth * 2, height + borderWidth * 2, QImage::Format_ARGB32);
            tempImage.fill(Qt::transparent);
            QPainter painter(&tempImage);

            QPen pen = QPen(foregroundColor, borderWidth);
            pen.setStyle(Qt::SolidLine);
            painter.setPen(pen);

            // 设置画刷为背景颜色，用于填充菱形
            painter.setBrush(backgroundColor);

            QPointF diamondPoints[4];
            diamondPoints[0] = QPointF(width / 2 + borderWidth / 2, borderWidth / 2);
            diamondPoints[1] = QPointF(width + borderWidth / 2, height / 2 + borderWidth / 2);
            diamondPoints[2] = QPointF(width / 2 + borderWidth / 2, height + borderWidth / 2);
            diamondPoints[3] = QPointF(borderWidth / 2, height / 2 + borderWidth / 2);

            painter.drawPolygon(diamondPoints, 4);

            // 将临时图像绘制到原始图像上，相对于 startPoint 的位置
            QPainter oriPainter(&originalImage);
            oriPainter.drawImage(left, top, tempImage);

            //update();
        }
        else if (mouse == 3)
        {
            backup = originalImage;
            addimage();
        }
        qDebug() << "画菱形";
    }
    void painting_hexagon(QGraphicsSceneMouseEvent *event, int mouse)
    {
        static QPointF startPoint;
        static QImage tempImage;

        if (mouse == 1)
        {
            startPoint = event->pos()/image_factor;
            backup = originalImage;
        }
        else if (mouse == 2)
        {
            QPointF endPoint = event->pos()/image_factor;
            originalImage = backup;

            // 计算矩形范围
            qreal left = qMin(startPoint.x(), endPoint.x());
            qreal top = qMin(startPoint.y(), endPoint.y());
            qreal right = qMax(startPoint.x(), endPoint.x());
            qreal bottom = qMax(startPoint.y(), endPoint.y());

            qreal width = right - left;
            qreal height = bottom - top;
            qreal sideLength = qMin(width, height);

            // 创建临时图像并绘制六边形
            tempImage = QImage(sideLength + borderWidth * 2, sideLength + borderWidth * 2, QImage::Format_ARGB32);
            tempImage.fill(Qt::transparent);
            QPainter painter(&tempImage);

            QPen pen = QPen(foregroundColor, borderWidth);
            pen.setStyle(Qt::SolidLine);
            painter.setPen(pen);

            // 设置画刷为背景颜色，用于填充六边形
            painter.setBrush(backgroundColor);

            qreal radius = sideLength / 2;
            qreal centerX = radius + borderWidth / 2;
            qreal centerY = radius + borderWidth / 2;
            QPointF hexagonPoints[6];
            qreal angleStep = (2 * M_PI) / 6;
            for (int i = 0; i < 6; ++i)
            {
                qreal angle = i * angleStep;
                qreal x = centerX + radius * qCos(angle);
                qreal y = centerY + radius * qSin(angle);
                QPointF point(x, y);
                if (i == 0)
                    hexagonPoints[0] = point;
                else if (i == 1)
                    hexagonPoints[1] = point;
                else if (i == 2)
                    hexagonPoints[2] = point;
                else if (i == 3)
                    hexagonPoints[3] = point;
                else if (i == 4)
                    hexagonPoints[4] = point;
                else if (i == 5)
                    hexagonPoints[5] = point;
            }

            painter.drawPolygon(hexagonPoints, 6);

            // 将临时图像绘制到原始图像上，相对于 startPoint 的位置
            QPainter oriPainter(&originalImage);
            oriPainter.drawImage(left, top, tempImage);

            //update();
        }
        else if (mouse == 3)
        {
            backup = originalImage;
            addimage();
        }
        qDebug() << "画六边形";
    }
    void painting_four_pointed_star(QGraphicsSceneMouseEvent *event, int mouse)
    {
        static QPointF startPoint;
        static QImage tempImage;

        if (mouse == 1)
        {
            startPoint = event->pos()/image_factor;
            backup = originalImage;
        }
        else if (mouse == 2)
        {
            QPointF endPoint = event->pos()/image_factor;
            originalImage = backup;

            // 计算矩形范围
            qreal left = qMin(startPoint.x(), endPoint.x());
            qreal top = qMin(startPoint.y(), endPoint.y());
            qreal right = qMax(startPoint.x(), endPoint.x());
            qreal bottom = qMax(startPoint.y(), endPoint.y());

            qreal width = right - left;
            qreal height = bottom - top;

            // 创建临时图像并绘制四角星
            tempImage = QImage(width + borderWidth * 2, height + borderWidth * 2, QImage::Format_ARGB32);
            tempImage.fill(Qt::transparent);
            QPainter painter(&tempImage);

            QPen pen = QPen(foregroundColor, borderWidth);
            pen.setStyle(Qt::SolidLine);
            painter.setPen(pen);

            // 设置画刷为背景颜色，用于填充四角星
            painter.setBrush(backgroundColor);

            // 将角度转换为弧度
            double degrees = 15.0;
            double radians = degrees * M_PI / 180.0;
            double tan15 = tan(radians);
            //double cot15 = 1.0 / tan15;

            QPointF starPoints[8];
            starPoints[0] = QPointF(width / 2 + borderWidth / 2, borderWidth / 2);
            starPoints[1] = QPointF(width/2+width *1/2*tan15 + borderWidth / 2, height*1/2-height*1/2*tan15 + borderWidth / 2);
            starPoints[2] = QPointF(width + borderWidth / 2, height / 2 + borderWidth / 2);
            starPoints[3] = QPointF(width/2+width*1/2*tan15 + borderWidth / 2, height/2+height*1/2*tan15 + borderWidth / 2);
            starPoints[4] = QPointF(width / 2 + borderWidth / 2, height + borderWidth / 2);
            starPoints[5] = QPointF(width/2-width*1/2*tan15 + borderWidth / 2, height/2+height*1/2*tan15 + borderWidth / 2);
            starPoints[6] = QPointF(borderWidth / 2, height / 2 + borderWidth / 2);
            starPoints[7] = QPointF(width/2-width*1/2*tan15 + borderWidth / 2, height/2-height*1/2*tan15 + borderWidth / 2);

            painter.drawPolygon(starPoints, 8);

            // 将临时图像绘制到原始图像上，相对于 startPoint 的位置
            QPainter oriPainter(&originalImage);
            oriPainter.drawImage(left, top, tempImage);

            //update();
        }
        else if (mouse == 3)
        {
            backup = originalImage;
            addimage();
        }
        qDebug() << "画四角星";
    }
    void painting_five_pointed_star(QGraphicsSceneMouseEvent *event, int mouse)
    {
        static QPointF startPoint;
        static QImage tempImage;

        if (mouse == 1)
        {
            startPoint = event->pos()/image_factor;
            backup = originalImage;
        }
        else if (mouse == 2)
        {
            QPointF endPoint = event->pos()/image_factor;
            originalImage = backup;

            // 计算矩形范围
            qreal left = qMin(startPoint.x(), endPoint.x());
            qreal top = qMin(startPoint.y(), endPoint.y());
            qreal right = qMax(startPoint.x(), endPoint.x());
            qreal bottom = qMax(startPoint.y(), endPoint.y());

            qreal width = right - left;
            qreal height = bottom - top;

            // 创建临时图像并绘制五角星
            tempImage = QImage(width + borderWidth * 2, height + borderWidth * 2, QImage::Format_ARGB32);
            tempImage.fill(Qt::transparent);
            QPainter painter(&tempImage);

            QPen pen = QPen(foregroundColor, borderWidth);
            pen.setStyle(Qt::SolidLine);
            painter.setPen(pen);

            // 设置画刷为背景颜色，用于填充五角星
            painter.setBrush(backgroundColor);

            qreal radius = qMin(width, height) / 2;
            qreal centerX = radius + borderWidth / 2;
            qreal centerY = radius + borderWidth / 2;

            QPointF starPoints[10]; // 声明 starPoints 数组

            qreal angleStep = (2 * M_PI) / 5;
            for (int i = 0; i < 5; ++i)
            {
                qreal angle = i * angleStep;
                qreal x = centerX + radius * qCos(angle);
                qreal y = centerY + radius * qSin(angle);
                QPointF outerPoint(x, y);

                // 计算内点位置
                qreal innerRadius = radius * 0.382;
                qreal innerAngle = angle + angleStep / 2;
                qreal innerX = centerX + innerRadius * qCos(innerAngle);
                qreal innerY = centerY + innerRadius * qSin(innerAngle);
                QPointF innerPoint(innerX, innerY);

                if (i == 0)
                {
                    starPoints[0] = outerPoint;
                    starPoints[1] = innerPoint;
                }
                else
                {
                    starPoints[(i * 2)] = outerPoint;
                    starPoints[(i * 2) + 1] = innerPoint;
                }
            }

            painter.drawPolygon(starPoints, 10);

            // 将临时图像绘制到原始图像上，相对于 startPoint 的位置
            QPainter oriPainter(&originalImage);
            oriPainter.drawImage(left, top, tempImage);

            //update();
        }
        else if (mouse == 3)
        {
            backup = originalImage;
            addimage();
        }
        qDebug() << "画五角星";
    }
    void painting_six_pointed_star(QGraphicsSceneMouseEvent *event, int mouse)
    {
        static QPointF startPoint;
        static QImage tempImage;

        if (mouse == 1)
        {
            startPoint = event->pos()/image_factor;
            backup = originalImage;
        }
        else if (mouse == 2)
        {
            QPointF endPoint = event->pos()/image_factor;
            originalImage = backup;

            // 计算矩形范围
            qreal left = qMin(startPoint.x(), endPoint.x());
            qreal top = qMin(startPoint.y(), endPoint.y());
            qreal right = qMax(startPoint.x(), endPoint.x());
            qreal bottom = qMax(startPoint.y(), endPoint.y());

            qreal width = right - left;
            qreal height = bottom - top;

            // 创建临时图像并绘制六角星
            tempImage = QImage(width + borderWidth * 2, height + borderWidth * 2, QImage::Format_ARGB32);
            tempImage.fill(Qt::transparent);
            QPainter painter(&tempImage);

            QPen pen = QPen(foregroundColor, borderWidth);
            pen.setStyle(Qt::SolidLine);
            painter.setPen(pen);

            // 设置画刷为背景颜色，用于填充六角星
            painter.setBrush(backgroundColor);

            qreal radius = qMin(width, height) / 2;
            qreal centerX = radius + borderWidth / 2;
            qreal centerY = radius + borderWidth / 2;

            QPointF starPoints[12]; // 声明 starPoints 数组

            qreal angleStep = (2 * M_PI) / 6;
            for (int i = 0; i < 6; ++i)
            {
                qreal angle = i * angleStep;
                qreal x = centerX + radius * qCos(angle);
                qreal y = centerY + radius * qSin(angle);
                QPointF outerPoint(x, y);

                // 计算内点位置
                qreal innerRadius = radius * 0.5;
                qreal innerAngle = angle + angleStep / 2;
                qreal innerX = centerX + innerRadius * qCos(innerAngle);
                qreal innerY = centerY + innerRadius * qSin(innerAngle);
                QPointF innerPoint(innerX, innerY);

                if (i == 0)
                {
                    starPoints[0] = outerPoint;
                    starPoints[1] = innerPoint;
                }
                else
                {
                    starPoints[(i * 2)] = outerPoint;
                    starPoints[(i * 2) + 1] = innerPoint;
                }
            }

            painter.drawPolygon(starPoints, 12);

            // 将临时图像绘制到原始图像上，相对于 startPoint 的位置
            QPainter oriPainter(&originalImage);
            oriPainter.drawImage(left, top, tempImage);

            //update();
        }
        else if (mouse == 3)
        {
            backup = originalImage;
            addimage();
        }
        qDebug() << "画六角星";
    }
    /*
    void painting_heart(QGraphicsSceneMouseEvent *event, int mouse)
    {
        static QPointF startPoint;
        static QImage tempImage;

        if (mouse == 1)
        {
            startPoint = event->pos() / image_factor;
            backup = originalImage;
        }
        else if (mouse == 2)
        {
            QPointF endPoint = event->pos() / image_factor;
            originalImage = backup;

            // 计算矩形范围
            qreal left = qMin(startPoint.x(), endPoint.x());
            qreal top = qMin(startPoint.y(), endPoint.y());
            qreal right = qMax(startPoint.x(), endPoint.x());
            qreal bottom = qMax(startPoint.y(), endPoint.y());

            qreal width = right - left;
            qreal height = bottom - top;

            // 创建临时图像并绘制心形
            tempImage = QImage(width + borderWidth * 2, height + borderWidth * 2, QImage::Format_ARGB32);
            tempImage.fill(Qt::transparent);
            QPainter painter(&tempImage);

            // 启用抗锯齿
            painter.setRenderHint(QPainter::Antialiasing);

            QPen pen = QPen(foregroundColor, borderWidth);
            pen.setStyle(Qt::SolidLine);
            painter.setPen(pen);

            // 设置画刷为背景颜色，用于填充心形
            painter.setBrush(backgroundColor);

            // 计算心形中心点和大小
            qreal centerX = width / 2 + borderWidth;
            qreal centerY = height / 2 + borderWidth;
            qreal size = qMin(width, height) / 4;

            QPainterPath heartPath;
            heartPath.moveTo(centerX, centerY +size); // 心形底部
            // 微调左侧贝塞尔曲线控制点，使心形更圆润
            heartPath.cubicTo(centerX - size * 0.5, centerY - size * 0.866, centerX - size * 0.5, centerY + size * 0.866, centerX, centerY);
            // 微调右侧贝塞尔曲线控制点
            heartPath.cubicTo(centerX + size * 0.5, centerY + size * 0.866, centerX + size * 0.5, centerY - size * 0.866, centerX, centerY + size);
            heartPath.closeSubpath();

            // 绘制心形
            painter.drawPath(heartPath);

            // 将临时图像绘制到原始图像上，相对于 startPoint 的位置
            QPainter oriPainter(&originalImage);
            oriPainter.drawImage(left, top, tempImage);

            update();
        }
        else if (mouse == 3)
        {
            backup = originalImage;
        }
        qDebug() << "画心形";
    }
*/
    void painting_lightning(QGraphicsSceneMouseEvent *event, int mouse)
    {
        static QPointF startPoint;
        static QImage tempImage;

        if (mouse == 1)
        {
            startPoint = event->pos()/image_factor;
            backup = originalImage;
        }
        else if (mouse == 2)
        {
            QPointF endPoint = event->pos()/image_factor;
            originalImage = backup;

            // 计算矩形范围
            qreal left = qMin(startPoint.x(), endPoint.x());
            qreal top = qMin(startPoint.y(), endPoint.y());
            qreal right = qMax(startPoint.x(), endPoint.x());
            qreal bottom = qMax(startPoint.y(), endPoint.y());

            qreal width = right - left;
            qreal height = bottom - top;

            // 创建临时图像并绘制闪电
            tempImage = QImage(width + borderWidth * 2, height + borderWidth * 2, QImage::Format_ARGB32);
            tempImage.fill(Qt::transparent);
            QPainter painter(&tempImage);

            QPen pen = QPen(foregroundColor, borderWidth);
            pen.setStyle(Qt::SolidLine);
            painter.setPen(pen);

            // 设置画刷为背景颜色，用于填充闪电
            painter.setBrush(backgroundColor);

            QPointF lightningPoints[6];
            lightningPoints[0] = QPointF(width*216/320 + borderWidth / 2, borderWidth / 2);
            lightningPoints[1] = QPointF(width *180/320+ borderWidth / 2, height*130/320 + borderWidth / 2);
            lightningPoints[2] = QPointF(width * 270/320 + borderWidth / 2, height*150/320 + borderWidth / 2);
            lightningPoints[3] = QPointF(width * 100/320 + borderWidth / 2, height + borderWidth / 2);
            lightningPoints[4] = QPointF(width *130/320+ borderWidth / 2, height * 190/320 + borderWidth / 2);
            lightningPoints[5] = QPointF(width*40/320 + borderWidth / 2, height *170/320 + borderWidth / 2);

            painter.drawPolygon(lightningPoints, 6);

            // 将临时图像绘制到原始图像上，相对于 startPoint 的位置
            QPainter oriPainter(&originalImage);
            oriPainter.drawImage(left, top, tempImage);

            //update();
        }
        else if (mouse == 3)
        {
            backup = originalImage;
            addimage();
        }
        qDebug() << "画闪电";
    }
    void painting_left(QGraphicsSceneMouseEvent *event, int mouse)
    {
        static QPointF startPoint;
        static QImage tempImage;

        if (mouse == 1)
        {
            startPoint = event->pos()/image_factor;
            backup = originalImage;
        }
        else if (mouse == 2)
        {
            QPointF endPoint = event->pos()/image_factor;
            originalImage = backup;

            // 计算矩形范围
            qreal left = qMin(startPoint.x(), endPoint.x());
            qreal top = qMin(startPoint.y(), endPoint.y());
            qreal right = qMax(startPoint.x(), endPoint.x());
            qreal bottom = qMax(startPoint.y(), endPoint.y());

            qreal width = right - left;
            qreal height = bottom - top;

            // 创建临时图像并绘制左箭头
            tempImage = QImage(width + borderWidth * 2, height + borderWidth * 2, QImage::Format_ARGB32);
            tempImage.fill(Qt::transparent);
            QPainter painter(&tempImage);

            QPen pen = QPen(foregroundColor, borderWidth);
            pen.setStyle(Qt::SolidLine);
            painter.setPen(pen);
            // 设置画刷为背景颜色，用于填充箭头
            painter.setBrush(backgroundColor);

            QPointF leftArrowPoints[7];
            leftArrowPoints[0] = QPointF(width+borderWidth/2, height*90/320+borderWidth / 2);
            leftArrowPoints[1] = QPointF(width *160/320+ borderWidth / 2, height*90/320+borderWidth / 2);
            leftArrowPoints[2] = QPointF(width *160/320+ borderWidth / 2,borderWidth / 2);
            leftArrowPoints[3] = QPointF( borderWidth / 2, height/2 + borderWidth / 2);
            leftArrowPoints[4] = QPointF(width*160/320 + borderWidth / 2, height + borderWidth / 2);
            leftArrowPoints[5] = QPointF(width *160/320 + borderWidth / 2, height *240/320 + borderWidth / 2);
            leftArrowPoints[6] = QPointF(width+borderWidth / 2, height*240/320+borderWidth / 2);

            painter.drawPolygon(leftArrowPoints, 7);

            // 将临时图像绘制到原始图像上，相对于 startPoint 的位置
            QPainter oriPainter(&originalImage);
            oriPainter.drawImage(left, top, tempImage);

            //update();
        }
        else if (mouse == 3)
        {
            backup = originalImage;
            addimage();
        }
        qDebug() << "画左箭头";
    }
    void painting_right(QGraphicsSceneMouseEvent *event, int mouse)
    {
        static QPointF startPoint;
        static QImage tempImage;

        if (mouse == 1)
        {
            startPoint = event->pos()/image_factor;
            backup = originalImage;
        }
        else if (mouse == 2)
        {
            QPointF endPoint = event->pos()/image_factor;
            originalImage = backup;

            // 计算矩形范围
            qreal left = qMin(startPoint.x(), endPoint.x());
            qreal top = qMin(startPoint.y(), endPoint.y());
            qreal right = qMax(startPoint.x(), endPoint.x());
            qreal bottom = qMax(startPoint.y(), endPoint.y());

            qreal width = right - left;
            qreal height = bottom - top;

            // 创建临时图像并绘制右箭头
            tempImage = QImage(width + borderWidth * 2, height + borderWidth * 2, QImage::Format_ARGB32);
            tempImage.fill(Qt::transparent);
            QPainter painter(&tempImage);

            QPen pen = QPen(foregroundColor, borderWidth);
            pen.setStyle(Qt::SolidLine);
            painter.setPen(pen);
            // 设置画刷为背景颜色，用于填充箭头
            painter.setBrush(backgroundColor);

            QPointF rightArrowPoints[7];
            rightArrowPoints[0] = QPointF(borderWidth/2, height*90/320+borderWidth / 2);
            rightArrowPoints[1] = QPointF(width *160/320+ borderWidth / 2, height*90/320+borderWidth / 2);
            rightArrowPoints[2] = QPointF(width *160/320+ borderWidth / 2,borderWidth / 2);
            rightArrowPoints[3] = QPointF(width + borderWidth / 2, height/2 + borderWidth / 2);
            rightArrowPoints[4] = QPointF(width*160/320 + borderWidth / 2, height + borderWidth / 2);
            rightArrowPoints[5] = QPointF(width *160/320 + borderWidth / 2, height *240/320 + borderWidth / 2);
            rightArrowPoints[6] = QPointF(borderWidth / 2, height*240/320+borderWidth / 2);

            painter.drawPolygon(rightArrowPoints, 7);

            // 将临时图像绘制到原始图像上，相对于 startPoint 的位置
            QPainter oriPainter(&originalImage);
            oriPainter.drawImage(left, top, tempImage);

            //update();
        }
        else if (mouse == 3)
        {
            backup = originalImage;
            addimage();
        }
        qDebug() << "画右箭头";
    }
    void painting_top(QGraphicsSceneMouseEvent *event, int mouse)
    {
        static QPointF startPoint;
        static QImage tempImage;

        if (mouse == 1)
        {
            startPoint = event->pos()/image_factor;
            backup = originalImage;
        }
        else if (mouse == 2)
        {
            QPointF endPoint = event->pos()/image_factor;
            originalImage = backup;

            // 计算矩形范围
            qreal left = qMin(startPoint.x(), endPoint.x());
            qreal top = qMin(startPoint.y(), endPoint.y());
            qreal right = qMax(startPoint.x(), endPoint.x());
            qreal bottom = qMax(startPoint.y(), endPoint.y());

            qreal width = right - left;
            qreal height = bottom - top;

            // 创建临时图像并绘制上箭头
            tempImage = QImage(width + borderWidth * 2, height + borderWidth * 2, QImage::Format_ARGB32);
            tempImage.fill(Qt::transparent);
            QPainter painter(&tempImage);

            QPen pen = QPen(foregroundColor, borderWidth);
            pen.setStyle(Qt::SolidLine);
            painter.setPen(pen);

            // 设置画刷为背景颜色，用于填充箭头
            painter.setBrush(backgroundColor);

            QPointF topArrowPoints[7];
            topArrowPoints[0] = QPointF(width / 2 + borderWidth / 2, borderWidth / 2);
            topArrowPoints[1] = QPointF(width + borderWidth / 2, height / 2+ borderWidth / 2);
            topArrowPoints[2] = QPointF(width * 3 / 4 + borderWidth / 2, height / 2 + borderWidth / 2);
            topArrowPoints[3] = QPointF(width * 3 / 4 + borderWidth / 2, height + borderWidth / 2);
            topArrowPoints[4] = QPointF(width*1/4 + borderWidth / 2, height+ borderWidth / 2);
            topArrowPoints[5] = QPointF(width*1/4+borderWidth / 2, height * 1/2+ borderWidth / 2);
            topArrowPoints[6] = QPointF(borderWidth / 2, height / 2 + borderWidth / 2);

            painter.drawPolygon(topArrowPoints, 7);

            // 将临时图像绘制到原始图像上，相对于 startPoint 的位置
            QPainter oriPainter(&originalImage);
            oriPainter.drawImage(left, top, tempImage);

            //update();
        }
        else if (mouse == 3)
        {
            backup = originalImage;
            addimage();
        }
        qDebug() << "画上箭头";
    }
    void painting_bottom(QGraphicsSceneMouseEvent *event, int mouse)
    {
        static QPointF startPoint;
        static QImage tempImage;

        if (mouse == 1)
        {
            startPoint = event->pos()/image_factor;
            backup = originalImage;
        }
        else if (mouse == 2)
        {
            QPointF endPoint = event->pos()/image_factor;
            originalImage = backup;

            // 计算矩形范围
            qreal left = qMin(startPoint.x(), endPoint.x());
            qreal top = qMin(startPoint.y(), endPoint.y());
            qreal right = qMax(startPoint.x(), endPoint.x());
            qreal bottom = qMax(startPoint.y(), endPoint.y());

            qreal width = right - left;
            qreal height = bottom - top;

            // 创建临时图像并绘制下箭头
            tempImage = QImage(width + borderWidth * 2, height + borderWidth * 2, QImage::Format_ARGB32);
            tempImage.fill(Qt::transparent);
            QPainter painter(&tempImage);

            QPen pen = QPen(foregroundColor, borderWidth);
            pen.setStyle(Qt::SolidLine);
            painter.setPen(pen);

            // 设置画刷为背景颜色，用于填充箭头
            painter.setBrush(backgroundColor);

            QPointF bottomArrowPoints[7];
            bottomArrowPoints[0] = QPointF(width / 2 + borderWidth / 2,height+ borderWidth / 2);
            bottomArrowPoints[1] = QPointF(width + borderWidth / 2, height / 2+ borderWidth / 2);
            bottomArrowPoints[2] = QPointF(width * 3 / 4 + borderWidth / 2, height / 2 + borderWidth / 2);
            bottomArrowPoints[3] = QPointF(width * 3 / 4 + borderWidth / 2,  borderWidth / 2);
            bottomArrowPoints[4] = QPointF(width*1/4 + borderWidth / 2,  borderWidth / 2);
            bottomArrowPoints[5] = QPointF(width*1/4+borderWidth / 2, height * 1/2+ borderWidth / 2);
            bottomArrowPoints[6] = QPointF(borderWidth / 2, height / 2 + borderWidth / 2);

            painter.drawPolygon(bottomArrowPoints, 7);

            // 将临时图像绘制到原始图像上，相对于 startPoint 的位置
            QPainter oriPainter(&originalImage);
            oriPainter.drawImage(left, top, tempImage);

            //update();
        }
        else if (mouse == 3)
        {
            backup = originalImage;
            addimage();
        }
        qDebug() << "画下箭头";
    }
    void painting_rounded_rectangle_annotation(QGraphicsSceneMouseEvent *event, int mouse)
    {
        static QPointF startPoint;
        static QImage tempImage;

        if (mouse == 1)
        {
            startPoint = event->pos()/image_factor;
            backup = originalImage;
        }
        else if (mouse == 2)
        {
            QPointF endPoint = event->pos()/image_factor;
            originalImage = backup;

            // 计算矩形范围
            qreal left = qMin(startPoint.x(), endPoint.x());
            qreal top = qMin(startPoint.y(), endPoint.y());
            qreal right = qMax(startPoint.x(), endPoint.x());
            qreal bottom = qMax(startPoint.y(), endPoint.y());

            qreal width = right - left;
            qreal height = bottom - top;

            // 创建临时图像并绘制圆角矩形注释
            tempImage = QImage(width + borderWidth * 2, height + borderWidth * 2, QImage::Format_ARGB32);
            tempImage.fill(Qt::transparent);
            QPainter painter(&tempImage);

            QPen pen = QPen(foregroundColor, borderWidth);
            pen.setStyle(Qt::SolidLine);
            painter.setPen(pen);

            // 设置画刷为背景颜色，用于填充圆角矩形
            painter.setBrush(backgroundColor);

            painter.drawRoundedRect(borderWidth / 2, borderWidth / 2, width, height * 3/4, 10, 10);

            // 绘制指向下方的第一个三角形
            QPointF firstTrianglePoints[3];
            firstTrianglePoints[0] = QPointF(width / 2-width/8+borderWidth/2, height * 3/4 + borderWidth/2);
            firstTrianglePoints[1] = QPointF(width / 2 + width /8+borderWidth/2, height * 3/4 + borderWidth/2);
            firstTrianglePoints[2] = QPointF(width / 2+borderWidth/2, height + borderWidth/2);

            painter.setBrush(backgroundColor);
            painter.drawPolygon(firstTrianglePoints, 3);

            // 绘制覆盖的第二个三角形
            QPointF secondTrianglePoints[3];
            secondTrianglePoints[0] = QPointF(width / 2 - width/8+borderWidth/2, height * 3 / 4-1);
            secondTrianglePoints[1] = QPointF(width / 2 + width /8+borderWidth/2, height * 3 / 4-1);
            secondTrianglePoints[2] = QPointF(width / 2+borderWidth/2, height-1);

            // 不设置边框，直接用背景色填充三角形
            painter.setPen(Qt::NoPen);
            painter.setBrush(backgroundColor);
            painter.drawPolygon(secondTrianglePoints, 3);

            // 将临时图像绘制到原始图像上，相对于 startPoint 的位置
            QPainter oriPainter(&originalImage);
            oriPainter.drawImage(left, top, tempImage);

            //update();
        }
        else if (mouse == 3)
        {
            backup = originalImage;
            addimage();
        }
        qDebug() << "画圆角矩形注释";
    }
    void painting_cloud_annotation(QGraphicsSceneMouseEvent *event, int mouse)
    {
        static QPointF startPoint;
        static QImage tempImage;

        if (mouse == 1)
        {
            startPoint = event->pos()/image_factor;
            backup = originalImage;
        }
        else if (mouse == 2)
        {
            QPointF endPoint = event->pos()/image_factor;
            originalImage = backup;

            // 计算矩形范围
            qreal left = qMin(startPoint.x(), endPoint.x());
            qreal top = qMin(startPoint.y(), endPoint.y());
            qreal right = qMax(startPoint.x(), endPoint.x());
            qreal bottom = qMax(startPoint.y(), endPoint.y());

            qreal width = right - left;
            qreal height = bottom - top;

            // 创建临时图像并绘制云注释（三个椭圆）
            tempImage = QImage(width + borderWidth * 2, height + borderWidth * 2, QImage::Format_ARGB32);
            tempImage.fill(Qt::transparent);
            QPainter painter(&tempImage);

            QPen pen = QPen(foregroundColor, borderWidth);
            pen.setStyle(Qt::SolidLine);
            painter.setPen(pen);

            // 设置画刷为背景颜色，用于填充椭圆
            painter.setBrush(backgroundColor);

            // 最小椭圆在左下角
            qreal smallEllipseWidth = width / 15;
            qreal smallEllipseHeight = height / 10;
            painter.drawEllipse(width/10+borderWidth/2+smallEllipseWidth, height*8/9 - borderWidth-smallEllipseHeight, smallEllipseWidth, smallEllipseHeight);

            // 中等椭圆在最小椭圆左上
            qreal mediumEllipseWidth = width / 8;
            qreal mediumEllipseHeight = height / 6;
            painter.drawEllipse(width/8+borderWidth/2+smallEllipseWidth, height*7/9 - borderWidth-smallEllipseHeight, mediumEllipseWidth, mediumEllipseHeight);

            // 最大椭圆在正中间
            qreal largeEllipseWidth = width / 2;
            qreal largeEllipseHeight = height / 2;
            painter.drawEllipse(width / 2 - largeEllipseWidth / 2 + borderWidth, height / 2 - largeEllipseHeight / 2 + borderWidth, largeEllipseWidth, largeEllipseHeight);

            // 将临时图像绘制到原始图像上，相对于 startPoint 的位置
            QPainter oriPainter(&originalImage);
            oriPainter.drawImage(left, top, tempImage);

           // update();
        }
        else if (mouse == 3)
        {
            backup = originalImage;
            addimage();
        }
        qDebug() << "画云注释";
    }
    void  printing_circle_annotation(QGraphicsSceneMouseEvent *event, int mouse)
    {
        static QPointF startPoint;
        static QImage tempImage;

        if (mouse == 1)
        {
            startPoint = event->pos()/image_factor;
            backup = originalImage;
        }
        else if (mouse == 2)
        {
            QPointF endPoint = event->pos()/image_factor;
            originalImage = backup;

            // 计算矩形范围
            qreal left = qMin(startPoint.x(), endPoint.x());
            qreal top = qMin(startPoint.y(), endPoint.y());
            qreal right = qMax(startPoint.x(), endPoint.x());
            qreal bottom = qMax(startPoint.y(), endPoint.y());

            qreal width = right - left;
            qreal height = bottom - top;

            // 创建临时图像并绘制圆形注释
            tempImage = QImage(width + borderWidth * 2, height + borderWidth * 2, QImage::Format_ARGB32);
            tempImage.fill(Qt::transparent);
            QPainter painter(&tempImage);

            QPen pen = QPen(foregroundColor, borderWidth);
            pen.setStyle(Qt::SolidLine);
            painter.setPen(pen);

            // 设置画刷为背景颜色，用于填充圆形
            painter.setBrush(backgroundColor);

            qreal circleRadius = qMin(width, height) / 3;
            painter.drawEllipse(width / 2 - circleRadius + borderWidth, height / 2 - circleRadius + borderWidth, circleRadius * 2, circleRadius * 2);

            // 计算三角形的尺寸，确保上面两个角在圆内，第三个角在圆外
            qreal triangleHeight = circleRadius * 0.6;
            qreal triangleBase = triangleHeight * 2;
            QPointF firstTrianglePoints[3];
            firstTrianglePoints[0] = QPointF(width / 2 - triangleBase / 2/2 + borderWidth / 2, height / 2 + circleRadius - triangleHeight / 2/2 + borderWidth / 2);
            firstTrianglePoints[1] = QPointF(width / 2 + triangleBase / 2/2 + borderWidth / 2, height / 2 + circleRadius - triangleHeight / 2/2 + borderWidth / 2);
            firstTrianglePoints[2] = QPointF(width / 2 + borderWidth / 2, height*45/100 + circleRadius + triangleHeight + borderWidth / 2);

            painter.setBrush(backgroundColor);
            painter.drawPolygon(firstTrianglePoints, 3);

            // 在圆内画一个稍小的无边框圆，覆盖第一个圆的填充部分
            painter.setPen(Qt::NoPen);
            painter.setBrush(backgroundColor);
            painter.drawEllipse(width / 2 - circleRadius + borderWidth*2, height / 2 - circleRadius + borderWidth*2*1.3, circleRadius * 2-borderWidth*2-1, circleRadius * 2-borderWidth*2-1);

            // 将临时图像绘制到原始图像上，相对于 startPoint 的位置
            QPainter oriPainter(&originalImage);
            oriPainter.drawImage(left, top, tempImage);

            //update();
        }
        else if (mouse == 3)
        {
            backup = originalImage;
            addimage();
        }
        qDebug() << "画圆形注释";
    }
    void size()
    {
        // 创建size_Dialog对话框对象，这里使用堆分配以避免局部变量生命周期问题
        size_Dialog* dialog1 = new size_Dialog();
        dialog1->setpixel_x(width);
        dialog1->setpixel_y(height);

        if (dialog1->exec() == QDialog::Accepted) {
            if (dialog1->getstate() == true) {
                // 根据百分比计算新的尺寸
                width = static_cast<int>(static_cast<double>(dialog1->getpercentage_x()) / 100 * width);
                height = static_cast<int>(static_cast<double>(dialog1->getpercentage_y()) / 100 * height);
                qDebug() << "比率" << width;
                qDebug() << "比率" << height;
            }
            else {
                // 获取用户输入的像素尺寸
                width = dialog1->getpixel_x();
                height = dialog1->getpixel_y();
                qDebug() << "像素" << width;
                qDebug() << "像素" << height;
            }

            // 缩放原始图像，注意这里可能需要考虑是否要保留原始图像的备份
            originalImage = originalImage.scaled(width, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
            // 根据可能存在的image_factor缩放image，这里不清楚image_factor的来源和作用，如果有问题需要进一步检查
            image = image.scaled(width * image_factor, height * image_factor, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
            addimage();
            rect.setSize(QSizeF(width, height));
            emit refresh_signals();
        }
        // 释放对话框对象内存
        delete dialog1;
    }

    void color_extractor(QGraphicsSceneMouseEvent *event, int mouse) {
        if (mouse == 1||mouse==2) {
            QPointF color_lacotion = event->pos();

            // 确保坐标在图像范围内
            if (color_lacotion.x() >= 0 && color_lacotion.x() < originalImage.width()*image_factor &&
                color_lacotion.y() >= 0 && color_lacotion.y() < originalImage.height()*image_factor) {
                QColor color = originalImage.pixel(color_lacotion.rx(), color_lacotion.ry());
                qDebug() << "颜色值：" << color.red() << color.green() << color.blue();
                emit change_color_signals(color);
            } else {
                qDebug() << "点击位置超出图像范围";
            }
        }
    }
    void my_erase(QGraphicsSceneMouseEvent *event, int mouse)
    {

        if(mouse==2||mouse==1)
        {
            QPointF startPoint, endPoint;
            startPoint = event->lastScenePos();
            endPoint = event->scenePos();
            erase_location=startPoint;
            // 获取当前图像和原始图像的尺寸
            QSize currentSize = image.size();
            QSize originalSize = originalImage.size();

            // 计算当前图像和原始图像的中心点坐标
            QPointF currentCenter(currentSize.width() / 2.0, currentSize.height() / 2.0);
            QPointF originalCenter(originalSize.width() / 2.0, originalSize.height() / 2.0);

            // 计算鼠标移动起始位置距离当前图像中心点的距离
            QPointF startDistanceToCurrentCenter = startPoint - currentCenter;
            // 将距离除以 image_factor
            QPointF startAdjustedDistance(startDistanceToCurrentCenter.x() / image_factor, startDistanceToCurrentCenter.y() / image_factor);
            // 计算真实起始坐标，即减去原始图像中心点坐标
            QPointF realStartPoint = startAdjustedDistance + originalCenter;

            // 计算鼠标移动结束位置距离当前图像中心点的距离
            QPointF endDistanceToCurrentCenter = endPoint - currentCenter;
            // 将距离除以 image_factor
            QPointF endAdjustedDistance(endDistanceToCurrentCenter.x() / image_factor, endDistanceToCurrentCenter.y() / image_factor);
            // 计算真实结束坐标，即减去原始图像中心点坐标
            QPointF realEndPoint = endAdjustedDistance + originalCenter;

            drawLine(realStartPoint, realEndPoint, QColor(255,255,255), borderWidth/image_factor);
        }
        else if(mouse==3)
        {
            addimage();
        }
    }
    void fill(QGraphicsSceneMouseEvent *event, int mouse)
    {
        if (mouse == 1||mouse==2)
        {
            QPointF colorLocation = event->pos()/ image_factor;
            QColor targetColor = originalImage.pixelColor(colorLocation.toPoint());

            // 使用QSet来避免重复访问像素点，替代QStack防止栈溢出
            QSet<QPoint> visitedPoints;
            QQueue<QPoint> queue;
            queue.enqueue(colorLocation.toPoint());

            while (!queue.isEmpty()) {
                QPoint point = queue.dequeue();
                int px = point.x();
                int py = point.y();

                if (visitedPoints.contains(point)) {
                    continue;
                }
                visitedPoints.insert(point);

                QRgb currentColor = originalImage.pixel(px, py);
                if (currentColor == targetColor.rgba()) {
                    originalImage.setPixel(px, py, backgroundColor.rgba());

                    // 检查并添加四个方向的合法点
                    if (px > 0 &&!visitedPoints.contains(QPoint(px - 1, py))) queue.enqueue(QPoint(px - 1, py));
                    if (px < originalImage.width()*image_factor - 1 &&!visitedPoints.contains(QPoint(px + 1, py))) queue.enqueue(QPoint(px + 1, py));
                    if (py > 0 &&!visitedPoints.contains(QPoint(px, py - 1))) queue.enqueue(QPoint(px, py - 1));
                    if (py < originalImage.height()*image_factor - 1 &&!visitedPoints.contains(QPoint(px, py + 1))) queue.enqueue(QPoint(px, py + 1));
                }
            }
        }
        else if(mouse==3)
        {
            addimage();
        }
    }
    void crop(QGraphicsSceneMouseEvent *event,int mouse)
    {
        if(mouse==1)
        {
            QPointF k=event->pos();
            r.setTopLeft(QPoint(k.rx(),k.ry()));
        }
        else if(mouse == 2)
        {
            QPointF currentMousePos = event->pos();
            int newWidth = currentMousePos.x() - r.x();
            int newHeight = currentMousePos.y() - r.y();
            r.setWidth(newWidth);
            r.setHeight(newHeight);
        }
        else if(mouse == 3)
        {
            // 计算相交矩形
            QRect intersectionRect = r.intersected(QRect(0, 0, originalImage.width(), originalImage.height()));
            if (!intersectionRect.isNull())
            {
                QImage croppedImage = originalImage.copy(intersectionRect);
                originalImage = croppedImage;
                // 更新与图像相关的大小信息（这里假设存在相关变量来记录图像大小，如width和height）
                width = originalImage.width();
                height = originalImage.height();
                image=originalImage;
                //image = image.scaled(width, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation); // Update the image reference
                //doScaling(image_factor);
                r.setTopLeft(QPoint(1000, 1000));
                rect.setSize(QSizeF(width, height));
                r.setX(1000);
                r.setY(1000);
                //update();
                addimage();
                emit refresh_signals();
            }
        }
    }
    void choice_painting(QGraphicsSceneMouseEvent *event,int mouse)
    {
        if (foregroundColor.alpha()!= 0) {
            switch (graphics1) {
            case basic:
                painting_basic(event, mouse);
                break;
            case straight_line:
                painting_straight_line(event, mouse);
                break;
            case right_circle:
                painting_right_circle(event, mouse);
                break;
            case ellipse:
                painting_ellipse(event, mouse);
                break;
            case isosceles_triangle:
                painting_isosceles_triangle(event, mouse);
                break;
            case right_triangle:
                painting_right_triangle(event, mouse);
                break;
            case right_rectangle:
                painting_right_rectangle(event, mouse);
                break;
            case rounded_rectangle:
                painting_rounded_rectangle(event, mouse);
                break;
            case diamond:
                painting_diamond(event, mouse);
                break;
            case hexagon:
                painting_hexagon(event, mouse);
                break;
            case four_pointed_star:
                painting_four_pointed_star(event, mouse);
                break;
            case five_pointed_star:
                painting_five_pointed_star(event, mouse);
                break;
            case six_pointed_star:
                painting_six_pointed_star(event, mouse);
                break;
            case lightning:
                painting_lightning(event, mouse);
                break;
            case left:
                painting_left(event, mouse);
                break;
            case right:
                painting_right(event, mouse);
                break;
            case top:
                painting_top(event, mouse);
                break;
            case bottom:
                painting_bottom(event, mouse);
                break;
            case rounded_rectangle_annotation:
                painting_rounded_rectangle_annotation(event, mouse);
                break;
            case cloud_annotation:
                painting_cloud_annotation(event, mouse);
                break;
            case circle_annotation:
                printing_circle_annotation(event, mouse);
                break;
            default:
                std::cerr << "Unhandled graphics1 value in foreground drawing: " << static_cast<int>(graphics1) << std::endl;
                break;
            }
        }
        else if (backgroundColor.alpha()!= 0) {
            switch (graphics1) {
            case basic:
                painting_basic(event, mouse);
                break;
            case straight_line:
                painting_straight_line(event, mouse);
                break;
            case right_circle:
                painting_right_circle(event, mouse);
                break;
            case ellipse:
                painting_ellipse(event, mouse);
                break;
            case isosceles_triangle:
                painting_isosceles_triangle(event, mouse);
                break;
            case right_triangle:
                painting_right_triangle(event, mouse);
                break;
            case right_rectangle:
                painting_right_rectangle(event, mouse);
                break;
            case rounded_rectangle:
                painting_rounded_rectangle(event, mouse);
                break;
            case diamond:
                painting_diamond(event, mouse);
                break;
            case hexagon:
                painting_hexagon(event, mouse);
                break;
            case four_pointed_star:
                painting_four_pointed_star(event, mouse);
                break;
            case five_pointed_star:
                painting_five_pointed_star(event, mouse);
                break;
            case six_pointed_star:
                painting_six_pointed_star(event, mouse);
                break;
            case lightning:
                painting_lightning(event, mouse);
                break;
            case left:
                painting_left(event, mouse);
                break;
            case right:
                painting_right(event, mouse);
                break;
            case top:
                painting_top(event, mouse);
                break;
            case bottom:
                painting_bottom(event, mouse);
                break;
            case rounded_rectangle_annotation:
                painting_rounded_rectangle_annotation(event, mouse);
                break;
            case cloud_annotation:
                painting_cloud_annotation(event, mouse);
                break;
            case circle_annotation:
                printing_circle_annotation(event, mouse);
                break;
            default:
                std::cerr << "Unhandled graphics1 value in background drawing: " << static_cast<int>(graphics1) << std::endl;
                break;
            }
        }
    }
    void choice_function(QGraphicsSceneMouseEvent *event,int mouse)
    {
        switch(function1)
        {
            case all_my_function::painting:
                choice_painting(event,mouse);
                break;
            case all_my_function::color_extractor:
                color_extractor(event,mouse);
                break;
            case all_my_function::my_erase:
                my_erase(event,mouse);
                break;
            case all_my_function::fill:
                fill(event,mouse);
                break;
            case all_my_function::crop:
                crop(event,mouse);
                break;
            default:
                break;
        }
    }
    // 修改图像的大小
    void changeImageSize(int newWidth, int newHeight)
    {
        QImage newImage(newWidth, newHeight, QImage::Format_ARGB32);
        newImage.fill(Qt::white);

        QPainter painter(&newImage);
        painter.drawImage(0, 0, image);
        image = newImage;

        //updata();
        rect.setSize(QSizeF(newWidth, newHeight));
    }
    void drawPoint(QPointF point, QColor color, int diameter)
    {
        if (originalImage.isNull())
            return; // 确保图像有效
        QPen pen(color);
        pen.setStyle(Qt::SolidLine);

        QBrush brush(color);

        QPainter painter(&originalImage);
        painter.setPen(pen);
        painter.setBrush(brush);
        if (diameter < 2)
        {
            painter.drawPoint(point);
        }
        else
        {
            painter.drawEllipse(QRectF(point.x() - diameter / 2.0, point.y() - diameter / 2.0, diameter, diameter));
        }
    }
    void drawLine(QPointF startPoint, QPointF endPoint, QColor color, int width)
    {
        if (originalImage.isNull())
            return; // 确保图像有效

        QPen pen(color);
        pen.setWidth(width);
        pen.setCapStyle(Qt::RoundCap);

        QPainter painter(&originalImage);
        painter.setPen(pen);

        painter.drawLine(startPoint, endPoint);
        update();
    }
    void setGeometry(int x, int y)
    {
        // 修改图像的位置和大小
        QImage newImage(width, height, QImage::Format_ARGB32);
        newImage.fill(Qt::white);

        QPainter painter(&newImage);
        painter.drawImage(x, y, image);
        image = newImage;
        // 存储位置信息
       // setPos(x, y);
        rect.setRect(x, y, width, height);
    }
    int getwidth()
    {
        return width;
    }
    int getheight()
    {
        return height;
    }
    QImage getImage() const
    {
        return originalImage;
    }
    QRectF boundingRect() const override
    {
        return rect;
    }
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option = nullptr, QWidget *widget = nullptr) override
    {
        // 绘制图像
        painter->drawImage(0, 0, this->image);

        // 判断擦除位置是否在有效范围内，并绘制圆形
        if (erase_location.x() >= 0 && erase_location.rx() <= width && erase_location.y() >= 0 && erase_location.y() <= height) {
            int circleRadius = (borderWidth - 1) / 2;
            QPen pen(Qt::black, 1);
            QBrush brush(Qt::white);
            painter->setPen(pen);
            painter->setBrush(brush);
            painter->drawEllipse(erase_location, circleRadius, circleRadius);
            erase_location.setX(-100);
            erase_location.setY(-100);
            //emit refresh_signals();
        }
        // 如果矩形r的左上角坐标不是(1000, 1000)，则绘制矩形r
        if (r.x()!= 1000 || r.y()!= 1000) {

            // 在你的代码中，确保在适当的位置调用 srand() 以初始化随机数生成器
            srand(static_cast<unsigned int>(time(nullptr))); // 在程序开始时调用一次
            // 生成随机颜色
            int red = rand() % 256;   // 生成0-255之间的随机数
            int green = rand() % 256; // 生成0-255之间的随机数
            int blue = rand() % 256;  // 生成0-255之间的随机数

            QColor startColor(red, green, blue); // 随机起始颜色
            QColor endColor(rand() % 256, rand() % 256, rand() % 256); // 随机结束颜色

            QLinearGradient gradient(r.topLeft(), r.bottomRight());
            gradient.setColorAt(0, startColor);  // 起始颜色
            gradient.setColorAt(1, endColor);    // 结束颜色

            QPen rectPen;
            rectPen.setWidth(2);  // 设置线条宽度，可根据需要调整
            rectPen.setStyle(Qt::DashLine);
            painter->setPen(rectPen);
            painter->drawRect(r);
        }
    }
signals:
    void change_color_signals(const QColor& c);
    void refresh_signals();
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override
    {

        int newWidth = static_cast<int>(this->width * image_factor);
        int newHeight = static_cast<int>(this->height * image_factor);

        choice_function(event,1);
        image = originalImage.scaled(newWidth, newHeight, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        update();
    }
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override
    {

        choice_function(event,2);
        int newWidth = static_cast<int>(this->width * image_factor);
        int newHeight = static_cast<int>(this->height * image_factor);
        image = originalImage.scaled(newWidth, newHeight, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        update();
    }
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override
    {
        event->accept();
        choice_function(event,3);
        int newWidth = static_cast<int>(this->width * image_factor);
        int newHeight = static_cast<int>(this->height * image_factor);
        image = originalImage.scaled(newWidth, newHeight, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        update();
    }
private:
    //显示图像
    QImage image;
    //实际图像
    QImage originalImage;
    //备份图形
    QImage backup;
    //前景色
    QColor foregroundColor;
    //背景色
    QColor backgroundColor;
    //线宽
    int borderWidth;
    //位置范围
    QRectF rect;
    //宽
    int width;
    //高
    int height;
    //缩放比例
    qreal image_factor;
    //功能变量
    all_my_function function1;
    //图型变量
    all_my_graphics graphics1;
    //涂改位置
    QPointF erase_location;
    //裁剪矩形
    QRect r;
    //缓存文件
    QVector<QImage> buffer;
    //当前文件
    int now;
};

#endif // QCUSTOMIMAGE_H
