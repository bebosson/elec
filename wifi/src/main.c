#include "main.h"


extern char font[96][6];
char    chosen_specie; //flag of chosen species
char    transition;
volatile char    choosing;


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
    unsigned int lux;
    unsigned int mois;
    char        memory_species = 18 * (chosen_specie - 1);
    uint8_t spec[8];

    lux = read_lux();
    put_str("LUMINOSITE:         ", 0, 0);
    putnbr(lux, 13, 0);
    mois = read_moisture();
    put_str("HUMIDITE:           ", 0, 2);
    putnbr(mois, 13, 2);
    print_temp(getTemperature());
    put_str("ESPECE:   ", 0, 6);
    eeprom_read_page(memory_species, 8, spec); // recuperer dans la memoire l'espece choisi
    put_str(spec,11,6);
    print_screen();
}


int       main() {
    t_specie *specie;
    chosen_specie = 0;
//    EIFR |= (1 << INTF1); //Turn on interrupt INT 1
 //        // Turns on INT1
    EICRA |= (1 << ISC10) | (1 << ISC11);
    // UCSR0B |= (1<<RXCIE0); // enable interrupts when data received on uart
    SREG |= 1 << SREG_I; //allows interrupt
    
    EIMSK |= (1 << INT1); // interrupt on button "OK"
    ADCSRA |= (1 << ADEN); // enable ADC
    ADMUX |= (1 << REFS0); // VCC -> voltage reference
    display_init(); //pin connected to screen 
    choosing = 1;
    // eeprom_write_specie();

    DDRD |= (1 << PD2);
    uart_init();
    //esp_runtime_config();
    unsigned char  rx[2];
    rx[1]= '\0';
    // putnbr('O', 0, 4);
    unsigned int K = 0;
    int x=0;
    int	y=0;
    // putnbr(K, 0, 5);
    // put_str("0", 0, 5);


    uart_strx("AT\r\n");
    // uart_strx("AT+CWMODE_DEF=3\r\n"); //set AP and station mode
    // ft_delay(F_CPU / 50);
    // uart_strx("AT+CWLAP\r\n"); //list available APs
    // uart_strx("AT+CWJAP_CUR=\"iPhone\",\"Pedro900\"\r\n");



    // put_str("1", 1, 5);
    // uart_strx("\r\n");print_screen();
    // put_str("2", 2, 5);print_screen();
    // uart_strx("AT+UART_CUR?");
    // rx[0] = uart_rx();

    // put_str(rx, 0, 0);

    // rx[0] = uart_rx();

    // put_str(rx, 1, 0);

    // rx[0] = uart_rx();

    // put_str(rx, 2, 0);

    // rx[0] = uart_rx();

    // put_str(rx, 3, 0);
    // char str[2] = "A\0";
    while(1) {
        // put_str(str, 0, 6);print_screen();
        // str[0]++;
        rx[0] = uart_rx();
        // K = (unsigned int)(rx[0]);
        // if (rx[0] >= '0' && rx <= '9')
        // ft_putnbr(K, x, y++);
        put_str(rx, x, y);
        if (++x == 21) {
            x = 0;
            y++;
        }
        print_screen();
        // if (choosing == 1)
        //     display_menu();
        // else
        //     display_info();
        // ft_delay(F_CPU / 50);
    }

    return 0;
}
