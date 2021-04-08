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

void setup()
{
    Serial.begin(115200);
    ir.setPin(IR_RECEIVE_PIN);
#if DEBUG == 1
    Serial.print("IR connected to pin: ");
    Serial.println(ir.getPin());
#endif
}

void loop()
{
    uint32_t data = ir.getResult();
    if (ir.getResult() != data)
    {
#if DEBUG == 1
        Serial.print("Result is: ");
        Serial.println(data, HEX);
#endif
    }
}