#ifndef IFILEOPERATOR_H
#define IFILEOPERATOR_H

#include <QFile>
#include <QList>
#include <QString>
#include <QDataStream>

#include <iostream>
#include "pixel_info.h"


class IFileOperator {
public:
    explicit IFileOperator();
    virtual ~IFileOperator();

    virtual QList<Pixel> read_file(const QString& filename) = 0;

    virtual void write_file(const QString& filename, const QList<PixelInfo>& data) = 0;

};

#endif // IFILEOPERATOR_H
