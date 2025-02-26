#ifndef GPIO_DIGITAL_H
#define GPIO_DIGITAL_H

#define DigitalWrite(pin, state) ((state) ? _SetPinHigh(pin) : _SetPinLow(pin))
#define DigitalRead(pin) GPIO_READ_BIT(*(volatile uint8_t*)(GPIO_GET_PORT(GPIO_GET_DDR(pin))), GPIO_PIN_TO_BIT(pin))


#endif