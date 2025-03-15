#ifndef GPIO_H
#define GPIO_H

#define GPIO_IS_VALID(pin) ((pin) >= PIN_D0 && (pin) <= PIN_D13) || ((pin) >= PIN_A0 && (pin) <= PIN_A5)
#define GPIO_IS_ANALOG(pin) ((pin) >= PIN_A0 && (pin) <= PIN_A5)
#define GPIO_IS_DIGITAL(pin) ((pin) >= PIN_D0 && (pin) <= PIN_D13)
#define GPIO_IS_PWM(pin) (((pin) >= (PIN_D9) && (pin) <= (PIN_D11))  || (pin) == (PIN_D5) || (pin) == (PIN_D6) || (pin) == (PIN_D3))

#define GPIO_GET_DDR(pin) \
    ((pin) >= PIN_D8 && (pin) <= PIN_D13) ? (&DDRB) : \
    ((pin) >= PIN_D0 && (pin) <= PIN_D7) ? (&DDRD) : \
    (&DDRC)


#define GPIO_PIN_TO_BIT(pin) \
  ( ((pin) >= PIN_D8 && (pin) <= PIN_D13) ? (pin - PIN_D8) : \
    ((pin) >= PIN_D0 && (pin) <= PIN_D7)  ? (pin - PIN_D0) : \
    ((pin) - PIN_A0) )


// Getting PORTx by DDRx 
#define GPIO_GET_PORT(ddr) \
  ( (ddr) == (&DDRB) ? (&PORTB) : \
    (ddr) == (&DDRD) ? (&PORTD) : \
    (ddr) == (&DDRC) ? (&PORTC) : \
    (&PORTB) )


#define GPIO_SET_PIN_OUTPUT(pin) SetBit(*(volatile uint8_t*)(GPIO_GET_DDR(pin)), GPIO_PIN_TO_BIT(pin))
#define GPIO_SET_PIN_INPUT(pin) ClearBit(*(volatile uint8_t*)(GPIO_GET_DDR(pin)), GPIO_PIN_TO_BIT(pin))

#define GPIO_SET_PIN_HIGH(pin) SetBit(*(volatile uint8_t*)(GPIO_GET_PORT(GPIO_GET_DDR(pin))), GPIO_PIN_TO_BIT(pin))
#define GPIO_SET_PIN_LOW(pin) ClearBit(*(volatile uint8_t*)(GPIO_GET_PORT(GPIO_GET_DDR(pin))), GPIO_PIN_TO_BIT(pin))

// DIGITAL
#include "gpioDigital.h"

// ANALOG
#include "gpioAnalog.h"

// PWM
#include "gpioPWM.h"


#define SetPin(pin, mode) \
  ((mode) ? (GPIO_SET_PIN_OUTPUT(pin)) : (GPIO_SET_PIN_INPUT(pin)))

#define TogglePin(pin) \
    ToggleBit(*(volatile uint8_t*)(GPIO_GET_PORT(GPIO_GET_DDR(pin))), GPIO_PIN_TO_BIT(pin))


#endif /*GPIO_H*/