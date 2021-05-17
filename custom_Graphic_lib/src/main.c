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
    uint16_t lux;
    uint16_t mois;
    uint8_t        memory_species = 18 * (chosen_specie - 1);
    uint8_t spec[8];

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
    //ft_delay(F_CPU / 500);
    //uart_strx1("AT+CWMODE_DEF=3\r\n"); //set AP and station mode
    //ft_delay(F_CPU / 500);
    // // uart_strx("AT+CWLAP\r\n"); //list available APs
    // uart_strx1("AT+GMR\r\n");
    uart_strx1("AT+CWJAP_CUR=\"iPhone\",\"Pedro900\"\r\n");
    // uart_strx1("AT+CWJAP_CUR=\"Pixel_6023\",\"92itn65rmnq5ij\"\r\n");
    ft_delay(F_CPU / 7);
    // uart_strx1("AT+CIPMUX=1\r\n");
    ft_delay(F_CPU / 50);
    // uart_strx1("AT+CIPSSLSIZE=4096\r\n");
    ft_delay(F_CPU / 50);
    // uart_strx1("AT+CIPSNTPCFG=1,8,\"cn.ntp.org.cn\",\"ntp.sjtu.edu.cn\",\"us.pool.ntp.org\"\r\n");
    // uart_strx1("AT+CIPSNTPCFG=1,8\r\n");
    ft_delay(F_CPU / 50);
    // uart_strx1("AT+CIPSNTPCFG?\r\n");
    ft_delay(F_CPU / 50);
    // uart_strx1("AT+CIPSSLCCONF=2\r\n");
    ft_delay(F_CPU / 50);
    // TEST CONNECTION A UN ORDI SUR LE MEME RESEAU (nc -l 80)
    // uart_strx1("AT+CIPSTART=\"TCP\",\"172.20.10.7\",80\r\n");
    // ft_delay(F_CPU / 10);
    // uart_strx1("AT+CIPSTART=\"TCP\",\"le-kube-4269e-default-rtdb.europe-west1.firebasedatabase.app\",443\r\n");
    // uart_strx1("AT+CIPSTART=\"SSL\",\"51.77.194.65\",443,1000\r\n");
    // uart_strx1("AT+CIPSTART=\"SSL\",\"www.google.com\",443,1200\r\n");
    uart_strx1("AT+CIPSTART=\"TCP\",\"www.google.com\",80\r\n");	
    ft_delay(F_CPU / 50);
    uart_strx1("AT+CIPSTATUS\r\n");
    ft_delay(F_CPU / 50);
    // char cmd[] = "GET / HTTP/1.0\r\nhost: 42chips.fr\r\n\r\n";
    char cmd[] = "GET /images/branding/googlelogo/2x/googlelogo_color_120x44dp.png HTTP/1.0\r\nHost: www.google.com\r\nUser-Agent: ESP8266\r\nAccept: image\r\nConnection: keep-alive\r\n\r\n";
    char tmp[3];
    sprintf(tmp, "AT+CIPSEND=%d\r\n", strlen(cmd));
    uart_strx1(tmp);
    ft_delay(F_CPU / 500);
    // uart_strx1("GET http://httpbin.org/get HTTP/1.1");
    // uart_strx1("GET https://le-kube-4269e-default-rtdb.europe-west1.firebasedatabase.app/test.json HTTPS/1.1");
    
    // uart_strx1("GET https://le-kube-4269e-default-rtdb.europe-west1.firebasedatabase.app:443/test.json HTTPS/1.1\r\n\r\n");
    uart_strx1(cmd);
    ft_delay(F_CPU / 20);
    
    // uart_strx1("AT+CIPSTART=\"TCP\",\"le-kube-4269e-default-rtdb.europe-west1.firebasedatabase.app\",443\r\n");
    // ft_delay(F_CPU / 50);
    // uart_strx1("AT+CIPSEND=96\r\n");
    // ft_delay(F_CPU / 500);
    // uart_strx1("GET /test.json HTTPS/1.1\r\nHost: le-kube-4269e-default-rtdb.europe-west1.firebasedatabase.app\r\n\r\n");

    // uart_strx1("AT+CIPSTART=\"TCP\",\"le-kube-4269e-default-rtdb.europe-west1.firebasedatabase.app\",443\r\n");
    // ft_delay(F_CPU / 50);
    // uart_strx1("AT+CIPSTATUS\r\n");
    // ft_delay(F_CPU / 50);
    // uart_strx1("AT+CIPSEND=96\r\n");
    // ft_delay(F_CPU / 50);
    // uart_strx1("GET /test.json HTTP/1.1\r\nHost:le-kube-4269e-default-rtdb.europe-west1.firebasedatabase.app\r\n\r\n");

    // uart_strx1("AT+CIPSTART=\"TCP\",\"httpbin.org\",443\r\n");
    // ft_delay(F_CPU / 50);
    // uart_strx1("AT+CIPSEND=41\r\n");
    // ft_delay(F_CPU / 50);
    // uart_strx1("GET /get HTTPS/1.1\r\nHost:httpbin.org\r\n\r\n");

    // uart_strx1("AT+CIPSTART=\"TCP\",\"httpbin.org\",443\r\n");
    // ft_delay(F_CPU / 50);
    // uart_strx1("AT+CIPSEND=39\r\n");
    // ft_delay(F_CPU / 50);
    // uart_strx1("GET /get HTTPS/1.1\r\nHost:httpbin.org\r\n\r\n");


    // uart_strx1("AT+CIPSTART=\"TCP\",\"le-kube-4269e-default-rtdb.europe-west1.firebasedatabase.app\",443\r\n");
    // ft_delay(F_CPU / 50);
    // uart_strx1("AT+CIPSEND=95\r\n");
    // ft_delay(F_CPU / 50);
    // uart_strx1("GET /test.json HTTP/1.1\r\nHost: le-kube-4269e-default-rtdb.europe-west1.firebasedatabase.app\r\n\r\n");




    // uart_strx1("GET /receiver.php?apples=56&oranges=23 HTTP/1.1\r\nHost: shotlu.usrs0.com\r\n\r\n");

    // uart_strx1("AT+CIPDOMAIN=\"www.google.com\"\r\n");
    // ft_delay(F_CPU / 50);
    // uart_strx1("AT+CIPDOMAIN=\"le-kube-4269e-default-rtdb.europe-west1.firebasedatabase.app\"\r\n");
    // ft_delay(F_CPU / 50);
    // uart_strx1("AT+CIPSTART=\"TCP\",\"le-kube-4269e-default-rtdb.europe-west1.firebasedatabase.app\",80\r\n");
    // ft_delay(F_CPU / 50);
    // uart_strx1("AT+HTTPCLIENT=2,0,\"http://httpbin.org/get\",\"httpbin.org\",\"/get\",1\r\n");
    // ft_delay(F_CPU / 50);
    // uart_strx1("AT+CIPSTART=\"TCP\",\"https://le-kube-4269e-default-rtdb.europe-west1.firebasedatabase.app\",5000\r\n");
    // ft_delay(F_CPU / 50);
    // uart_strx1("AT+CIPSTART=\"TCP\",\"https://le-kube-4269e-default-rtdb.europe-west1.firebasedatabase.app\",9099\r\n");
    // ft_delay(F_CPU / 50);
    //uart_strx1("AT+HTTPCLIENT=2,0,\"le-kube-4269e-default-rtdb.europe-west1.firebasedatabase.app/test\",\"/get\",1\r\n");


    // uart_strx1("AT+HTTPCPOST=\"https://le-kube-4269e-default-rtdb.europe-west1.firebasedatabase.app/moisture/value.json\",18\r\n");
    // ft_delay(F_CPU / 50);
    // uart_strx1("{ \"value\" : \"12\" }\r\n");
    // ft_delay(F_CPU / 500);

    while(1) {
        if (choosing == 1)
            display_menu();
        else
            display_info();
        ft_delay(F_CPU / 1000);
    }
    return 0;
}