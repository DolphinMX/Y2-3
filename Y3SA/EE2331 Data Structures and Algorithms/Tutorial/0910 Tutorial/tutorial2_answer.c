// SID: <Type your student ID here>
// Name: <Type your student name here>
//
// EE 2331 Data Structures and Algorithms,
// Semester B, 2009/10
// Tutorial 2 - Matrix
//

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10	//constraint: the maximum size of the matrix is 10 x 10

struct _matrix {
  float element[MAXSIZE][MAXSIZE];
  int row;
  int col;
};

typedef struct _matrix Matrix;

//To print out the content of the matrix m (pass-by-reference)
//Precondition: m (and its row & col) has been initialized
void printout(Matrix *m) {
	int i, j;

	for (i = 0; i < m->row; i++) {
		for (j = 0; j < m->col; j++)
			printf("%6.2f ", m->element[i][j]);
		printf("\n");
	} 
	printf("\n");
}

//To print out the content of the matrix m (pass-by-value)
//Precondition: m (and its row & col) has been initialized
void printout2(Matrix m) {
	//Task C
	int i, j;

	for (i = 0; i < m.row; i++) {
		for (j = 0; j < m.col; j++)
			printf("%6.2f ", m.element[i][j]);
		printf("\n");
	} 
	printf("\n");
}

//To perform matrix addition S = A + B
//Precondition: A, B have been initialized
//Postcondition: return 1 for successful addition, return 0 for any error occurs in the function
int add(Matrix *A, Matrix *B, Matrix *S) {
	//Task A
    int i, j;

	if ((A->row != B->row) || (A->col != B->col))
		return 0;	//return 0 means an error has occurred in this function

	for (i = 0; i < A->row; i++)
		for (j = 0; j < A->col; j++)
			S->element[i][j] = A->element[i][j] + B->element[i][j];
	//To set the row & col of matrix S
	S->row = A->row;	//or S->row = B->row;
	S->col = A->col;	//or S->rol = B->rol;
	return 1;	//successful addition
}    

//To perform matrix multiplication P = A x B
//Precondition: A, B have been initialized
//Postcondition: return 1 for successful multiplication, return 0 for any error occurs in the function
int multiply(Matrix *A, Matrix *B, Matrix *P) {
	//Task B
    int i, j, k;

	if (A->col != B->row) return 0;	//return 0 means an error has occurred in this function

	P->row = A->row;
	P->col = B->col;
	for (i = 0; i < P->row; i++)
		for (j = 0; j < P->col; j++) {
			P->element[i][j] = 0;
			for (k = 0; k < A->col; k++)
				P->element[i][j] += A->element[i][k] * B->element[k][j];
		}
	return 1;	//successful multiplication
}    

int main() {
	FILE *fp;
	char filename[20];
	Matrix A, B, S, P;
	int i, j, success;
	int action;

	printf("Enter the file name for testing: ");
	scanf("%s", filename);
	fp = fopen(filename, "rt");
	if (fp == NULL) {
		printf("Error: file open error\n");
		exit(1);	//to indicate different error to OS
	}

	//read in matrix A
	fscanf(fp, "%d %d", &A.row, &A.col);
    for (i = 0; i < A.row; i++)
		for (j = 0; j < A.col; j++)
			fscanf(fp, "%f", &A.element[i][j]);
	
	//read in matrix B
	fscanf(fp, "%d %d", &B.row, &B.col);
    for (i = 0; i < B.row; i++)
		for (j = 0; j < B.col; j++)
			fscanf(fp, "%f", &B.element[i][j]);
  
	fclose(fp);
	
	if ((A.row > MAXSIZE) || (A.col > MAXSIZE) || (B.row > MAXSIZE) || (B.col > MAXSIZE)) {
		printf("Error: dimension exceed the maximum size!\n");
		exit(2);	//to indicate different error to OS
	}

	printf("Please enter your action ( 1) Task A, 2) Task B, 3) Task C ): ");
	scanf("%d", &action);
	switch (action) {
		case 1:	//Task A
			printf("Matrix A is :\n");
			printout(&A);
			printf("Matrix B is :\n");
			printout(&B);
			
			success = add(&A, &B, &S);
			if (success) {
				printf("The sum is: \n");
				printout(&S);
			} else {
				printf("Cannot perform addition. Error in dimension!\n\n");
			}

			break;
		case 2:	//Task B
			printf("Matrix A is :\n");
			printout(&A);
			printf("Matrix B is :\n");
			printout(&B);

			success = multiply(&A, &B, &P);
			if (success) {
				printf("The product is: \n");
				printout(&P);
			} else {
				printf("Cannot perform multiplication. Error in dimension!\n\n");
			}
			
			break;
		case 3: //Task C
			printf("Matrix A is :\n");
			printout2(A);
			printf("Matrix B is :\n");
			printout2(B);
			break;
		default:
			printf("Invalid input.\n");
	}

	return 0;	//return 0 to operating system upon successful completion of program
}