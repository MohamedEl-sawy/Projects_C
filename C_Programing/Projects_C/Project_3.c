#include<stdio.h>
int main()
{
    unsigned int NumberOne1=55;
    unsigned int Reg= 0x00;
    unsigned char NumberOne=1,NumbrtTwo=1,Result=0;

    printf("reg= 0x%X\n",Reg); // 0000 0000
    // Method to set any bit
    Reg = Reg | (1<<0);
    Reg = Reg | (1<<2);
    Reg = Reg | (1<<4);
    printf("Reg=0x%x\n",Reg); //0x00010101 => 0x15
    // Method to clear any bit => 
    Reg =Reg & ~ (1<<4);      
    printf("Reg=0x%x\n",Reg); //0x00000101 => 0x5
    // Method to toggle any bit => changr any bit from 0 to 1 or from 1 to 0.
    Reg = Reg ^ (1<<0);
    Reg = Reg ^ (1<<2);
    printf("Reg=0x%x\n",Reg); //0x00000000 => 0x00
    // Assignment Operetors Print Address Variable in memory
    printf("Address= 0x%X\n", &Reg);
    printf("Addres= %i\n", &Reg);
    // Assignment Opretors Print Value a variable 
    printf("value= %i\n", *(&Reg));

    // Conditional Operator = if condition  
    Result= NumberOne==NumbrtTwo?0x11:0x22;
    printf("Result= 0x%X\n",Result);
    NumberOne=3;
    Result=NumberOne==NumbrtTwo?0x11:0x22;
    printf("Result= 0x%X\n",Result);

    printf("Enter NumberOne1 value : ");
    scanf("%i",&NumberOne1);
    if(55==NumberOne1){
        printf("Yes \n"); // NumberOne1=55
    }
    if(66==NumberOne1){
        printf("No \n"); //NumberOne1=66
    }

    // Casting
    float Number = 3.14;
    printf("Number= %.2f \n",Number);
    printf("Number= %i \n",Number); // Convert to integer
    printf("Number= %i \n",(int) Number);

    
    return 0;
}