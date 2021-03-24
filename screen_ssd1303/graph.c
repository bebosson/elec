#include "main.h"

#define WIDTH 128
#define HEIGHT 68

void clearDisplay(uint8_t *buffer) 
{
  memset(buffer, 0, WIDTH * ((HEIGHT + 7) / 8));
}

inline static void beginTransaction(SPISettings settings) {
    if (interruptMode > 0) {
      uint8_t sreg = SREG;
      noInterrupts();

      #ifdef SPI_AVR_EIMSK
      if (interruptMode == 1) {
        interruptSave = SPI_AVR_EIMSK;
        SPI_AVR_EIMSK &= ~interruptMask;
        SREG = sreg;
      } else
      #endif
      {
        interruptSave = sreg;
      }
    }

    #ifdef SPI_TRANSACTION_MISMATCH_LED
    if (inTransactionFlag) {
      pinMode(SPI_TRANSACTION_MISMATCH_LED, OUTPUT);
      digitalWrite(SPI_TRANSACTION_MISMATCH_LED, HIGH);
    }
    inTransactionFlag = 1;
    #endif

    SPCR = settings.spcr;
    SPSR = settings.spsr;
  }
}

void startWrite(void) {
  SPI_BEGIN_TRANSACTION(); //Before using SPI.transfer() or asserting chip select pins, this function is used to gain exclusive access to the SPI bus and configure the correct settings.
  if (_cs >= 0)
    SPI_CS_LOW();
}

void drawBitmap(int16_t x, int16_t y, const uint8_t bitmap[],
                              int16_t w, int16_t h, uint16_t color) {

  int16_t byteWidth = (w + 7) / 8; // Bitmap scanline pad = whole byte
  uint8_t byte = 0;

  startWrite(); //Call before issuing command(s) or data to display. Performs chip-select (if required) and starts an SPI transaction (if using hardware SPI and transactions are supported). Required for all display types; not an SPI-specific function. 
  for (int16_t j = 0; j < h; j++, y++) {
    for (int16_t i = 0; i < w; i++) {
      if (i & 7)
        byte <<= 1;
      else
        byte = pgm_read_byte(&bitmap[j * byteWidth + i / 8]);
      if (byte & 0x80)
        writePixel(x + i, y, color);
    }
  }
  endWrite(); //Call after issuing command(s) or data to display. Performs chip-deselect (if required) and ends an SPI transaction (if using hardware SPI and transactions are supported). Required for all display types; not an SPI-specific function. 
}