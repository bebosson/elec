#include "main.h"
#include <stdio.h>
#include <string.h>

extern uint8_t      font[96][6];
volatile uint8_t    chosen_specie; // =1 if a specie is chosen otherwise =0
volatile char       g_lux[] = "\0\0\0\0";
volatile char       g_mois[] = "\0\0\0\0";
volatile char       g_temp[] = "\0\0\0\0\0";
volatile uint8_t    choosing = 1;


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
        ft_delay(F_CPU / 500);
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
        ft_delay(F_CPU / 500);
    }
}

void    render_menu()
{
    uint8_t spec[8];
    put_str("CHOISISSEZ VOTRE", 2, 0);
    put_str("ESPECE", 7, 1);
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
}

void    display_menu() //choix espece
{
    static uint8_t x = 8;
    static uint8_t y = 3;
    navigation_button(&x, &y);
    render_menu();
    put_str("<", x, y);
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
    twi_writeTo(tx_address, 0x00, 1, true, true); //get temperature
    twi_readFrom(tx_address, rx_data, 2, true); //receive temperature
    twi_writeTo(tx_address, 0, 0, true, true); //end of communication

    return ((uint16_t)rx_data[0] << 8) | (rx_data[1]);
}

void    print_temp(int16_t val) {
    init_str(g_temp, 6);
    put_str("TEMPERATURE:         ", 0, 4);
    if (val < 0)
        put_str("-", 13, 4);
    val &= ~(1 << 15); // clear neg bit
    putnbr(val >> 8, 14, 4);
    put_str(".", 15 + (val >> 8 >= 10) + (val >> 8 >= 100), 4);
    putnbr(125 * ((val >> 5) & 7) / 100, 16 + (val >> 8 >= 10) + (val >> 8 >= 100), 4);
    put_str("oC", 17 + (val >> 8 >= 10) + (val >> 8 >= 100), 4); 
}

uint16_t read_lux() {
    uint16_t lux = 0;
    ADMUX &= ~(1 << MUX3);//set pin A3
    ADMUX &= ~(1 << MUX2);
    ADMUX |= (1 << MUX1);
    ADMUX |= (1 << MUX0);
    ADCSRA |= (1 << ADSC); // start calculations
        while((ADCSRA & (1 << ADSC))); // wait calculations is done
        lux = ADCL | (uint16_t)(ADCH & 0b11) << 8;
    init_str(g_mois, 5);
    ft_uitoa(lux, g_lux, 5);
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
    init_str(g_mois, 5);
    ft_uitoa(mois, g_mois, 5);
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
    choosing = !choosing;
    ft_delay(F_CPU / 750);
}

void    display_info()
{
    uint8_t     memory_species = 18 * (chosen_specie - 1);
    uint8_t     spec[8];
    uint16_t    lux;
    uint16_t    mois;

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
    EICRA |= (1 << ISC10) | (1 << ISC11);
    SREG |= 1 << SREG_I; //allows interrupt
    EIMSK |= (1 << INT1); //enable INT1 for Select button press
    ADCSRA |= (1 << ADEN); // enable ADC
    ADMUX |= (1 << REFS0); // AVCC with external capacitor at AREF pin
    ft_delay(F_CPU / 50);
    display_init(); //pin connected to screen
    // eeprom_write_specie();
    uart_init();
    // ft_delay(F_CPU / 50);
    uart_strx("AT+CWJAP_CUR=\"iPhone\",\"Pedro900\"\r\n");
    ft_delay(F_CPU / 10);
    uart_strx("AT+CIPSTATUS\r\n");
    ft_delay(F_CPU / 50);
    uart_strx("AT+CIPSTART=\"TCP\",\"87.89.194.28\",4000\r\n");
    ft_delay(F_CPU / 50);
    
    uint8_t body_len = 18 + strlen(g_temp) + 16 + strlen(g_mois) + 18 + strlen(g_lux) + 4; // 18 -> {\r\n\"temperature\":\"
    char cmd2[3] = "\0\0"; // content(body) length
    ft_uitoa(body_len, cmd2, 3);

    uint16_t cmd_len = 87 + 2 + 54 + body_len - 18;

    // Complete POST request example :
    // char cmd[] = "POST /api/insert HTTP/1.0\r\nHost: 87.89.194.28\r\nConnection: keep-alive\r\nContent-Length: 64\r\nContent-Type: application/json\r\n\r\n{\r\n\"temperature\":\"25\",\r\n\"humidite\":\"800\",\r\n\"luminosite\":\"500\"\r\n}";
    // char cmd[] = "GET /api/get HTTP/1.0\r\nHost: 87.89.194.28\r\n\r\n"; // GET http request example

    char cmd1[] = "POST /api/insert HTTP/1.0\r\nHost: 87.89.194.28\r\nConnection: keep-alive\r\nContent-Length: ";
    //cmd2 = body length
    char cmd3[] = "\r\nContent-Type: application/json\r\n\r\n{\r\n\"temperature\":\"";
    // g_temp
    char cmd5[] = "\",\r\n\"humidite\":\"";
    // g_mois
    char cmd7[] = "\",\r\n\"luminosite\":\"";
    // g_lux
    char cmd9[] = "\"\r\n}";
    char tmp[20];
    char fcmd[250];
    sprintf(tmp, "AT+CIPSEND=%d\r\n", strlen(cmd_len));
    uart_strx(tmp);
    ft_delay(F_CPU / 50);
    
    sprintf(fcmd, "%s%s%s%s%s%s%s%s%s", cmd1, cmd2, cmd3, g_temp, cmd5, g_mois, cmd7, g_lux, cmd9);
    uart_strx(fcmd);
    
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