#ifndef HatsuIR_h
#define HatsuIR_h

#include <Arduino.h>

class HatsuIR
{

private:
    int ir_pin;
    
public:
    void setPin(int pin);
    uint32_t getResult();
    uint32_t getIrPin(){ return ir_pin; };
};

#endif