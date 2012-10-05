/**************************************************************************
**
** This file is part of Qt Creator
**
** Copyright (c) 2012 Nokia Corporation and/or its subsidiary(-ies).
**
** Contact: http://www.qt-project.org/
**
**
** GNU Lesser General Public License Usage
**
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this file.
** Please review the following information to ensure the GNU Lesser General
** Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** Other Usage
**
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**************************************************************************/

#ifndef QMLCONSOLEITEM_H
#define QMLCONSOLEITEM_H

#include "qmljstools_global.h"

#include <QList>
#include <QString>

namespace QmlJSTools {

class QMLJSTOOLS_EXPORT QmlConsoleItem
{
public:
    enum ItemType
    {
        UndefinedType = 0x01, // Can be used for unknown and for Return values
        DebugType     = 0x02,
        WarningType   = 0x04,
        ErrorType     = 0x08,
        InputType     = 0x10,
        DefaultTypes  = InputType | UndefinedType
    };
    Q_DECLARE_FLAGS(ItemTypes, ItemType)

    QmlConsoleItem(QmlConsoleItem *parent,
                   QmlConsoleItem::ItemType type = QmlConsoleItem::UndefinedType,
                   const QString &data = QString());
    ~QmlConsoleItem();

    QmlConsoleItem *child(int number);
    int childCount() const;
    bool insertChildren(int position, int count);
    void insertChild(QmlConsoleItem *item, bool sorted);
    bool insertChild(int position, QmlConsoleItem *item);
    QmlConsoleItem *parent();
    bool removeChildren(int position, int count);
    bool detachChild(int position);
    int childNumber() const;
    void setText(const QString &text);
    const QString &text() const;

private:
    QmlConsoleItem *m_parentItem;
    QList<QmlConsoleItem *> m_childItems;
    QString m_text;

public:
    QmlConsoleItem::ItemType itemType;
    QString file;
    int line;
};

} // QmlJSTools

#endif // QMLCONSOLEITEM_H
