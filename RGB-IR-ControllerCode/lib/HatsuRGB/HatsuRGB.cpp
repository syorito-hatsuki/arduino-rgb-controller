#include <HatsuRGB.h>
#include <EEPROM.h>

void HatsuRGB::enable()
{
    setColorRGB(EEPROM.read(0), EEPROM.read(1), EEPROM.read(2));
}

void HatsuRGB::disable()
{
    saveEEPROM();
    setColorRGB(0, 0, 0);
}

void HatsuRGB::addSpeed(){
    if (speed + 20 < 255) {
        speed += 20;
        EEPROM.write(4, speed);
    }
}

void HatsuRGB::subtractSpeed(){
    if (speed - 20 > 0) {
        speed -= 20;
        EEPROM.write(4, speed);
    }
}

void HatsuRGB::setPins(int redPin, int greenPin, int bluePin)
{
    HatsuRGB::redPin = redPin;
    HatsuRGB::greenPin = greenPin;
    HatsuRGB::bluePin = bluePin;

    pinMode(redPin, INPUT);
    pinMode(greenPin, INPUT);
    pinMode(bluePin, INPUT);
}

void HatsuRGB::setColorRGB(uint8_t red, uint8_t green, uint8_t blue)
{
    HatsuRGB::red = red;
    HatsuRGB::green = green;
    HatsuRGB::blue = blue;

    analogWrite(redPin, red);
    analogWrite(greenPin, green);
    analogWrite(bluePin, blue);
}

void HatsuRGB::saveEEPROM(){
    EEPROM.write(0, HatsuRGB::red);
    EEPROM.write(1, HatsuRGB::green);
    EEPROM.write(2, HatsuRGB::blue);
}

void HatsuRGB::fadeEffect(){
    speed = EEPROM.read(4);
    setColorRGB(255, 0, 0);
    delay(speed);
    setColorRGB(0, 255, 0);
    delay(speed);
    setColorRGB(0, 0, 255);
    delay(speed);
}

void HatsuRGB::strokeEffect(){

}

void HatsuRGB::flashEffect(){

}

void HatsuRGB::smoothEffect(){

}