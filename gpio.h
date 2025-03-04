#ifndef GPIO_H
#define GPIO_H

#include "defs.h"

#define GPIO_BIT _BV

#define GPIO_SET(port, bit)              ((port) = (bit))
#define GPIO_SET_BIT(port, bit)          ((port) |= (GPIO_BIT(bit)))
#define GPIO_CLEAR_BIT(port, bit)        ((port) &= ~(GPIO_BIT(bit)))
#define GPIO_TOGGLE_BIT(statePort, bit)  ((statePort) ^= (GPIO_BIT(bit)))
#define GPIO_READ_BIT(port, bit)         ((port) &  (GPIO_BIT(bit)))

#define GPIO_BIT_IS_SET bit_is_set
#define GPIO_BIT_IS_CLEAR bit_is_clear
#define GPIO_LOOP_UNTIL_BIT_IS_SET loop_until_bit_is_set
#define GPIO_LOOP_UNTIL_BIT_IS_CLEAR loop_until_bit_is_clear

#define GPIO_IS_VALID(pin) ((pin) >= PIN_D0 && (pin) <= PIN_D13) || ((pin) >= PIN_A0 && (pin) <= PIN_A5)

#define GPIO_IS_ANALOG(pin) ((pin) >= PIN_A0 && (pin) <= PIN_A5)

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


#define _SetOutput(pin) GPIO_SET_BIT(*(volatile uint8_t*)(GPIO_GET_DDR(pin)), GPIO_PIN_TO_BIT(pin))
#define _SetInput(pin) GPIO_CLEAR_BIT(*(volatile uint8_t*)(GPIO_GET_DDR(pin)), GPIO_PIN_TO_BIT(pin))

#define _SetPinHigh(pin) GPIO_SET_BIT(*(volatile uint8_t*)(GPIO_GET_PORT(GPIO_GET_DDR(pin))), GPIO_PIN_TO_BIT(pin))
#define _SetPinLow(pin) GPIO_CLEAR_BIT(*(volatile uint8_t*)(GPIO_GET_PORT(GPIO_GET_DDR(pin))), GPIO_PIN_TO_BIT(pin))

// DIGITAL
#include "gpioDigital.h"

// ANALOG
#include "gpioAnalog.h"

// PWM
#include "gpioPwm.h"


// MASTER 
#define SetPin(pin, mode) ((mode) ? (_SetOutput(pin)) : (GPIO_IS_ANALOG(pin) ? (GPIO_ANALOG_PIN_INPUT(pin)) : _SetInput(pin)))
#define TogglePin(pin) GPIO_TOGGLE_BIT(*(volatile uint8_t*)(GPIO_GET_PORT(GPIO_GET_DDR(pin))), GPIO_PIN_TO_BIT(pin))




#endif /*GPIO_H*/