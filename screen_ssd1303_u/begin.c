#include "main.h"

#define U8X8_MSG_DISPLAY_SET_POWER_SAVE 11
#define U8X8_MSG_DISPLAY_INIT 10
#define U8X8_MSG_DISPLAY_DRAW_TILE 15


uint8_t u8x8_dummy_cb(t_u8x8 *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr)
{
  /* the dummy callback will not handle any message and will fail for all messages */
  return 0;
}

void u8x8_InitDisplay(t_u8x8 *u8x8)
{
  u8x8->display_cb(u8x8, U8X8_MSG_DISPLAY_INIT, 0, NULL);  
}

void u8x8_SetPowerSave(t_u8x8 *u8x8, uint8_t is_enable)
{
  u8x8->display_cb(u8x8, U8X8_MSG_DISPLAY_SET_POWER_SAVE, 0, NULL);
}

void u8x8_ClearDisplayWithTile(t_u8x8 *u8x8, const uint8_t *buf)
{
  u8x8_tile_t tile;
  uint8_t h;

  tile.x_pos = 0;
  tile.cnt = 1;
  tile.tile_ptr = (uint8_t *)buf;		/* tile_ptr should be const, but isn't */
  
  h = u8x8->display_info->tile_height;
  tile.y_pos = 0;
  do
  {
    u8x8->display_cb(u8x8, U8X8_MSG_DISPLAY_DRAW_TILE, u8x8->display_info->tile_width, (void *)&tile);
    tile.y_pos++;
  } while( tile.y_pos < h );
}


void u8x8_ClearDisplay(t_u8x8 *u8x8)
{
  uint8_t buf[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
  u8x8_ClearDisplayWithTile(u8x8, buf);
}
/*
void initDisplay(void) 
{
    u8x8_InitDisplay(&u8x8); 
}
  */    
void clearDisplay(t_u8x8 *u8x8) 
{
    u8x8_ClearDisplay(&u8x8); 
}
/*
void setPowerSave(uint8_t is_enable) 
{
    u8x8_SetPowerSave(&u8x8, is_enable); 
}
*/


t_u8x8 *begin(void) 
{
  t_u8x8 *u8x8;
    u8x8->display_cb(u8x8, U8X8_MSG_DISPLAY_INIT, 0, NULL);
    clearDisplay(u8x8); 
    u8x8->display_cb(u8x8, U8X8_MSG_DISPLAY_SET_POWER_SAVE, 0, NULL);  
    return u8x8;
}