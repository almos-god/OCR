 #include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QApplication>
#include <QImage>
#include <QScrollArea>
#include <QGraphicsPixmapItem>
#include <QPalette>
#include <QGridLayout>
#include <QDebug>
#include <QMouseEvent>
#include <QPainter>
#include <QGraphicsView>
#include "QCustomImage.h"
#include <QMouseEvent>
#include <QSlider>
#include <QScrollBar>
#include <QAction>
#include <QGraphicsScene>
#include <QApplication>
#include <QFileDialog>
#include <QMessageBox>
#include <QProcess>
#include <QTimer>
#include <QGraphicsBlurEffect>
#include <QImage>
#include <QDebug>
#include <QProcess>
#include <QGraphicsProxyWidget>
#include <QClipboard>
#include <QMessageBox>
#include <QtConcurrent/QtConcurrent>
#include <QThread>
#include <QLabel>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 初始化长宽
    int miderlonger = 1280;
    int miderwider = 720;
    // 设置标题
    setWindowTitle("DrawingPadPro");
    setWindowIcon(QIcon(":/new/prefix1/FlatUiPicture.ico"));

    QMainWindow::resize(miderlonger, miderwider);
    // 三块工具栏
    // 创建 QPalette 对象并设置背景色为白色
    QPalette palette = ui->groupBox->palette();
    palette.setColor(QPalette::Window, Qt::white);
    // 将 QPalette 对象应用于 groupBox 和 groupBox_2
    ui->groupBox->setAutoFillBackground(true);
    ui->groupBox->setPalette(palette);

    ui->groupBox->setStyleSheet("QGroupBox { border: none; background-color: white; }");

    ui->groupBox_2->setAutoFillBackground(true);
    ui->groupBox_2->setPalette(palette);
   // ui->groupBox_2->setGeometry(0, 0, 200, 200);

    ui->groupBox_2->setStyleSheet("QGroupBox { border: none; background-color: white; }");

    ui->groupBox_3->setAutoFillBackground(true);
    ui->groupBox_3->setPalette(palette);

    ui->groupBox_3->setStyleSheet("QGroupBox { border: none; background-color: white; }");

    // 设置初始值为 0
    ui->spinBox->setValue(0);
    ui->spinBox_2->setValue(0);
    ui->spinBox_3->setValue(0);
    ui->spinBox_4->setValue(0);
    ui->horizontalSlider->setValue(0);
    ui->horizontalSlider_2->setValue(0);
    ui->horizontalSlider_3->setValue(0);
    // 调色板
    // 设置 graphicsView_2 的边框样式为黑色，线宽为 1
    ui->graphicsView_2->setStyleSheet("border:1px solid black;");
    // 将 graphicsView_2 设为使用状态
    ui->graphicsView_2->setEnabled(true);
    // 将 radioButton 设为选中状态
    ui->radioButton->setChecked(true);
    // 设置 graphicsView_3 的边框样式为黑色，线宽为 1
    ui->graphicsView_3->setStyleSheet("border:1px solid black;");
    // 将 graphicsView_3 设为禁用状态
    ui->graphicsView_3->setEnabled(false);
    // 将 radioButton 设为未选中状态
    ui->radioButton->setChecked(false);

    // 设置动作的图标
    //ui->undo->setIcon(QIcon(":/new/prefix1/back  up.svg"));
    //ui->redo->setIcon(QIcon(":/new/prefix1/advance.svg"));

    //前景色，背景色状态初始化
    background_color=true;
    foreground_color=true;
    ui->pushButton_14->setText(foreground_color? "启用" : "禁用");
    ui->pushButton_15->setText(background_color? "启用" : "禁用");

    QColor color(0, 0, 0);
    // 设置工作台背景色
    ui->graphicsView_2->setStyleSheet(QString("background-color:%1").arg(color.name()));
    ui->graphicsView_3->setStyleSheet(QString("background-color:%1").arg(color.name()));

    // 画板
    graphicsView = new QGraphicsView(this);
    viewWidth = this->width()-20; // 获取窗口的宽度
    viewHeight = this->height()-260; // 获取窗口的高度
    graphicsView->setGeometry(0, 220, viewWidth, viewHeight);

    graphicsView->setStyleSheet("background:transparent;");
    graphicsView->setFrameShape(QFrame::NoFrame); // 设置无边框
    scene = new QGraphicsScene(this);
    scene->update();
    customImage = new QCustomImage(800,600);
    customImage->setGeometry(0, 0);
    customImage->update();
    scene->addItem(customImage);
    graphicsView->setScene(scene);

    // 设置视图的矩形区域，并留出边距
    QRectF viewRect = scene->sceneRect();
    int margin = 50;
    viewRect.setX(viewRect.x() - margin);
    // 左上角减去边距
    viewRect.setY(viewRect.y() - margin); // 左上角减去边距
    // 定义边距大小
    viewRect.setWidth(viewRect.width() +  margin);
    // 左右各留出边距
    viewRect.setHeight(viewRect.height() +  margin);
    // 上下各留出边距
    graphicsView->setSceneRect(viewRect);


    // 功能按钮
    ui->painting->setStyleSheet("QPushButton {background-color:QColor(200,200,200);}");
    ui->painting->setDown(true);

    ui->pushButton_14->setStyleSheet("background-color:white");
    ui->pushButton_15->setStyleSheet("background-color:white");


    for (int j = 0; j < ui->gridLayout_2->count(); ++j)
    {
        QLayoutItem *itemJ = ui->gridLayout_2->itemAt(j);
        if (QPushButton *b = qobject_cast<QPushButton*>(itemJ->widget()))
        {
            b->setStyleSheet("QPushButton {background-color:white;}");
        }
    }
    for (int j = 0; j < ui->gridLayout->count(); ++j)
    {
        QLayoutItem *itemJ = ui->gridLayout->itemAt(j);
        if (QPushButton *b = qobject_cast<QPushButton*>(itemJ->widget()))
        {
            b->setStyleSheet("QPushButton { background-color:white; }");
        }
    }
    ui->my_erase->setToolTip("擦除的宽度是线宽，先调大线宽，再使用。不使用时将其移出画外。");

    // 初始化 slider 和 valueLabel
    slider = new QSlider(Qt::Horizontal, this);
    slider->setMinimum(100);
    slider->setMaximum(8000);
    slider->setValue(1000); // 初始化为 100%，对应值为 1000

    valueLabel = new QLabel(QString::number(slider->value()/10)+QString("%"), this);

    // 创建状态栏
    QStatusBar *statusBar = new QStatusBar(this);
    statusBar->addPermanentWidget(valueLabel);
    statusBar->addPermanentWidget(slider);
    setStatusBar(statusBar);

    // 连接菜单项的信号和槽
    ui->menu->setIcon(QIcon());
    ui->menu->setTitle("菜单(space)");


    // 为每个 QAction 设置快捷键
    ui->new_window->setShortcut(QKeySequence("Ctrl+N"));  // 新建文件快捷键 Ctrl+N
    ui->open_file->setShortcut(QKeySequence("Ctrl+O"));  // 打开文件快捷键 Ctrl+O
    ui->save->setShortcut(QKeySequence("Ctrl+S"));  // 保存文件快捷键 Ctrl+S
    ui->save_as_anothing_file->setShortcut(QKeySequence("Ctrl+Shift+S"));  // 另存为快捷键 Ctrl+Shift+S
    ui->exit->setShortcut(QKeySequence("Ctrl+Q"));  // 退出快捷键 Ctrl+Q
    ui->redo->setShortcut(QKeySequence("Ctrl+Y"));  // 重做快捷键 Ctrl+Y
    ui->undo->setShortcut(QKeySequence("Ctrl+Z"));  // 撤销快捷键 Ctrl+Z

    // 设置显示菜单的快捷键（例如 Ctrl+M）
    showMenuAction = new QAction(this);
    this->showMenuAction->setShortcut(QKeySequence("Ctrl+Space"));
    ui->menubar->addAction(this->showMenuAction);

    // 连接菜单项的 triggered 信号和槽函数
    connect(ui->new_window, &QAction::triggered, this, [this]() {
        startNewDrawingProcess();
    });

    connect(ui->open_file, &QAction::triggered, this, [this]() {
        openImage();
    });

    connect(ui->save, &QAction::triggered, this, [this]() {
        saveImage();
    });

    connect(ui->save_as_anothing_file, &QAction::triggered, this, [this]() {
        anotheringsaveImage();
    });

    connect(ui->exit, &QAction::triggered, this, [this]() {
        exitApp();
    });

    connect(ui->redo, &QAction::triggered, this, [this]() {
        int result = customImage->redoimage();
        if (result == -1) {
            QMessageBox::information(this, "信息", "已是最后一个.");
        }
    });

    connect(ui->undo, &QAction::triggered, this, [this]() {
        int result = customImage->undoimage();
        if (result == -1) {
            QMessageBox::information(this, "信息", "已是第一个.");
        }
    });

    // 连接显示菜单快捷键的触发事件
    connect(showMenuAction, &QAction::triggered, this, [this]() {
        ui->menu->exec(QCursor::pos());  // 显示菜单
    });


    //初始化功能映射
    functionMap["painting"]=all_my_function::painting;
    functionMap["size"]=all_my_function::size;
    functionMap["color_extractor"]=all_my_function::color_extractor;
    functionMap["my_erase"]=all_my_function::my_erase;
    functionMap["fill"]=all_my_function::fill;
    functionMap["crop"]=all_my_function::crop;
    functionMap["right_rotation"]=all_my_function::right_rotation;
    functionMap["left_rotation"]=all_my_function::left_rotation;
    functionMap["flip_horizontally"]=all_my_function::flip_horizontally;
    functionMap["flip_vertically"]=all_my_function::flip_vertically;

    // 初始化图形映射
    graphicsMap["basic"] = all_my_graphics::basic;
    graphicsMap["straight_line"] = all_my_graphics::straight_line;
    graphicsMap["right_circle"] = all_my_graphics::right_circle;
    graphicsMap["ellipse"] = all_my_graphics::ellipse;
    graphicsMap["isosceles_triangle"] = all_my_graphics::isosceles_triangle;
    graphicsMap["right_triangle"] = all_my_graphics::right_triangle;
    graphicsMap["right_rectangle"] = all_my_graphics::right_rectangle;
    graphicsMap["rounded_rectangle"] = all_my_graphics::rounded_rectangle;
    graphicsMap["diamond"] = all_my_graphics::diamond;
    graphicsMap["hexagon"] = all_my_graphics::hexagon;
    graphicsMap["four_pointed_star"] = all_my_graphics::four_pointed_star;
    graphicsMap["five_pointed_star"] = all_my_graphics::five_pointed_star;
    graphicsMap["six_pointed_star"] = all_my_graphics::six_pointed_star;
    graphicsMap["lightning"] = all_my_graphics::lightning;
    graphicsMap["left"] = all_my_graphics::left;
    graphicsMap["right"] = all_my_graphics::right;
    graphicsMap["top"] = all_my_graphics::top;
    graphicsMap["bottom"] = all_my_graphics::bottom;
    graphicsMap["rounded_rectangle_annotation"] = all_my_graphics::rounded_rectangle_annotation;
    graphicsMap["cloud_annotation"] = all_my_graphics::cloud_annotation;
    graphicsMap["circle_annotation"] = all_my_graphics::circle_annotation;


    // 初始化菜单项
    showBoundaryAction = new QAction(tr("显示边界"), this);
    hideBoundaryAction = new QAction(tr("隐藏边界"), this);

    // 设置初始状态
    showBoundaryAction->setEnabled(true);  // 可用
    hideBoundaryAction->setEnabled(false); // 禁用

    // 连接菜单项信号和槽
    connect(showBoundaryAction, &QAction::triggered, this, &MainWindow::showBoundary);
    connect(hideBoundaryAction, &QAction::triggered, this, &MainWindow::hideBoundary);

    // 启用右键菜单策略
    setContextMenuPolicy(Qt::DefaultContextMenu);

    // 初始化截图工具
    screenshotTool = new ScreenshotTool();

    connect(ui->screenshot, &QPushButton::clicked, this, [this]() {
        int delay = 0; // 默认延迟 0 秒

        // 判断哪个单选按钮被选中
        if (ui->zero->isChecked()) {
            delay = 0; // 0 秒延迟
        } else if (ui->three->isChecked()) {
            delay = 3000; // 3 秒延迟
        } else if (ui->five->isChecked()) {
            delay = 5000; // 5 秒延迟
        }

        qDebug() << "延迟" << delay / 1000 << "秒后启动截图";

        // 设置延迟
        QTimer::singleShot(delay, this, [this]() {
            qDebug() << "延迟结束后启动截图";
            this->screenshotTool->startScreenshot(); // 启动截图
        });
    });

    // 将单选按钮设置为未选中状态
    ui->zero->setChecked(true);
    connect(screenshotTool, &ScreenshotTool::screenshotTaken, this, [this]() {
        // 设置 customImage 的图像
        customImage->setimage(this->screenshotTool->getScreenshotImage());

        // 将当前窗口弹出并设置为最顶层
        this->raise();           // 将窗口提升到顶层
        this->activateWindow();   // 激活窗口，使其获得焦点
    });

    ui->screenshot->setStyleSheet("background-color:white");
    ui->ocr->setStyleSheet("background-color:white");
    this->close=new QPushButton(this);
    this->save=new QPushButton(this);
    this->copy=new QPushButton(this);
    this->text=new QTextEdit(this);

    this->close->setText("关闭");
    this->save->setText("保存");
    this->copy->setText("复制");
    viewWidth = this->width(); // 获取窗口的宽度
    viewHeight = this->height()-260; // 获取窗口的高度

    graphicsView->setGeometry(0, 220, viewWidth, viewHeight);
    // 设置 text 控件的位置和大小
    this->text->setGeometry(viewWidth, 220, viewWidth, viewHeight-25);
    // 设置 close 按钮的位置和大小
    this->close->setGeometry(viewWidth+200*2+180, viewHeight-25, 180, 25);

    // 设置 save 按钮的位置和大小
    this->save->setGeometry(viewWidth+200+180,viewHeight-25, 180,25);

    // 设置 copy 按钮的位置和大小
    this->copy->setGeometry(viewWidth+180, viewHeight-25,180,25);
    // 使用 Lambda 表达式连接按钮的点击事件
    connect(this->close, &QPushButton::clicked, [this]() {
        ui->ocr->setDown(false); // 将 close 按钮设为弹起状态
        viewWidth=(this->width());
        // 设置 text 控件的位置和大小
        this->text->setGeometry(viewWidth, 220, viewWidth, viewHeight-25);
        // 设置 close 按钮的位置和大小
        this->close->setGeometry(viewWidth+200*2+180, viewHeight-25, 180, 25);

        // 设置 save 按钮的位置和大小
        this->save->setGeometry(viewWidth+200+180,viewHeight-25 , 180,25);

        // 设置 copy 按钮的位置和大小
        this->copy->setGeometry(viewWidth+180, viewHeight-25,180,25);
        graphicsView->setGeometry(0, 220, viewWidth, viewHeight);
        qDebug() << "Close button is unchecked.";
    });

    connect(this->save, &QPushButton::clicked, [this]() {
        ui->ocr->setDown(true); // 将 close 按钮设为状态
        QString fileName = QFileDialog::getSaveFileName(this, "Save File", "", "Text Files (*.txt)"); // 打开文件保存对话框
        if (!fileName.isEmpty()) {
            QFile file(fileName);
            if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                QTextStream stream(&file);
                stream << this->text->toPlainText(); // 将 text 的内容写入文件
                file.close();
                qDebug() << "Text saved to file:" << fileName;
            } else {
                qDebug() << "Failed to save file:" << fileName;
            }
        }
    });

    connect(this->copy, &QPushButton::clicked, [this]() {
        ui->ocr->setDown(true); // 将 close 按钮设为状态
        QClipboard *clipboard = QApplication::clipboard();
        clipboard->setText(this->text->toPlainText()); // 将 text 的内容复制到剪切板
        qDebug() << "Text copied to clipboard.";
    });


}

MainWindow::~MainWindow()
{
    delete ui;
}
// 重写右键菜单事件
void MainWindow::contextMenuEvent(QContextMenuEvent *event){
    QMenu menu(this);
    menu.addAction(showBoundaryAction);
    menu.addAction(hideBoundaryAction);
    menu.exec(event->globalPos());
}
void MainWindow::showBoundary() {
    qDebug() << "显示边界";
    // 切换菜单项状态
    showBoundaryAction->setEnabled(false);
    hideBoundaryAction->setEnabled(true);

    customImage->set_expansion(true);
}

void MainWindow::hideBoundary() {
    qDebug() << "隐藏边界";
    // 切换菜单项状态
    showBoundaryAction->setEnabled(true);
    hideBoundaryAction->setEnabled(false);

    // 添加隐藏边界的逻辑
    customImage->set_expansion(false);
}
void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event); // 首先调用基类的resizeEvent函数

    viewHeight = this->height()-260; // 获取窗口的高度

    if(ui->ocr->isDown())
    {
        viewWidth=(this->width())/2;
        // 设置 text 控件的位置和大小
        this->text->setGeometry(viewWidth, 220, viewWidth, viewHeight-25);
        // 设置 close 按钮的位置和大小
        this->close->setGeometry(viewWidth*2-200*2-180, 220+viewHeight-25, 180, 25);

        // 设置 save 按钮的位置和大小
        this->save->setGeometry(viewWidth*2-200-180,220+viewHeight-25 , 180,25);

        // 设置 copy 按钮的位置和大小
        this->copy->setGeometry(viewWidth*2-180, 220+viewHeight-25,180,25);
    }
    else
    {
        viewWidth=(this->width());
        // 设置 text 控件的位置和大小
        this->text->setGeometry(viewWidth, 220, viewWidth, viewHeight-25);
        // 设置 close 按钮的位置和大小
        this->close->setGeometry(viewWidth+200*2+180, viewHeight-25, 180, 25);

        // 设置 save 按钮的位置和大小
        this->save->setGeometry(viewWidth+200+180,viewHeight-25 , 180,25);

        // 设置 copy 按钮的位置和大小
        this->copy->setGeometry(viewWidth+180, viewHeight-25,180,25);
    }
    graphicsView->setGeometry(0, 220, viewWidth, viewHeight);
    this->get_refresh();
    customImage->update();
}
void MainWindow::showEvent(QShowEvent * /*event*/)
{
    connect(ui->painting, &QPushButton::clicked, this, [=]() {
        // 变成灰色
        for (int j = 0; j < ui->gridLayout->count(); ++j) {
            QLayoutItem *itemJ = ui->gridLayout->itemAt(j);
            if (QPushButton *b = qobject_cast<QPushButton*>(itemJ->widget())) {
                b->setStyleSheet("QPushButton {background-color:white;}");
            }
        }
        // 设置布局中的按钮为白色
        for (int i = 0; i < ui->gridLayout_2->count(); ++i) {
            QLayoutItem *item = ui->gridLayout_2->itemAt(i);
            if (QPushButton *button = qobject_cast<QPushButton*>(item->widget())) {
                button->setStyleSheet("QPushButton {background-color:white;}");
            }
        }
        customImage->changefunction(painting);
        customImage->changegraphics(basic);
        this->hideBoundary();
        // 可以使用鼠标在scene上画线
        qDebug() << "按钮改变回去";
        ui->painting->setStyleSheet("QPushButton {background-color:QColor(200,200,200);}");
    });

    // 连接 spinBox 的 valueChanged 信号
    connect(ui->spinBox, QOverload<int>::of(&QSpinBox::valueChanged), this, [this](int value) {
        linewidth = value;
        customImage->setborderWidth(value);
        customImage->update();
    });

    // 监听边框的状态更改事件
    connect(ui->radioButton, &QRadioButton::toggled, this, [=](bool checked) {
        if (checked) {
            // 获取颜色值
            intred = ui->spinBox_2->value();
            intgreen = ui->spinBox_3->value();
            intblue = ui->spinBox_4->value();
            // 创建填充色
            QColor color(intred, intgreen, intblue);
            // 设置背景色
            ui->graphicsView_2->setStyleSheet(QString("background-color:%1").arg(color.name()));
            customImage->setforegroundColor(color,foreground_color);
            customImage->update();
        } else {
            // 清除填充色
            ui->graphicsView_2->setBackgroundBrush(Qt::NoBrush);
        }
    });
    // 监听填充的状态更改事件
    connect(ui->radioButton_2, &QRadioButton::toggled, this, [=](bool checked) {
        if (checked) {
            // 获取颜色值
            intred = ui->spinBox_2->value();
            intgreen = ui->spinBox_3->value();
            intblue = ui->spinBox_4->value();
            // 创建填充色
            QColor color(intred, intgreen, intblue);

            // 设置背景色
            ui->graphicsView_3->setStyleSheet(QString("background-color:%1").arg(color.name()));
            customImage->setbackgroundColor(color,background_color);
            customImage->update();

        } else {
            // 清除填充色
            ui->graphicsView_3->setBackgroundBrush(Qt::NoBrush);
        }
    });

    // 当空中的值更改时
    connect(ui->spinBox_2, QOverload<int>::of(&QSpinBox::valueChanged), this, [this]() {
        updateGraphicsViewColor(ui->radioButton, ui->radioButton_2);
    });
    connect(ui->spinBox_3, QOverload<int>::of(&QSpinBox::valueChanged), this, [this]() {
        updateGraphicsViewColor(ui->radioButton, ui->radioButton_2);
    });
    connect(ui->spinBox_4, QOverload<int>::of(&QSpinBox::valueChanged), this, [this]() {
        updateGraphicsViewColor(ui->radioButton, ui->radioButton_2);
    });

    // 当滑动条改变时，值要改变
    connect(ui->horizontalSlider, &QSlider::valueChanged, ui->spinBox_2, &QSpinBox::setValue);
    connect(ui->horizontalSlider_2, &QSlider::valueChanged, ui->spinBox_3, &QSpinBox::setValue);
    connect(ui->horizontalSlider_3, &QSlider::valueChanged, ui->spinBox_4, &QSpinBox::setValue);

    connect(ui->pushButton_14, &QPushButton::clicked, this, [=]() {
        foreground_color = !foreground_color;
        customImage->setforegroundColor(customImage->getforegroundColor(), foreground_color);

        customImage->update();

        // 根据 foreground_color 设置按钮状态和标题
        ui->pushButton_14->setText(foreground_color ? "启用" : "禁用");
    });

    connect(ui->pushButton_15, &QPushButton::clicked, this, [=]() {
        background_color = !background_color;
        customImage->setbackgroundColor(customImage->getbackgroundColr(), background_color);

        customImage->update();

        // 根据 background_color 设置按钮状态和标题
        ui->pushButton_15->setText(background_color ? "启用" : "禁用");
    });

    for (int i = 0; i < ui->gridLayout->count(); ++i) {
        QLayoutItem *item = ui->gridLayout->itemAt(i);
        if (QPushButton *button = qobject_cast<QPushButton*>(item->widget())) {
            connect(button, &QPushButton::clicked, this, [this, button]() {
                // 遍历布局中的所有按钮
                for (int j = 0; j < ui->gridLayout->count(); ++j) {
                    QLayoutItem *itemJ = ui->gridLayout->itemAt(j);
                    if (QPushButton *b = qobject_cast<QPushButton*>(itemJ->widget())) {
                        b->setStyleSheet("QPushButton {background-color:white;}");
                    }
                }
                for (int j = 0; j < ui->gridLayout_2->count(); ++j) {
                    QLayoutItem *itemJ = ui->gridLayout_2->itemAt(j);
                    if (QPushButton *b = qobject_cast<QPushButton*>(itemJ->widget())) {
                        b->setStyleSheet("QPushButton {background-color:white;}");
                    }
                }

                ui->painting->setDown(true);
                // 设置被点击的按钮为灰色
                button->setStyleSheet("QPushButton {background-color:QColor(200,200,200);}");
                QString buttonObjectName = button->objectName();
                qDebug() << buttonObjectName;
                auto it = graphicsMap.find(buttonObjectName);
                if (it!= graphicsMap.end()) {
                    all_my_graphics graphicsType = it->second;
                    qDebug() << graphicsType;
                    customImage->changegraphics(graphicsType);
                    this->hideBoundary();
                }
            });
        }
    }

    for (int i = 0; i < ui->gridLayout_2->count(); ++i) {
        QLayoutItem *item = ui->gridLayout_2->itemAt(i);
        if (QPushButton *button = qobject_cast<QPushButton*>(item->widget())) {
            connect(button, &QPushButton::clicked, this, [this, button]() {
                for (int j = 0; j < ui->gridLayout->count(); ++j) {
                    QLayoutItem *itemJ = ui->gridLayout->itemAt(j);
                    if (QPushButton *b = qobject_cast<QPushButton*>(itemJ->widget())) {
                        b->setStyleSheet("QPushButton {background-color:white;}");
                    }
                }
                // 遍历布局中的所有按钮
                for (int j = 0; j < ui->gridLayout_2->count(); ++j) {
                    QLayoutItem *itemJ = ui->gridLayout_2->itemAt(j);
                    if (QPushButton *b = qobject_cast<QPushButton*>(itemJ->widget())) {
                        b->setStyleSheet("QPushButton {background-color:white;}");
                    }
                }

                ui->painting->setStyleSheet("QPushButton {background-color:white;}");
                ui->painting->setDown(false);
                // 设置被点击的按钮
                button->setStyleSheet("QPushButton {background-color:QColor(200,200,200);}");
                QString buttonObjectName = button->objectName();
                qDebug() << buttonObjectName;
                auto it = functionMap.find(buttonObjectName);
                if (it!= functionMap.end()) {
                    all_my_function functionType = it->second;
                    qDebug() << functionType;
                    customImage->changefunction(functionType);
                    this->hideBoundary();
                }
            });
        }
    }

    connect(customImage, &QCustomImage::change_color_signals, this, &MainWindow::get_color_signal);

    connect(customImage,&QCustomImage::refresh_signals,this,&MainWindow::get_refresh);

    // 连接滑块的值改变事件
    connect(slider, &QSlider::valueChanged, [this](int value) {
        // customImage 进行缩放
        valueLabel->setText(QString::number(value/10)+QString("%"));

        qreal percentage = sqrt(value / 1000.0);
        customImage->doScaling(percentage);
    });

}

void MainWindow::updateGraphicsViewColor(QRadioButton* radioButton1,QRadioButton* radioButton2){


    if(radioButton1->isChecked()){
        //获取颜色值
        intred=ui->spinBox_2->value();
        intgreen=ui->spinBox_3->value();
        intblue=ui->spinBox_4->value();

        //创建填充色
        QColor color(intred,intgreen,intblue);
        //设置背景色
        ui->graphicsView_2->setStyleSheet(QString("background-color:%1").arg(color.name()));
        customImage->setforegroundColor(color,foreground_color);
        customImage->update();
    }
    else if(radioButton2->isChecked()){
        //获取颜色值
        intred=ui->spinBox_2->value();
        intgreen=ui->spinBox_3->value();
        intblue=ui->spinBox_4->value();

        //创建填充色
        QColor color(intred,intgreen,intblue);
        //设置背景色
        ui->graphicsView_3->setStyleSheet(QString("background-color:%1").arg(color.name()));
        customImage->setbackgroundColor(color,background_color);
        customImage->update();
    }

    ui->horizontalSlider->setValue(intred);
    ui->horizontalSlider_2->setValue(intgreen);
    ui->horizontalSlider_3->setValue(intblue);

}
void MainWindow::get_color_signal(const QColor &c)
{
    int redValue = c.red();
    int greenValue = c.green();
    int blueValue = c.blue();

    ui->spinBox_2->setValue(redValue);
    ui->spinBox_3->setValue(greenValue);
    ui->spinBox_4->setValue(blueValue);

    ui->horizontalSlider->setValue(redValue);
    ui->horizontalSlider_2->setValue(greenValue);
    ui->horizontalSlider_3->setValue(blueValue);

    if(ui->radioButton->isChecked())
    {
        ui->graphicsView_2->setStyleSheet(QString("background-color:%1").arg(c.name()));
        if(foreground_color)
        {
            qDebug() << "前景色";
            QColor nonConstColor = c;  // 创建一个非const副本
            customImage->setforegroundColor(nonConstColor, foreground_color);
        }
    }
    else
    {
        ui->graphicsView_3->setStyleSheet(QString("background-color:%1").arg(c.name()));
        if(background_color)
        {
            qDebug() << "后景色";
            QColor nonConstColor = c;  // 创建一个非const副本
            customImage->setbackgroundColor(nonConstColor, background_color);
        }
    }
    update();
}
// 在cpp文件中实现saveImage
void MainWindow::saveImage()
{
    // 询问用户是否保存修改
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Save Changes", "是否保存修改？",
                                                              QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
    if (reply == QMessageBox::Yes) {
        QString fileFilter = "Image Files (*.png *.jpg *.bmp);;All Files (*)";
        if (this->filename.isNull()) {
            this->filename = QFileDialog::getSaveFileName(this, "Save Image", "", fileFilter);
        }

        if (this->filename.isEmpty()) {
            QMessageBox::warning(this, "Error", "Failed to save the image.");
            return;
        }
        if (!customImage->getImage().save(this->filename)) {
            QMessageBox::warning(this, "Error", "Failed to save the image.");
        } else {
            QMessageBox::information(this, "Success", "Image saved successfully.");
        }
    } else  {
        return;
    }
    // 如果用户选择No，则直接退出函数，不执行保存操作
}
void MainWindow::anotheringsaveImage()
{
    // 根据需要使用someValue参数，或者忽略它
    QString fileFilter = "Image Files (*.png *.jpg *.bmp);;All Files (*)";

    this->filename = QFileDialog::getSaveFileName(this, "Save anothering Image", "", fileFilter);

    if (this->filename.isEmpty()) {
        QMessageBox::warning(this, "Error", "Failed to save the image.");
        return;
    }
    if (!customImage->getImage().save(this->filename)) {
        QMessageBox::warning(this, "Error", "Failed to save the image.");
    } else {
        QMessageBox::information(this, "Success", "Image saved successfully.");
    }
}
void MainWindow::startNewDrawingProcess()
{
    QProcess *process = new QProcess(this);
    // 假设画图板程序在当前目录下，根据实际情况修改路径
    process->start("drawing.exe");
}
// 在cpp文件中实现openImage
void MainWindow::openImage()
{
    // 询问用户是否保存修改
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Save Changes", "是否保存修改？",
                                                              QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
    if (reply == QMessageBox::Yes) {
        QString fileFilter = "Image Files (*.png *.jpg *.bmp);;All Files (*)";
        if (this->filename.isNull()) {
            this->filename = QFileDialog::getSaveFileName(this, "Save Image", "", fileFilter);
        }

        if (this->filename.isEmpty()) {
            QMessageBox::warning(this, "Error", "Failed to save the image.");
            return;
        }
        if (!customImage->getImage().save(this->filename)) {
            QMessageBox::warning(this, "Error", "Failed to save the image.");
        } else {
            QMessageBox::information(this, "Success", "Image saved successfully.");
        }
    } else  if(reply==QMessageBox::Cancel){
        return;
    }
    QString fileFilter = "Image Files (*.png *.jpg *.bmp);;All Files (*)";
    this->filename = QFileDialog::getOpenFileName(this, "Open Image", "", fileFilter);
    if (this->filename.isEmpty()) {
        QMessageBox::warning(this, "Error", "No file selected.");
        return;
    }
    QImage Image = QImage(this->filename);
    if (Image.isNull()) {
        QMessageBox::warning(this, "Error", "Failed to load the image.");
    } else {
        customImage->setimage(Image);
    }
}
// 在cpp文件中实现exitApp
void MainWindow::exitApp()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Save Changes", "Do you want to save the current file?",
                                  QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
    if(reply==QMessageBox::Cancel)
    {
        return;
    }
    else
    {
        if (reply == QMessageBox::Yes) {
            saveImage(); // 调用之前定义的保存图像函数
        }
        QApplication::quit();
    }
}
void MainWindow::get_refresh()
{
    // 获取QSlider的值，计算缩放比例
    qreal percentage = sqrt((slider->value()) / 1000.0);

    // 设置视图的变换矩阵
    QTransform transform;
    transform.scale(percentage, percentage);
    graphicsView->setTransform(transform);

    // 获取 customImage 的边界
    QRectF viewRect = customImage->boundingRect();

    // 设置场景的可视区域
    graphicsView->setSceneRect(viewRect);

    // **确保 customImage 居中**
    graphicsView->centerOn(customImage);
}

void MainWindow::showFloatingMessage(const QString &message, int timeout) {
    // 创建浮动提示框
    QLabel *floatingMessage = new QLabel(this);
    floatingMessage->setText(message);
    floatingMessage->setStyleSheet("background-color: white; border: 1px solid black; padding: 5px;");
    floatingMessage->setAlignment(Qt::AlignCenter);

    // 设置提示框位置和大小
    floatingMessage->setGeometry(width() / 2 - 100, height() / 2 - 25, 200, 50);
    floatingMessage->show();

    // 设置定时器，自动关闭提示框
    QTimer::singleShot(timeout, floatingMessage, &QLabel::deleteLater);
}

void MainWindow::on_ocr_clicked() {

    // 调整 UI 布局
    if (!ui->ocr->isDown()) {

        // 设置按钮为按下状态
        ui->ocr->setDown(true);

        viewWidth = (this->width()) / 2;

        graphicsView->setGeometry(0, 220, viewWidth, viewHeight);
        this->text->setGeometry(viewWidth, 220, viewWidth, viewHeight - 25);
        this->close->setGeometry(viewWidth * 2 - 200 * 2 - 180, 220 + viewHeight - 25, 180, 25);
        this->save->setGeometry(viewWidth * 2 - 200 - 180, 220 + viewHeight - 25, 180, 25);
        this->copy->setGeometry(viewWidth * 2 - 180, 220 + viewHeight - 25, 180, 25);
        this->get_refresh();
        customImage->update();
    }

    // 清空文本框
    this->text->clear();

    // 显示浮动提示框
    showFloatingMessage("正在识别中，请稍候...", 1000); // 显示 3 秒

    // 将图像临时保存为本地图片
    QString imagePath = qApp->applicationDirPath() + "/Tesseract-OCR/image/temp.png";
    QImage image = customImage->getImage();
    if (!image.save(imagePath)) {
        qDebug() << "Failed to save image";
        showFloatingMessage("保存图像失败！", 1000); // 显示 3 秒
        return;
    }

    // 使用 QtConcurrent 异步执行 OCR 识别
    QtConcurrent::run([this, imagePath]() {
        // 识别结果输出路径
        QString retOutPath = qApp->applicationDirPath() + "/result";

        // 调用 OCR
        QStringList args;
        args << imagePath
             << retOutPath
             << QString("-l")
             << QString("chi_sim+eng");
        QString pathExe = qApp->applicationDirPath() + "/Tesseract-OCR/tesseract.exe";
        QString program(pathExe);
        QProcess pTesseract;
        pTesseract.start(program, args);

        // 等待识别完成
        bool bResult = pTesseract.waitForFinished();

        // 识别完成后，更新 UI
        QMetaObject::invokeMethod(this, [this, retOutPath, bResult, imagePath]() {
            if (!bResult) {
                showFloatingMessage("OCR 识别失败！", 1000); // 显示 3 秒
                return;
            }

            // 读取识别结果
            QString txtPath = QString("%1.txt").arg(retOutPath);
            QFile file(txtPath);
            if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                qDebug() << file.errorString();
                showFloatingMessage("读取识别结果失败！", 1000); // 显示 3 秒
                return;
            }

            QTextStream inText(&file);
            while (!inText.atEnd()) {
                QString lineTxt = inText.readLine();
                this->text->append(lineTxt);
            }
            file.close();

            // 删除本地临时文件
            QFile::remove(imagePath);

            // 显示“识别完成”提示
            showFloatingMessage("识别完成！", 1000); // 显示 3 秒
        });
    });
}
