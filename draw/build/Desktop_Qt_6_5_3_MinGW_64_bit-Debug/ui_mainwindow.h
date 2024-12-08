/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox_2;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QPushButton *my_erase;
    QPushButton *size;
    QPushButton *color_extractor;
    QPushButton *fill;
    QPushButton *crop;
    QGroupBox *groupBox;
    QSpinBox *spinBox;
    QLabel *label_2;
    QPushButton *painting;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QGraphicsView *graphicsView_2;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *radioButton;
    QPushButton *pushButton_14;
    QGraphicsView *graphicsView_3;
    QHBoxLayout *horizontalLayout_5;
    QRadioButton *radioButton_2;
    QPushButton *pushButton_15;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *hexagon;
    QPushButton *six_pointed_star;
    QPushButton *right_circle;
    QPushButton *five_pointed_star;
    QPushButton *diamond;
    QPushButton *four_pointed_star;
    QPushButton *ellipse;
    QPushButton *right_rectangle;
    QPushButton *rounded_rectangle;
    QPushButton *straight_line;
    QPushButton *right_triangle;
    QPushButton *isosceles_triangle;
    QPushButton *lightning;
    QPushButton *left;
    QPushButton *right;
    QPushButton *top;
    QPushButton *bottom;
    QPushButton *rounded_rectangle_annotation;
    QPushButton *cloud_annotation;
    QPushButton *circle_annotation;
    QSpinBox *spinBox_2;
    QLabel *label_3;
    QSlider *horizontalSlider;
    QSpinBox *spinBox_3;
    QLabel *label_5;
    QSlider *horizontalSlider_2;
    QSpinBox *spinBox_4;
    QLabel *label_4;
    QSlider *horizontalSlider_3;
    QMenuBar *menubar;
    QMenu *menuopen_file;
    QMenu *menusave;
    QMenu *menusave_anothing_file;
    QMenu *menuexit;
    QMenu *menuundo;
    QMenu *menuredo;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1315, 746);
        MainWindow->setTabletTracking(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(0, 0, 200, 200));
        QFont font;
        font.setPointSize(10);
        groupBox_2->setFont(font);
        gridLayoutWidget_2 = new QWidget(groupBox_2);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(10, 10, 180, 91));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        my_erase = new QPushButton(gridLayoutWidget_2);
        my_erase->setObjectName("my_erase");
        my_erase->setMinimumSize(QSize(40, 40));
        my_erase->setMaximumSize(QSize(40, 40));
        QFont font1;
        font1.setPointSize(8);
        my_erase->setFont(font1);
        my_erase->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/earse.svg);"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/CarbonErase.svg"), QSize(), QIcon::Normal, QIcon::Off);
        my_erase->setIcon(icon);
        my_erase->setIconSize(QSize(32, 32));
        my_erase->setAutoExclusive(true);

        gridLayout_2->addWidget(my_erase, 0, 3, 1, 1);

        size = new QPushButton(gridLayoutWidget_2);
        size->setObjectName("size");
        size->setMinimumSize(QSize(40, 40));
        size->setMaximumSize(QSize(40, 40));
        size->setFont(font1);
        size->setStyleSheet(QString::fromUtf8(""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/SimpleLineIconsSizeFullscreen.svg"), QSize(), QIcon::Normal, QIcon::Off);
        size->setIcon(icon1);
        size->setIconSize(QSize(32, 32));
        size->setAutoExclusive(true);

        gridLayout_2->addWidget(size, 0, 0, 1, 1);

        color_extractor = new QPushButton(gridLayoutWidget_2);
        color_extractor->setObjectName("color_extractor");
        color_extractor->setMinimumSize(QSize(40, 40));
        color_extractor->setMaximumSize(QSize(40, 40));
        color_extractor->setFont(font1);
        color_extractor->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/color picker.svg);"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/FaEyedropper.svg"), QSize(), QIcon::Normal, QIcon::Off);
        color_extractor->setIcon(icon2);
        color_extractor->setIconSize(QSize(32, 32));
        color_extractor->setAutoExclusive(true);

        gridLayout_2->addWidget(color_extractor, 0, 1, 1, 1);

        fill = new QPushButton(gridLayoutWidget_2);
        fill->setObjectName("fill");
        fill->setMinimumSize(QSize(40, 40));
        fill->setMaximumSize(QSize(40, 40));
        fill->setFont(font1);
        fill->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/fill.svg);"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/MdiFill.svg"), QSize(), QIcon::Normal, QIcon::Off);
        fill->setIcon(icon3);
        fill->setIconSize(QSize(32, 32));
        fill->setAutoExclusive(true);

        gridLayout_2->addWidget(fill, 0, 4, 1, 1);

        crop = new QPushButton(gridLayoutWidget_2);
        crop->setObjectName("crop");
        crop->setMinimumSize(QSize(40, 40));
        crop->setMaximumSize(QSize(40, 40));
        crop->setFont(font1);
        crop->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/cut out.svg);"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix1/RiCropLine.svg"), QSize(), QIcon::Normal, QIcon::Off);
        crop->setIcon(icon4);
        crop->setIconSize(QSize(32, 32));
        crop->setAutoExclusive(true);

        gridLayout_2->addWidget(crop, 1, 0, 1, 1);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(200, 0, 940, 200));
        spinBox = new QSpinBox(groupBox);
        spinBox->setObjectName("spinBox");
        spinBox->setGeometry(QRect(90, 60, 100, 30));
        spinBox->setFont(font);
        spinBox->setMinimum(1);
        spinBox->setMaximum(255);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 60, 80, 30));
        QFont font2;
        font2.setPointSize(12);
        label_2->setFont(font2);
        painting = new QPushButton(groupBox);
        painting->setObjectName("painting");
        painting->setGeometry(QRect(10, 10, 180, 25));
        QFont font3;
        font3.setPointSize(13);
        painting->setFont(font3);
        painting->setAutoExclusive(true);
        verticalLayoutWidget_2 = new QWidget(groupBox);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(210, 10, 161, 171));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        graphicsView_2 = new QGraphicsView(verticalLayoutWidget_2);
        graphicsView_2->setObjectName("graphicsView_2");

        verticalLayout_2->addWidget(graphicsView_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        radioButton = new QRadioButton(verticalLayoutWidget_2);
        radioButton->setObjectName("radioButton");
        radioButton->setFont(font);

        horizontalLayout_4->addWidget(radioButton);

        pushButton_14 = new QPushButton(verticalLayoutWidget_2);
        pushButton_14->setObjectName("pushButton_14");

        horizontalLayout_4->addWidget(pushButton_14);


        verticalLayout_2->addLayout(horizontalLayout_4);

        graphicsView_3 = new QGraphicsView(verticalLayoutWidget_2);
        graphicsView_3->setObjectName("graphicsView_3");

        verticalLayout_2->addWidget(graphicsView_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        radioButton_2 = new QRadioButton(verticalLayoutWidget_2);
        radioButton_2->setObjectName("radioButton_2");
        radioButton_2->setFont(font);

        horizontalLayout_5->addWidget(radioButton_2);

        pushButton_15 = new QPushButton(verticalLayoutWidget_2);
        pushButton_15->setObjectName("pushButton_15");

        horizontalLayout_5->addWidget(pushButton_15);


        verticalLayout_2->addLayout(horizontalLayout_5);

        gridLayoutWidget = new QWidget(groupBox);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(570, 10, 364, 161));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        hexagon = new QPushButton(gridLayoutWidget);
        hexagon->setObjectName("hexagon");
        hexagon->setMinimumSize(QSize(40, 40));
        hexagon->setMaximumSize(QSize(40, 40));
        hexagon->setFont(font1);
        hexagon->setStyleSheet(QString::fromUtf8(""));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/prefix1/MdiHexagonOutline.svg"), QSize(), QIcon::Normal, QIcon::Off);
        hexagon->setIcon(icon5);
        hexagon->setIconSize(QSize(32, 32));
        hexagon->setAutoExclusive(false);

        gridLayout->addWidget(hexagon, 1, 1, 1, 1);

        six_pointed_star = new QPushButton(gridLayoutWidget);
        six_pointed_star->setObjectName("six_pointed_star");
        six_pointed_star->setMinimumSize(QSize(40, 40));
        six_pointed_star->setMaximumSize(QSize(40, 40));
        six_pointed_star->setFont(font1);
        six_pointed_star->setStyleSheet(QString::fromUtf8(""));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/new/prefix1/MdiHexagramOutline.svg"), QSize(), QIcon::Normal, QIcon::Off);
        six_pointed_star->setIcon(icon6);
        six_pointed_star->setIconSize(QSize(32, 32));
        six_pointed_star->setAutoExclusive(true);

        gridLayout->addWidget(six_pointed_star, 1, 4, 1, 1);

        right_circle = new QPushButton(gridLayoutWidget);
        right_circle->setObjectName("right_circle");
        right_circle->setMinimumSize(QSize(40, 40));
        right_circle->setMaximumSize(QSize(40, 40));
        right_circle->setFont(font1);
        right_circle->setStyleSheet(QString::fromUtf8(""));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/new/prefix1/circle.svg"), QSize(), QIcon::Normal, QIcon::Off);
        right_circle->setIcon(icon7);
        right_circle->setIconSize(QSize(32, 32));
        right_circle->setAutoExclusive(true);

        gridLayout->addWidget(right_circle, 0, 1, 1, 1);

        five_pointed_star = new QPushButton(gridLayoutWidget);
        five_pointed_star->setObjectName("five_pointed_star");
        five_pointed_star->setMinimumSize(QSize(40, 40));
        five_pointed_star->setMaximumSize(QSize(40, 40));
        five_pointed_star->setFont(font1);
        five_pointed_star->setStyleSheet(QString::fromUtf8(""));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/new/prefix1/five-pointed star.svg"), QSize(), QIcon::Normal, QIcon::Off);
        five_pointed_star->setIcon(icon8);
        five_pointed_star->setIconSize(QSize(32, 32));
        five_pointed_star->setAutoExclusive(true);

        gridLayout->addWidget(five_pointed_star, 1, 3, 1, 1);

        diamond = new QPushButton(gridLayoutWidget);
        diamond->setObjectName("diamond");
        diamond->setMinimumSize(QSize(40, 40));
        diamond->setMaximumSize(QSize(40, 40));
        diamond->setFont(font1);
        diamond->setStyleSheet(QString::fromUtf8(""));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/new/prefix1/MdiRhombusOutline.svg"), QSize(), QIcon::Normal, QIcon::Off);
        diamond->setIcon(icon9);
        diamond->setIconSize(QSize(32, 32));
        diamond->setAutoExclusive(true);

        gridLayout->addWidget(diamond, 1, 0, 1, 1);

        four_pointed_star = new QPushButton(gridLayoutWidget);
        four_pointed_star->setObjectName("four_pointed_star");
        four_pointed_star->setMinimumSize(QSize(40, 40));
        four_pointed_star->setMaximumSize(QSize(40, 40));
        four_pointed_star->setFont(font1);
        four_pointed_star->setStyleSheet(QString::fromUtf8(""));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/new/prefix1/MdiStarFourPointsOutline.svg"), QSize(), QIcon::Normal, QIcon::Off);
        four_pointed_star->setIcon(icon10);
        four_pointed_star->setIconSize(QSize(32, 32));
        four_pointed_star->setAutoExclusive(true);

        gridLayout->addWidget(four_pointed_star, 1, 2, 1, 1);

        ellipse = new QPushButton(gridLayoutWidget);
        ellipse->setObjectName("ellipse");
        ellipse->setMinimumSize(QSize(40, 40));
        ellipse->setMaximumSize(QSize(40, 40));
        ellipse->setFont(font1);
        ellipse->setStyleSheet(QString::fromUtf8(""));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/new/prefix1/ellipse.svg"), QSize(), QIcon::Normal, QIcon::Off);
        ellipse->setIcon(icon11);
        ellipse->setIconSize(QSize(32, 32));
        ellipse->setAutoExclusive(true);

        gridLayout->addWidget(ellipse, 0, 2, 1, 1);

        right_rectangle = new QPushButton(gridLayoutWidget);
        right_rectangle->setObjectName("right_rectangle");
        right_rectangle->setMinimumSize(QSize(40, 40));
        right_rectangle->setMaximumSize(QSize(40, 40));
        right_rectangle->setFont(font1);
        right_rectangle->setStyleSheet(QString::fromUtf8(""));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/new/prefix1/MdiRectangleOutline.svg"), QSize(), QIcon::Normal, QIcon::Off);
        right_rectangle->setIcon(icon12);
        right_rectangle->setIconSize(QSize(32, 32));
        right_rectangle->setAutoExclusive(true);

        gridLayout->addWidget(right_rectangle, 0, 5, 1, 1);

        rounded_rectangle = new QPushButton(gridLayoutWidget);
        rounded_rectangle->setObjectName("rounded_rectangle");
        rounded_rectangle->setMinimumSize(QSize(40, 40));
        rounded_rectangle->setMaximumSize(QSize(40, 40));
        rounded_rectangle->setFont(font1);
        rounded_rectangle->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/rectangle.svg);"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/new/prefix1/TopcoatRoundedrectangleOutline.svg"), QSize(), QIcon::Normal, QIcon::Off);
        rounded_rectangle->setIcon(icon13);
        rounded_rectangle->setIconSize(QSize(32, 32));
        rounded_rectangle->setAutoExclusive(true);

        gridLayout->addWidget(rounded_rectangle, 0, 6, 1, 1);

        straight_line = new QPushButton(gridLayoutWidget);
        straight_line->setObjectName("straight_line");
        straight_line->setMinimumSize(QSize(40, 40));
        straight_line->setMaximumSize(QSize(40, 40));
        straight_line->setFont(font1);
        straight_line->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/line.svg);"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/new/prefix1/IconoirLinear.svg"), QSize(), QIcon::Normal, QIcon::Off);
        straight_line->setIcon(icon14);
        straight_line->setIconSize(QSize(32, 32));
        straight_line->setAutoExclusive(true);

        gridLayout->addWidget(straight_line, 0, 0, 1, 1);

        right_triangle = new QPushButton(gridLayoutWidget);
        right_triangle->setObjectName("right_triangle");
        right_triangle->setMinimumSize(QSize(40, 40));
        right_triangle->setMaximumSize(QSize(40, 40));
        right_triangle->setFont(font1);
        right_triangle->setStyleSheet(QString::fromUtf8(""));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/new/prefix1/HugeiconsRightTriangle.svg"), QSize(), QIcon::Normal, QIcon::Off);
        right_triangle->setIcon(icon15);
        right_triangle->setIconSize(QSize(32, 32));
        right_triangle->setAutoExclusive(true);

        gridLayout->addWidget(right_triangle, 0, 4, 1, 1);

        isosceles_triangle = new QPushButton(gridLayoutWidget);
        isosceles_triangle->setObjectName("isosceles_triangle");
        isosceles_triangle->setMinimumSize(QSize(40, 40));
        isosceles_triangle->setMaximumSize(QSize(40, 40));
        isosceles_triangle->setFont(font1);
        isosceles_triangle->setStyleSheet(QString::fromUtf8(""));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/new/prefix1/MdiTriangleDownOutline.svg"), QSize(), QIcon::Normal, QIcon::Off);
        isosceles_triangle->setIcon(icon16);
        isosceles_triangle->setIconSize(QSize(32, 32));
        isosceles_triangle->setAutoExclusive(true);

        gridLayout->addWidget(isosceles_triangle, 0, 3, 1, 1);

        lightning = new QPushButton(gridLayoutWidget);
        lightning->setObjectName("lightning");
        lightning->setMinimumSize(QSize(40, 40));
        lightning->setMaximumSize(QSize(40, 40));
        lightning->setFont(font1);
        lightning->setStyleSheet(QString::fromUtf8(""));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/new/prefix1/PhLightningFill.svg"), QSize(), QIcon::Normal, QIcon::Off);
        lightning->setIcon(icon17);
        lightning->setIconSize(QSize(32, 32));
        lightning->setAutoExclusive(true);

        gridLayout->addWidget(lightning, 1, 5, 1, 1);

        left = new QPushButton(gridLayoutWidget);
        left->setObjectName("left");
        left->setMinimumSize(QSize(40, 40));
        left->setMaximumSize(QSize(40, 40));
        left->setFont(font1);
        left->setStyleSheet(QString::fromUtf8(""));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/new/prefix1/LsArrowleft.svg"), QSize(), QIcon::Normal, QIcon::Off);
        left->setIcon(icon18);
        left->setIconSize(QSize(32, 32));
        left->setAutoExclusive(true);

        gridLayout->addWidget(left, 1, 6, 1, 1);

        right = new QPushButton(gridLayoutWidget);
        right->setObjectName("right");
        right->setMinimumSize(QSize(40, 40));
        right->setMaximumSize(QSize(40, 40));
        right->setFont(font1);
        right->setStyleSheet(QString::fromUtf8(""));
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/new/prefix1/LsArrowright.svg"), QSize(), QIcon::Normal, QIcon::Off);
        right->setIcon(icon19);
        right->setIconSize(QSize(32, 32));
        right->setAutoExclusive(true);

        gridLayout->addWidget(right, 2, 0, 1, 1);

        top = new QPushButton(gridLayoutWidget);
        top->setObjectName("top");
        top->setMinimumSize(QSize(40, 40));
        top->setMaximumSize(QSize(40, 40));
        top->setFont(font1);
        top->setStyleSheet(QString::fromUtf8(""));
        QIcon icon20;
        icon20.addFile(QString::fromUtf8(":/new/prefix1/LsArrowup.svg"), QSize(), QIcon::Normal, QIcon::Off);
        top->setIcon(icon20);
        top->setIconSize(QSize(32, 32));
        top->setAutoExclusive(true);

        gridLayout->addWidget(top, 2, 1, 1, 1);

        bottom = new QPushButton(gridLayoutWidget);
        bottom->setObjectName("bottom");
        bottom->setMinimumSize(QSize(40, 40));
        bottom->setMaximumSize(QSize(40, 40));
        bottom->setFont(font1);
        bottom->setStyleSheet(QString::fromUtf8(""));
        QIcon icon21;
        icon21.addFile(QString::fromUtf8(":/new/prefix1/LsArrowdown.svg"), QSize(), QIcon::Normal, QIcon::Off);
        bottom->setIcon(icon21);
        bottom->setIconSize(QSize(32, 32));
        bottom->setAutoExclusive(true);

        gridLayout->addWidget(bottom, 2, 2, 1, 1);

        rounded_rectangle_annotation = new QPushButton(gridLayoutWidget);
        rounded_rectangle_annotation->setObjectName("rounded_rectangle_annotation");
        rounded_rectangle_annotation->setMinimumSize(QSize(40, 40));
        rounded_rectangle_annotation->setMaximumSize(QSize(40, 40));
        rounded_rectangle_annotation->setFont(font1);
        rounded_rectangle_annotation->setStyleSheet(QString::fromUtf8(""));
        QIcon icon22;
        icon22.addFile(QString::fromUtf8(":/new/prefix1/F7BubbleMiddleBottom.svg"), QSize(), QIcon::Normal, QIcon::Off);
        rounded_rectangle_annotation->setIcon(icon22);
        rounded_rectangle_annotation->setIconSize(QSize(32, 32));
        rounded_rectangle_annotation->setAutoExclusive(true);

        gridLayout->addWidget(rounded_rectangle_annotation, 2, 3, 1, 1);

        cloud_annotation = new QPushButton(gridLayoutWidget);
        cloud_annotation->setObjectName("cloud_annotation");
        cloud_annotation->setMinimumSize(QSize(40, 40));
        cloud_annotation->setMaximumSize(QSize(40, 40));
        cloud_annotation->setFont(font1);
        cloud_annotation->setStyleSheet(QString::fromUtf8(""));
        QIcon icon23;
        icon23.addFile(QString::fromUtf8(":/new/prefix1/MdiThoughtBubble.svg"), QSize(), QIcon::Normal, QIcon::Off);
        cloud_annotation->setIcon(icon23);
        cloud_annotation->setIconSize(QSize(32, 32));
        cloud_annotation->setAutoExclusive(true);

        gridLayout->addWidget(cloud_annotation, 2, 4, 1, 1);

        circle_annotation = new QPushButton(gridLayoutWidget);
        circle_annotation->setObjectName("circle_annotation");
        circle_annotation->setMinimumSize(QSize(40, 40));
        circle_annotation->setMaximumSize(QSize(40, 40));
        circle_annotation->setFont(font1);
        circle_annotation->setStyleSheet(QString::fromUtf8(""));
        QIcon icon24;
        icon24.addFile(QString::fromUtf8(":/new/prefix1/HeroiconsChatBubbleOvalLeft.svg"), QSize(), QIcon::Normal, QIcon::Off);
        circle_annotation->setIcon(icon24);
        circle_annotation->setIconSize(QSize(32, 32));
        circle_annotation->setAutoExclusive(true);

        gridLayout->addWidget(circle_annotation, 2, 5, 1, 1);

        spinBox_2 = new QSpinBox(groupBox);
        spinBox_2->setObjectName("spinBox_2");
        spinBox_2->setGeometry(QRect(450, 10, 100, 30));
        spinBox_2->setFont(font);
        spinBox_2->setMaximum(255);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setEnabled(true);
        label_3->setGeometry(QRect(370, 10, 80, 30));
        QFont font4;
        font4.setPointSize(11);
        label_3->setFont(font4);
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        horizontalSlider = new QSlider(groupBox);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setGeometry(QRect(390, 40, 159, 22));
        horizontalSlider->setMaximum(255);
        horizontalSlider->setOrientation(Qt::Orientation::Horizontal);
        spinBox_3 = new QSpinBox(groupBox);
        spinBox_3->setObjectName("spinBox_3");
        spinBox_3->setGeometry(QRect(450, 70, 100, 30));
        spinBox_3->setFont(font);
        spinBox_3->setMaximum(255);
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(370, 70, 80, 30));
        label_5->setFont(font4);
        label_5->setAlignment(Qt::AlignmentFlag::AlignCenter);
        horizontalSlider_2 = new QSlider(groupBox);
        horizontalSlider_2->setObjectName("horizontalSlider_2");
        horizontalSlider_2->setGeometry(QRect(390, 100, 159, 22));
        horizontalSlider_2->setMaximum(255);
        horizontalSlider_2->setOrientation(Qt::Orientation::Horizontal);
        spinBox_4 = new QSpinBox(groupBox);
        spinBox_4->setObjectName("spinBox_4");
        spinBox_4->setGeometry(QRect(450, 130, 100, 30));
        spinBox_4->setFont(font);
        spinBox_4->setMaximum(255);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(370, 130, 80, 30));
        label_4->setFont(font4);
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        horizontalSlider_3 = new QSlider(groupBox);
        horizontalSlider_3->setObjectName("horizontalSlider_3");
        horizontalSlider_3->setGeometry(QRect(390, 160, 158, 22));
        horizontalSlider_3->setMaximum(255);
        horizontalSlider_3->setOrientation(Qt::Orientation::Horizontal);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1315, 22));
        menuopen_file = new QMenu(menubar);
        menuopen_file->setObjectName("menuopen_file");
        QIcon icon25;
        icon25.addFile(QString::fromUtf8(":/new/prefix1/WhhOpenfolderalt.svg"), QSize(), QIcon::Normal, QIcon::Off);
        menuopen_file->setIcon(icon25);
        menusave = new QMenu(menubar);
        menusave->setObjectName("menusave");
        QIcon icon26;
        icon26.addFile(QString::fromUtf8(":/new/prefix1/FluentSave32Regular.svg"), QSize(), QIcon::Normal, QIcon::Off);
        menusave->setIcon(icon26);
        menusave_anothing_file = new QMenu(menubar);
        menusave_anothing_file->setObjectName("menusave_anothing_file");
        QIcon icon27;
        icon27.addFile(QString::fromUtf8(":/new/prefix1/FadSaveas.svg"), QSize(), QIcon::Normal, QIcon::Off);
        menusave_anothing_file->setIcon(icon27);
        menuexit = new QMenu(menubar);
        menuexit->setObjectName("menuexit");
        QIcon icon28;
        icon28.addFile(QString::fromUtf8(":/new/prefix1/SolarExitBoldDuotone.svg"), QSize(), QIcon::Normal, QIcon::Off);
        menuexit->setIcon(icon28);
        menuundo = new QMenu(menubar);
        menuundo->setObjectName("menuundo");
        QIcon icon29;
        icon29.addFile(QString::fromUtf8(":/new/prefix1/back up.svg"), QSize(), QIcon::Normal, QIcon::Off);
        menuundo->setIcon(icon29);
        menuredo = new QMenu(menubar);
        menuredo->setObjectName("menuredo");
        QIcon icon30;
        icon30.addFile(QString::fromUtf8(":/new/prefix1/advance.svg"), QSize(), QIcon::Normal, QIcon::Off);
        menuredo->setIcon(icon30);
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        QIcon icon31;
        icon31.addFile(QString::fromUtf8(":/new/prefix1/WhhNewwindow.svg"), QSize(), QIcon::Normal, QIcon::Off);
        menu->setIcon(icon31);
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menuopen_file->menuAction());
        menubar->addAction(menusave->menuAction());
        menubar->addAction(menusave_anothing_file->menuAction());
        menubar->addAction(menuexit->menuAction());
        menubar->addAction(menuundo->menuAction());
        menubar->addAction(menuredo->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox_2->setTitle(QString());
        my_erase->setText(QString());
        size->setText(QString());
        color_extractor->setText(QString());
        fill->setText(QString());
        crop->setText(QString());
        groupBox->setTitle(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "\347\272\277\345\256\275", nullptr));
        painting->setText(QCoreApplication::translate("MainWindow", "\347\273\230\345\233\276", nullptr));
        radioButton->setText(QCoreApplication::translate("MainWindow", "\345\211\215\346\231\257\350\211\262", nullptr));
        pushButton_14->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        radioButton_2->setText(QCoreApplication::translate("MainWindow", "\350\203\214\346\231\257\350\211\262", nullptr));
        pushButton_15->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        hexagon->setText(QString());
        six_pointed_star->setText(QString());
        right_circle->setText(QString());
        five_pointed_star->setText(QString());
        diamond->setText(QString());
        four_pointed_star->setText(QString());
        ellipse->setText(QString());
        right_rectangle->setText(QString());
        rounded_rectangle->setText(QString());
        straight_line->setText(QString());
        right_triangle->setText(QString());
        isosceles_triangle->setText(QString());
        lightning->setText(QString());
        left->setText(QString());
        right->setText(QString());
        top->setText(QString());
        bottom->setText(QString());
        rounded_rectangle_annotation->setText(QString());
        cloud_annotation->setText(QString());
        circle_annotation->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "\347\272\242\350\211\262", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\347\273\277\350\211\262", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\350\223\235\350\211\262", nullptr));
        menuopen_file->setTitle(QCoreApplication::translate("MainWindow", "open file", nullptr));
        menusave->setTitle(QCoreApplication::translate("MainWindow", "save", nullptr));
        menusave_anothing_file->setTitle(QCoreApplication::translate("MainWindow", "save as anothing file", nullptr));
        menuexit->setTitle(QCoreApplication::translate("MainWindow", "exit", nullptr));
        menuundo->setTitle(QCoreApplication::translate("MainWindow", "undo", nullptr));
        menuredo->setTitle(QCoreApplication::translate("MainWindow", "redo", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "meun", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
