#include <inttypes.h>

#define SERIAL_8N1 0x06

void    hw_serial_begin(uint64_t baud, uint8_t config);