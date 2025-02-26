#ifndef GPIO_PWM_H
#define GPIO_PWM_H

/*
    PWM configuration:
    Timer0 (8-bit)
    Timer1 (16-bit)
    Timer2 (8-bit)

*/

#define _PWM_UP (1023)

#define GPIO_IS_PWM(pin) (((pin) >= (PIN_D9) && (pin) <= (PIN_D11))  || (pin) == (PIN_D5) || (pin) == (PIN_D3))


// Timer1
#define GPIO_PWM_INIT_TIMER_1() {\
    GPIO_SET(TCCR1A,             \
        GPIO_BIT(COM1A1) |       \
        GPIO_BIT(COM1B1) |       \
        GPIO_BIT(WGM11)  |       \
        GPIO_BIT(WGM10)          \
    );                           \
    GPIO_SET(TCCR1B,             \
        GPIO_BIT(WGM12) |        \
        GPIO_BIT(CS10)           \
    );                           \
    GPIO_SET(ICR1, _PWM_UP);     \
}

#define GPIO_PWM_SET_TIMER_1A(duty) GPIO_SET(OCR1A, (uint16_t)(duty))
#define GPIO_PWM_SET_TIMER_1B(duty) GPIO_SET(OCR1B, (uint16_t)(duty))

// Timer0
// Timer2
#define GPIO_PWM_INIT_TIMER_0() {\
    GPIO_SET_BIT(TCCR0A, COM0A1);\
    GPIO_SET_BIT(TCCR0A, WGM01); \
    GPIO_SET_BIT(TCCR0A, WGM00); \
    GPIO_SET_BIT(TCCR0B, CS01);  \
}

#define GPIO_PWM_SET_TIMER_0A(duty)  GPIO_SET(OCR0A, (uint8_t)(duty))
#define GPIO_PWM_SET_TIMER_0B(duty)  GPIO_SET(OCR0B, (uint8_t)(duty))

#endif