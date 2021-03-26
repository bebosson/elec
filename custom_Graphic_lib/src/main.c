#include "main.h"
#include "screen.h"

unsigned int read_lux(){
    unsigned int nb;
    ADMUX &= ~(1 << MUX0) & ~(1 << MUX1) & ~(1 << MUX2) & ~(1 << MUX3);//set pin A0
    ADCSRA |= (1 << ADSC); // start calculations
	while(ADCSRA & (1 << ADSC)); // wait calculations is done
	nb = (unsigned int)ADCL;
    if (ADCH & 1) {
		nb |= (1 << 8);
	}
	if (ADCH & 2) {
		nb |= (1 << 9);
	}
    return (nb);
}

unsigned int read_moisture(){
    unsigned int nb;
    ADMUX |= (1 << MUX0);
    ADMUX &= ~(1 << MUX1) & ~(1 << MUX2) & ~(1 << MUX3);
//    ADMUX &= ~(1 << MUX0);//set pin A1
    ADCSRA |= (1 << ADSC); // start calculations
	while(ADCSRA & (1 << ADSC)); // wait calculations is done
	nb = (unsigned int)ADCL;
    if (ADCH & 1) {
		nb |= (1 << 8);
	}
	if (ADCH & 2) {
		nb |= (1 << 9);
	}
    return (nb);
}

unsigned int read_temperature(){
    unsigned int nb;
    ADMUX |= (1 << MUX2) | (1 << MUX0);
    ADMUX &= ~(1 << MUX1)  & ~(1 << MUX3);
//    ADMUX &= ~(1 << MUX0);//set pin A1
    ADCSRA |= (1 << ADSC); // start calculations
	while(ADCSRA & (1 << ADSC)); // wait calculations is done
	nb = (unsigned int)ADCL;
    if (ADCH & 1) {
		nb |= (1 << 8);
	}
	if (ADCH & 2) {
		nb |= (1 << 9);
	}
    return (nb);
}

extern char font[96][6];
int       main() {
    unsigned int lux;
    unsigned int mois;
    ADCSRA |= (1 << ADEN); // enable ADC
    ADMUX |= (1 << REFS0); // VCC -> voltage reference
   
    display_init();

    
    
    while(1) {
    lux = read_lux();
    put_str("LUMINOSITE:    ", 0, 0);
    putnbr(lux, 14, 0);
    mois = read_moisture();
    put_str("HUMIDITE:    ", 0, 2);
    putnbr(mois, 12, 2);
    print_screen();
    
        // for (uint8_t i = 0; i < 113; i++)
        //     SPI_MasterTransmit(i);
        ft_delay(F_CPU / 1000);
        // PORTD &= ~(1 << PD6); // set command mode
        // SPI_MasterTransmit(0x00);
        // SPI_MasterTransmit(0x10);
        // PORTD |= (1 << PD6); // set data mode
    }

    return 0;
}
