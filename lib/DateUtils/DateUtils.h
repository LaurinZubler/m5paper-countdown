#ifndef DATEUTILS_H
#define DATEUTILS_H

#include <ctime>

class DateUtils {

public:
    static int getDaysBetween(const tm& date1, const tm& date2);
    static int getSecondsUntilMidnight(const tm& date);
};

#endif // DATEUTILS_H
