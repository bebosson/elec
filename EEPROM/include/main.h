#include <stdbool.h>
#include <inttypes.h>
#include "twi.h"
#include "utils.h"
#include "eeprom.h"
#include "stdusart0.h"
#include "usartcommon.h"

#define DEFAULT_I2C_ADDRESS 0x48;
#define BUFFER_LENGTH 32