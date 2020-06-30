/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef ChapterTable_H
#define ChapterTable_H

#include <QAbstractItemModel>
#include <QModelIndex>
#include <QVariant>

#include "DialogueItem.h"

class ChapterTable : public QAbstractItemModel
{
    Q_OBJECT

public:
    ///Constructor
    ChapterTable(const QStringList &headers);

    ///Deconstructor
    ~ChapterTable() override;

    void UpdateTableData(QString storyFilePath);

    /* INHERITED */
    QModelIndex parent(const QModelIndex &index) const override;

    ///Retrieves the data held within the given index, for the given role
    QVariant data(const QModelIndex &index, int role) const override;

    ///Updates the data held within the given index for the given role (Edit by default)
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;

    ///Returns the index of the item in the model specified by the given row, column, and parent index
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const override;

    ///Given an index for an item in the table, return the number of children rows
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    ///Given an index for an item in the table, return the number of columns the item encompasses
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;


    Qt::ItemFlags flags(const QModelIndex &index) const override;


    bool setHeaderData(int section, Qt::Orientation orientation,
                       const QVariant &value, int role = Qt::EditRole) override;

    bool insertRows(int position, int rows,
                    const QModelIndex &parent = QModelIndex()) override;

    bool removeRows(int position, int rows,
                    const QModelIndex &parent = QModelIndex()) override;

private:
    ///Given an index for an item in the table, return a pointer to the item itself
    DialogueItem *getItem(const QModelIndex &index) const;
    DialogueItem *rootItem;

};
//! [2]

#endif // ChapterTable_H
