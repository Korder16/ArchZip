#include "config_reader.h"

ConfigReader::ConfigReader() {}

ConfigReader::~ConfigReader() {}


ConfigReader& ConfigReader::get_instance() {
    static ConfigReader instance;
    return instance;
}


void ConfigReader::read_config(const QString &config_name) {
    QFile* file = new QFile(config_name);
    if(file->open(QIODevice::ReadOnly)) {
        QTextStream out(file);
        fill_qmap(out);
    }
    else {
        std::cerr << "Cannot open config file" << std::endl;
    }
    file->close();
}


void ConfigReader::fill_qmap(QTextStream& out) {
    while(!out.atEnd()) {
        QString setting = out.readLine();
        settings.insert(setting.split(splitter).first(), setting.split(splitter).last());
    }
}

QString ConfigReader::get_config_setting(const QString& key) const {
    return settings.value(key);
}
