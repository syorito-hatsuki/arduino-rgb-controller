#pragma once
#include <Arduino.h>

class HatsuIR {
    uint8_t ir_pin;
    uint32_t prevIRData;
    
public:
    void setPin(uint8_t pin);

    uint32_t getResult();
    uint32_t getPreviousResult(){ return prevIRData; }
    uint8_t getIrPin(){ return ir_pin; };
};
