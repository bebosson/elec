#include "main.h"


//   // Select the temperature register at register_index.                                                                                              
//   bus->beginTransmission(i2c_address);                                            ||||||  rien de special en soit....                                                    
//   bus->write(register_index);                                                     ||||||  comme transmitting=1 : load dans le buffer l'adresse du registre de la temperature que le master veut demander au slave                                            
//   bus->endTransmission();                                                         ||||||  fait un appel a twi_writeTo ce qui transmet le contenu de la demande au slave                                       

//   // Start a transaction to read the register data.                               ||||||  fait un appel a twi_readFrom ce qui permet de recevoir la donnee                                                              
//   bus->requestFrom(i2c_address, (uint8_t) (resolution <= 8 ? 1 : 2));                                                                                                

//   // Read the most significant byte of the temperature data.                                                                                             
//   uint16_t t = bus->read() << 8;                                                  ||||||  stocker la valeur recue dans une autre var...                                        

//   // Read the least significant byte of the temperature data, if requested.                                                                                              
//   if (resolution > 8) {                                                           ||||||  stocker le deuxieme octet...                                   
//     t |= bus->read();                                                                                                
//   }                                                                                              

//   // Finished reading the register data.                                                                                             
//   bus->endTransmission();                                                         ||||||  twi_writeTo pour envoyer un NACK et une stop condition                                       

//   // Mask out unused/reserved bit from the full 16-bit register.                                                                                             
//   t &= resolution_mask;                                                                                              

//   // Read the raw memory as a 16-bit signed integer and return.                                                                                              
//   return *(int16_t *)(&t);

uint16_t  getTemperature() {
    //send start and ask data register to slave
    uint8_t tx_address = DEFAULT_I2C_ADDRESS;
    uint8_t rx_data;
    uint16_t temperature;
    // uart_tx('B');
   twi_writeTo(tx_address, 0x00, 1, true, true);
//    uart_tx('C');
   twi_readFrom(tx_address, &rx_data, 2, true);
   twi_writeTo(tx_address, 0, 0, true, true);
    return *(int16_t *)(&rx_data);
}

int       main() {
    SREG |= (1 << SREG_I);
    // twi_init();
    uint16_t temp;
    uart_init();
    // ft_delay(F_CPU / 25);
    while(1) {
        uart_tx('>');
        // uart_strx(" | while start | ");
        uint32_t i = F_CPU / 25;
        while (i-- > 0) {};
        temp = getTemperature();
        i = F_CPU / 25;
        // while (i-- > 0) {};
        uart_strx(" | TEMP IS :");
        uart_putnbr((uint32_t)temp);
        uart_strx(" | end | ");
    }
    return 0;
}
