#ifndef TIME_COUNTER_H
#define TIME_COUNTER_H

#include <QElapsedTimer>
#include <QString>

#include <iostream>
#include <functional>

class TimeCounter {
public:
    explicit TimeCounter();
    ~TimeCounter();

    void count_time(std::function<void(QString)> function,
                    const QString& filename);
};

#endif // TIME_COUNTER_H
