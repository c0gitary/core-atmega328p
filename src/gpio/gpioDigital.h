#ifndef GPIO_DIGITAL_H
#define GPIO_DIGITAL_H

#define DigitalWrite(pin, state) ((state) ? GPIO_SET_PIN_HIGH(pin) : GPIO_SET_PIN_LOW(pin))
#define DigitalRead(pin) ReadBit(*(volatile uint8_t*)(GPIO_GET_PORT(GPIO_GET_DDR(pin))), GPIO_PIN_TO_BIT(pin))


#endif