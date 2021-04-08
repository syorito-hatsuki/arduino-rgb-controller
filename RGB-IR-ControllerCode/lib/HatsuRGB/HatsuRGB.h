#ifndef HatsuRGB_h
#define HatsuRGB_h
#include <Arduino.h>

class HatsuRGB
{
private:
    byte red, green, blue;
    int redPin, greenPin, bluePin;

public:
    HatsuRGB(int redPin, int greenPin, int bluePin);
    
    void setColorRGB(byte red, byte green, byte blue);
    void setColorHSV(byte hue, byte saturation, byte value);
    void setColorHEX(int hex);

    byte getRed() { return red; };
    byte getGreen() { return green; };
    byte getBlue() { return blue; };

    int getRedPin() { return redPin; };
    int getGreenPin() { return greenPin; };
    int getBluePin() { return bluePin; };
};

#endif