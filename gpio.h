#ifndef GPIO_H
#define GPIO_H

#include "defs.h"

#define GPIO_BIT(_b) (1 << (_b))
#define GPIO_BITUL(_b) (1UL << (_b))

#define GPIO_SET_BIT(port, bit)          ((port) |= GPIO_BIT(bit))
#define GPIO_CLEAR_BIT(port, bit)        ((port) &= ~(GPIO_BIT(bit)))
#define GPIO_TOGGLE_BIT(statePort, bit)  ((statePort) ^= GPIO_BIT(bit))
#define GPIO_READ_BIT(port, bit)         ((port) &  GPIO_BIT(bit))

#define GPIO_IS_VALID(pin) ((pin) >= PIN_D0 && (pin) <= PIN_D13) || ((pin) >= PIN_A0 && (pin) <= PIN_A5)

#define GPIO_GET_DDR_PORT(pin) \
    ((pin) >= PIN_D8 && (pin) <= PIN_D13) ? (&DDRB) : \
    ((pin) >= PIN_D0 && (pin) <= PIN_D7) ? (&DDRD) : \
    (&DDRC)


#define GPIO_PIN_TO_BIT(pin) \ 
  ( ((pin) >= PIN_D8 && (pin) <= PIN_D13) ? (pin - PIN_D8) : \
    ((pin) >= PIN_D0 && (pin) <= PIN_D7)  ? (pin - PIN_D0) : \
    ((pin) - PIN_A0) )


#define GPIO_GET_STATE_PORT(_DDRport) ((_DDRport) == &DDRB ? (&PORTB) : (_DDRport) == (&DDRD) ? (&PORTD) : (&PORTC))

#define _SetOutput(pin) GPIO_SET_BIT(*(volatile uint8_t*)(GPIO_GET_DDR_PORT(pin)), GPIO_PIN_TO_BIT(pin))
#define _SetInput(pin) GPIO_CLEAR_BIT(*(volatile uint8_t*)(GPIO_GET_DDR_PORT(pin)), GPIO_PIN_TO_BIT(pin))

#define _SetPinHigh(pin) GPIO_SET_BIT(*(volatile uint8_t*)(GPIO_GET_STATE_PORT(GPIO_GET_DDR_PORT(pin))), GPIO_PIN_TO_BIT(pin))
#define _SetPinLow(pin) GPIO_CLEAR_BIT(*(volatile uint8_t*)(GPIO_GET_STATE_PORT(GPIO_GET_DDR_PORT(pin))), GPIO_PIN_TO_BIT(pin))


#define DigitalWritePin(pin, state) ((state) ? _SetPinHigh(pin) : _SetPinLow(pin))

#define PinMode(pin, mode) ((mode) ? (_SetOutput(pin)) : (_SetInput(pin)))

#define TogglePin(pin) GPIO_TOGGLE_BIT(*(volatile uint8_t*)(GPIO_GET_STATE_PORT(GPIO_GET_DDR_PORT(pin))), GPIO_PIN_TO_BIT(pin))



#endif /*PORT_MANIPULATION_H*/