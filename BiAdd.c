/*Yiqing Zhang*/
/*Cse2421*/

#include<stdio.h>
int main()
{
	int n1, n2, sum;

	printf("give 2 integers in hex to add: ");
	scanf(" %x %x", &n1, &n2);
	/* printf("0x%08X", a)
		0: left-pads the number with zeroes instead of spaces
		8: width: min number of characters to be printed. The value is not truncated even if the result is larger
		x: specifier for hex integer
			x: print hex with lower-case letters
			X: print hex with upper-case letters
	*/
	printf("First = 0x%08X As unsigned = %u As signed = ", n1, n1);
	//if n1 is a positive integer, print the positive sign
	/*printf will print negative integers with a negative sign*/
	if((n1 & (1 << 31)) == 0){	
		printf("+");
	}
	printf("%d", n1);
	printf("\nFirst = 0x%08X As unsigned = %u As signed = ", n2, n2);
	//if n2 is a positive integer, print the positive sign
	/*printf will print negative integers with a negative sign*/
	if((n2 & (1 << 31)) == 0){	
		printf("+");
	}
	printf("%d", n2);
	sum = BinaryAdd(n1, n2);
	return 0;
}

int BinaryAdd(int in1, int in2){
	//sum is the binary digit for the result	
	int i, carryin = 0, sum = 0, result = 0, a = 0, b = 0;
	//initialized mask to get the value of the least significant bit
	int mask = 1;
	for (i = 0; i < 32; i++){
		// get the ith least significant bits of n1 and n2		
		a = (in1 >> i) & mask; // n1 will not change 
		b = (in2 >> i) & mask;
		// different situations for a and b
		if(a == 1 && b ==1){
			//a = 1, b = 1, and carryin = 1, then sum = 1, carryin = 1
			if(carryin == 1){
				sum = 1;			
			}
			//a = 1, b = 1, and carryin = 0, then sum = 0, carryin = 1
			else{
				sum = 0;
				carryin = 1;
			}
		}
		// one of a and b is 0
		else if (((a == 1) && (b == 0)) || ((a == 0) && (b == 1))){
			// carryin = 1, then sum = 0 and carryin = 1			
			if(carryin == 1){
				sum = 0;
			}
			// carryin = 0, then sum = 1 and carryin = 0
			else{
				sum = 1;
			}
		}
		else{
			// if a = 0, b = 0
			if(carryin == 1){
				sum = 1;
				carryin = 0;
			}
			else{
				sum = 0;
			}
		}
		//make the ith least significant digit of result as ith sum 
		result = result | (sum << i);

	}
	printf("\nSum = 0x%08X As unsigned = %u As signed = ", result, result);
	//print the positive sign if result is poaitive (printf will print negative integers with a negative sign)
	if((result & (1 << 31)) == 0){	
		printf("+");
	}
	printf("%d", result);
	//if the final carryout if 1, then the result does not fit 32 bits - unsigned overflow	
	if(carryin == 1){
		printf("\nUnsigned overflow\n");
	}
	//if the MSB of result is 1 and MSB of n1 and n2 are 0, or final carryout is 0 and MSB of n1 and n2 is 1	
	if(((sum == 1 && a == 0 && b == 0) || (sum == 0 && a == 1 && b == 1))){
		printf("\nSigned overflow\n");
	}
	return result;
}


	
			
			
				

	
	
	
