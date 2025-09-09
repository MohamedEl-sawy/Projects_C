#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

unsigned char Pass[5]={'h' , 'a', 's' , 'n' , 'a'};
unsigned char UserPass[5];
unsigned int passFlag=0;
unsigned int Trails=0;
int main()
{
    unsigned int UserPassIndex = 0;
    while(Trails<3)
    {
        printf("Please inter pass : ");
        for(UserPassIndex = 0 ; UserPassIndex <5 ; UserPassIndex++)
        {
            scanf("%c" ,& UserPass[UserPassIndex]);
        }
        printf("Please wait ");
        for(UserPassIndex = 0 ; UserPassIndex <15 ; UserPassIndex++)
        {
            printf(".");
            Sleep(20);
        }
        printf("\n");
        for(UserPassIndex = 0 ; UserPassIndex <5 ; UserPassIndex++)
        {
            if(UserPass[UserPassIndex] != Pass[UserPassIndex])
            {
                passFlag=1;
                break;
            }
        }
        if (1== passFlag)
        {
            Trails++;
            printf("Invalid Pass !!! \n");
            printf("Please Enter Your Pass Again \n");
        }
        else
        {
            printf("Welcome \n");
            break;
        }
    }


    return 0;
}