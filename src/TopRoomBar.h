/*
 * nheko Copyright (C) 2017  Konstantinos Sideris <siderisk@auth.gr>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <QColor>
#include <QStringList>
#include <QWidget>

class Avatar;
class FlatButton;
class Menu;
class TextLabel;
class OverlayModal;

class QPainter;
class QLabel;
class QIcon;
class QHBoxLayout;
class QVBoxLayout;

class TopRoomBar : public QWidget
{
        Q_OBJECT

        Q_PROPERTY(QColor borderColor READ borderColor WRITE setBorderColor)

public:
        TopRoomBar(QWidget *parent = nullptr);

        void updateRoomAvatar(const QString &avatar_image);
        void updateRoomAvatar(const QIcon &icon);
        void updateRoomName(const QString &name);
        void updateRoomTopic(QString topic);
        void updateRoomAvatarFromName(const QString &name);

        void reset();

        QColor borderColor() const { return borderColor_; }
        void setBorderColor(QColor &color) { borderColor_ = color; }

public slots:
        //! Add a "back-arrow" button that can switch to roomlist only view.
        void enableBackButton();
        //! Replace the "back-arrow" button with the avatar of the room.
        void disableBackButton();

signals:
        void inviteUsers(QStringList users);
        void showRoomList();
        void mentionsClicked(const QPoint &pos);

protected:
        void mousePressEvent(QMouseEvent *) override;
        void paintEvent(QPaintEvent *) override;

private:
        QHBoxLayout *topLayout_  = nullptr;
        QVBoxLayout *textLayout_ = nullptr;

        QLabel *nameLabel_     = nullptr;
        TextLabel *topicLabel_ = nullptr;

        Menu *menu_;
        QAction *leaveRoom_    = nullptr;
        QAction *roomMembers_  = nullptr;
        QAction *roomSettings_ = nullptr;
        QAction *inviteUsers_  = nullptr;

        FlatButton *settingsBtn_;
        FlatButton *mentionsBtn_;
        FlatButton *backBtn_;

        Avatar *avatar_;

        int buttonSize_;

        QColor borderColor_;
};
