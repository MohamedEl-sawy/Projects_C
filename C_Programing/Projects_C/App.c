#include <stdio.h>

#include "App.h"
unsigned int  my_arr[10]={12,12,3,43,65,56,676,0,4,3};
void change_arrey_value( unsigned int arr[], unsigned int index, unsigned int value)
{
    if(index > ARRY_MAX_SIZE-1)
    {
        printf("Error out of index \n");
    }
    else 
    {
        arr[index]= value;
        printf("Done \n");
    }
}

void print_embedded_diploma(void)
{
    printf("Hello Embedded diploma \n");
    change_arrey_value(my_arr, 6, 789);
}

unsigned int Summing (unsigned int N1, unsigned int n2)
{
    return N1+n2;
}
int main()
{
    
    print_embedded_diploma();
    printf("==============\n");
    unsigned int var =2*EXP;
    printf("var =%i\n",var);
    printf("==============\n");

    unsigned int Test_Value= TEST;
    // char name = MyName;
    printf("Summing = %i\n",SUMMING (2,3)); // remove Sumint and submit (2+3)
    printf("Summing = %i\n",Summing(2,3)); // this is function Normaly
    printf("==============\n");
    unsigned int x=2 ,y=3;
    printf("x= %i \t y=%i\n",x,y);
    SWAAP(&x, &y)
    printf("x= %i \t y=%i\n",x,y);
    SWAAP(&x, &y)
    printf("x= %i \t y=%i\n",x,y);
    SWAAP(&x, &y)
    printf("x= %i \t y=%i\n",x,y);

    //-------------------------------------

    unsigned int value =0x01; // 0000 0001
    printf("==============\n");
    // printf("Value =%i \n",value); //1
    // // value =value | (1 << 1);
    // printf("Value =%i \n",value); // 3  0000 0011
    printf("==============\n");
    printf("Value =%i \n",value);
    SET_BIT(value,1);
    printf("Value =%i \n",value);
    CLER_BIT(value,1);
    printf("Value =%i \n",value);
    TOGLE_BIT(value,1);
    printf("Value =%i \n",value);
    
    
    printf("==============\n");

    printf("SQ= %i \n",SQUARE1(2+1));
    printf("SQ= %i \n",SQUARE2(2+1));
    printf("SQ= %i \n",SQUARE3(2+1));
    printf("SQ= %i \n",SQUARE4(2+1));

    printf("==============\n");

    printf("%c - %i - %s \n " ,__FILE__, __LINE__ , __DATE__ );
    
    #line 33 "Application.c"
    printf("%c - %i - %s \n " ,"App.c", 77 , "Oct 17 2023" );
    printf("%c - %i - %s \n " ,"App.c", 77 , "Oct 17 2023" );

    printf("==============\n");
    
    printf("Hi " " , i am ahmed \n");

    PrintName("Mohamed " , "Fawzy");

    unsigned int nummber;
    nummber =nummber+2;
    printf(" NUMMber = %i ", nummber);

    } 