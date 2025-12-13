#ifndef LANGUAGE_SELECTION_DIALOG_H
#define LANGUAGE_SELECTION_DIALOG_H

#include <QDialog>
#include <QListWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QCoreApplication>
#include <QMap>
#include <QWindow>
#include <QStringList>
#include <QStyledItemDelegate>
#include <QListWidgetItem>


class LanguageSelectionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LanguageSelectionDialog(QWidget *parent = nullptr);
    ~LanguageSelectionDialog();

    // 获取选中的语言代码列表
    QStringList selectedLanguageCodes() const;
    // 设置选中的语言代码列表
    void setSelectedLanguageCodes(const QStringList &codes);
    
    // 兼容旧接口，返回第一个选中的语言代码
    QString selectedLanguageCode() const;
    // 兼容旧接口，设置选中的语言代码
    void setSelectedLanguageCode(const QString &code);

private slots:
    // 处理确定按钮点击
    void onOkButtonClicked();
    // 处理取消按钮点击
    void onCancelButtonClicked();

private:
    // 初始化UI
    void initUI();
    // 加载可用语言
    void loadAvailableLanguages();
    // 重写paintEvent实现彩色流动背景
    void paintEvent(QPaintEvent *event) override;
    // 语言代码到显示名称的映射
    QMap<QString, QString> m_languageMap;
    // 当前选中的语言代码列表
    QStringList m_selectedLanguageCodes;
    // 语言列表视图
    QListWidget *m_languageListWidget;
};

#endif // LANGUAGE_SELECTION_DIALOG_H