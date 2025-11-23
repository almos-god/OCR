/********************************************************************************
** Form generated from reading UI file 'size_dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIZE_DIALOG_H
#define UI_SIZE_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_size_Dialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QRadioButton *pixel;
    QRadioButton *percentage;
    QLabel *x_label;
    QLabel *y_label;
    QLineEdit *x_number;
    QLineEdit *y_number;

    void setupUi(QDialog *size_Dialog)
    {
        if (size_Dialog->objectName().isEmpty())
            size_Dialog->setObjectName("size_Dialog");
        size_Dialog->resize(400, 252);
        buttonBox = new QDialogButtonBox(size_Dialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(50, 200, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        label = new QLabel(size_Dialog);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 401, 51));
        QFont font;
        font.setPointSize(21);
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        gridLayoutWidget = new QWidget(size_Dialog);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(20, 60, 361, 103));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pixel = new QRadioButton(gridLayoutWidget);
        pixel->setObjectName("pixel");
        QFont font1;
        font1.setPointSize(12);
        pixel->setFont(font1);
        pixel->setAutoFillBackground(true);

        gridLayout->addWidget(pixel, 0, 2, 1, 1);

        percentage = new QRadioButton(gridLayoutWidget);
        percentage->setObjectName("percentage");
        percentage->setFont(font1);
        percentage->setAutoFillBackground(true);

        gridLayout->addWidget(percentage, 0, 0, 1, 1);

        x_label = new QLabel(gridLayoutWidget);
        x_label->setObjectName("x_label");
        QFont font2;
        font2.setPointSize(14);
        x_label->setFont(font2);

        gridLayout->addWidget(x_label, 2, 0, 1, 1);

        y_label = new QLabel(gridLayoutWidget);
        y_label->setObjectName("y_label");
        y_label->setFont(font2);

        gridLayout->addWidget(y_label, 2, 2, 1, 1);

        x_number = new QLineEdit(gridLayoutWidget);
        x_number->setObjectName("x_number");

        gridLayout->addWidget(x_number, 2, 1, 1, 1);

        y_number = new QLineEdit(gridLayoutWidget);
        y_number->setObjectName("y_number");

        gridLayout->addWidget(y_number, 2, 3, 1, 1);


        retranslateUi(size_Dialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, size_Dialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, size_Dialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(size_Dialog);
    } // setupUi

    void retranslateUi(QDialog *size_Dialog)
    {
        size_Dialog->setWindowTitle(QCoreApplication::translate("size_Dialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("size_Dialog", "\345\244\247\345\260\217", nullptr));
        pixel->setText(QCoreApplication::translate("size_Dialog", "\345\203\217\347\264\240", nullptr));
        percentage->setText(QCoreApplication::translate("size_Dialog", "\347\231\276\345\210\206\346\257\224", nullptr));
        x_label->setText(QCoreApplication::translate("size_Dialog", "\346\260\264\345\271\263\357\274\232", nullptr));
        y_label->setText(QCoreApplication::translate("size_Dialog", "\345\236\202\347\233\264\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class size_Dialog: public Ui_size_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIZE_DIALOG_H
