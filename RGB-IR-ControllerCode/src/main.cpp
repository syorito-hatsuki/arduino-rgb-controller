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

#define DEBUG 0

/* IO Pins */

#define IR_RECEIVE_PIN 2

HatsuIR ir;
HatsuRGB rgb;
uint32_t current = 0xFFD02F;

void recive();

void setup()
{
    Serial.begin(115200);
    ir.setPin(IR_RECEIVE_PIN);
    rgb.setPins(9, 11, 10);
#if DEBUG == 1
    Serial.print("IR connected to pin: ");
    Serial.println(ir.getIrPin());
#endif
    attachInterrupt(0, recive, FALLING);
}

void loop() {}

void recive()
{
    current = ir.getResult();
    if (ir.getResult() != current)
    {
        if (current == 0)
        {
            Serial.println("Zero");
        }
        else
        {
            Serial.print("Current result: ");
            Serial.println(current, HEX);
        }
    }

    switch (current)
    {
        /* Function keys */
    case FUNCTION_PLUS:

        break;
    case FUNCTION_MINUS:

        break;
    case FUNCTION_OFF:
        rgb.setColorRGB(0, 0, 0);
        break;
    case FUNCTION_ON:

        break;

        /* Color keys */
    case COLOR_WHITE:
        rgb.setColorRGB(255, 255, 255);
        break;
    case COLOR_RED:
        rgb.setColorRGB(255, 0, 0);
        break;
    case COLOR_DARK_ORANGE:

        break;
    case COLOR_ORANGE:

        break;
    case COLOR_LIGHT_ORANGE:

        break;
    case COLOR_YELLOW:

        break;
    case COLOR_GREEN:
        rgb.setColorRGB(0, 255, 0);
        break;
    case COLOR_LIGHT_GREEN:

        break;
    case COLOR_CYAN:

        break;
    case COLOR_TEAL:

        break;
    case COLOR_OCEAN:

        break;
    case COLOR_BLUE:
        rgb.setColorRGB(0, 0, 255);
        break;
    case COLOR_LIGHT_BLUE:

        break;
    case COLOR_PURPLE:

        break;
    case COLOR_VIOLET:

        break;
    case COLOR_PINK:

        break;

        /* Effect keys */
    case EFFECT_FADE:

        break;
    case EFFECT_STROBE:

        break;
    case EFFECT_FLASH:

        break;
    case EFFECT_SMOOTH:

        break;
    }
}