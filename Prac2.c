#include<stdio.h>

#define TITLE "DECIMAL TO RADIX-i converter"
#define AUTHOR "Luke Richardson"
#define YEAR 2022

int main(){
    
	printf("*****************************\n");
	printf("%s\n", TITLE);
	printf("Written by: %s\n", AUTHOR);
	printf("Date: %d\n", YEAR);
	printf("*****************************\n");
	
	int dec;
	int rad;
	
	while(1){

		printf("Enter a decimal value: ");
		scanf("%d", &dec);
		if (dec<=0){
			printf("EXIT");
			break;
		}
		printf("The number you have entered is %d\n", dec);
		printf("Enter a radix for the converter between 2 and 16: ");
		scanf("%d", &rad);
		printf("The radix you have entered is %d\n", rad);
		
	}

	
    return 0;
}
