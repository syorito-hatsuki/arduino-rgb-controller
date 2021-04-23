#include <HatsuIR.h>

void HatsuIR::setPin(uint8_t pin)
{
    ir_pin = pin;
    pinMode(pin, INPUT);
}

uint32_t HatsuIR::getResult()
{
    int pulseLength = 0;
    uint32_t receivedData = 0;
    if (digitalRead(ir_pin) == LOW)
    {             //tarkistaa jos alkubitti on vetänyt datalinjan alas
        delay(8); //odottaa kunnes alkubitti on melkein ohi (9200 us)
        if (digitalRead(ir_pin) == LOW)
        { //tarkistaa jos alkubitti on edelleen menossa

            //NULL transmission detection:
            pulseLength = pulseIn(ir_pin, HIGH);
            if (pulseLength > 2500)
            { //etene jos lähetys ei ole NULL

                //IR vastaanotto
                for (byte i = 0; i < 32; i++)
                {
                    pulseLength = pulseIn(ir_pin, HIGH, 5000);
                    if (pulseLength > 1100)
                    {                       //IR looginen "1" on noin 1600us pitkä; yli 1100us
                        receivedData <<= 1; //siirtää tavua yhden vasemmalle (esim 01100111 -> 11001110 mikäli pituus 8 bittiä
                        receivedData |= 1;  //asettaa LSB:n arvoksi 1 muuttamatta lopun tavun arvoa
                    }
                    else
                    { //IR looginen "0" on noin 600us pitkä; alle 1100us
                        receivedData <<= 1;
                        receivedData |= 0;
                    }
                } //Vastaanoton loppu
                HatsuIR::prevIRData = receivedData;
                return receivedData;
            }
        }
    }
    return 0;
}
