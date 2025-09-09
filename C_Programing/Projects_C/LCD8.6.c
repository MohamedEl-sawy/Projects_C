#include <stdio.h>
#include "LCD8.6.h"
#include "LCD8.6.h"
#include "LCD8.6.h"

static void print_data_lcd_4bit(uint8_t data)
{
    printf("lcd_4bit_data =%c \n",data);
}
static void print_data_lcd_8bit(uint8_t data)
{
    printf("lcd_8bit_data =%c \n",data);
}
void lcd_print_data(uint8_t data)
{
    #if LCD_MODE==4
    #ifdef CHAR_LCD_DEBIG
    printf("Callinr Fun : print_data_lcd_4bit \n");
    #endif
    print_data_lcd_4bit(data);
    #elif LCD_MODE==8
    print_data_lcd_8bit(data);
    #endif
}