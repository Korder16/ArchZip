#include "compression_logger.h"

CompressionLogger::CompressionLogger() {}

CompressionLogger::~CompressionLogger() {}

void CompressionLogger::read_log(const QString &log_name) {}

void CompressionLogger::write_log(const QString &log_name, const QString& data_to_write) {
    QFile* file = new QFile(log_name);
    if(file->open(QIODevice::WriteOnly | QIODevice::Append)) {
        QTextStream in(file);
        in << data_to_write;
        in << "\n";
    }
    else {
        std::cerr << "Error while openning file" << std::endl;
        return;
    }
    file->close();
}

void CompressionLogger::write_compression_log(const CompressionInfo& compression_info) {
    std::cout << "Slot in compression logger" << std::endl;
    QString log_name = "log_" + QDate::currentDate().toString("dd.MM.yyyy");

    QString log_str = make_log_str(compression_info);

    write_log(ConfigReader::get_instance().get_config_setting("compression_logs_dir") + log_name,
              log_str);
}


QString CompressionLogger::make_log_str(const CompressionInfo &compression_info) {
    // Make str to write in log
    int compression_ratio = compression_info._img_size / compression_info._compressed_img_size;
    QString log_str = QString("image:%1 "
                              "compression_time:%2ms "
                              "input_size:%3b "
                              "result_size:%4b "
                              "compression ratio:%5 "
                              "current_time:%6 "
                              "algorithm:%7 ").
            arg(compression_info._filename.split("/").last()).
            arg(QString::number(compression_info._time_elapsed)).
            arg(compression_info._img_size).
            arg(compression_info._compressed_img_size).
            arg(QString::number(compression_ratio)).
            arg(compression_info._current_time).
            arg(compression_info._algorithm);

    return log_str;
}
