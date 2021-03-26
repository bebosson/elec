#include "main.h"

int       main() {

    uint16_t byte = 4;
    uint16_t addr = 1;
    uint16_t read_byte;
    uart_init();
    uint32_t i;
    while(1) {
        eeprom_write(addr, (uint8_t)(byte & 0xFF)); //write the byte to the eeprom.  since the eeprom is 8 bit, we need to mask the upper 8 bits of the 16 bit variable
        read_byte = eeprom_read(addr);
        uart_putnbr(read_byte);
        byte++;
        i = F_CPU / 25; while (i-- > 0) {};
    }
    return 0;
}
