#include <stdio.h>

unsigned int Std_IDS[5]={0x11, 0x22, 0x44, 0x55, 0x66};
unsigned int Std_IDS_V1[5]={0x99};
unsigned int MyArray[]={0x1, 0x2, 0x4, 0x5, 0x6};
unsigned int Summing;

// Methode One Pass Array To Function 
unsigned int StudentIdS [5] = {11 , 22 , 33 , 44 , 55};
void printStdIdsV1 (const unsigned int StudentIdSArray[] , const unsigned int lentgh);
// Methode Two Pass Array To Function
void printStdIdsV2 (const unsigned int StudentIdSArray[5] , const unsigned int lentgh);

char STDName [5][30] = {"Mohamed Fawzy Sawy",
                        "Hamza Fawzy Sawy",
                        "Sara Fawzy SAwy",
                        "Assmaa Fawzy Sawy",
                        "Fawzy Sawy"};
void printSTDName(const unsigned int STDNameArray[][30] , const unsigned int lentgh);


int main ()
{
    printf("Size = %i \n",sizeof(Std_IDS)); // Size of Array 20 Byte

    printf("Value =0x %X \n",Std_IDS[0]);
    printf("Value =0x %X \n",Std_IDS[1]);
    printf("Value =0x %X \n",Std_IDS[2]);
    printf("Value =0x %X \n",Std_IDS[3]);
    printf("Value =0x %X \n",Std_IDS[4]);
    printf("===================================\n");
    Std_IDS_V1[1]=0x14;
    Std_IDS_V1[2]=0x67;
    Std_IDS_V1[3]=0x164;
    Std_IDS_V1[4]=0x190;
    printf("Value =0x %X \n",Std_IDS_V1[0]);
    printf("Value =0x %X \n",Std_IDS_V1[1]);
    printf("Value =0x %X \n",Std_IDS_V1[2]);
    printf("Value =0x %X \n",Std_IDS_V1[3]);
    printf("Value =0x %X \n",Std_IDS_V1[4]);
    printf("===================================\n");
    printf("Value =0x %X \n",MyArray[0]);
    printf("Value =0x %X \n",MyArray[1]);
    printf("Value =0x %X \n",MyArray[2]);
    printf("Value =0x %X \n",MyArray[3]);
    printf("Value =0x %X \n",MyArray[4]);
    //------------------------------
    printf("===================================\n");

    // print All Array Method
    printf("Std_IDS : ");
    for(unsigned int STD_index =0 ; STD_index<5 ; STD_index++)
    {
        printf("0x%X\t",Std_IDS[STD_index]);
    } 
    printf("\n");

    // scanf or change all Array Method
    printf("Please Enter Students Id : ");
    for(unsigned int STD_index =0 ; STD_index<5 ; STD_index++)
    {
        scanf("%i", & Std_IDS[STD_index]);
    }
    
    printf("\n");
    printf("Std_IDS : ");
    for(unsigned int STD_index =0 ; STD_index<5 ; STD_index++)
    {
        printf("0x%X\t",Std_IDS[STD_index]);
    }
    printf("\n");
    // Summig Array Method
    for(unsigned int STD_index =0 ; STD_index<5 ; STD_index++)
    {
        Summing+=Std_IDS[STD_index];
    }
    printf("Summing = %i \n",Summing);
    //-------------------------------
    printf("===================================\n");
    // print Size Array Number of Elemnt in array
    unsigned int My_Array_Size =sizeof(Std_IDS)/sizeof(Std_IDS[0]);
    printf("Size of Array :%i \n",My_Array_Size);
    //---------------------------------
    printf("===================================\n");
    // print 12 becouse array in elemnt 3 and all elemnt 4 byte (3*4)
    unsigned int ArratNumber [] = {1,2,3};
    printf("Size Array Number : %i \n", sizeof(ArratNumber));
    //---------------------------------
    printf("===================================\n");
    char Name1 [8]= "Mohamed";
    char Massage1[10]= "Embedded1";
    char Massage2[10]= "Embedded2";
    char Massage3[6]=  {'E' , 'm' , 'b' , ' ' , '6'};

    // printf("%s \n",Name1);
    // printf("%s \n",Massage1);
    // printf("%s \n",Massage2);
    // printf("%s \n",Massage3);
    // printf("%s \n",Name1);

    printf("%s \n",Massage1);
    // scanf("%s" , Massage1);
    // function to get string any string 
    gets(Massage1);
    printf("%s \n",Massage1);

    unsigned int Number1 [3] [3] = { 1 , 2, 3,
                                     5 , 6 , 7,
                                     7 , 8 , 9 };
    unsigned int index1 =1 , index2 =2;
    printf("Value Array 2D : \n");
    for(index1 =0 ; index1<3 ; index1++)
    {
        for(index2=0; index2<3 ; index2++)
        {
            printf("%i \t" , Number1 [index1] [index2]);
        }
        printf("\n");
    }
    unsigned int Summing2d;
    printf("Value Array 2D : \n");
    for(index1 =0 ; index1<3 ; index1++)
    {
        for(index2=0; index2<3 ; index2++)
        {
            Summing2d+=Number1 [index1] [index2];
        }
        printf("\n");
        printf("%i \t \n " , Number1 [index1] [index2]);
        printf(" Summing2d : %i \n",Summing2d);
    }
    //----------------------------------------------
    printf("===================================\n");

    //Array Pass Function
    // Methode One Pass Array To Function 
    
    printStdIdsV1(StudentIdS,5);
    //----------------------------------------------
    printf("===================================\n");
    printStdIdsV2(StudentIdS,5);
    //----------------------------------------------
    printf("===================================\n");
    printSTDName(STDName , 5);
}
// if Prameter Not Change from user => const..(prameter)
void printStdIdsV1 (const unsigned int StudentIdSArray[] , const unsigned int lentgh)
{
    unsigned int Index =0 ;
    for (Index =0 ; Index <lentgh ; Index++)
    {
        printf("StdIds[%i] = %i\n" ,Index , StudentIdSArray[Index]);
    }
}
// Methode Two Pass Array To Function
void printStdIdsV2 (const unsigned int StudentIdSArray[5] , const unsigned int lentgh)
{
    unsigned int Index =0 ;
    for (Index =0 ; Index <lentgh ; Index++)
    {
        printf("StdIds[%i] = %i\n" ,Index , StudentIdSArray[Index]);
    }
}

void printSTDName(const char int STDNameArray[][30] , const unsigned int lentgh)
{
    unsigned int Index =0 ;
    for (Index =0 ; Index <lentgh ; Index++)
    {
        printf("StdIds[%i] = %i\n" ,Index , StudentIdSArray[Index]);
    }
}