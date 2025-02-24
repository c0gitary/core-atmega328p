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

#include <avr/io.h>

#define INPUT 0
#define OUTPUT 1

#define LOW 0
#define HIGH 1


// ANALOG 
// PORTC (PC0-PC6)
#define PIN_A0 PC0
#define PIN_A1 PC1
#define PIN_A2 PC2
#define PIN_A3 PC3
#define PIN_A4 PC4
#define PIN_A5 PC5
#define NUM_ANALOG_PINS 6


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

// DIGITAL
// PORTD (PD0-PD7)
#define PIN_D0 PD0
#define PIN_D1 PD1
#define PIN_D2 PD2
#define PIN_D3 PD3
#define PIN_D4 PD4
#define PIN_D5 PD5
#define PIN_D6 PD6
#define PIN_D7 PD7

#define NUM_DIGITAL_PINS 14

// Data (UART)
#define PIN_RX D0
#define PIN_TX D1

// Interrupt
#define PIN_INT0 D2
#define PIN_INT1 D3

// SPI
#define PIN_SPI_MOSI PIN_D11
#define PIN_SPI_MISO PIN_D12
#define PIN_SPI_SCK  PIN_D13

// I2C
#define PIN_SDA PIN_A4
#define PIN_SCL PIN_A5

// SYS
#define RESET PC6

// PWM
#define PIN_D11_PWM PIN_D11
#define PIN_D10_PWM PIN_D10
#define PIN_D9_PWM  PIN_D9
#define PIN_D5_PWM  PIN_D5
#define PIN_D3_PWM  PIN_D3

#endif

