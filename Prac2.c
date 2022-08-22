#include<stdio.h>
#include<math.h>

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
		printf("The log2 of the number is %.2f\n", log2f(dec));
		printf("The integer result of the number divided by %d is %d\n", rad, dec/rad);
		printf("The remainder is %d\n", dec%rad);
		
	}

	
    return 0;
}
