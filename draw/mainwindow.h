#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QRadioButton>
#include <QPointF>
#include "QCustomImage.h"
#include <QSpinBox>
#include <QSlider>
#include <QLabel>
#include <QHBoxLayout>
#include <QGraphicsScene>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    std::map<QString,all_my_graphics> graphicsMap;
    std::map<QString,all_my_function> functionMap;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    // 在头文件中声明槽函数
public slots:
    void updateGraphicsViewColor(QRadioButton* radioButton1, QRadioButton* radioButton2);
    void get_color_signal(const QColor &c);
    void get_refresh();
    void saveImage(); // 修改为接受bool参数
    void startNewDrawingProcess();
    void openImage();
    void anotheringsaveImage();
    void exitApp();
protected:
    void resizeEvent(QResizeEvent *event);
    void showEvent(QShowEvent * /*event*/);

private:

    Ui::MainWindow *ui;
    QPixmap *pix;
    QCustomImage* customImage;
    QGraphicsView* graphicsView;
    QGraphicsScene* scene;

    QSlider *slider;
    QLabel *valueLabel;
    QHBoxLayout *layout;

    int intred;
    int intblue;
    int intgreen;

    bool foreground_color;
    bool background_color;
    int linewidth;
    QString filename;
};
#endif // MAINWINDOW_H
