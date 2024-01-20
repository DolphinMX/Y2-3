// SID: <Type your student ID here>
// Name: <Type your student name here>
//
// EE 2331 Data Structures and Algorithms,
// Semester B, 2009/10
// Tutorial 8 - Generating Bit Sequence
//

#include <stdio.h>
#include <stdlib.h>

//To generate and print the combination of 2-bit sequence by iteration
void generate2Bits() {
	int i, j;
	for (i = 0; i < 2; i++)
		for (j = 0; j < 2; j++)
			printf("%d%d\n", i, j);
}

//To generate and print the combination of 3-bit sequence by iteration
void generate3Bits() {
	//Task A
	int i, j, k;
	for (i = 0; i < 2; i++)
		for (j = 0; j < 2; j++)
			for (k = 0; k < 2; k++)
				printf("%d%d%d\n", i, j, k);
}

//To generate and print the combination of 4-bit sequence by iteration
void generate4Bits() {
	//Task B
	int i, j, k, l;
	for (i = 0; i < 2; i++)
		for (j = 0; j < 2; j++)
			for (k = 0; k < 2; k++)
				for (l = 0; l < 2; l++)
					printf("%d%d%d%d\n", i, j, k, l);
}

//To generate and print the combination of n-bit sequence by recursion
//parameters:
//	k: the current bit number
//	n: the total number of bits
//	bits: integer array to store the temporary bit pattern
void generateNBits(int k, int n, int bits[]) {
	//Task C
	int i;
	if (k >= n) {					//base case: k == n
		for (i = 0; i < n; i++)
			printf("%d", bits[i]);
		printf("\n");
		return;
	}
	for (i = 0; i < 2; i++) {
		bits[k] = i;
		generateNBits(k+1, n, bits);	//recursion: approaching base case (k+1 => n)
	}
}

int main(int argc, char * argv[]) {
	int n, *bits;

	printf("Enter the number of bit: ");
	scanf("%d", &n);

	switch(n) {
		case 2:
			generate2Bits();
			break;
		case 3:
			generate3Bits();
			break;
		case 4:
			generate4Bits();
			break;
		default:
			if (n > 0) {
				bits = (int *)malloc(sizeof(int) * n);
				if (bits == NULL) {
					printf("Error: cannot allocate memory!\n");
					exit(1);
				}
				generateNBits(0, n, bits);
				free(bits);
			} else {
				printf("Invalid number of n!\n");
			}
	}

	return 0;	//return 0 to operating system upon successful completion of program
}
