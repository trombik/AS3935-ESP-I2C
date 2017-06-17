#include <AS3935.h>
#include <Wire.h>

AS3935 as3935(0x00, D3);

void
setup()
{
	delay(3000);
	Serial.begin(115200);
	Serial.println();
	Serial.println(__FILE__);
	as3935.begin();
}

void
loop()
{
	uint8_t i;
	for (i = 0; i <= 0x08; i++) {
		Serial.print("reg[");
		Serial.print(i);
		Serial.print("]: ");
		Serial.println(as3935.readRegister(i), HEX);
	}
	delay(1000);
}
