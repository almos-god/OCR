// customtextbox.cpp
#include "customtextbox.h"
#include <QGraphicsTextItem> // 添加这个包含
#include <QTextDocument>
#include <QGraphicsScene>
/*
CustomTextBox::CustomTextBox(QImage *targetImage, QGraphicsItem *parent)
    : QGraphicsItem(parent), image(targetImage), isResizing(false)
{
    cursor = QTextCursor(&document);
    document.setPlainText("");
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);
    //Qt::TextInteractionFlags(Qt::TextEditorInteraction);
    currentFormat.setFont(QFont("Arial", 12)); // 设置默认字体
}

QRectF CustomTextBox::boundingRect() const
{
    return QRectF(QPointF(0, 0), document.size());
}

void CustomTextBox::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    if (hasFocus()) {
        painter->drawImage(QPoint(0, 0), *image);
        painter->translate(pos());
        painter->setFont(currentFormat.font());
        painter->setPen(currentFormat.foreground().color());
        document.drawContents(painter);
    }
}

void CustomTextBox::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        QRectF rect = boundingRect();
        QPointF pos = event->pos();
        if (pos.x() >= rect.right() - 10 && pos.x() <= rect.right() && pos.y() >= rect.bottom() - 10 && pos.y() <= rect.bottom()) {
            isResizing = true;
            resizeStartPos = pos;
        } else {
            cursor = QTextCursor(&document);
            int posInDocument = document.findBlock(pos.y()).position() + pos.x();
            cursor.setPosition(posInDocument);
            setFocus();
        }
    }
}

void CustomTextBox::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (isResizing) {
        QPointF newPos = event->pos();
        QRectF rect = boundingRect();
        qreal widthDelta = newPos.x() - resizeStartPos.x();
        qreal heightDelta = newPos.y() - resizeStartPos.y();

        QTextBlockFormat format = cursor.blockFormat();
        format.setRightMargin(format.rightMargin() + widthDelta);
        format.setBottomMargin(format.bottomMargin() + heightDelta);
        cursor.setBlockFormat(format);

        document.setTextWidth(format.rightMargin());
        resizeStartPos = newPos;
        update();
    } else {
        QGraphicsItem::mouseMoveEvent(event);
    }
}

void CustomTextBox::focusOutEvent(QFocusEvent *event)
{
    QPainter painter(image);
    painter.setFont(currentFormat.font());
    painter.setPen(currentFormat.foreground().color());
    painter.drawText(pos().toPoint(), document.toPlainText());
    scene()->removeItem(this);
    QGraphicsItem::focusOutEvent(event);
}

void CustomTextBox::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape) {
        focusOutEvent(nullptr);
    } else {
        // 手动处理文本输入
        if (event->text().size() > 0) {
            cursor.insertText(event->text());
        }
        update();
    }
}

void CustomTextBox::setTextFormat(const QTextCharFormat &format)
{
    currentFormat = format;
    update();
}
*/
