/*
    3-bit registers:
      DDRx  - direction (input/output)
      PORTx - set state (HIGH/LOW)
      PINx  - read state    

    'x' - port numbering
    'n' - port bit number


    I/O-space: (0x00-0x1f) PORTB, TCCR0a, ...
    Flash mem: (>=0x20) PORTD, SPDR, ...
        
    ANALOG:
    ADMUX - select channel & reference voltage
    ADCSRA - control of the freq converter & diveder
    ADCL - read result
    ADCH - read result


    PORTB (PB0-PB7) 
    |----------|------|------|------------
    | BIT PORT | PIN  | PIN A|  FN
    |----------|------|------|------------
    |   PB0    |  14  |  D8  | ICP1, CLKO 
    |   PB1    |  15  |  D9  | OC1A(PWM), Timer1
    |   PB2    |  16  |  D10 | SS(SPI), OC1B(PWM), Timer1
    |   PB3    |  17  |  D11 | MOSI(SPI), OC2A(PWM), Timer2
    |   PB4    |  18  |  D12 | MISO(SPI)
    |   PB5    |  19  |  D13 | SCK(SPI)
    |   PB6    |  9   |  --  | XTAL1(QuartzRes)  !NON-GPIO
    |   PB7    |  10  |  --  | XTAL2(QuartzRes)  !NON-GPIO
    |----------|------|------|------------


    PORTC (PC0-PC6) 
    |----------|------|------|------------
    | BIT PORT | PIN  | PIN A|  FN
    |----------|------|------|------------
    |   PC0    |  23  |  A0  | ADC0 (AnalogInput)
    |   PC1    |  24  |  A1  | ADC1 (AnalogInput)
    |   PC2    |  25  |  A2  | ADC2 (AnalogInput)
    |   PC3    |  26  |  A3  | ADC3 (AnalogInput)
    |   PC4    |  27  |  A4  | ADC4 (AnalogInput), SDA(I2C)
    |   PC5    |  28  |  A5  | ADC5 (AnalogInput), SCL(I2C)
    |   PC6    |  1   |  RES | Reset !NON-GPIO
    |----------|------|------|------------
    |   ADC6   |  1   |  A6  | ADC6 (AnalogInput)
    |   ADC7   |  1   |  A7  | ADC7 (AnalogInput)
    |----------|------|------|------------

    
    PORTD (PD0-PD7) 
    |----------|------|------|------------
    | BIT PORT | PIN  | PIN A|  FN
    |----------|------|------|------------
    |   PD0    |  2   |  D0  | RXD(UART[SerialCommunication])
    |   PD1    |  3   |  D1  | TXD(UART[SerialCommunication])
    |   PD2    |  4   |  D2  | INT0(internal interrupt)
    |   PD3    |  5   |  D3  | INT1, OC2B(PWM), Timer2
    |   PD4    |  6   |  D4  | XCK(USART), Timer0
    |   PD5    |  11  |  D5  | OC0B(PWM), Timer0
    |   PD6    |  12  |  D6  | OC0A(PWM), AIN0 
    |   PD7    |  13  |  D7  | AIN1 
    |----------|------|------|------------

*/
#ifndef DEFS_H
#define DEFS_H

#include <avr/io.h>
#include <util/delay.h>

#define DelayMs _delay_ms
#define DelayUs _delay_us

// GPIO
#define INPUT (0)
#define OUTPUT (1)

// STATE
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
#define PIN_D3_PWM  PIN_D3  // T2-8b
#define PIN_D11_PWM PIN_D11 // T2-8b
#define PIN_D10_PWM PIN_D10 // T1-16bs
#define PIN_D9_PWM  PIN_D9  // T1-16b
#define PIN_D6_PWM  PIN_D6  // T0-8b
#define PIN_D5_PWM  PIN_D5  // T0-8b

#endif