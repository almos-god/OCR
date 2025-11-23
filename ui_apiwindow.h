/********************************************************************************
** Form generated from reading UI file 'apiwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APIWINDOW_H
#define UI_APIWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QTabWidget *tabWidget;
    QWidget *image;
    QGraphicsView *graphicsView;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QComboBox *imageapioptions;
    QProgressBar *imageapiinternetspeed;
    QLabel *imageapiinternetspeedlabel;
    QPushButton *imageapidelete;
    QPushButton *imageapiadd;
    QLineEdit *newimageapikey;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QTextEdit *textEdit;
    QPushButton *load;
    QPushButton *send;
    QWidget *chat;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QComboBox *chatapioptions;
    QProgressBar *chatapiinternetspeed;
    QLabel *chatapiinternetspeedlabel;
    QPushButton *chatapidelete;
    QPushButton *chatapiadd;
    QLineEdit *newchatapikey;
    QListView *listView;
    QWidget *chatInputLayoutWidget;
    QHBoxLayout *chatInputLayout;
    QTextEdit *chatMessageInput;
    QPushButton *chatSendButton;
    QPushButton *download;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName("Form");
        Form->resize(800, 656);
        tabWidget = new QTabWidget(Form);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, 0, 780, 650));
        image = new QWidget();
        image->setObjectName("image");
        graphicsView = new QGraphicsView(image);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(20, 320, 721, 261));
        gridLayoutWidget = new QWidget(image);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(20, 30, 721, 80));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        imageapioptions = new QComboBox(gridLayoutWidget);
        imageapioptions->setObjectName("imageapioptions");

        gridLayout->addWidget(imageapioptions, 0, 0, 1, 1);

        imageapiinternetspeed = new QProgressBar(gridLayoutWidget);
        imageapiinternetspeed->setObjectName("imageapiinternetspeed");
        imageapiinternetspeed->setValue(24);

        gridLayout->addWidget(imageapiinternetspeed, 0, 1, 1, 1);

        imageapiinternetspeedlabel = new QLabel(gridLayoutWidget);
        imageapiinternetspeedlabel->setObjectName("imageapiinternetspeedlabel");

        gridLayout->addWidget(imageapiinternetspeedlabel, 0, 2, 1, 1);

        imageapidelete = new QPushButton(gridLayoutWidget);
        imageapidelete->setObjectName("imageapidelete");

        gridLayout->addWidget(imageapidelete, 0, 3, 1, 1);

        imageapiadd = new QPushButton(gridLayoutWidget);
        imageapiadd->setObjectName("imageapiadd");

        gridLayout->addWidget(imageapiadd, 1, 2, 1, 1);

        newimageapikey = new QLineEdit(gridLayoutWidget);
        newimageapikey->setObjectName("newimageapikey");

        gridLayout->addWidget(newimageapikey, 1, 0, 1, 1);

        gridLayout->setColumnStretch(0, 10);
        gridLayout->setColumnStretch(1, 2);
        gridLayout->setColumnStretch(2, 1);
        gridLayout->setColumnStretch(3, 2);
        horizontalLayoutWidget = new QWidget(image);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(20, 130, 721, 151));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        textEdit = new QTextEdit(horizontalLayoutWidget);
        textEdit->setObjectName("textEdit");

        horizontalLayout->addWidget(textEdit);

        load = new QPushButton(image);
        load->setObjectName("load");
        load->setGeometry(QRect(660, 590, 80, 24));
        send = new QPushButton(image);
        send->setObjectName("send");
        send->setGeometry(QRect(660, 290, 80, 24));
        tabWidget->addTab(image, QString());
        chat = new QWidget();
        chat->setObjectName("chat");
        gridLayoutWidget_2 = new QWidget(chat);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(20, 20, 721, 80));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        chatapioptions = new QComboBox(gridLayoutWidget_2);
        chatapioptions->setObjectName("chatapioptions");

        gridLayout_2->addWidget(chatapioptions, 0, 0, 1, 1);

        chatapiinternetspeed = new QProgressBar(gridLayoutWidget_2);
        chatapiinternetspeed->setObjectName("chatapiinternetspeed");
        chatapiinternetspeed->setValue(24);

        gridLayout_2->addWidget(chatapiinternetspeed, 0, 1, 1, 1);

        chatapiinternetspeedlabel = new QLabel(gridLayoutWidget_2);
        chatapiinternetspeedlabel->setObjectName("chatapiinternetspeedlabel");

        gridLayout_2->addWidget(chatapiinternetspeedlabel, 0, 2, 1, 1);

        chatapidelete = new QPushButton(gridLayoutWidget_2);
        chatapidelete->setObjectName("chatapidelete");

        gridLayout_2->addWidget(chatapidelete, 0, 3, 1, 1);

        chatapiadd = new QPushButton(gridLayoutWidget_2);
        chatapiadd->setObjectName("chatapiadd");

        gridLayout_2->addWidget(chatapiadd, 1, 2, 1, 1);

        newchatapikey = new QLineEdit(gridLayoutWidget_2);
        newchatapikey->setObjectName("newchatapikey");

        gridLayout_2->addWidget(newchatapikey, 1, 0, 1, 1);

        gridLayout_2->setColumnStretch(0, 10);
        gridLayout_2->setColumnStretch(1, 2);
        gridLayout_2->setColumnStretch(2, 1);
        gridLayout_2->setColumnStretch(3, 2);
        listView = new QListView(chat);
        listView->setObjectName("listView");
        listView->setGeometry(QRect(20, 130, 721, 371));
        chatInputLayoutWidget = new QWidget(chat);
        chatInputLayoutWidget->setObjectName("chatInputLayoutWidget");
        chatInputLayoutWidget->setGeometry(QRect(20, 510, 721, 31));
        chatInputLayout = new QHBoxLayout(chatInputLayoutWidget);
        chatInputLayout->setObjectName("chatInputLayout");
        chatInputLayout->setContentsMargins(0, 0, 0, 0);
        chatMessageInput = new QTextEdit(chatInputLayoutWidget);
        chatMessageInput->setObjectName("chatMessageInput");

        chatInputLayout->addWidget(chatMessageInput);

        chatSendButton = new QPushButton(chatInputLayoutWidget);
        chatSendButton->setObjectName("chatSendButton");

        chatInputLayout->addWidget(chatSendButton);

        download = new QPushButton(chatInputLayoutWidget);
        download->setObjectName("download");

        chatInputLayout->addWidget(download);

        tabWidget->addTab(chat, QString());

        retranslateUi(Form);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
#if QT_CONFIG(tooltip)
        tabWidget->setToolTip(QCoreApplication::translate("Form", "\345\233\276\345\203\217", nullptr));
#endif // QT_CONFIG(tooltip)
        imageapiinternetspeedlabel->setText(QCoreApplication::translate("Form", "0 KB/s", nullptr));
        imageapidelete->setText(QCoreApplication::translate("Form", "\345\210\240\351\231\244", nullptr));
        imageapiadd->setText(QCoreApplication::translate("Form", "\346\267\273\345\212\240", nullptr));
        label->setText(QCoreApplication::translate("Form", "\346\217\217\350\277\260\357\274\232", nullptr));
        load->setText(QCoreApplication::translate("Form", "\350\275\275\345\205\245", nullptr));
        send->setText(QCoreApplication::translate("Form", "\345\217\221\351\200\201", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(image), QCoreApplication::translate("Form", "\345\233\276\345\203\217", nullptr));
        chatapiinternetspeedlabel->setText(QCoreApplication::translate("Form", "0 KB/s", nullptr));
        chatapidelete->setText(QCoreApplication::translate("Form", "\345\210\240\351\231\244", nullptr));
        chatapiadd->setText(QCoreApplication::translate("Form", "\346\267\273\345\212\240", nullptr));
        chatSendButton->setText(QCoreApplication::translate("Form", "\345\217\221\351\200\201", nullptr));
        download->setText(QCoreApplication::translate("Form", "\344\270\213\350\275\275", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(chat), QCoreApplication::translate("Form", "\350\201\212\345\244\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APIWINDOW_H
