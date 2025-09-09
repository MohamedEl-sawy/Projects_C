#include <stdio.h>
unsigned char Btn_State = 0x00; // 0000 0000 
unsigned char Btn1_State= 0;  
unsigned char Btn2_State= 0;  
unsigned char Btn3_State= 0;  
int main()
{
	printf("Please rnter BTN1 State :");
	scanf("%i",&Btn1_State);

	if(1==Btn1_State){
		printf("Btn State Is High \n");
		Btn_State=Btn_State|0b0000001;
		printf("Btn_State = 0x%X\n",Btn_State);
	}
	else if (0==Btn1_State){
		printf("Btn State Is Low \n");

	}
	else{
		printf("Invalid State !!\n\n");
	}


		printf("Please rnter Btn2_State :");
	scanf("%i",&Btn2_State);

	if(1==Btn2_State){
		printf("Btn State Is High \n");
		Btn_State=Btn_State|0b0000010;
		printf("Btn_State = 0x%X\n",Btn_State);
	}
	else if (0==Btn2_State){
		printf("Btn State Is Low \n");

	}
	else{
		printf("Invalid State !!\n\n");
	}

	printf("Please inter Btn3 State : ");
	scanf("%i",&Btn3_State);

	if(1==Btn3_State){
		printf("Btn State Is High");
		Btn_State=Btn_State | 0b00000100;
		printf("Btn State = 0x%X\n",Btn_State);
	}
	else if (0==Btn3_State){
		printf("Btn State Is Low");
	}
	else{
		printf("Invalid State !! \n\n");
	}


} 