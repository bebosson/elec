#include <inttypes.h>

void uart_init();
void uart_tx(char c);
void uart_strx(char *str);
void uart_init1();
void uart_tx1(char c);
void uart_strx1(char *str);
void uart_putnbr(uint16_t nb);
void uart_putnbr8(uint8_t nb);
void ft_delay(uint64_t delay);
