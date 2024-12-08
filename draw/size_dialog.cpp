#include "size_dialog.h"
#include "ui_size_dialog.h"
#include <QIntValidator>
#include <QRegularExpression>
#include <QMessageBox>
#include <QCheckBox>
size_Dialog::size_Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::size_Dialog)
{
    ui->setupUi(this);
    setWindowTitle("大小");
    setWindowIcon(QIcon(":/new/prefix1/FlatUiPicture.ico"));

    this->state = true;
    this->percentage_x = 100;
    this->percentage_y = 100;
    ui->percentage->setChecked(true);
    ui->x_number->setText(QString::number(percentage_x));
    ui->y_number->setText(QString::number(percentage_y));

    // 不允许空字符串，匹配1 - 100
    QRegularExpression regex("^([1-9]|[1-9][0-9]|100)$");
    ui->x_number->setValidator(new QRegularExpressionValidator(regex, this));
    ui->y_number->setValidator(new QRegularExpressionValidator(regex, this));
    ui->x_number->setToolTip("输入的内容范围为1~100");
    ui->y_number->setToolTip("输入的内容范围为1~100");

}

size_Dialog::~size_Dialog()
{
    delete ui;
}

void size_Dialog::showEvent(QShowEvent * /*event*/)
{

    // 当 percentage 被选定时
    connect(ui->percentage, &QCheckBox::toggled, this, [this](bool checked) {
        if (checked) {

            this->state=true;
            // 更新显示
            ui->x_number->setText(QString::number(static_cast<int>(this->percentage_x)));
            ui->y_number->setText(QString::number(static_cast<int>(this->percentage_y)));

            // 不允许空字符串，匹配1 - 100
            QRegularExpression regex("^([1-9]|[1-9][0-9]|100)$");
            ui->x_number->setValidator(new QRegularExpressionValidator(regex, this));
            ui->y_number->setValidator(new QRegularExpressionValidator(regex, this));

            ui->x_number->setToolTip("输入的内容范围为1~100");
            ui->y_number->setToolTip("输入的内容范围为1~100");
        }
    });

    // 当 pixel 被选定时
    connect(ui->pixel, &QCheckBox::toggled, this, [this](bool checked) {
        if (checked) {

            this->state=false;
            // 更新显示
            ui->x_number->setText(QString::number(static_cast<int>(this->pixel_x)));
            ui->y_number->setText(QString::number(static_cast<int>(this->pixel_y)));

            // 设置范围为1~9999的正则表达式
            QRegularExpression regex("^(9999|[1-9]{1}|[1-9][0-9]{1,3})$");
            ui->x_number->setValidator(new QRegularExpressionValidator(regex, this));
            ui->y_number->setValidator(new QRegularExpressionValidator(regex, this));
            ui->x_number->setToolTip("输入的内容范围为1~9999");
            ui->y_number->setToolTip("输入的内容范围为1~9999");
        }
    });

    // 假设 percentage_x, percentage_y, pixel_x, pixel_y 是类的成员变量
    connect(ui->x_number, &QLineEdit::textChanged, this, [this]() {

        bool blocked = ui->y_number->blockSignals(true);

        // 获取当前 x_number 的值
        bool ok;
        int currentX = ui->x_number->text().toInt(&ok);
        if (!ok) return; // 如果转换失败，退出

        // 根据 state 的值更新 percentage_x 或 pixel_x
        if (this->state) {
            this->percentage_x = currentX;
            //this->percentage_y=newY;
        } else {
            this->pixel_x = currentX;
            //this->pixel_y=newY;
        }
        ui->y_number->blockSignals(blocked);

    });

    connect(ui->y_number, &QLineEdit::textChanged, this, [this]() {

        bool blocked = ui->x_number->blockSignals(true);

        // 获取当前 y_number 的值
        bool ok;
        int currentY = ui->y_number->text().toInt(&ok);
        if (!ok) return; // 如果转换失败，退出

        // 根据 state 的值更新 percentage_y 或 pixel_y
        if (this->state) {
            this->percentage_y = currentY;
            //this->percentage_x=newX;
        } else {
            //this->percentage_x=newX;
            this->pixel_y = currentY;
        }
        ui->x_number->blockSignals(blocked);
    });

}
int size_Dialog::setpixel_x(int piexel_x)
{
    this->pixel_x=piexel_x;
    return 0;
}
int size_Dialog::setpixel_y(int piexel_y)
{
    this->pixel_y=piexel_y;
    return 0;
}
int size_Dialog::getstate()
{
    return this->state;
}
int size_Dialog::getpercentage_x()
{
    return this->percentage_x;
}
int size_Dialog::getpercentage_y()
{
    return this->percentage_y;
}
int size_Dialog::getpixel_x()
{
    return this->pixel_x;
}
int size_Dialog::getpixel_y()
{
    return this->pixel_y;
}
