#ifndef ILOGGER_H
#define ILOGGER_H

#include <QFile>
#include <QDate>
#include <QString>
#include <QObject>
#include <QTextStream>

#include <iostream>
#include "config_reader.h"
#include "compression_info.h"

class ILogger : public QObject {
    Q_OBJECT
public:
    explicit ILogger();
    virtual ~ILogger();

    virtual void read_log(const QString& log_name) = 0;
    virtual void write_log(const QString& log_name, const QString& data_to_write) = 0;

    virtual QString make_log_str(const CompressionInfo& compression_info) = 0;

private slots:
    virtual void write_compression_log(const CompressionInfo& compression_info) = 0;
};

#endif // ILOGGER_H
