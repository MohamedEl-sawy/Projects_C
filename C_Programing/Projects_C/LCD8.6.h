
#ifndef _Lcd_H_
#define _Lcd_H_

#define LCD_MODE 4

typedef unsigned char uint8_t;
void print_data_lcd_4bit(uint8_t data);
void print_data_lcd_8bit(uint8_t data);

#define CHAR_LCD_DEBIG

#endif

#ifdef CHAR_LCD_DEBIG
#error " TEST id DEfined"
#endif

