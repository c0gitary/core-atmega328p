#ifndef GPIO_ANALOG_H
#define GPIO_ANALOG_H

#define GPIO_ADC_INIT() { \
    GPIO_SET_BIT(ADMUX, REFS0);\
    GPIO_SET_BIT(ADCSRA, ADEN | GPIO_BIT(ADPS2) |  GPIO_BIT(ADPS1) | GPIO_BIT(ADPS0));\
    GPIO_SET(DIDR0, 0x3f);\
}
  
extern uint16_t AnalogRead(uint16_t pin);

#endif