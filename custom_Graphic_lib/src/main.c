#include "main.h"
#include <stdio.h>
#include <string.h>

extern uint8_t font[96][6];
uint8_t    chosen_specie; //flag of chosen species
uint8_t    transition;
volatile uint8_t    choosing;


uint8_t   clean_transition()
{
    for (uint8_t i = 0; i < 8; i++)
        put_str("                    ", 0, i);
    return (1);
}

void    transition_menu(uint8_t *x, uint8_t *y)
{
    if (*x == 8)
        *x = 19;
    else if (*x == 19)
        *x = 8;
}



void   navigation_button(uint8_t *x, uint8_t *y)
{

    if (PIND & (1 << PD4)) //boutton du bas
    {
        put_str(" ",*x, *y);
        (*y)++;
        if (*y > 7)
        {
            transition_menu(x, y);
            *y = 3;
        }
//        PIND ^= ~(1 << PD4); rebond ?
    }
    if (PIND & (1 << PD5)) // boutton du bas
    {
        put_str(" ",*x, *y);
        (*y)--;
        if (*y < 3)
        {
            transition_menu(x, y);
            *y = 7;
        }
//        PIND ^= ~(1 << PD5); rebond ?
    }
}

void    render_title()
{
    put_str("CHOISISSEZ VOTRE", 2, 0);
    put_str("ESPECE", 7, 1);
}

void    render_champ()
{
    uint8_t spec[8];
    render_title();
    eeprom_read_page(0, 8, spec);
    put_str(spec,0,3);
    eeprom_read_page(18, 8, spec);
    put_str(spec,0,4);
    // eeprom_read_page(18, 18, specie);
    // put_str(specie,0,4);
    // eeprom_read_page(36, 18, specie);
    // put_str(specie,0,5);
    // put_str("CHAMP 4   ",0,6);
    // put_str("CHAMP 5   ",0,7);
/*  put_str("CHAMP 6   ",10,3);
    put_str("CHAMP 7   ",10,4);
    put_str("CHAMP 8   ",10,5);
    put_str("CHAMP 9   ",10,6);
    put_str("CHAMP 10   ",10,7); */

}

void    display_menu() //choix espece
{
    static uint8_t x = 8;
    static uint8_t y = 3;
    navigation_button(&x, &y);
    render_champ();
    put_str("<",x, y);
    // if (PIND & (1 << PORT3))
    // {
        // ft_delay(F_CPU / 1000);
        chosen_specie = (y - 2) + (x == 18 ? 5 : 0); // CHOOSE_SPECIES
        // return;
    // }
    print_screen();
    return (0);
}



uint16_t  getTemperature() {

    uint8_t tx_address = DEFAULT_I2C_ADDRESS;
    uint8_t rx_data[TWI_BUFFER_LENGTH];

    uint8_t i = 0;
    while (i < TWI_BUFFER_LENGTH) {
        rx_data[i++] = 0;
    }
    twi_writeTo(tx_address, 0x00, 1, true, true);
    twi_readFrom(tx_address, &(rx_data[0]), 2, true);
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
        put_str("-",12,4);
    }
    putnbr(temperature,13,4);
    if(is_point_five) {
        put_str(".5", (temperature < 10) ? 14 : 15,4);
    } else {
        put_str(".0", (temperature < 10) ? 14 : 15,4);
    }
    put_str("oC", (temperature < 10) ? 16 : 17, 4);
    //test value temp fº specie arrow
}

uint16_t read_lux(){
    uint16_t lux = 0;
    ADMUX &= ~(1 << MUX3);//set pin A3
    ADMUX &= ~(1 << MUX2);
    ADMUX |= (1 << MUX1);
    ADMUX |= (1 << MUX0);
    ADCSRA |= (1 << ADSC); // start calculations
        while((ADCSRA & (1 << ADSC))); // wait calculations is done
        lux = ADCL | (uint16_t)(ADCH & 0b11) << 8;
    return (lux);
}

uint16_t read_moisture(){
    uint16_t mois = 0;
    ADMUX |= (1 << MUX1); // set ADC2
    ADMUX &= ~(1 << MUX0);
    ADMUX &= ~(1 << MUX2);
    ADMUX &= ~(1 << MUX3);
    ADCSRA |= (1 << ADSC); // start calculations
    while((ADCSRA & (1 << ADSC))); // wait calculations is done
    mois = ADCL | (uint16_t)(ADCH & 0b11) << 8;
    // putnbr(adch, 0, 4);
    // print_screen();
    // return (mois);
    // return ((100 - ((mois * 100 / 1023) / 100)));
    //return (mois);
    return ((1023 - mois) / 5);
}

ISR(INT1_vect)
{
    clean_transition();
    if (choosing) {
        choosing = 0;
    } else
        choosing = 1;
    ft_delay(F_CPU / 5000);
}

void    display_info()
{
    uint16_t    lux;
    uint16_t    mois;
    uint8_t     memory_species = 18 * (chosen_specie - 1);
    uint8_t     spec[8];

    lux = read_lux();
    put_str("LUMINOSITE:         ", 0, 0);
    putnbr(lux, 13, 0);
    mois = read_moisture();
    put_str("HUMIDITE:       % ", 0, 2);
    putnbr(mois, 13, 2);
    print_temp(getTemperature());
    put_str("ESPECE:   ", 0, 6);
    eeprom_read_page(memory_species, 8, spec); // recuperer dans la memoire l'espece choisi
    put_str(spec, 11, 6);
    print_screen();
}


int       main() {
    bool    is_connected = false;
    EICRA |= (1 << ISC10) | (1 << ISC11);
    SREG |= 1 << SREG_I; //allows interrupt
    EIMSK |= (1 << INT1);
    ADCSRA |= (1 << ADEN); // enable ADC
    ADMUX |= (1 << REFS0); // AVCC with external capacitor at AREF pin
    display_init(); //pin connected to screen
    choosing = 1;
    // eeprom_write_specie();
    uart_init1();
    ft_delay(F_CPU / 50);
    uart_strx1("AT+CWJAP_CUR=\"iPhone\",\"Pedro900\"\r\n");
    ft_delay(F_CPU / 10);
    uart_strx1("AT+CIPSTATUS\r\n");
    ft_delay(F_CPU / 50);
    uart_strx1("AT+CIPSTART=\"TCP\",\"87.89.194.28\",4000\r\n");
    ft_delay(F_CPU / 50);
    // char cmd[] = "GET /api/get HTTP/1.0\r\nHost: 87.89.194.28\r\n\r\n";
    char cmd[] = "POST /api/insert HTTP/1.0\r\nHost: 87.89.194.28\r\nConnection: keep-alive\r\nContent-Length: 64\r\nContent-Type: application/json\r\n\r\n{\r\n\"temperature\":\"25\",\r\n\"humidite\":\"800\",\r\n\"luminosite\":\"500\"\r\n}";
    char cmd_body[] = "";
    char tmp[3];
    sprintf(tmp, "AT+CIPSEND=%d\r\n", strlen(cmd));
    uart_strx1(tmp);
    ft_delay(F_CPU / 500);
    uart_strx1(cmd);
    ft_delay(F_CPU / 20);

    while(1) {
        if (choosing == 1)
            display_menu();
        else
            display_info();
        ft_delay(F_CPU / 1000);
    }
    return 0;
}