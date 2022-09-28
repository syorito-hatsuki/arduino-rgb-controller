#include <HatsuRGB.h>
#include <EEPROM.h>

#define MAX_SPEED 1000
#define MIN_SPEED 100
#define SPEED_STEP 100

uint16_t speed = 100;
uint32_t Rvalue = 254, Gvalue = 1, Bvalue = 127;
uint32_t Rdirection = -1, Gdirection = 1, Bdirection = -1;

void HatsuRGB::addSpeed()
{
    EEPROM.get(4, speed);
    if (speed - SPEED_STEP > MIN_SPEED)
    {
        speed -= SPEED_STEP;
        EEPROM.put(4, speed);
    } else {
        speed = MIN_SPEED;
    }
}

void HatsuRGB::subtractSpeed()
{
    EEPROM.get(4, speed);
    if (speed + SPEED_STEP < MAX_SPEED)
    {
        speed += SPEED_STEP;
        EEPROM.put(4, speed);
    } else {
        speed = MAX_SPEED;
    }
}

void HatsuRGB::setPins(uint8_t redPin, uint8_t greenPin, uint8_t bluePin)
{
    HatsuRGB::redPin = redPin;
    HatsuRGB::greenPin = greenPin;
    HatsuRGB::bluePin = bluePin;

    srand(A0);
    EEPROM.get(4, speed);

    pinMode(redPin, INPUT);
    pinMode(greenPin, INPUT);
    pinMode(bluePin, INPUT);
}

void HatsuRGB::setColorRGB(uint8_t red, uint8_t green, uint8_t blue)
{
    if (red != 0 && green != 0 && blue != 0)
    {
        HatsuRGB::red = red;
        HatsuRGB::green = green;
        HatsuRGB::blue = blue;
    }

    analogWrite(redPin, red);
    analogWrite(greenPin, green);
    analogWrite(bluePin, blue);
}

void HatsuRGB::fadeEffect()
{
    setColorRGB(255, 0, 0);
    delay(speed);
    setColorRGB(255, 255, 0);
    delay(speed);
    setColorRGB(0, 255, 0);
    delay(speed);
    setColorRGB(0, 255, 255);
    delay(speed);
    setColorRGB(0, 0, 255);
    delay(speed);
    setColorRGB(255, 0, 255);
    delay(speed);


    Serial.print("effect speed is: ");
    Serial.println(speed);
}

void HatsuRGB::strobeEffect()
{
    setColorRGB(1 + (rand() % 255), 1 + (rand() % 255), 1 + (rand() % 255));
    delay(speed);
}

void HatsuRGB::flashEffect()
{
    setColorRGB(255, 255, 255);
    delay(speed);
    setColorRGB(0, 0, 0);
    delay(speed);
}

void HatsuRGB::smoothEffect()
{

    setColorRGB(Rvalue, Gvalue, Bvalue);

    Rvalue = Rvalue + Rdirection; //changing values of LEDs
    Gvalue = Gvalue + Gdirection;
    Bvalue = Bvalue + Bdirection;

    //now change direction for each color if it reaches 255
    if (Rvalue >= 255 || Rvalue <= 0)
    {
        Rdirection = Rdirection * -1;
    }
    if (Gvalue >= 255 || Gvalue <= 0)
    {
        Gdirection = Rdirection * -1;
    }
    if (Bvalue >= 255 || Bvalue <= 0)
    {
        Bdirection = Bdirection * -1;
    }
    delay(speed / 10); //give some delay so you can see the change
}