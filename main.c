#include<stdio.h>
#include<math.h>


/* Defining global variables*/
#define TITLE "DECIMAL TO RADIX-i converter"
#define AUTHOR "Luke Richardson"
#define YEAR 2022


/* Declare the decimal to radix-i converter function */
void Dec2RadixI (int decValue, int radValue);


int main(void){
    
	/********************************************************************************************************************************/
	/* Print the title block and initialise variables */
	
	printf("*****************************\n");
	printf("%s\n", TITLE);
	printf("Written by: %s\n", AUTHOR);
	printf("Date: %d\n", YEAR);
	printf("*****************************\n");
	
	float x, y;
	int rad;
	int dec;
	
	/*******************************************************************************************************************************/
	/* Start an infinite loop that will continuously ask for an integer input and produce outputs until the decimal entered is less than 0. */
	
	while(1){
		printf("Enter a decimal value: ");
		scanf("%f", &x);							// scan in the decimal value.
		
		/***************************************************************************************************************************/
		/* Check for valid inputs and print preliminary calculations */
		
		if ((x - floor(x)) > 0){					// Check if the number entered is an integer, restart the loop if it is not.
			printf("%.2f is ot a valid integer.\n", x);
			continue;
		}

		dec = (int)(x);								// Change the entered decimal value into an integer for further computing.

		if (dec<0){									// Check for when the value entered is less than 0.
			printf("EXIT");
			break;									// Exit the while loop.
		}

		printf("The number you have entered is %d\n", dec);
		printf("Enter a radix for the converter between 2 and 16: ");
		scanf("%f", &y);							// scan in the radix value.

		
		if (((y - floor(y)) > 0)|(y<2)|(y>16)){		// Check if the number entered is an integer and is between 2 and 16, restart the loop if it is not.
			printf("%.2f is not a valid radix.\n", y);
			continue;
		}

		rad = (int)(y);								// change the entered radix value into an integer for furhter computing.
		
		printf("The radix you have entered is %d\n", rad);
		printf("The log2 of the number is %.2f\n", log2f(dec));
		printf("The integer result of the number divided by %d is %d\n", rad, dec/rad);
		printf("The remainder is %d\n", dec%rad);

		Dec2RadixI(dec, rad);						// convert the decimal value to the specified radix.
	}
    return 0;
}


/***********************************************************************************************************************************/
/* Define the decimal to radix-i converter function */
void Dec2RadixI (int decValue, int radValue){
	
	/* Initialise variables */
	
	int remainder = decValue;						// initialise the remainder value to the decimal value.
	char digit_i;									// initialise the digit variable that will be printed.
	
	char MSD_index = floor((log2(decValue)/(log2(radValue))));		// calculate index of most significant digit (MSD)
	
	printf("The radix-%d value is ", radValue);
	
	/*******************************************************************************************************************************/
	/* print the resulting radix-i value using the sum of weights method*/
	
	for (int i = MSD_index; i >= 0; i--){			// iterate over the digits from the most significant digit to the least significant digit
		
		digit_i = remainder/(pow(radValue, i));		// find the value of the i-th digit
		
		if (digit_i<=9) printf("%d", digit_i);		// if the digit is less than 10, print the digit to the output stream.
		else printf("%c", digit_i + 55);			// if the digit is greater than 9, prints its corresponding ASCII character.
		
		remainder = remainder%((int)(floor(pow(radValue, i))));		// update the remainder variable
	}
	
	printf("\n");
}
