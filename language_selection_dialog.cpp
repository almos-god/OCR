#include "language_selection_dialog.h"
#include <QDir>
#include <QFileInfo>
#include <QDebug>
#include <QListWidgetItem>
#include <QWidget>
#include <QPainter>
#include <QPainterPath>
#include <QPalette>
#include <QWindow>
#include <QTimer>
#include <QTime>
#include <cmath>

#include <QApplication>

// Windows-specific includes for acrylic effect
#ifdef Q_OS_WIN
#include <windows.h>
#include <dwmapi.h>
#pragma comment(lib, "dwmapi.lib")
#endif

// 自定义委托，用于绘制列表项
class CheckableListDelegate : public QStyledItemDelegate
{
public:
    explicit CheckableListDelegate(QObject *parent = nullptr) : QStyledItemDelegate(parent) {}

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override
    {
        QStyleOptionViewItem opt = option;
        initStyleOption(&opt, index);

        // 不绘制立体阴影，使用简单背景
        if (option.state & QStyle::State_MouseOver) {
            painter->fillRect(option.rect, QColor(255, 255, 255, 30)); // 非常淡的透明背景
        }

        // 绘制文本
        QString text = index.data(Qt::DisplayRole).toString();
        
        // 设置文本颜色为黑色，确保在彩色背景上清晰可见
        QPen textPen(Qt::black);
        painter->setPen(textPen);
        
        // 设置字体大小
        QFont textFont = painter->font();
        textFont.setPointSize(14); // 增大字体
        textFont.setBold(true); // 加粗
        painter->setFont(textFont);
        
        painter->drawText(option.rect.adjusted(30, 0, 0, 0), Qt::AlignVCenter, text);

        // 绘制复选框
        QStyleOptionButton checkboxOption;
        checkboxOption.rect = QRect(option.rect.left() + 5, option.rect.top() + (option.rect.height() - 20) / 2, 20, 20); // 增大复选框
        checkboxOption.state |= QStyle::State_Enabled;
        
        // 设置复选框颜色为白色
        checkboxOption.palette.setColor(QPalette::Button, Qt::white);
        checkboxOption.palette.setColor(QPalette::WindowText, Qt::white);
        checkboxOption.palette.setColor(QPalette::ButtonText, Qt::white);
        
        bool checked = index.data(Qt::UserRole + 1).toBool();
        if (checked) {
            checkboxOption.state |= QStyle::State_On;
        } else {
            checkboxOption.state |= QStyle::State_Off;
        }

        // 使用自定义样式绘制复选框，确保黑色外观
        painter->save();
        painter->setPen(QPen(Qt::black, 2));
        
        // 绘制复选框边框
        painter->drawRect(checkboxOption.rect.adjusted(1, 1, -1, -1));
        
        // 如果选中，绘制对勾
        if (checked) {
            QLineF line1(checkboxOption.rect.left() + 5, checkboxOption.rect.top() + 10, 
                        checkboxOption.rect.left() + 9, checkboxOption.rect.top() + 14);
            QLineF line2(checkboxOption.rect.left() + 9, checkboxOption.rect.top() + 14, 
                        checkboxOption.rect.left() + 15, checkboxOption.rect.top() + 6);
            painter->drawLine(line1);
            painter->drawLine(line2);
        }
        
        painter->restore();
    }

    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override
    {
        QSize size = QStyledItemDelegate::sizeHint(option, index);
        size.setHeight(qMax(size.height(), 30));
        return size;
    }
};

LanguageSelectionDialog::LanguageSelectionDialog(QWidget *parent)
    : QDialog(parent)
    , m_selectedLanguageCodes(QStringList() << "eng") // 默认选择英文
    , m_languageListWidget(new QListWidget)
{
    // 启用窗口透明效果
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::Window);
    setAttribute(Qt::WA_TranslucentBackground, true);
    
    // 设置窗口背景透明度为75%
    QPalette palette = this->palette();
    palette.setColor(QPalette::Window, QColor(255, 255, 255, 191)); // 191 = 255 * 0.75
    this->setPalette(palette);
    
    initUI();
    loadAvailableLanguages();
    
    // Windows亚克力效果 - 使用DWM API (Qt 6 compatible)
#ifdef Q_OS_WIN
    // 延迟一下，确保窗口已经创建
    QTimer::singleShot(0, this, [this]() {
        QWindow *window = this->windowHandle();
        if (window) {
            HWND hwnd = reinterpret_cast<HWND>(window->winId());
            
            // 设置窗口背景模糊效果
            DWM_BLURBEHIND bb = {0};
            bb.dwFlags = DWM_BB_ENABLE;
            bb.fEnable = true;
            bb.hRgnBlur = NULL;
            DwmEnableBlurBehindWindow(hwnd, &bb);
            
            // 扩展客户区到边框
            MARGINS margins = {-1, -1, -1, -1};
            DwmExtendFrameIntoClientArea(hwnd, &margins);
        }
    });
#endif
}

// 重写paintEvent实现彩色流动背景
void LanguageSelectionDialog::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing); // 启用抗锯齿
    
    // 获取当前时间作为动画种子
    int time = QTime::currentTime().msec() + QTime::currentTime().second() * 1000;
    double animationProgress = (time % 3000) / 3000.0; // 0-1的动画进度，加快速度
    
    // 计算当前帧的背景位置和大小
    QRect rect = this->rect();
    int width = rect.width();
    int height = rect.height();
    int borderRadius = 20; // 圆角半径
    
    // 创建圆角矩形路径
    QPainterPath backgroundPath;
    backgroundPath.addRoundedRect(rect, borderRadius, borderRadius);
    
    // 设置裁剪区域
    painter.setClipPath(backgroundPath);
    
    // 简化颜色设置，使用三种柔和的颜色
    QColor colors[3] = {
        QColor(255, 180, 200), // 柔和的粉红色
        QColor(180, 220, 255), // 柔和的蓝色
        QColor(180, 255, 200)  // 柔和的绿色
    };
    
    // 创建更简单的流动效果：颜色从左到右，再从右到左流动
    for (int i = 0; i < 3; ++i) {
        double colorProgress = fmod(animationProgress + i * 0.33, 1.0);
    
    // 计算渐变中心位置：简单的左右流动
        int centerX;
        if (colorProgress < 0.5) {
            // 从左到右
            centerX = width * 0.1 + colorProgress * 1.6 * width;
        } else {
            // 从右到左
            centerX = width * 0.9 - (colorProgress - 0.5) * 1.6 * width;
        }
        
        QPointF center(centerX, height * (0.3 + i * 0.35));
        
        // 增大渐变半径，减少空白区域
        double radius = qMax(width, height) * 0.8;
        
        // 创建径向渐变
        QRadialGradient radialGrad(center, radius);
        
        // 设置渐变颜色，减少透明度变化，避免过多透视
        radialGrad.setColorAt(0, colors[i]); // 中心颜色不透明
        
        QColor midColor = colors[i];
        midColor.setAlpha(150);
        radialGrad.setColorAt(0.7, midColor); // 中间透明度适中
        
        QColor edgeColor = colors[i];
        edgeColor.setAlpha(50);
        radialGrad.setColorAt(1, edgeColor); // 边缘保留一定透明度
        
        // 填充圆角矩形
        painter.fillPath(backgroundPath, radialGrad);
    }
    
    // 添加一层半透明的白色覆盖，降低整体透明度，减少透视效果
    painter.fillPath(backgroundPath, QColor(255, 255, 255, 100));
    
    // 调用父类的paintEvent以确保其他UI元素正常绘制
    QDialog::paintEvent(event);
}

LanguageSelectionDialog::~LanguageSelectionDialog()
{
}

QStringList LanguageSelectionDialog::selectedLanguageCodes() const
{
    return m_selectedLanguageCodes;
}

void LanguageSelectionDialog::setSelectedLanguageCodes(const QStringList &codes)
{
    m_selectedLanguageCodes = codes;
    
    // 更新列表视图中对应的复选框状态
    for (int i = 0; i < m_languageListWidget->count(); ++i) {
        QListWidgetItem *item = m_languageListWidget->item(i);
        if (item) {
            QString langCode = item->data(Qt::UserRole).toString();
            bool isChecked = m_selectedLanguageCodes.contains(langCode);
            item->setData(Qt::UserRole + 1, isChecked);
            m_languageListWidget->update();
        }
    }
}

// 兼容旧接口，返回第一个选中的语言代码
QString LanguageSelectionDialog::selectedLanguageCode() const
{
    if (m_selectedLanguageCodes.isEmpty()) {
        return "";
    }
    return m_selectedLanguageCodes.first();
}

// 兼容旧接口，设置选中的语言代码
void LanguageSelectionDialog::setSelectedLanguageCode(const QString &code)
{
    // 兼容旧接口，清除其他选中项，只选中指定的语言代码
    m_selectedLanguageCodes.clear();
    if (!code.isEmpty()) {
        m_selectedLanguageCodes.append(code);
    }
    
    // 更新列表视图中对应的复选框状态
    for (int i = 0; i < m_languageListWidget->count(); ++i) {
        QListWidgetItem *item = m_languageListWidget->item(i);
        if (item) {
            QString langCode = item->data(Qt::UserRole).toString();
            bool isChecked = (langCode == code);
            item->setData(Qt::UserRole + 1, isChecked);
        }
    }
    m_languageListWidget->update();
}

void LanguageSelectionDialog::onOkButtonClicked()
{
    // 查找选中的列表项
    m_selectedLanguageCodes.clear();
    for (int i = 0; i < m_languageListWidget->count(); ++i) {
        QListWidgetItem *item = m_languageListWidget->item(i);
        if (item && item->data(Qt::UserRole + 1).toBool()) {
            QString langCode = item->data(Qt::UserRole).toString();
            m_selectedLanguageCodes.append(langCode);
        }
    }
    
    // 如果没有选中任何语言，默认选中英文
    if (m_selectedLanguageCodes.isEmpty()) {
        m_selectedLanguageCodes.append("eng");
    }
    
    accept(); // 关闭对话框并返回QDialog::Accepted
}

void LanguageSelectionDialog::onCancelButtonClicked()
{
    reject(); // 关闭对话框并返回QDialog::Rejected
}

void LanguageSelectionDialog::initUI()
{
    // 设置对话框标题
    setWindowTitle("语言选择");
    
    // 设置字体
    QFont font = this->font();
    font.setPointSize(10);
    this->setFont(font);
    
    // 创建主布局
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(20, 20, 20, 20);
    mainLayout->setSpacing(15);
    
    // 设置列表视图
    m_languageListWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    m_languageListWidget->setAlternatingRowColors(false); // 去掉交替行颜色
    m_languageListWidget->setItemDelegate(new CheckableListDelegate(this));
    m_languageListWidget->setStyleSheet("QListWidget { "
                                          "background: transparent; "
                                          "border: none; "
                                          "padding: 5px; "
                                          "}"
                                          "QListWidget::item { "
                                          "background: transparent; "
                                          "}"
                                          "QScrollBar:vertical, QScrollBar:horizontal { "
                                          "background: transparent; "
                                          "width: 0px; "
                                          "height: 0px; "
                                          "}"
                                          "QScrollBar::handle:vertical, QScrollBar::handle:horizontal { "
                                          "background: transparent; "
                                          "}"
                                          "QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical, "
                                          "QScrollBar::add-line:horizontal, QScrollBar::sub-line:horizontal { "
                                          "background: transparent; "
                                          "}");
    m_languageListWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_languageListWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    
    // 启动定时器，实现背景动画
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [this]() {
        this->update();
    });
    timer->start(50); // 每50毫秒更新一次，实现流畅动画
    
    // 连接列表项点击信号
    connect(m_languageListWidget, &QListWidget::itemClicked, this, [this](QListWidgetItem *item) {
        bool isChecked = item->data(Qt::UserRole + 1).toBool();
        item->setData(Qt::UserRole + 1, !isChecked);
        m_languageListWidget->update();
    });
    
    // 创建按钮布局
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->setSpacing(15);
    
    QPushButton *okButton = new QPushButton("确定");
    okButton->setStyleSheet("QPushButton { "
                               "background-color: rgba(255, 255, 255, 0.95); "
                               "color: black; "
                               "border: none; "
                               "border-radius: 8px; "
                               "padding: 12px 24px; "
                               "font-weight: bold; "
                               "font-size: 14px; "
                               "box-shadow: 2px 2px 6px rgba(0, 0, 0, 0.3), "
                               "            inset 1px 1px 2px rgba(255, 255, 255, 0.2); "
                           "}"
                           "QPushButton:hover { "
                               "background-color: rgba(255, 255, 255, 1); "
                               "box-shadow: 3px 3px 8px rgba(0, 0, 0, 0.4), "
                               "            inset 1px 1px 2px rgba(255, 255, 255, 0.2); "
                           "}"
                           "QPushButton:pressed { "
                               "box-shadow: 1px 1px 4px rgba(0, 0, 0, 0.2), "
                               "            inset 2px 2px 4px rgba(0, 0, 0, 0.3); "
                               "transform: translateY(1px); "
                           "}");
    
    QPushButton *cancelButton = new QPushButton("取消");
    cancelButton->setStyleSheet("QPushButton { "
                                 "background-color: rgba(255, 255, 255, 0.95); "
                                 "color: black; "
                                 "border: none; "
                                 "border-radius: 8px; "
                                 "padding: 12px 24px; "
                                 "font-weight: bold; "
                                 "font-size: 14px; "
                                 "box-shadow: 2px 2px 6px rgba(0, 0, 0, 0.2), "
                                 "            inset 1px 1px 2px rgba(0, 0, 0, 0.1); "
                             "}"
                             "QPushButton:hover { "
                                 "background-color: rgba(255, 255, 255, 1); "
                                 "box-shadow: 3px 3px 8px rgba(0, 0, 0, 0.3), "
                                 "            inset 1px 1px 2px rgba(0, 0, 0, 0.1); "
                             "}"
                             "QPushButton:pressed { "
                                 "box-shadow: 1px 1px 4px rgba(0, 0, 0, 0.1), "
                                 "            inset 2px 2px 4px rgba(0, 0, 0, 0.2); "
                                 "transform: translateY(1px); "
                             "}");
    
    buttonLayout->addStretch();
    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);
    
    // 添加到主布局
    mainLayout->addWidget(m_languageListWidget);
    mainLayout->addLayout(buttonLayout);
    
    // 连接信号和槽
    connect(okButton, &QPushButton::clicked, this, &LanguageSelectionDialog::onOkButtonClicked);
    connect(cancelButton, &QPushButton::clicked, this, &LanguageSelectionDialog::onCancelButtonClicked);
    
    // 设置对话框大小
    resize(500, 600);
}

void LanguageSelectionDialog::loadAvailableLanguages()
{
    // 清除现有列表项
    m_languageListWidget->clear();
    
    // 语言代码到显示名称的映射
    m_languageMap.insert("eng", "英文");
    m_languageMap.insert("chi_sim", "中文(简体)");
    m_languageMap.insert("chi_tra", "中文(繁体)");
    m_languageMap.insert("fra", "français");
    m_languageMap.insert("deu", "Deutsch");
    m_languageMap.insert("spa", "Español");
    m_languageMap.insert("ita", "Italiano");
    m_languageMap.insert("jpn", "日本語");
    m_languageMap.insert("kor", "한국어");
    m_languageMap.insert("rus", "Русский");
    m_languageMap.insert("ara", "العربية");
    m_languageMap.insert("hin", "हिन्दी");
    m_languageMap.insert("por", "Português");
    m_languageMap.insert("nl", "Nederlands");
    m_languageMap.insert("sv", "Svenska");
    m_languageMap.insert("pl", "Polski");
    m_languageMap.insert("tr", "Türkçe");
    m_languageMap.insert("vi", "Tiếng Việt");
    
    // 检查tessdata目录中的语言文件
    QDir tessdataDir("tessdata");
    if (!tessdataDir.exists()) {
        // 尝试应用程序目录下的tessdata
        tessdataDir.setPath(QCoreApplication::applicationDirPath() + "/tessdata");
        if (!tessdataDir.exists()) {
            qDebug() << "tessdata目录不存在";
            // 添加默认语言
            for (auto it = m_languageMap.constBegin(); it != m_languageMap.constEnd(); ++it) {
                QListWidgetItem *item = new QListWidgetItem(it.value(), m_languageListWidget);
                item->setData(Qt::UserRole, it.key());
                item->setData(Qt::UserRole + 1, m_selectedLanguageCodes.contains(it.key()));
                item->setFlags(item->flags() | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
            }
            return;
        }
    }
    
    // 获取所有.traineddata文件
    QStringList filters;
    filters << "*.traineddata";
    tessdataDir.setNameFilters(filters);
    
    QFileInfoList fileList = tessdataDir.entryInfoList();
    
    // 创建语言映射，优先使用m_languageMap中的显示名称
    QMap<QString, QString> availableLanguages;
    
    for (const QFileInfo &fileInfo : fileList) {
        QString baseName = fileInfo.baseName();
        QString languageCode = baseName;
        
        // 跳过osd.traineddata（方向和脚本检测）
        if (languageCode == "osd") {
            continue;
        }
        
        QString displayName;
        if (m_languageMap.contains(languageCode)) {
            displayName = m_languageMap[languageCode];
        } else {
            // 如果没有映射，使用语言代码作为显示名称
            displayName = languageCode;
        }
        
        availableLanguages.insert(languageCode, displayName);
    }
    
    // 如果没有找到任何语言文件，使用默认映射
    if (availableLanguages.isEmpty()) {
        availableLanguages = m_languageMap;
    }
    
    // 添加列表项
    for (auto it = availableLanguages.constBegin(); it != availableLanguages.constEnd(); ++it) {
        QListWidgetItem *item = new QListWidgetItem(it.value(), m_languageListWidget);
        item->setData(Qt::UserRole, it.key());
        item->setData(Qt::UserRole + 1, m_selectedLanguageCodes.contains(it.key()));
        item->setFlags(item->flags() | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    }
}