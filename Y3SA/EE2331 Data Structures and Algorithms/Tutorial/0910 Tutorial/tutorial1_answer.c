// SID: <Type your student ID here>
// Name: <Type your student name here>
//
// EE 2331 Data Structures and Algorithms,
// Semester B, 2009/10
// Tutorial 1 - Pointers
//

#include <stdio.h>	//required by printf() and scanf()

void task_a() {
	int *p, a, b;
	a = 5;
	p = &a;
	//Task A
	printf("The address of p       = %#p\n", &p);
	printf("The value of p         = %#p\n", p);
	printf("The value pointed by p = %d\n", *p);
	printf("\n");
	printf("The address of a       = %#p\n", &a);
	printf("The value of a         = %d\n", a);
	printf("\n");
	printf("The address of b       = %#p\n", &b);
}

void task_b() {
	int *p;
	int a[] = {6, 2, 4};
	p = a;
	while (p < &(a[3])) {
		//Task B
		printf("The address of p       = %#p\n", &p);
		printf("The value of p         = %#p\n", p);
		printf("The value pointed by p = %d\n", *p);
		printf("\n");
		p++;
	}
}

//Task C
//write your own swap function here
void swap(char *p, char *q) {
	*p ^= *q;
	*q ^= *p;
	*p ^= *q;
}

void reverse(char a[], int len) {
/* unmask this part for task C */
	char *p, *q;
	p = &(a[0]);
	q = &(a[len-1]);
	while (p < q) {
		swap(p++, q--);
	}
}

void print(char a[], int len) {
	int i;
	for (i = 0; i < len; i++)
		printf("%c", *a++);
		// equivalent to
		// printf("%c", a[i]);
	printf("\n");
}

int main() {
	int action;
	char a[] = "abcdefghi";

	printf("Please enter your action ( 1) Task A, 2) Task B, 3) Task C ): ");
	scanf("%d", &action);
	switch(action) {
		case 1:	//Task A
			task_a();
			break;
		case 2:	//Task B
			task_b();
			break;
		case 3: //Task C
			reverse(a, 9);
			print(a, 9);
			break;
		default:
			printf("Invalid input.\n");
	}
	return 0;	//return 0 to operating system upon successful completion of program
}