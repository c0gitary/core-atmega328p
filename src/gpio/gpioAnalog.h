#ifndef GPIO_ANALOG_H
#define GPIO_ANALOG_H

#define GPIO_ADC_PRESCALER_2    (Bit(ADPS0))
#define GPIO_ADC_PRESCALER_4    (Bit(ADPS1))
#define GPIO_ADC_PRESCALER_8    (Bit(ADPS1) | Bit(ADPS0))
#define GPIO_ADC_PRESCALER_16   (Bit(ADPS2))
#define GPIO_ADC_PRESCALER_32   (GPIO_ADC_PRESCALER_16 | Bit(ADPS0))
#define GPIO_ADC_PRESCALER_64   (GPIO_ADC_PRESCALER_16 | GPIO_ADC_PRESCALER_4)
#define GPIO_ADC_PRESCALER_128  (GPIO_ADC_PRESCALER_64 | GPIO_ADC_PRESCALER_2)

#define GPIO_ADC_SET_PRESCALER(PRESCALER) (ADCSRA |= PRESCALER)

#define GPIO_ADC_START() SetBit(ADCSRA, ADEN)

#define GPIO_ADC_STOP()  ClearBit(ADCSRA, ADEN)

#define GPIO_ADC_INIT(pin) { \
    GPIO_SET_PIN_INPUT(pin);\
    Set(ADMUX, (ADMUX & 0xF0) | (pin & 0x0F));\
    SetBit(ADMUX, REFS0);\
    GPIO_ADC_START();\
    GPIO_ADC_SET_PRESCALER(GPIO_ADC_PRESCALER_128);\
}


__attribute__((always_inline, __gnu_inline__)) 
static inline uint16_t 
AnalogRead(const uint8_t adcPin){
    SetBit(ADCSRA, ADSC);
    while(ADCSRA & Bit(ADSC));
    return ADC;
}

#endif