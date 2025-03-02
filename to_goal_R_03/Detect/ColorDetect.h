#ifndef ___CLASS_COLORDETECT
#define ___CLASS_COLORDETECT

#include "HSVMonitor.h"

class ColorDetect {
public:
    enum eColor { BLACK, RED, BLUE, YELLOW, ELSE, };

    ColorDetect(HSVMonitor* hsvmonitor);
    eColor getColor(eColor target_color);
    void getBlack();
    void getRed();
    void getBlue();
    void getYellow();

private:
    HSVMonitor* mHSVMonitor;

    eColor color;
    int hue;
    int saturation;
    int value;
};

#endif // ___CLASS_COLORDETECT
