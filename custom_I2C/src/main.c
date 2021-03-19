#include "main.h"

// static volatile uint8_t twi_error;
// static volatile uint8_t twi_state;
// static volatile uint8_t twi_slarw;
// static volatile uint8_t twi_sendStop;			// should the transaction end with a stop
// static volatile uint8_t twi_inRepStart;			// in the middle of a repeated start
// static uint8_t twi_masterBuffer[BUFFER_LENGTH];
// static volatile uint8_t twi_masterBufferIndex;
// static volatile uint8_t twi_masterBufferLength;
// static uint8_t twi_txBuffer[BUFFER_LENGTH];
// static volatile uint8_t twi_txBufferIndex;
// static volatile uint8_t twi_txBufferLength;
// static uint8_t twi_rxBuffer[BUFFER_LENGTH];
// static volatile uint8_t twi_rxBufferIndex;

// static void (*twi_onSlaveReceive)(uint8_t*, int);
// static void (*twi_onSlaveTransmit)(void);

// /* 
//  * Function twi_attachSlaveRxEvent
//  * Desc     sets function called before a slave read operation
//  * Input    function: callback function to use
//  * Output   none
//  */
// void twi_attachSlaveRxEvent( void (*function)(uint8_t*, int) )
// {
//   twi_onSlaveReceive = function;
// }

// /* 
//  * Function twi_attachSlaveTxEvent
//  * Desc     sets function called before a slave write operation
//  * Input    function: callback function to use
//  * Output   none
//  */
// void twi_attachSlaveTxEvent( void (*function)(void) )
// {
//   twi_onSlaveTransmit = function;
// }

// void twi_reply(uint8_t ack)
// {
//   // transmit master read ready signal, with or without ack
//   if(ack){
//     TWCR = _BV(TWEN) | _BV(TWIE) | _BV(TWINT) | _BV(TWEA);
//   }else{
// 	  TWCR = _BV(TWEN) | _BV(TWIE) | _BV(TWINT);
//   }
// }

// /* 
//  * Function twi_stop
//  * Desc     relinquishes bus master status
//  * Input    none
//  * Output   none
//  */
// void twi_stop(void)
// {
//   // send stop condition
//   TWCR = _BV(TWEN) | _BV(TWIE) | _BV(TWEA) | _BV(TWINT) | _BV(TWSTO);

//   // wait for stop condition to be exectued on bus
//   // TWINT is not set after a stop condition!
//   while(TWCR & _BV(TWSTO)){
//     continue;
//   }

//   // update twi state
//   twi_state = TWI_READY;
// }

// /* 
//  * Function twi_releaseBus
//  * Desc     releases bus control
//  * Input    none
//  * Output   none
//  */
// void twi_releaseBus(void)
// {
//   // release bus
//   TWCR = _BV(TWEN) | _BV(TWIE) | _BV(TWEA) | _BV(TWINT);

//   // update twi state
//   twi_state = TWI_READY;
// }

// ISR(TWI_vect)
// {
//   switch(TW_STATUS){
//     // All Master
//     case TW_START:     // sent start condition
//     case TW_REP_START: // sent repeated start condition
//       // copy device address and r/w bit to output register and ack
//       TWDR = twi_slarw;
//       twi_reply(1);
//       break;

//     // Master Transmitter
//     case TW_MT_SLA_ACK:  // slave receiver acked address
//     case TW_MT_DATA_ACK: // slave receiver acked data
//       // if there is data to send, send it, otherwise stop 
//       if(twi_masterBufferIndex < twi_masterBufferLength){
//         // copy data to output register and ack
//         TWDR = twi_masterBuffer[twi_masterBufferIndex++];
//         twi_reply(1);
//       }else{
// 	if (twi_sendStop)
//           twi_stop();
// 	else {
// 	  twi_inRepStart = true;	// we're gonna send the START
// 	  // don't enable the interrupt. We'll generate the start, but we 
// 	  // avoid handling the interrupt until we're in the next transaction,
// 	  // at the point where we would normally issue the start.
// 	  TWCR = _BV(TWINT) | _BV(TWSTA)| _BV(TWEN) ;
// 	  twi_state = TWI_READY;
// 	}
//       }
//       break;
//     case TW_MT_SLA_NACK:  // address sent, nack received
//       twi_error = TW_MT_SLA_NACK;
//       twi_stop();
//       break;
//     case TW_MT_DATA_NACK: // data sent, nack received
//       twi_error = TW_MT_DATA_NACK;
//       twi_stop();
//       break;
//     case TW_MT_ARB_LOST: // lost bus arbitration
//       twi_error = TW_MT_ARB_LOST;
//       twi_releaseBus();
//       break;

//     // Master Receiver
//     case TW_MR_DATA_ACK: // data received, ack sent
//       // put byte into buffer
//       twi_masterBuffer[twi_masterBufferIndex++] = TWDR;
//     case TW_MR_SLA_ACK:  // address sent, ack received
//       // ack if more bytes are expected, otherwise nack
//       if(twi_masterBufferIndex < twi_masterBufferLength){
//         twi_reply(1);
//       }else{
//         twi_reply(0);
//       }
//       break;
//     case TW_MR_DATA_NACK: // data received, nack sent
//       // put final byte into buffer
//       twi_masterBuffer[twi_masterBufferIndex++] = TWDR;
// 	if (twi_sendStop)
//           twi_stop();
// 	else {
// 	  twi_inRepStart = true;	// we're gonna send the START
// 	  // don't enable the interrupt. We'll generate the start, but we 
// 	  // avoid handling the interrupt until we're in the next transaction,
// 	  // at the point where we would normally issue the start.
// 	  TWCR = _BV(TWINT) | _BV(TWSTA)| _BV(TWEN) ;
// 	  twi_state = TWI_READY;
// 	}    
// 	break;
//     case TW_MR_SLA_NACK: // address sent, nack received
//       twi_stop();
//       break;
//     // TW_MR_ARB_LOST handled by TW_MT_ARB_LOST case

//     // Slave Receiver
//     case TW_SR_SLA_ACK:   // addressed, returned ack
//     case TW_SR_GCALL_ACK: // addressed generally, returned ack
//     case TW_SR_ARB_LOST_SLA_ACK:   // lost arbitration, returned ack
//     case TW_SR_ARB_LOST_GCALL_ACK: // lost arbitration, returned ack
//       // enter slave receiver mode
//       twi_state = TWI_SRX;
//       // indicate that rx buffer can be overwritten and ack
//       twi_rxBufferIndex = 0;
//       twi_reply(1);
//       break;
//     case TW_SR_DATA_ACK:       // data received, returned ack
//     case TW_SR_GCALL_DATA_ACK: // data received generally, returned ack
//       // if there is still room in the rx buffer
//       if(twi_rxBufferIndex < BUFFER_LENGTH){
//         // put byte in buffer and ack
//         twi_rxBuffer[twi_rxBufferIndex++] = TWDR;
//         twi_reply(1);
//       }else{
//         // otherwise nack
//         twi_reply(0);
//       }
//       break;
//     case TW_SR_STOP: // stop or repeated start condition received
//       // put a null char after data if there's room
//       if(twi_rxBufferIndex < BUFFER_LENGTH){
//         twi_rxBuffer[twi_rxBufferIndex] = '\0';
//       }
//       // sends ack and stops interface for clock stretching
//       twi_stop();
//       // callback to user defined callback
//       twi_onSlaveReceive(twi_rxBuffer, twi_rxBufferIndex);
//       // since we submit rx buffer to "wire" library, we can reset it
//       twi_rxBufferIndex = 0;
//       // ack future responses and leave slave receiver state
//       twi_releaseBus();
//       break;
//     case TW_SR_DATA_NACK:       // data received, returned nack
//     case TW_SR_GCALL_DATA_NACK: // data received generally, returned nack
//       // nack back at master
//       twi_reply(0);
//       break;
    
//     // Slave Transmitter
//     case TW_ST_SLA_ACK:          // addressed, returned ack
//     case TW_ST_ARB_LOST_SLA_ACK: // arbitration lost, returned ack
//       // enter slave transmitter mode
//       twi_state = TWI_STX;
//       // ready the tx buffer index for iteration
//       twi_txBufferIndex = 0;
//       // set tx buffer length to be zero, to verify if user changes it
//       twi_txBufferLength = 0;
//       // request for txBuffer to be filled and length to be set
//       // note: user must call twi_transmit(bytes, length) to do this
//       twi_onSlaveTransmit();
//       // if they didn't change buffer & length, initialize it
//       if(0 == twi_txBufferLength){
//         twi_txBufferLength = 1;
//         twi_txBuffer[0] = 0x00;
//       }
//       // transmit first byte from buffer, fall
//     case TW_ST_DATA_ACK: // byte sent, ack returned
//       // copy data to output register
//       TWDR = twi_txBuffer[twi_txBufferIndex++];
//       // if there is more to send, ack, otherwise nack
//       if(twi_txBufferIndex < twi_txBufferLength){
//         twi_reply(1);
//       }else{
//         twi_reply(0);
//       }
//       break;
//     case TW_ST_DATA_NACK: // received nack, we are done 
//     case TW_ST_LAST_DATA: // received ack, but we are done already!
//       // ack future responses
//       twi_reply(1);
//       // leave slave receiver state
//       twi_state = TWI_READY;
//       break;

//     // All
//     case TW_NO_INFO:   // no state information
//       break;
//     case TW_BUS_ERROR: // bus error, illegal stop/start
//       twi_error = TW_BUS_ERROR;
//       twi_stop();
//       break;
//   }
// }

// uint8_t twi_transmit(const uint8_t* data, uint8_t length, t_I2C_Data *I2C_Data)
// {
//   uint8_t i;

//   // ensure data will fit into buffer
//   if(BUFFER_LENGTH < length){
//     return 1;
//   }
  
//   // ensure we are currently a slave transmitter
//   if(TWI_STX != twi_state) {
//    return 2;
//   }
  
//   // set length and copy data into tx buffer
//   (*I2C_Data).txBufferLength = length;
//   for(i = 0; i < length; ++i) {
//     (*I2C_Data).txBuffer[i] = data[i];
//   }
  
//   return 0;
// }

// /* 
//  * Function twi_writeTo
//  * Desc     attempts to become twi bus master and write a
//  *          series of bytes to a device on the bus
//  * Input    address: 7bit i2c device address
//  *          data: pointer to byte array
//  *          length: number of bytes in array
//  *          wait: boolean indicating to wait for write or not
//  *          sendStop: boolean indicating whether or not to send a stop at the end
//  * Output   0 .. success
//  *          1 .. length to long for buffer
//  *          2 .. address send, NACK received
//  *          3 .. data send, NACK received
//  *          4 .. other twi error (lost bus arbitration, bus error, ..)
//  */
// uint8_t twi_writeTo(uint8_t address, uint8_t* data, uint8_t length, uint8_t wait, uint8_t sendStop) {
//   uint8_t i;

//   // ensure data will fit into buffer
//   if(BUFFER_LENGTH < length) {
//     return 1;
//   }

//   // wait until twi is ready, become master transmitter
//   while(TWI_READY != twi_state) {
//     continue;
//   }
//   twi_state = TWI_MTX;
//   twi_sendStop = sendStop;
//   // reset error state (0xFF.. no error occured)
//   twi_error = 0xFF;

//   // initialize buffer iteration vars
//   twi_masterBufferIndex = 0;
//   twi_masterBufferLength = length;
  
//   // copy data to twi buffer
//   for(i = 0; i < length; ++i){
//     twi_masterBuffer[i] = data[i];
//   }
  
//   // build sla+w, slave device address + w bit
//   twi_slarw = TW_WRITE;
//   twi_slarw |= address << 1;
  
//   // if we're in a repeated start, then we've already sent the START
//   // in the ISR. Don't do it again.
//   //
//   if (true == twi_inRepStart) {
//     // if we're in the repeated start state, then we've already sent the start,
//     // (@@@ we hope), and the TWI statemachine is just waiting for the address byte.
//     // We need to remove ourselves from the repeated start state before we enable interrupts,
//     // since the ISR is ASYNC, and we could get confused if we hit the ISR before cleaning
//     // up. Also, don't enable the START interrupt. There may be one pending from the 
//     // repeated start that we sent outselves, and that would really confuse things.
//     twi_inRepStart = false;			// remember, we're dealing with an ASYNC ISR
//     TWDR = twi_slarw;				
//     TWCR = _BV(TWINT) | _BV(TWEA) | _BV(TWEN) | _BV(TWIE);	// enable INTs, but not START
//   }
//   else
//     // send start condition
//     TWCR = _BV(TWINT) | _BV(TWEA) | _BV(TWEN) | _BV(TWIE) | _BV(TWSTA);	// enable INTs

//   // wait for write operation to complete
//   while(wait && (TWI_MTX == twi_state)){
//     continue;
//   }
  
//   if (twi_error == 0xFF)
//     return 0;	// success
//   else if (twi_error == TW_MT_SLA_NACK)
//     return 2;	// error: address send, nack received
//   else if (twi_error == TW_MT_DATA_NACK)
//     return 3;	// error: data send, nack received
//   else
//     return 4;	// other twi error
// }

// uint64_t    write(uint8_t data, t_I2C_Data *I2C_Data)
// {
//   if ((*I2C_Data).transmitting) {
//   // in master transmitter mode
//     // don't bother if buffer is full
//     if ((*I2C_Data).txBufferLength >= BUFFER_LENGTH){
//       //setWriteError();
//       return 0;
//     }
//     // put byte in tx buffer
//     (*I2C_Data).txBuffer[(*I2C_Data).txBufferIndex] = data;
//     ++((*I2C_Data).txBufferIndex);
//     // update amount in buffer   
//     (*I2C_Data).txBufferLength = (*I2C_Data).txBufferIndex;
//   } else {
//   // in slave send mode
//     // reply to master
//     twi_transmit(&data, 1);
//   }
//   return 1;
// }


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
//    twi_writeTo(tx_address, 0x00, 1, true, true);
//    twi_readFrom(tx_address, &rx_data, 2, true);
//    twi_writeTo(tx_address, 0, 0, true, true);
    return *(int16_t *)(&rx_data);
    // // temperature = rx_data & mask_resolution;
    // // t_I2C_Data I2C_Data;

    // //get_temperature() -> readTemperatureC()

    // //readTemperatureC() -> convertIntegerTemperature(readIntegerTemperatureRegister(attributes->registers->temperature))
    // //    readIntegerTemperatureRegister-> 
    //                                     // Select the temperature register at register_index.
    // //                                    bus->beginTransmission(i2c_address);
    // //                                              transmitting = 1;
    // //                                              txAddress = address;
    // //                                              txBufferIndex = 0;
    // //                                              txBufferLength = 0;
    // // I2C_Data.transmitting = 1;
    // // I2C_Data.txAddress = DEFAULT_I2C_ADDRESS;
    // // I2C_Data.txBufferIndex = 0;
    // // I2C_Data.txBufferLength = 0;

    // //                                    bus->write(register_index);
    // write(0x00, &I2C_Data);                                                                                             // <--- register address containing temperature is 0x00 : the master is asking to access a slave data of his choice

    // //                                    bus->endTransmission();
    // // transmit buffer (blocking)
    // int8_t ret = twi_writeTo(I2C_Data.txAddress, I2C_Data.txBuffer, I2C_Data.txBufferLength, 1, true);
    // // reset tx buffer iterator vars
    // I2C_Data.txBufferIndex = 0;
    // I2C_Data.txBufferLength = 0;
    // // indicate that we are done transmitting
    // I2C_Data.transmitting = 0;
    // // return ret;  <-- ret is the return code of twi_writeTo (cf. twi_writeTo for details)


                                        
    //                                     // Start a transaction to read the register data.
    // //                                    bus->requestFrom(i2c_address, (uint8_t) (resolution <= 8 ? 1 : 2));
                                        
    //                                     // Read the most significant byte of the temperature data.
    // //                                    uint16_t t = bus->read() << 8;
                                        
    //                                     // Read the least significant byte of the temperature data, if requested.
    // //                                    if (resolution > 8) {
    // //                                      t |= bus->read();
    // //                                    }
                                        
    //                                     // Finished reading the register data.
    // //                                    bus->endTransmission();
                                        
    //                                     // Mask out unused/reserved bit from the full 16-bit register.
    // //                                    t &= resolution_mask;
                                        
    //                                     // Read the raw memory as a 16-bit signed integer and return.
    // //                                    return *(int16_t *)(&t);

}
int       main() {
    //twi_init();
    // uint16_t temp;
    uart_init();
    char c = 'H';
    // ft_delay(F_CPU / 25);
    while(1) {
        uart_tx(c);
        uint32_t i = F_CPU / 25;
        while (i-- > 0) {};
        // temp = getTemperature();
        // uart_putnbr((uint32_t)temp);

    }
    return 0;
}
