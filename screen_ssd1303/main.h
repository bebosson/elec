#ifndef main_h
#define main_h

typedef struct s_spi
{



}               t_spi;

typedef struct s_screen
{



}               t_screen;

typedef unsigned int uint8_t;
typedef signed int int16_t;

bool begin(uint8_t vcs, uint8_t addr, bool reset, bool periphBegin);

#endif