#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//i didnt understand the "One of the parts is clearly not effective. What can you put here to remove the unnecessary code?" part, so i couldnt do that, but ive done all
int main() 
{

	int Number,Quotient,Remainder,Digit1,Digit2,Digit3,Digit4,Digit5;
	
	printf("Please enter a 5-digit number: \n");
	scanf("%d",&Number);
	
	//for 5. digit
	Quotient=Number/10000;
	Digit1=Quotient;
	Remainder= Number % 10000;
	
	//for 4. digit
	Quotient=Remainder/1000;
	Digit2=Quotient;
	Remainder= Remainder % 1000;
	
	//for 3. digit
	Quotient=Remainder/100;
	Digit3=Quotient;
	Remainder= Remainder % 100;
	
	//for 2. digit
	Quotient=Remainder/10;
	Digit4=Quotient;
	Remainder= Remainder % 10;
	
    //for 1. digit
    Digit5= Remainder;
	printf("\nFirst digit is: %d\nSecond digit is: %d\nThird digit is: %d\nFourth digit is: %d\nFifth digit is: %d",Digit5,Digit4,Digit3,Digit2,Digit1);
		return 0;


}
