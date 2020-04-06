#ifndef COMPRESSION_LOGGER_H
#define COMPRESSION_LOGGER_H

#include "ilogger.h"

class CompressionLogger : public ILogger {
    Q_OBJECT
public:
    CompressionLogger();
    ~CompressionLogger();

    void read_log(const QString& log_name);
    void write_log(const QString& log_name, const QString& data_to_write);

    QString make_log_str(const CompressionInfo& compression_info) override;

private slots:
    void write_compression_log(const CompressionInfo& compression_info);
};

#endif // COMPRESSION_LOGGER_H
