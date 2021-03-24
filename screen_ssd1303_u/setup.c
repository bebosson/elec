#include "main.h"



void u8x8_SetupDefaults(t_u8x8 *u8x8)
{
    u8x8->display_info = NULL;
    u8x8->display_cb = u8x8_dummy_cb;
    u8x8->cad_cb = u8x8_dummy_cb;
    u8x8->byte_cb = u8x8_dummy_cb;
    u8x8->gpio_and_delay_cb = u8x8_dummy_cb;
    u8x8->is_font_inverse_mode = 0;
    //u8x8->device_address = 0;
    u8x8->utf8_state = 0;		/* also reset by u8x8_utf8_init */
    u8x8->bus_clock = 0;		/* issue 769 */
    u8x8->i2c_address = 255;
    u8x8->debounce_default_pin_state = 255;	/* assume all low active buttons */
  
#ifdef U8X8_USE_PINS 
  {
    uint8_t i;
    for( i = 0; i < U8X8_PIN_CNT; i++ )
      u8x8->pins[i] = U8X8_PIN_NONE;
  }
#endif
}

void u8x8_Setup(t_u8x8 *u8x8, u8x8_msg_cb display_cb, u8x8_msg_cb cad_cb, u8x8_msg_cb byte_cb, u8x8_msg_cb gpio_and_delay_cb)
{
  /* setup defaults and reset pins to U8X8_PIN_NONE */
  u8x8_SetupDefaults(u8x8);

  /* setup specific callbacks */
  u8x8->display_cb = display_cb;
  u8x8->cad_cb = cad_cb;
  u8x8->byte_cb = byte_cb;
  u8x8->gpio_and_delay_cb = gpio_and_delay_cb;

  /* setup display info */
  u8x8->display_cb(u8x8, U8X8_MSG_DISPLAY_SETUP_MEMORY, 0, NULL);
}