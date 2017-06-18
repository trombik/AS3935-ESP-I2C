#ifndef AS3935_h
#define AS3935_h
#include "Arduino.h"

static const uint8_t AS3935_INT_STRIKE = 0x08;
static const uint8_t AS3935_INT_DISTURBER = 0x04;
static const uint8_t AS3935_INT_NOISE = 0x01;
static const int8_t  AS3935_DISTANCE_OUT_OF_RANGE = -2;
static const uint8_t AS3935_AFE_INDOOR =  0b10010;
static const uint8_t AS3935_AFE_OUTDOOR = 0b01110;

class AS3935
{
public:
    AS3935(uint8_t address, uint8_t interruptPin);
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
    int8_t getDistance(void);
    bool isIndoor(void);
    bool setIndoor(void);
    bool setIndoor(bool enable);
    bool isOutdoor(void);
    bool setOutdoor(void);
    bool setOutdoor(bool enable);
    uint8_t getMinimumLightning(void);
    bool setMinimumLightning(uint8_t);
    void clearStats(void);
    uint8_t getNoiseFloor(void);
    bool setNoiseFloor(int level);
    uint8_t increaseNoiseFloor(void);
    uint8_t descreseNoiseFloor(void);
    uint8_t setTuningCapacitor(uint8_t);
    void calibrate(uint8_t);

private:
    uint8_t _address;
    uint8_t _interruptPin;
#ifdef ARDUINO_ARCH_AVR
    const uint8_t _defaultSDA = A4;
    const uint8_t _defaultSCL = A5;
#else
    const uint8_t _defaultSDA = SDA; // D4
    const uint8_t _defaultSCL = SCL; // D5
#endif
    uint8_t _getShift(uint8_t mask);
};

#endif
