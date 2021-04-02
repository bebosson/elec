#include "main.h"

void    ft_delay(uint64_t delay) {
    while (delay--){};
}

// int x=0;
// int	y=0;

// ISR(USART_RX_vect) {
// 	/* Wait for empty transmit buffer */
// 	// while (!(UCSR0A & (1<<UDRE0)));
// 	put_str("enter", 0, 3);print_screen();
// 	char c = UDR0;
// 	char rx[2];
// 	rx[1] = '\0';
// 	rx[0] = c;
// 	put_str(rx, x, y);
// 	if (++x == 21) {
// 		x = 0;
// 		y++;
// 	}
// 	put_str("end  ", 0, 3);print_screen();
// }

void uart_init() {
	// UCSR0A |= (1 << U2X0); // double the speed rate
	/*Set baud rate */
	UBRR0L = 103; // 8 -> 115200 | 16 -> 57600
	/*Enable transmitter */
	UCSR0B = (1<<RXEN0) | (1 << TXEN0);
	/* Set frame format: 8data, 1stop bit */
	UCSR0C = (1 << UCSZ00) | (1 << UCSZ01); //8data
}

unsigned char uart_rx()
{
	/* Wait for data to be received */
	while (!(UCSR0A & (1<<RXC0)));
	/* Get and return received data from buffer */
	return (UDR0);
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
		uart_putnbr8(nb / 10);
		uart_putnbr8(nb % 10);
	}
	else
		uart_tx(nb + '0');
}