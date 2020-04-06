#ifndef CONFIG_READER_H
#define CONFIG_READER_H

#include <QMap>
#include <QFile>
#include <QString>
#include <QTextStream>

#include <iostream>

class ConfigReader {
public:
    static ConfigReader& get_instance();
    void read_config(const QString& config_name);
    QString get_config_setting(const QString& key) const;

private:
    // Singleton
    ConfigReader();
    ~ConfigReader();
    ConfigReader(const ConfigReader& oth);
    ConfigReader& operator=(const ConfigReader& oth);

    void fill_qmap(QTextStream& out);
    QMap<QString, QString> settings;
    const QString splitter{"="};
};

#endif // CONFIG_READER_H
