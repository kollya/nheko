#pragma once

#include <QIcon>
#include <QImage>
#include <QPixmap>
#include <QWidget>

#include "Theme.h"

class Avatar : public QWidget
{
        Q_OBJECT

        Q_PROPERTY(QColor textColor WRITE setTextColor READ textColor)
        Q_PROPERTY(QColor backgroundColor WRITE setBackgroundColor READ backgroundColor)

public:
        explicit Avatar(QWidget *parent = nullptr, int size = ui::AvatarSize);

        void setBackgroundColor(const QColor &color);
        void setIcon(const QIcon &icon);
        void setImage(const QString &avatar_url);
        void setImage(const QString &room, const QString &user);
        void setLetter(const QString &letter);
        void setTextColor(const QColor &color);

        QColor backgroundColor() const;
        QColor textColor() const;

        QSize sizeHint() const override;

protected:
        void paintEvent(QPaintEvent *event) override;

private:
        void init();

        ui::AvatarType type_;
        QString letter_;
        QString avatar_url_, room_, user_;
        QColor background_color_;
        QColor text_color_;
        QIcon icon_;
        QPixmap pixmap_;
        int size_;
};
