#include "custom_spi.h"
#include <inttypes.h>
#include <avr/io.h>

// extern void    hw_serial_begin(uint64_t baud, uint8_t config)
// {
//     // Try u2x mode first
//     uint16_t baud_setting = (F_CPU / 4 / baud - 1) / 2;
//     UCSR0A |= (1 << U2X0);

//     /*
//     // hardcoded exception for 57600 for compatibility with the bootloader
//   // shipped with the Duemilanove and previous boards and the firmware
//   // on the 8U2 on the Uno and Mega 2560. Also, The baud_setting cannot
//   // be > 4095, so switch back to non-u2x mode if the baud rate is too
//   // low.
//     if (((F_CPU == 16000000UL) && (baud == 57600)) || (baud_setting >4095))
//     {
//         UCSR0A = 0;
//         baud_setting = (F_CPU / 8 / baud - 1) / 2;
//     }*/

//     // assign the baud_setting, a.k.a. ubrr (USART Baud Rate Register)
//     UBRR0H = baud_setting >> 8;
//     UBRR0L = baud_setting;

//   //  _written = false; bool in HardwareSerial Class

//   //set the data bits, parity, and stop bits
//   #if defined(__AVR_ATmega8__)
//     config |= 0x80; // select UCSRC register (shared with UBRRH)
//   #endif
//     UCSR0C = config;

//   UCSR0B |= (1 << RXEN0);
//   UCSR0B |= (1 << TXEN0);
//   UCSR0B &= ~(1 << RXCIE0);
//   UCSR0B &= ~(1 << UDRIE0);
// }