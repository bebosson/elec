#include <inttypes.h>
#include <avr/io.h>

void    ft_delay(uint64_t delay) {
    while (delay--){};
}

void uart_init() {
	// UCSR0A |= (1 << U2X0); // double the speed rate
	/*Set baud rate */
	UBRR0L = 8; // 8 -> 115200 | 16 -> 57600
	/*Enable transmitter */
	UCSR0B |= (1 << TXEN0);
	/* Set frame format: 8data, 1stop bit */
	UCSR0C = (1 << UCSZ00) | (1 << UCSZ01); //8data
}

void uart_tx(char c) {
	while ( !( UCSR0A & (1<<UDRE0)) ); // wait for empty buffer
	UDR0 = c;
}

void uart_strx(char *str) {
    while (*str) {
        uart_tx(*str);
        str++;
    }
}

void uart_putnbr(uint16_t nb) {
	if (nb >= 10)
	{
		uart_putnbr(nb / 10);
		uart_putnbr(nb % 10);
	}
	else
		uart_tx(nb + '0');
}

void uart_putnbr8(uint8_t nb) {
	if (nb >= 10)
	{
		uart_putnbr(nb / 10);
		uart_putnbr(nb % 10);
	}
	else
		uart_tx(nb + '0');
}