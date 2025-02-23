/*
    3-bit registers:
      DDRx  - direction (input/output)
      PORTx - set state (HIGH/LOW)
      PINx  - read state    

    'x' - port numbering
    'n' - port bit number

    PORTB (PB0-PB7) 
    |----------|------|------------
    | BIT PORT | PIN  |  FN
    |----------|------|------------
    |   PB0    |  14  | ICP1, CLKO 
    |   PB1    |  15  | OC1A(PWM), TIMER1
    |   PB2    |  16  | SS(SPI), OC1B(PWM)
    |   PB3    |  17  | MOSI(SPI), OC2A(PWM)
    |   PB4    |  18  | MISO(SPI)
    |   PB5    |  19  | SCK(SPI)
    |   PB6    |  9   | XTAL1(QuartzRes)  !NON-GPIO
    |   PB7    |  10  | XTAL2(QuartzRes)  !NON-GPIO
    |----------|------|------------


    PORTC (PC0-PC6) 
    |----------|------|------------
    | BIT PORT | PIN  |  FN
    |----------|------|------------
    |   PC0    |  23  | ADC0 (AnalogInput)
    |   PC1    |  24  | ADC1 (AnalogInput)
    |   PC2    |  25  | ADC2 (AnalogInput)
    |   PC3    |  26  | ADC3 (AnalogInput)
    |   PC4    |  27  | ADC4 (AnalogInput), SDA(I2C)
    |   PC5    |  28  | ADC5 (AnalogInput), SCL(I2C)
    |   PC6    |  1   | Reset !NON-GPIO
    |----------|------|------------

    
    PORTD (PD0-PD7) 
    |----------|------|------------
    | BIT PORT | PIN  |  FN
    |----------|------|------------
    |   PD0    |  2   | RXD(UART[SerialCommunication])
    |   PD1    |  3   | TXD(UART[SerialCommunication])
    |   PD2    |  4   | INT0(internal interrupt)
    |   PD3    |  5   | INT1, OC2B(PWM)
    |   PD4    |  6   | XCK(USART), T0
    |   PD5    |  11  | OC0B(PWM), T1
    |   PD6    |  12  | OC0A(PWM), AIN0 
    |   PD7    |  13  | AIN1 
    |----------|------|------------

*/
#ifndef DEFS_H
#define DEFS_H

#define __AVR_ATmega328P__
#define __AVR_ATmega328__

#include <avr/iom328p.h>

#define F_CPU 16000000UL
#define BAUD 9600
#define BAUD_PRESCALE (((F_CPU / (BAUD * 16UL)) - 1) / 2)
#define USART_BAUD_PRESCALE BAUD_PRESCALE
#define USART_RX_BUFFER_SIZE 128


//
// ANALOG 
// PORTC (PC0-PC6)
#define PIN_A0 PC0
#define PIN_A1 PC1
#define PIN_A2 PC2
#define PIN_A3 PC3
#define PIN_A4 PC4
#define PIN_A5 PC5
#define PIN_SDA A4
#define PIN_SCL A5

//
// DIGITAL
// PORTB (PB0-PB7)
#define PIN_D8  PB0
#define PIN_D9  PB1
#define PIN_D10 PB2 
#define PIN_D11 PB3 // + MOSI (SPI)
#define PIN_D12 PB4 // + MISO (SPI)
#define PIN_D13 PB5 // + SCK  (SPI)
#define PIN_XTAL1 PB6 // QuartzRes
#define PIN_XTAL2 PB7 // QuartzRes

// PORTD (PD0-PD7)
#define PIN_D0 PD0
#define PIN_D1 PD1
#define PIN_D2 PD2
#define PIN_D3 PD3
#define PIN_D4 PD4
#define PIN_D5 PD5
#define PIN_D6 PD6
#define PIN_D7 PD7


#define PIN_RX D0
#define PIN_TX D1
#define PIN_INT0 D2 // interrupt
#define PIN_INT1 D3 // interrupt
#define PIN_PWM_TIMER_0 // Timer0
#define PIN_PWM_TIMER_1 // Timer0



#define RESET PC6



#endif

