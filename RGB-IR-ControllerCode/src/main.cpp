#include <Arduino.h>
#include <IRremote.h>

/* Color Keys */
#define COLOR_RED 0xF609FF00
#define COLOR_DARK_ORANGE 0xF20DFF00
#define COLOR_ORANGE 0xEA15FF00
#define COLOR_LIGHT_ORANGE 0xE619FF00
#define COLOR_YELLOW 0xEE11FF00
#define COLOR_GREEN 0xF708FF00
#define COLOR_LIGHT_GREEN 0xF30CFF00
#define COLOR_CYAN 0xEB14FF00
#define COLOR_TEAL 0xE718FF00
#define COLOR_OCEAN 0xEF10FF00
#define COLOR_BLUE 0xF50AFF00
#define COLOR_LIGHT_BLUE 0xF10EFF00
#define COLOR_PURPLE 0xE916FF00
#define COLOR_VIOLET 0xE51AFF00
#define COLOR_PINK 0xED12FF00
#define COLOR_WHITE 0xF40BFF00

/* Function Keys */
#define FUNCTION_PLUS 0xFA05FF00
#define FUNCTION_MINUS 0xFB04FF00
#define FUNCTION_OFF 0xF906FF00
#define FUNCTION_ON 0xF807FF00

/* Effect Keys */
#define EFFECT_FADE 0xF00FFF00
#define EFFECT_STROBE 0xE817FF00
#define EFFECT_FLASH 0xE41BFF00
#define EFFECT_SMOOTH 0xEC13FF00

/* IO Pins */

#define IR_RECEIVE_PIN 7

IRrecv irrecv(IR_RECEIVE_PIN);

void setup()
{
    Serial.begin(115200);
    irrecv.enableIRIn();
}

void loop()
{
    if (irrecv.decode())
    {
        // Serial.println(irrecv.decodedIRData.decodedRawData, HEX);

        if (!irrecv.decodedIRData.decodedRawData == 0)
        {
            if (irrecv.decodedIRData.decodedRawData == (FUNCTION_PLUS || FUNCTION_MINUS || FUNCTION_ON || FUNCTION_OFF))
            {
                Serial.println(F("Effect key"));
                Serial.println(irrecv.decodedIRData.decodedRawData, HEX);
            }
            else if (irrecv.decodedIRData.decodedRawData == (EFFECT_FADE || EFFECT_STROBE || EFFECT_FLASH || EFFECT_SMOOTH))
            {
                Serial.println(F("Function key"));
                Serial.println(irrecv.decodedIRData.decodedRawData, HEX);
            }
            else
            {
                Serial.println(F("Color key"));
                Serial.println(irrecv.decodedIRData.decodedRawData, HEX);
            }
        }
        Serial.println();
    }
    irrecv.resume();
}