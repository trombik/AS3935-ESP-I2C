#include <Wire.h>
#include <AS3935.h>

/*
 * a line-by-line port of https://github.com/pcfens/particle-as3935/
 * an exercise for me to write a library.
 */

AS3935::AS3935(uint8_t i2c_address, uint8_t int_pin)
{
  _i2c_address = i2c_address;
  _int_pin = int_pin;
}

AS3935::AS3935::~AS3935()
{
}

/**
 * Begin using the object with default SDA, and SCL pin numbers.
 */
void AS3935::begin()
{
    begin((int) _default_sda, (int) _default_scl);
}

/**
 * Begin using the object
 * - Begin wire
 * - Enable interrupt pin as INPUT
 * - Disable Oscillators on interrupt pin.
 */
void AS3935::begin(int sda, int scl)
{
    Wire.begin(sda, scl);
    pinMode(_int_pin, INPUT);
    disableOscillators();
}

/**
 * Find the shift required to make the mask use the LSB.
 * @param mask The mask to find the shift of
 * @return The number of bit positions to shift the mask
 */
uint8_t AS3935::_getShift(uint8_t mask)
{
    uint8_t i = 0;
    for (i = 0; ~mask & 1; i++)
        mask >>= 1;
    return i;
}

/**
 * Read a byte from a register.
 * @param reg The register address
 * @return The value in the register
 */
uint8_t AS3935::readRegister(uint8_t reg)
{
    uint8_t v;
    Wire.beginTransmission(_i2c_address);
    Wire.write(reg);
    Wire.endTransmission(false);
    Wire.requestFrom((int)_i2c_address, 1);
    v = Wire.read();
    return v;
}

/**
 * Read a byte from a register, return a masked and shifted value
 * @param reg The register address
 * @param mask The mask to use when shifting contents
 * @return An uint8_t with the right most bits containing the masked and
 * shifted contents of the requested register
 */
uint8_t AS3935::readRegisterWithMask(uint8_t reg, uint8_t mask)
{
    uint8_t v;
    v = readRegister(reg) & mask;
    return (v >> _getShift(mask));
}

/**
 * Write a masked value to register reg, preserving other bits
 * @param reg The register address
 * @param mask The bitmask to mask
 * @param value The value to write to the register
 */
void AS3935::writeRegisterWithMask(uint8_t reg, uint8_t mask, uint8_t value)
{
    uint8_t registerValue;
    registerValue = readRegister(reg);
    registerValue &= ~(mask);
    registerValue |= ((value << (_getShift(mask))) & mask);
    Wire.beginTransmission(_i2c_address);
    Wire.write(reg);
    Wire.write(registerValue);
    Wire.endTransmission();
}

/**
 * Write value to register reg.
 * @param reg the register address to write value to.
 * @param value the value to write to the register.
 */
void AS3935::writeRegister(uint8_t reg, uint8_t value)
{
    writeRegisterWithMask(reg, 0xff, value);
}

/**
 * Sets all registers in default mode
 */
void AS3935::setDefault(void)
{
    writeRegister(0x3c, 0x96);
}

/**
 * Calibrates the internal RC Oscillators automatically
 */
void AS3935::calibrateRCO(void)
{
    writeRegister(0x3D, 0x96);
}

/**
 * Disable LCO/SRCO/TRCO on IRQ pin.
 */
void AS3935::disableOscillators(void)
{
    writeRegisterWithMask(0x08, 0xE0, 0x00);
}
