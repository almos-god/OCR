#ifndef SIZE_DIALOG_H
#define SIZE_DIALOG_H

#include <QDialog>
#include <QIntValidator>
namespace Ui {
class size_Dialog;
}

class size_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit size_Dialog(QWidget *parent = nullptr);
    ~size_Dialog();
    void showEvent(QShowEvent * /*event*/);
    int setpixel_x(int pixel_x);
    int setpixel_y(int pixel_x);
    int getstate();
    int getpercentage_x();
    int getpercentage_y();
    int getpixel_x();
    int getpixel_y();
private:
    Ui::size_Dialog *ui;
    bool state;
    int percentage_x;
    int percentage_y;
    int pixel_x;
    int pixel_y;

};

#endif // SIZE_DIALOG_H
