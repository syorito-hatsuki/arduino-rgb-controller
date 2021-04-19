#include <HatsuRGB.h>

void HatsuRGB::setPins(int redPin, int greenPin, int bluePin)
{
    HatsuRGB::redPin = redPin;
    HatsuRGB::greenPin = greenPin;
    HatsuRGB::bluePin = bluePin;

    pinMode(redPin, INPUT);
    pinMode(greenPin, INPUT);
    pinMode(bluePin, INPUT);
}

void HatsuRGB::setColorRGB(byte red, byte green, byte blue)
{
    HatsuRGB::red = red;
    HatsuRGB::green = green;
    HatsuRGB::blue = blue;

    analogWrite(redPin, red);
    analogWrite(greenPin, green);
    analogWrite(bluePin, blue);
}