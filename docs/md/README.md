# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`AS3935`](#classAS3935) | 

# class `AS3935` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`AS3935`](#classAS3935_1ac8546848906ceee3d8265eae7307695b)`(uint8_t address,uint8_t interruptPin)` | Constructor. 
`public  `[`~AS3935`](#classAS3935_1a527270c68aac74d36d126a67ec684df4)`(void)` | 
`public void `[`begin`](#classAS3935_1a75542117963fb6a48f6bf257bca06c41)`(void)` | Begin using the object with default SDA, and SCL pin numbers.
`public void `[`begin`](#classAS3935_1a3ea6e01becd6faac61daf92ff6a8f7d3)`(int sda,int scl)` | Begin using the object
`public uint8_t `[`readRegister`](#classAS3935_1a584f473e60e2a5c194cbf89b86f47827)`(uint8_t reg)` | Read a byte from a register. 
`public uint8_t `[`readRegisterWithMask`](#classAS3935_1a0f9456068c3bd92bfa08db7b3c0b95ef)`(uint8_t reg,uint8_t mask)` | Read a byte from a register, return a masked and shifted value 
`public void `[`writeRegisterWithMask`](#classAS3935_1aea1d2d14948ff505b237884ff34a7ac3)`(uint8_t reg,uint8_t mask,uint8_t value)` | Write a masked value to register reg, preserving other bits 
`public void `[`writeRegister`](#classAS3935_1a48b69ea6c7517619ccdf7a0b78cb670e)`(uint8_t reg,uint8_t value)` | Write value to register reg. 
`public void `[`setDefault`](#classAS3935_1ada8b8b208c3247a580fd98f817d658f1)`(void)` | Sets all registers in default mode
`public void `[`calibrateRCO`](#classAS3935_1ab0cfd4523be09c3e92d874472c8d0650)`(void)` | Calibrates the internal RC Oscillators automatically
`public void `[`disableOscillators`](#classAS3935_1affd3cfa6277c479da8e15d0f63c2240f)`(void)` | Disable LCO/SRCO/TRCO on IRQ pin.
`public uint8_t `[`getIntrruptReason`](#classAS3935_1af8e6b140e4d495de1fde1586c9a037e3)`(void)` | Get intrrupt reason 
`public int8_t `[`getDistance`](#classAS3935_1a7757e3320432cf7aa037a56a204d5946)`(void)` | Return the estimated distance in km to the head of an approaching storm. 
`public bool `[`isIndoor`](#classAS3935_1a0ffdb4dfbe9809c0132cee79ebc1bd5d)`(void)` | Returns bool whether or not current AFE setting is indoor. 
`public bool `[`setIndoor`](#classAS3935_1a2dfca515cd05d3d8a2f21a63ecca9803)`(void)` | Set AFE setting to indoor mode 
`public bool `[`setIndoor`](#classAS3935_1a50d484a2b9cf94415a53f85a739956c7)`(bool enable)` | Set or unset AFE setting to indoor mode. 
`public bool `[`isOutdoor`](#classAS3935_1ac9a95f6e666a87fac4f20d211af2fe50)`(void)` | Returns bool whether or not current AFE setting is outdoor. 
`public bool `[`setOutdoor`](#classAS3935_1a3f069dc7019193600bf5e0c1fd8a700c)`(void)` | Set the AFE setting to outdoor mode. 
`public bool `[`setOutdoor`](#classAS3935_1aea4888bce6d95ecd15455eb5c646ecf5)`(bool enable)` | Set or unset AFE setting to outdoor mode. 
`public uint8_t `[`getMinimumLightning`](#classAS3935_1acb47e57b90db5fd7076e8f613c21d7d3)`(void)` | Get minimum number of lightning 
`public bool `[`setMinimumLightning`](#classAS3935_1a101cee8826bf70b18a50bfbbe2bd2133)`(uint8_t)` | Set minimum number of lightning to trigger an event 
`public void `[`clearStats`](#classAS3935_1a3d155965989392aaad3755a98e9f4bcf)`(void)` | Clear the statistics built up by the lightning distance estimation algorithm block.
`public uint8_t `[`getNoiseFloor`](#classAS3935_1a27a053f6681f76fe822532796b32154b)`(void)` | Get noise floor level from [AS3935](#classAS3935). 
`public bool `[`setNoiseFloor`](#classAS3935_1a423451d2316612a42e03ef51f601933f)`(int level)` | Set noise floor level from [AS3935](#classAS3935). 
`public uint8_t `[`increaseNoiseFloor`](#classAS3935_1ae25cbdb28d34ccb7392c63bacd77f4c7)`(void)` | Increase noise floor level by one. When the level raeches to the maximum value, 7, further call will not increase the level. 
`public uint8_t `[`descreseNoiseFloor`](#classAS3935_1abbed826cf7f83a4d598e20e964620d34)`(void)` | Decrease noise floor level by one. When the level raeches to the minimum value, 0, further call will not decrease the level. 
`public uint8_t `[`setTuningCapacitor`](#classAS3935_1a36a66cea1b70e87dc97bde6bc0688c49)`(uint8_t)` | Set internal capacitor values, from 0 to 120pF in steps of 8pf. Interrupts are disabled while calibrating. 
`public void `[`calibrate`](#classAS3935_1a8c1e3a43620d11f834aebdadd8b284d7)`(uint8_t)` | Compatibility 

## Members

#### `public  `[`AS3935`](#classAS3935_1ac8546848906ceee3d8265eae7307695b)`(uint8_t address,uint8_t interruptPin)` 

Constructor. 
#### Parameters
* `address` I2C address of [AS3935](#classAS3935). 

* `interruptPin` pin that is tied to IRQ pin of [AS3935](#classAS3935).

#### `public  `[`~AS3935`](#classAS3935_1a527270c68aac74d36d126a67ec684df4)`(void)` 

#### `public void `[`begin`](#classAS3935_1a75542117963fb6a48f6bf257bca06c41)`(void)` 

Begin using the object with default SDA, and SCL pin numbers.

#### `public void `[`begin`](#classAS3935_1a3ea6e01becd6faac61daf92ff6a8f7d3)`(int sda,int scl)` 

Begin using the object

* Begin wire

* Enable interrupt pin as INPUT

* Disable Oscillators on interrupt pin.

#### Parameters
* `sda` SDA pin 

* `scl` SCL pin

#### `public uint8_t `[`readRegister`](#classAS3935_1a584f473e60e2a5c194cbf89b86f47827)`(uint8_t reg)` 

Read a byte from a register. 
#### Parameters
* `reg` The register address 

#### Returns
The value in the register

#### `public uint8_t `[`readRegisterWithMask`](#classAS3935_1a0f9456068c3bd92bfa08db7b3c0b95ef)`(uint8_t reg,uint8_t mask)` 

Read a byte from a register, return a masked and shifted value 
#### Parameters
* `reg` The register address 

* `mask` The mask to use when shifting contents 

#### Returns
An uint8_t with the right most bits containing the masked and shifted contents of the requested register

#### `public void `[`writeRegisterWithMask`](#classAS3935_1aea1d2d14948ff505b237884ff34a7ac3)`(uint8_t reg,uint8_t mask,uint8_t value)` 

Write a masked value to register reg, preserving other bits 
#### Parameters
* `reg` The register address 

* `mask` The bitmask to mask 

* `value` The value to write to the register

#### `public void `[`writeRegister`](#classAS3935_1a48b69ea6c7517619ccdf7a0b78cb670e)`(uint8_t reg,uint8_t value)` 

Write value to register reg. 
#### Parameters
* `reg` the register address to write value to. 

* `value` the value to write to the register.

#### `public void `[`setDefault`](#classAS3935_1ada8b8b208c3247a580fd98f817d658f1)`(void)` 

Sets all registers in default mode

#### `public void `[`calibrateRCO`](#classAS3935_1ab0cfd4523be09c3e92d874472c8d0650)`(void)` 

Calibrates the internal RC Oscillators automatically

#### `public void `[`disableOscillators`](#classAS3935_1affd3cfa6277c479da8e15d0f63c2240f)`(void)` 

Disable LCO/SRCO/TRCO on IRQ pin.

#### `public uint8_t `[`getIntrruptReason`](#classAS3935_1af8e6b140e4d495de1fde1586c9a037e3)`(void)` 

Get intrrupt reason 
#### Returns
one of AS3935_INT_STRIKE, AS3935_INT_DISTURBER, AS3935_INT_NOISE

#### `public int8_t `[`getDistance`](#classAS3935_1a7757e3320432cf7aa037a56a204d5946)`(void)` 

Return the estimated distance in km to the head of an approaching storm. 
#### Returns
int8_t value of the estimated distance in km, AS3935_DISTANCE_OUT_OF_RANGE when out of range, or -1 when the register value is invalid. See also: 8.9.3 Statistical Distance Estimation

#### `public bool `[`isIndoor`](#classAS3935_1a0ffdb4dfbe9809c0132cee79ebc1bd5d)`(void)` 

Returns bool whether or not current AFE setting is indoor. 
#### Returns
true if the setting is indoor, false if not

#### `public bool `[`setIndoor`](#classAS3935_1a2dfca515cd05d3d8a2f21a63ecca9803)`(void)` 

Set AFE setting to indoor mode 
#### Returns
true or false whether if setting to indoor mode succeeded.

#### `public bool `[`setIndoor`](#classAS3935_1a50d484a2b9cf94415a53f85a739956c7)`(bool enable)` 

Set or unset AFE setting to indoor mode. 
#### Parameters
* `enable` True of false whether to set AFE to indoor mode. 

#### Returns
true or false whether if setting to indoor mode succeeded.

#### `public bool `[`isOutdoor`](#classAS3935_1ac9a95f6e666a87fac4f20d211af2fe50)`(void)` 

Returns bool whether or not current AFE setting is outdoor. 
#### Returns
true if the setting is outdoor, false if not

#### `public bool `[`setOutdoor`](#classAS3935_1a3f069dc7019193600bf5e0c1fd8a700c)`(void)` 

Set the AFE setting to outdoor mode. 
#### Returns
true or false whether if setting to outdoor mode succeeded.

#### `public bool `[`setOutdoor`](#classAS3935_1aea4888bce6d95ecd15455eb5c646ecf5)`(bool enable)` 

Set or unset AFE setting to outdoor mode. 
#### Parameters
* `enable` True of false whether to set AFE to outdoor mode. 

#### Returns
true or false whether if setting to outdoor mode succeeded.

#### `public uint8_t `[`getMinimumLightning`](#classAS3935_1acb47e57b90db5fd7076e8f613c21d7d3)`(void)` 

Get minimum number of lightning 
#### Returns
uint8_t number of minimum number of lightning, one of 1, 5, 9, or 16.

#### `public bool `[`setMinimumLightning`](#classAS3935_1a101cee8826bf70b18a50bfbbe2bd2133)`(uint8_t)` 

Set minimum number of lightning to trigger an event 
#### Parameters
* `n` Minimum number of lightnings, one of 1, 5, 9, or 16. 

#### Returns
bool whether or not setting the value succeeded.

#### `public void `[`clearStats`](#classAS3935_1a3d155965989392aaad3755a98e9f4bcf)`(void)` 

Clear the statistics built up by the lightning distance estimation algorithm block.

#### `public uint8_t `[`getNoiseFloor`](#classAS3935_1a27a053f6681f76fe822532796b32154b)`(void)` 

Get noise floor level from [AS3935](#classAS3935). 
#### Returns
The current noise floor level from the register

#### `public bool `[`setNoiseFloor`](#classAS3935_1a423451d2316612a42e03ef51f601933f)`(int level)` 

Set noise floor level from [AS3935](#classAS3935). 
#### Parameters
* `level` The noise floor level, from 0 to 7, to set. 

#### Returns
true or false whether if setting the level is succeeded

#### `public uint8_t `[`increaseNoiseFloor`](#classAS3935_1ae25cbdb28d34ccb7392c63bacd77f4c7)`(void)` 

Increase noise floor level by one. When the level raeches to the maximum value, 7, further call will not increase the level. 
#### Returns
The noise floor level after the change.

#### `public uint8_t `[`descreseNoiseFloor`](#classAS3935_1abbed826cf7f83a4d598e20e964620d34)`(void)` 

Decrease noise floor level by one. When the level raeches to the minimum value, 0, further call will not decrease the level. 
#### Returns
The noise floor level after the change.

#### `public uint8_t `[`setTuningCapacitor`](#classAS3935_1a36a66cea1b70e87dc97bde6bc0688c49)`(uint8_t)` 

Set internal capacitor values, from 0 to 120pF in steps of 8pf. Interrupts are disabled while calibrating. 
#### Parameters
* `cap` Integer, from 0 to 15. 

#### Returns
the value of the internal capacitor

#### `public void `[`calibrate`](#classAS3935_1a8c1e3a43620d11f834aebdadd8b284d7)`(uint8_t)` 

Compatibility 
#### Parameters
* `cap` Integer, from 0 to 15. 

**See also**: [AS3935::setTuningCapacitor(uint8_t)](#classAS3935_1a36a66cea1b70e87dc97bde6bc0688c49)

Generated by [Moxygen](https://sourcey.com/moxygen)