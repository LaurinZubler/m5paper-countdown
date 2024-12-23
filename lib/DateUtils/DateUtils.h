#ifndef DATEUTILS_H
#define DATEUTILS_H

#include <ctime>

class DateUtils {
private:
    static tm* getCurrentDateTime();

public:
    static int getDaysBetween(const tm& date1, const tm& date2);
    static int getSecondsUntilMidnight();
};

#endif // DATEUTILS_H
