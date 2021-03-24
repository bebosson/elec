#ifndef main_h
#define main_h

#include <stdio.h>

/*==========================================*/
/* Command Arg Data (CAD) Interface */

/*
  U8X8_MSG_CAD_INIT
    no args
    call U8X8_MSG_BYTE_INIT
    setup default values for the I/O lines
*/
#define U8X8_MSG_CAD_INIT 20


#define U8X8_MSG_CAD_SEND_CMD 21
/*  arg_int: cmd byte */
#define U8X8_MSG_CAD_SEND_ARG 22
/*  arg_int: arg byte */
#define U8X8_MSG_CAD_SEND_DATA 23
/* arg_int: expected cs level after processing this msg */
#define U8X8_MSG_CAD_START_TRANSFER 24
/* arg_int: expected cs level after processing this msg */
#define U8X8_MSG_CAD_END_TRANSFER 25
/* arg_int = 0: disable chip, arg_int = 1: enable chip */
//#define U8X8_MSG_CAD_SET_I2C_ADR 26
//#define U8X8_MSG_CAD_SET_DEVICE 27


#define U8X8_MSG_DISPLAY_SET_POWER_SAVE 11
#define U8X8_MSG_DISPLAY_INIT 10
#define U8X8_MSG_DISPLAY_DRAW_TILE 15
#define U8X8_MSG_DELAY_MILLI		41

/** PIN **/

#define U8X8_PIN_OUTPUT_CNT 16
#define U8X8_PIN_INPUT_CNT 6
#define U8X8_MSG_DISPLAY_SETUP_MEMORY 9
#define U8X8_PIN_CNT (U8X8_PIN_OUTPUT_CNT+U8X8_PIN_INPUT_CNT)

#define U8X8_START_TRANSFER()	(U8X8_MSG_CAD_START_TRANSFER)
#define U8X8_END_TRANSFER()	(U8X8_MSG_CAD_END_TRANSFER)
#define U8X8_C(c0)				(U8X8_MSG_CAD_SEND_CMD), (c0)
#define U8X8_END()			(0xff)

typedef unsigned int uint32_t;
typedef unsigned int uint8_t;
typedef struct u8x8_display_info_struct u8x8_display_info_t;
typedef uint8_t (*u8x8_msg_cb)(t_u8x8 *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr);
typedef unsigned int uint16_t;


typedef struct       s_u8x8
{
  u8x8_char_cb next_cb;
  u8x8_msg_cb display_cb;
  u8x8_msg_cb cad_cb;
  u8x8_msg_cb byte_cb;
  u8x8_msg_cb gpio_and_delay_cb;
  const u8x8_display_info_t *display_info;
  uint8_t is_font_inverse_mode; 	/* 0: normal, 1: font glyphs are inverted */
  uint32_t bus_clock;	/* can be used by the byte function to store the clock speed of the bus */
  uint8_t i2c_address;	/* a valid i2c adr. Initially this is 255, but this is set to something usefull during DISPLAY_INIT ??*/
  uint8_t utf8_state;		/* number of chars which are still to scan */
  uint8_t debounce_default_pin_state;
  uint8_t pins[U8X8_PIN_CNT];
  uint8_t x_offset;	/* copied from info struct, can be modified in flip mode */

}                    t_u8x8;

typedef struct u8x8_tile_struct
{
  uint8_t *tile_ptr;	/* pointer to one or more tiles... should be "const" */
  uint8_t cnt;		/* number of tiles */
  uint8_t x_pos;	/* tile x position */
  uint8_t y_pos;	/* tile y position */
}                   u8x8_tile_t;

struct u8x8_display_info_struct
{
  /* == general == */

  uint8_t chip_enable_level;			/* UC1601: 0 */
  uint8_t chip_disable_level;			/* opposite of chip_enable_level */
  
  uint8_t post_chip_enable_wait_ns;		/* UC1601: 5ns */
  uint8_t pre_chip_disable_wait_ns;		/* UC1601: 5ns */
  uint8_t reset_pulse_width_ms;		/* UC1601: 0.003ms --> 1ms */ 
  uint8_t post_reset_wait_ms;			/* UC1601: 6ms  */ 
  
  
  /* == SPI interface == */
  
  /* after SDA has been applied, wait this much time for the SCK data takeover edge */
  /* if this is smaller than sck_pulse_width_ns, then use the value from sck_pulse_width_ns */
  uint8_t sda_setup_time_ns;		/* UC1601: 12ns */
  /* the pulse width of the the clock signal, cycle time is twice this value */
  /* max freq is 1/(2*sck_pulse_width_ns) */
  /* AVR: below 70: DIV2, 8 MHz, >= 70 --> 4MHz clock (DIV4) */
  uint8_t sck_pulse_width_ns;		/* UC1701: 50ns */
  
  /* until here we have 8 bytes (uint8_t). Newly introduced for SPI.beginTransaction */
  uint32_t sck_clock_hz;
  
  /* previous name "sck_takeover_edge" renamed to "spi_mode" */
  /* bit 0 of spi_mode is equal to the value of the previous variable sck_takeover_edge, 20 Aug 16: This is wrong the bit is actually inverted */ 
  /* SPI has four clock modes: */
  /*   0: clock active high, data out on falling edge, clock default value is zero, takover on rising edge */
  /*   1: clock active high, data out on rising edge, clock default value is zero, takover on falling edge */
  /*   2: clock active low, data out on rising edge */
  /*   3: clock active low, data out on falling edge */
  /* most displays have clock mode 1 */
  uint8_t spi_mode;
  
  /* == I2C == */
  uint8_t i2c_bus_clock_100kHz;		/* UC1601: 1000000000/275 = 37 *100k */

  
  /* == 8 bit interface == */
  
  /* how long to wait after all data line are set */
  uint8_t data_setup_time_ns;		/* UC1601: 30ns */
  /* write enable pulse width */
  uint8_t write_pulse_width_ns;		/* UC1601: 40ns */
  
  /* == layout == */
  uint8_t tile_width;
  uint8_t tile_height;

  uint8_t default_x_offset;		/* default x offset for the display */
  uint8_t flipmode_x_offset;	/* x offset, if flip mode is enabled */
 
 /* pixel width is not used by the u8x8 procedures */
 /* instead it will be used by the u8g2 procedures, because the pixel dimension can */
 /* not always be calculated from the tile_width/_height */
 /* the following conditions must be true: */
 /* pixel_width <= tile_width*8 */
 /* pixel_height <= tile_height*8 */
  uint16_t pixel_width;
  uint16_t pixel_height;
};

uint8_t u8x8_dummy_cb(t_u8x8 *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr);

#endif