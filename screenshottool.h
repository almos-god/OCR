#ifndef SCREENSHOTTOOL_H
#define SCREENSHOTTOOL_H

#include <QWidget>
#include <QTimer>
#include <QScreen>
#include <QPixmap>
#include <QPainter>
#include <QMouseEvent>
#include <QImage>

class ScreenshotTool : public QWidget {
    Q_OBJECT

public:
    explicit ScreenshotTool(QWidget *parent = nullptr);
    QImage getScreenshotImage() const; // 获取截图结果
    void takeScreenshot();
    void startScreenshot();
signals:
    void screenshotTaken(const QImage &image); // 截图完成信号

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

    bool isSelecting; // 是否正在选择区域
    QRect selectionRect; // 选择的矩形区域
    QImage screenshotImage; // 保存的截图
};

#endif // SCREENSHOTTOOL_H
