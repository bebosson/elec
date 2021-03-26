
#include "avr/io.h"

void eeprom_write ( uint16_t address, uint8_t byte ) {  //write a byte to the AVR EEPROM
	while (EECR & _BV(EEPE)) ;                 //wait until any write operation is complete
	EEAR = address;                            //set the desired address
	EEDR = byte;                               //set the desired byte
	EECR |= ( 1 << EEMPE );                    //enable write operations
	EECR |= ( 1 << EEPE );                     //start the write operation
}

uint8_t eeprom_read ( uint16_t address ) {     //read a byte from the AVR EEPROM
	while (EECR & _BV(EEPE)) ;                 //wait until any write operation is complete
	EEAR = address;                            //set the desired address
	EECR |= ( 1 << EERE );                     //trigger a read operation
	return EEDR;                               //return the data
}

void eeprom_write_page (uint16_t saddress, uint16_t n, uint8_t* bytes) {  //write a string of bytes to EEPROM
	uint16_t c;                                //counter variable
	for(c=0;c<n;c++) {                         //write n number of bytes
	    eeprom_write(saddress+c, bytes[c]);	   //write the next byte in the string
    }
}

void eeprom_read_page (uint16_t saddress, uint16_t n, uint8_t* bytes) {  //read a string of bytes from EEPROM
	uint16_t c;                                //counter variable
	for(c=0;c<n;c++) {                         //read n number of bytes
	    bytes[c] = eeprom_read(saddress+c);	   //read and store the next byte
    }	
}
