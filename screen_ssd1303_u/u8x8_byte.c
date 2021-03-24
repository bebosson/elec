#include "main.h"

#define U8X8_MSG_BYTE_INIT U8X8_MSG_CAD_INIT
#define U8X8_MSG_BYTE_SET_DC 32

#define U8X8_MSG_BYTE_SEND U8X8_MSG_CAD_SEND_DATA

#define U8X8_MSG_BYTE_START_TRANSFER U8X8_MSG_CAD_START_TRANSFER
#define U8X8_MSG_BYTE_END_TRANSFER U8X8_MSG_CAD_END_TRANSFER




uint8_t u8x8_byte_SetDC(t_u8x8 *u8x8, uint8_t dc)
{
  return u8x8->byte_cb(u8x8, U8X8_MSG_BYTE_SET_DC, dc, NULL);
}

uint8_t u8x8_byte_SendBytes(t_u8x8 *u8x8, uint8_t cnt, uint8_t *data)
{
  return u8x8->byte_cb(u8x8, U8X8_MSG_BYTE_SEND, cnt, (void *)data);
}

uint8_t u8x8_byte_SendByte(t_u8x8 *u8x8, uint8_t byte)
{
  return u8x8_byte_SendBytes(u8x8, 1, &byte);
}

uint8_t u8x8_byte_StartTransfer(t_u8x8 *u8x8)
{
  return u8x8->byte_cb(u8x8, U8X8_MSG_BYTE_START_TRANSFER, 0, NULL);
}

uint8_t u8x8_byte_EndTransfer(t_u8x8 *u8x8)
{
  return u8x8->byte_cb(u8x8, U8X8_MSG_BYTE_END_TRANSFER, 0, NULL);
}