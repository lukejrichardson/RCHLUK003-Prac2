#include<stdio.h>
#include<math.h>

#define TITLE "DECIMAL TO RADIX-i converter"
#define AUTHOR "Luke Richardson"
#define YEAR 2022

void Dec2RadixI (int decValue, int radValue);		// Declare the decimal to radix-i converter function

int main(){
    
	printf("*****************************\n");
	printf("%s\n", TITLE);
	printf("Written by: %s\n", AUTHOR);
	printf("Date: %d\n", YEAR);
	printf("*****************************\n");		// print the title block
	
	int dec;
	int rad;
	
	while(1){				// create an infinite loop that will continuously ask for an integer input until the value entered is less than 1
		
		printf("Enter a decimal value: ");
		scanf("%d", &dec);
		
		if (dec<=0){		// Check for when the value entered is less than 1
			printf("EXIT");
			break;			// Exit the loop
		}
		
		printf("The number you have entered is %d\n", dec);
		printf("Enter a radix for the converter between 2 and 16: ");
		scanf("%d", &rad);
		printf("The radix you have entered is %d\n", rad);
		printf("The log2 of the number is %.2f\n", log2f(dec));
		printf("The integer result of the number divided by %d is %d\n", rad, dec/rad);
		printf("The remainder is %d\n", dec%rad);
		Dec2RadixI(dec, rad);
	}

    return 0;
}

void Dec2RadixI (int decValue, int radValue){		// Define the decimal to radix-i converter function
	
	int remainder = decValue;
	char digit_i;
	
	char MSD_index = floor((log2f(decValue)/(log2f(radValue))));		// calculate index of most significant digit (MSD)
	
	printf("The radix-%d value is ", radValue);
	
	// find the resulting radix-i value using the sum of weights method
	
	for (int i = MSD_index; i >= 0; i--){			// iterate over the digits from the most dignificant digit to the least significant digit
		digit_i = remainder/(int)pow(radValue, i);
		
		if (digit_i<=9) printf("%d", digit_i);
		else printf("%c", digit_i + 55);
		
		remainder = remainder%(int)(round(pow(radValue, i)));
	}
	
	printf("\n");
}
