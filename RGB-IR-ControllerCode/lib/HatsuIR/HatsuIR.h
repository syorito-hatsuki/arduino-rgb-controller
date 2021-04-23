#ifndef HatsuIR_h
#define HatsuIR_h

#include <Arduino.h>

class HatsuIR
{

private:
    uint8_t ir_pin;
    uint32_t prevIRData;
    
public:
    void setPin(uint8_t pin);
    void setPreviousResult(uint32_t value);

    uint32_t getResult();
    uint32_t getPreviousResult(){ return prevIRData; }
    uint8_t getIrPin(){ return ir_pin; };
};

#endif