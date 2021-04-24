#include <Arduino.h>
#include <../lib/HatsuRGB/HatsuRGB.h>
#include <../lib/HatsuIR/HatsuIR.h>

/* Color Keys */
#define COLOR_RED 0xFF906F
#define COLOR_DARK_ORANGE 0xFFB04F
#define COLOR_ORANGE 0xFFA857
#define COLOR_LIGHT_ORANGE 0xFF9867
#define COLOR_YELLOW 0xFF8877
#define COLOR_GREEN 0xFF10EF
#define COLOR_LIGHT_GREEN 0xFF30CF
#define COLOR_CYAN 0xFF28D7
#define COLOR_TEAL 0xFF18E7
#define COLOR_OCEAN 0xFF08F7
#define COLOR_BLUE 0xFF50AF
#define COLOR_LIGHT_BLUE 0xFF708F
#define COLOR_PURPLE 0xFF6897
#define COLOR_VIOLET 0xFF58A7
#define COLOR_PINK 0xFF48B7
#define COLOR_WHITE 0xFFD02F

/* Function Keys */
#define FUNCTION_PLUS 0xFFA05F
#define FUNCTION_MINUS 0xFF20DF
#define FUNCTION_OFF 0xFF609F
#define FUNCTION_ON 0xFFE01F

/* Effect Keys */
#define EFFECT_FADE 0xFFF00F
#define EFFECT_STROBE 0xFFE817
#define EFFECT_FLASH 0xFFD827
#define EFFECT_SMOOTH 0xFFC837

/* IO Pins */

#define IR_RECEIVE_PIN 2

HatsuIR ir;
HatsuRGB rgb;
volatile uint32_t correctData;
uint32_t currentMode;

void recive();

void setup()
{
    ir.setPin(IR_RECEIVE_PIN);
    rgb.setPins(9, 11, 10);
    attachInterrupt(0, recive, FALLING);
}

void loop()
{
    switch (correctData)
    {
        /* Function keys */
    case FUNCTION_PLUS:
        rgb.addSpeed();
        correctData = currentMode;
        break;
    case FUNCTION_MINUS:
        rgb.subtractSpeed();
        correctData = currentMode;
        break;
    case FUNCTION_OFF:
        rgb.setColorRGB(0, 0, 0);
        break;
    case FUNCTION_ON:
        correctData = currentMode;
        break;

        /* Color keys */
    case COLOR_WHITE:
        currentMode = correctData;
        rgb.setColorRGB(255, 255, 255);
        break;
    case COLOR_RED:
        currentMode = correctData;
        rgb.setColorRGB(255, 0, 0);
        break;
    case COLOR_DARK_ORANGE:
        currentMode = correctData;
        rgb.setColorRGB(255, 64, 0);
        break;
    case COLOR_ORANGE:
        currentMode = correctData;
        rgb.setColorRGB(255, 127, 0);
        break;
    case COLOR_LIGHT_ORANGE:
        currentMode = correctData;
        rgb.setColorRGB(255, 194, 0);
        break;
    case COLOR_YELLOW:
        currentMode = correctData;
        rgb.setColorRGB(255, 255, 0);
        break;
    case COLOR_GREEN:
        currentMode = correctData;
        rgb.setColorRGB(0, 255, 0);
        break;
    case COLOR_LIGHT_GREEN:
        currentMode = correctData;
        rgb.setColorRGB(64, 255, 0);
        break;
    case COLOR_CYAN:
        currentMode = correctData;
        rgb.setColorRGB(0, 255, 255);
        break;
    case COLOR_TEAL:
        currentMode = correctData;
        rgb.setColorRGB(0, 194, 255);
        break;
    case COLOR_OCEAN:
        currentMode = correctData;
        rgb.setColorRGB(0, 127, 255);
        break;
    case COLOR_BLUE:
        currentMode = correctData;
        rgb.setColorRGB(0, 0, 255);
        break;
    case COLOR_LIGHT_BLUE:
        currentMode = correctData;
        rgb.setColorRGB(0, 64, 255);
        break;
    case COLOR_PURPLE:
        currentMode = correctData;
        rgb.setColorRGB(127, 0, 255);
        break;
    case COLOR_VIOLET:
        currentMode = correctData;
        rgb.setColorRGB(255, 0, 255);
        break;
    case COLOR_PINK:
        currentMode = correctData;
        rgb.setColorRGB(255, 77, 189);
        break;

        /* Effect keys */
    case EFFECT_FADE:
        currentMode = correctData;
        rgb.fadeEffect();
        break;
    case EFFECT_STROBE:
        currentMode = correctData;
        rgb.strobeEffect();
        break;
    case EFFECT_FLASH:
        currentMode = correctData;
        rgb.flashEffect();
        break;
    case EFFECT_SMOOTH:
        currentMode = correctData;
        rgb.smoothEffect();
        break;
    }
}

void recive()
{
    uint32_t result = ir.getResult();
    if (ir.getResult() != result)
        if (ir.getPreviousResult() != 0)
            correctData = ir.getPreviousResult();
}