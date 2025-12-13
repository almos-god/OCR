#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QRadioButton>
#include <QPointF>
#include "QCustomImage.h"
#include "screenshottool.h"
#include <QSpinBox>
#include <QSlider>
#include <QLabel>
#include <QTabWidget>
#include <QHBoxLayout>
#include <QGraphicsScene>
#include <QProcess>
#include <QDebug>
#include <QTextEdit>
#include <QHash>
#include "enum_mappings.h"
// Tesseract OCR相关头文件
#include <tesseract/baseapi.h>
//#include "apiwindow.h"
//#include "apiwindow_global.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void showFloatingMessage(const QString &message, int timeout);
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
    void showBoundary();
    void hideBoundary();

protected:
    void resizeEvent(QResizeEvent *event);
    void showEvent(QShowEvent * /*event*/);

private slots:
    void on_ocr_clicked();
    void on_language_selection_triggered();

private:
    void contextMenuEvent(QContextMenuEvent *event);
    Ui::MainWindow *ui;
    QPixmap *pix;
    QCustomImage* customImage;
    QGraphicsView* graphicsView;
    QGraphicsScene* scene;

    int viewWidth ;
    int viewHeight ;
    QSlider *slider;
    QLabel *valueLabel;
    QTabWidget *tabWidget;
    QHBoxLayout *layout;

    int intred;
    int intblue;
    int intgreen;

    bool foreground_color;
    bool background_color;
    int linewidth;
    QString filename;
    QAction *showBoundaryAction; // "显示边界" 菜单项
    QAction *hideBoundaryAction; // "隐藏边界" 菜单项
    QAction  *showMenuAction;

    ScreenshotTool *screenshotTool; // 截图工具

    QPushButton* close;
    QPushButton* save;
    QPushButton* copy;
    QTextEdit* text;
    
    // 当前选中的OCR语言代码列表
    QStringList m_currentLanguageCodes;
    
    // Tesseract API 实例（作为成员变量，避免重复创建和销毁）
    tesseract::TessBaseAPI* m_tessApi;
};
#endif // MAINWINDOW_H
