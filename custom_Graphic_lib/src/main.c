#include "main.h"
#include "screen.h"

uint16_t  getTemperature() {

    uint8_t tx_address = DEFAULT_I2C_ADDRESS;
    uint8_t rx_data[TWI_BUFFER_LENGTH];

    uint8_t i = 0;
    while (i < TWI_BUFFER_LENGTH) {
        rx_data[i++] = 0;
    }

    twi_writeTo(tx_address, 0x00, 1, true, true);

    uint8_t read = twi_readFrom(tx_address, &(rx_data[0]), 2, true);

    twi_writeTo(tx_address, 0, 0, true, true);
    

    return *(int16_t *)(rx_data);
}

void    print_temp(uint16_t val) {
    uint8_t *byte = &val;
    uint8_t temperature = (*byte & 0b01111111);
    uint8_t is_negative = (*byte >> 7) ? 1 : 0;
    byte++;
    uint8_t is_point_five = (*byte >> 7) ? 1 : 0;
    put_str("TEMPERATURE:        ", 0, 4);
    if(is_negative) {
        put_str("-",13,4);
    }
    putnbr(temperature,14,4);
    if(is_point_five) {
        put_str(".5", (temperature < 10) ? 15 : 16,4);
    } else {
        put_str(".0", (temperature < 10) ? 15 : 16,4);
    }
    put_str("oC", (temperature < 10) ? 17 : 18, 4);
}

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
    SREG |= 1 << SREG_I; //allows interrupt
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
    print_temp(getTemperature());
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
