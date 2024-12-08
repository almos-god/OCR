
/*#include "ImageTextBox.h"
#include <QPainter>
#include <QVBoxLayout>
ImageTextBox::ImageTextBox(QWidget *parent) : QWidget(parent) {
    textInput = new QLineEdit(this);
    addButton = new QPushButton("Add Text", this);
    connect(addButton, &QPushButton::clicked, this, &ImageTextBox::addText);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(textInput);
    layout->addWidget(addButton);
}

void ImageTextBox::setImage(const QImage& newImage) {
    this->image = newImage;
    this->update();
}

void ImageTextBox::setTextFormat(const QTextCharFormat& format) {
    this->textFormat = format;
}
void ImageTextBox::setTextPosition(const QPoint& pos) {
    textPosition = pos;
}
void ImageTextBox::addText() {
    QPainter painter(&this->image);
    QFont font;
    font.setFamily(this->textFormat.fontFamily());
    font.setPointSize(this->textFormat.fontPointSize());
    font.setUnderline(this->textFormat.fontUnderline());
    font.setStrikeOut(this->textFormat.fontStrikeOut());
    font.setBold(this->textFormat.fontWeight() == QFont::Bold);
    font.setItalic(this->textFormat.fontItalic());
    painter.setFont(font);

    painter.drawText(textPosition, textInput->text());

    this->update();
    emit this->imageUpdated(this->image);
}

QImage ImageTextBox::getImage() const {
    return this->image;
}*/
/*
#include "ImageTextWidget.h"
#include <QPainter>

ImageTextWidget::ImageTextWidget(QImage *image, QGraphicsScene *scene, QGraphicsItem *parent)
    : QGraphicsItem(parent), targetImage(image), isResizing(false), parentScene(scene)
{
    cursor = QTextCursor(&document);
    document.setPlainText("");
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);
    setTextInteractionFlags(Qt::TextEditorInteraction);
}

QRectF ImageTextWidget::boundingRect() const
{
    return document.size().toRect();
}

void ImageTextWidget::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    if (hasFocus()) {
        painter->drawImage(QPoint(0, 0), *targetImage);
        painter->translate(initialPos);
        painter->setFont(currentFormat.font());
        painter->setPen(currentFormat.foreground().color());
        document.drawContents(painter);
    }
}

void ImageTextWidget::mousePressEvent(QMouseEvent *event)
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
            initialPos = pos;
        }
    }
}

void ImageTextWidget::mouseMoveEvent(QMouseEvent *event)
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

void ImageTextWidget::focusOutEvent(QFocusEvent *event)
{
    drawTextOnImage();
    parentScene->removeItem(this);
    QGraphicsItem::focusOutEvent(event);
}

void ImageTextWidget::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape) {
        drawTextOnImage();
        clearFocus();
        parentScene->removeItem(this);
    } else {
        document.keyPressEvent(event);
        update();
    }
}

void ImageTextWidget::setTextFormat(const QTextCharFormat &format)
{
    currentFormat = format;
    update();
}

void ImageTextWidget::setPosition(const QPointF &pos)
{
    initialPos = pos;
    setPos(pos);
}

void ImageTextWidget::drawTextOnImage()
{
    QPainter painter(targetImage);
    painter.setFont(currentFormat.font());
    painter.setPen(currentFormat.foreground().color());
    painter.drawText(initialPos.toPoint(), document.toPlainText());
}*/
