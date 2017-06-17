#ifndef AS3935_h
#define AS3935_h
#include "Arduino.h"

static const uint8_t AS3935_INT_STRIKE = 0x08;
static const uint8_t AS3935_INT_DISTURBER = 0x04;
static const uint8_t AS3935_INT_NOISE = 0x01;

class AS3935
{
public:
    AS3935(uint8_t i2c_address, uint8_t int_pin);
    ~AS3935(void);
    void begin(void);
    void begin(int sda, int scl);
    uint8_t readRegister(uint8_t reg);
    uint8_t readRegisterWithMask(uint8_t reg, uint8_t mask);
    void writeRegisterWithMask(uint8_t reg, uint8_t mask, uint8_t value);
    void writeRegister(uint8_t reg, uint8_t value);
    void setDefault(void);
    void calibrateRCO(void);
    void disableOscillators(void);
    uint8_t getIntrruptReason(void);

private:
    uint8_t _i2c_address;
    uint8_t _int_pin;
    const uint8_t _default_sda = SDA; // D4
    const uint8_t _default_scl = SCL; // D5
    uint8_t _getShift(uint8_t mask);
};

#endif
