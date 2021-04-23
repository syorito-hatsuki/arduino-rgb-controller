#pragma once
#include <Arduino.h>

class HatsuRGB {
    uint8_t red, green, blue;
    uint8_t redPin, greenPin, bluePin;

public:
    void addSpeed();      //Прибавить скорость
    void subtractSpeed(); //Убавить скорость

    void setPins(uint8_t redPin, uint8_t greenPin, uint8_t bluePin);        //Установка пинов
    void setColorRGB(uint8_t red, uint8_t green, uint8_t blue); //Установка цвета RGB

    void fadeEffect();
    void strobeEffect();
    void flashEffect();
    void smoothEffect();

    uint8_t getRed() { return red; };
    uint8_t getGreen() { return green; };
    uint8_t getBlue() { return blue; };

    uint8_t getRedPin() { return redPin; };
    uint8_t getGreenPin() { return greenPin; };
    uint8_t getBluePin() { return bluePin; };
};
