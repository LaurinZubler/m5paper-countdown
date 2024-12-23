#ifndef M5PAPERCONTROLLER_H
#define M5PAPERCONTROLLER_H

#include <M5EPD.h>

class M5PaperController {
public:
    void initialize();
    void update(int remainingDays);
};

#endif // M5PAPERCONTROLLER_H
