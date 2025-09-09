#include<stdio.h>


unsigned int GetSuming(unsigned int Number1,unsigned int Number2);

int main()
{
    unsigned ErrorSate=0;
    ErrorSate=GetSuming(4,1);
    ErrorSate|=GetSuming(2,7);
    ErrorSate|=GetSuming(1,3);
    ErrorSate|=GetSuming(1,8);
    ErrorSate|=GetSuming(1,1);
    printf("Error State = %i\n",ErrorSate);

    return 0;
}

unsigned int GetSuming(unsigned int Number1,unsigned int Number2)
{
    unsigned ErrorSate=0;
    if(Number1>5 || Number2>5)
    {
        ErrorSate =1;
        
    }
    else
    {
        printf("Suming = %i\n",(Number1 + Number2));
    }

    return ErrorSate;
}
