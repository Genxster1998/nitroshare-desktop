/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2016 Nathan Osman
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#ifndef FILE_H
#define FILE_H

#include <QDateTime>
#include <QDir>
#include <QFileInfo>
#include <QVariantMap>

#include <nitroshare/item.h>

/**
 * @brief Item for reading and writing files in the local filesystem
 */
class File : public Item
{
    Q_OBJECT

public:

    static const QString Type;

    File(const QVariantMap &properties);
    File(const QDir &root, const QFileInfo &info);

    // Reimplemented virtual methods
    virtual QVariantMap properties() const;
    virtual QIODevice *createReader();
    virtual QIODevice *createWriter();

private:

    QString mLocalFilename;
    QString mRelativeFilename;

    qint64 mSize;
    bool mReadOnly;

    QDateTime mCreated;
    QDateTime mLastRead;
    QDateTime mLastModified;
};

#endif // FILE_H
