#ifdef __SCREEN_H__
#define __SCREEN_H__

#include <inttypes.h>

typedef struct  s_screen {
    uint8_t     buffer[128];
	uint8_t		buf_height;
	uint8_t		tile_curr_row;
}               t_screen;

void    putnbr(char nb, char x, char y);
void    put_str(char *str, char x, char y);
void	SPI_MasterTransmit(char cData);
void    display_init();

#endif