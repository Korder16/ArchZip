#include "time_counter.h"

TimeCounter::TimeCounter() {}

TimeCounter::~TimeCounter() {}

void TimeCounter::count_time(std::function<void(QString)> function,
                             const QString& filename) {
    QElapsedTimer timer;
    // Start timer
    timer.start();
    // Do function
    function(filename);
    // Stop timer
    std::cout << "Time = " << timer.elapsed() << " ms" << std::endl;
}
