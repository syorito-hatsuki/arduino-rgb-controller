#pragma once
#include <Arduino.h>

class HatsuRGB {
    uint8_t red, green, blue;
    uint8_t redPin, greenPin, bluePin;

public:
    void enable();                                //Вкл
    void disable();                               //Выкл
    uint32_t addSpeed(uint32_t currentMode);      //Прибавить скорость
    uint32_t subtractSpeed(uint32_t currentMode); //Убавить скорость
    bool isEnabled();                             //Включено?

    void saveEEPROM(); //Сохранение настроек

    void setPins(int redPin, int greenPin, int bluePin);        //Установка пинов
    void setColorRGB(uint8_t red, uint8_t green, uint8_t blue); //Установка цвета RGB

    void fadeEffect();
    void strokeEffect();
    void flashEffect();
    void smoothEffect();

    uint8_t getRed() { return red; };
    uint8_t getGreen() { return green; };
    uint8_t getBlue() { return blue; };

    uint8_t getRedPin() { return redPin; };
    uint8_t getGreenPin() { return greenPin; };
    uint8_t getBluePin() { return bluePin; };
};
