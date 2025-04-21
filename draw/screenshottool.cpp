#include "screenshottool.h"
#include <QGuiApplication>
#include <QScreen>
#include <QDebug>

ScreenshotTool::ScreenshotTool(QWidget *parent) : QWidget(parent), isSelecting(false) {
    // 设置窗口为无边框并始终置顶
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);

    // 设置窗口透明度
    setWindowOpacity(0.25);
}

void ScreenshotTool::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        isSelecting = true;
        selectionRect.setTopLeft(event->pos());
        selectionRect.setBottomRight(event->pos());
    }
}

void ScreenshotTool::mouseMoveEvent(QMouseEvent *event) {
    if (isSelecting) {
        selectionRect.setBottomRight(event->pos());
        update(); // 触发重绘
    }
}

void ScreenshotTool::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton && isSelecting) {
        isSelecting = false;
        takeScreenshot();
        close();
    }
}

void ScreenshotTool::paintEvent(QPaintEvent* event) {
    QWidget::paintEvent(event);

    if (isSelecting) {
        QPainter painter(this);
        // 创建一个红色的画笔，宽度为3
        QPen pen(Qt::red, 3);
        painter.setPen(pen); // 设置选区边框颜色
        painter.drawRect(selectionRect); // 绘制选区矩形
    }
}

void ScreenshotTool::startScreenshot() {
    qDebug()<<"开始";
    show();
    // 设置窗口为全屏
    showFullScreen();
}

void ScreenshotTool::takeScreenshot() {
    // 获取屏幕图像
    QScreen *screen = QGuiApplication::primaryScreen();
    QPixmap fullPixmap = screen->grabWindow(0);

    // 调整截图区域，排除红线
    QRect adjustedRect = selectionRect.normalized().adjusted(
        2, 2, -2, -2
        );

    // 裁剪选择区域
    screenshotImage = fullPixmap.copy(adjustedRect).toImage();

    // 发送截图完成信号
    emit screenshotTaken(screenshotImage);
}

QImage ScreenshotTool::getScreenshotImage() const {
    return screenshotImage;
}
