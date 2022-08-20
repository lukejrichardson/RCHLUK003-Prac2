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
	
	printf("Enter a decimal value: ");
	scanf("%d", &dec);
	printf("The number you have entered is %d", dec);
	
    return 0;
}
