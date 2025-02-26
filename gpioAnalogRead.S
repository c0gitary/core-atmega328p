#include <avr/io.h>

.global AnalogRead

AnalogRead:
    andi r24, 0x0f
    lds r25, ADMUX  
    andi r25, 0x0f ; Clear bits channel (MUX0-MUX3)
    or r25, r24
    sts ADMUX, r25

    lds r25, ADCSRA
    ori r25, (1 << ADSC)
    sts ADCSRA, r25

    wait:
    lds r25, ADCSRA
    sbrc r25, ADSC
    rjmp wait

    lds r24, ADCL
    lds r25, ADCH
    ret