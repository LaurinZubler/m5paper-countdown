#ifndef COUNTDOWNTIMER_H
#define COUNTDOWNTIMER_H

#include <ctime>
#include <string>

class CountdownTimer {
private:
    tm targetDate{};

public:
    CountdownTimer(int year, int month, int day);
    int getDaysRemaining() const;
};

#endif // COUNTDOWNTIMER_H
