#ifndef GPIO_PWM_H
#define GPIO_PWM_H

/*
    PWM configuration:
    Timer0 (8-bit)  [D6,  D5]
    Timer1 (16-bit) [D9,  D10]
    Timer2 (8-bit)  [D11, D3]

    PRESCALER
    |CS02 | CS01 | CS00 | PRSCL
    |  0  |  0   |   0  |   - (stop)
    |  0  |  0   |   1  |   1
    |  0  |  1   |   0  |   8   
    |  0  |  1   |   1  |   32
    |  1  |  0   |   0  |   64
    |  1  |  0   |   1  |   128
    |  1  |  1   |   0  |   256
    |  1  |  1   |   1  |   1024

*/

#define PWM_IS_TIMER_0(pin) ((pin) == (PIN_D6) || (pin) == (PIN_D5))
#define PWM_IS_TIMER_1(pin) ((pin) == (PIN_D10) || (pin) == (PIN_D9))
#define PWM_IS_TIMER_2(pin) ((pin) == (PIN_D11) || (pin) == (PIN_D3))


#define PWM_INIT_TIMER(pin) {\
    if(PWM_IS_TIMER_0(pin)) {\
        GPIO_SET_PIN_OUTPUT(pin);\
        SetBit(TCCR0A, COM0A1);\
        SetBit(TCCR0A, WGM01);\
        SetBit(TCCR0A, WGM00);\
        SetBit(TCCR0B, CS01);\
    }\
}

#define PWM_SET_TIMER_0(pin, val) {\
    if((pin) == (PIN_D6)) Set(OCR0A, val);\
    else if((pin) == (PIN_D5)) Set(OCR0B, val);\
}


///

#define GPIO_PWM_INIT(pin) {\
    if(PWM_IS_TIMER_0(pin)) PWM_INIT_TIMER(pin);\
}


#define PWM_WRITE(pin, val) {\
    if(PWM_IS_TIMER_0(pin)) PWM_SET_TIMER_0(pin, constrain(val, 0, 0xff));\
}


#endif /* GPIO_PWM_H*/