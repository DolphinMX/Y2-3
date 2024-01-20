// SID: <Type your student ID here>
// Name: <Type your student name here>
//
// EE 2331 Data Structures and Algorithms,
// Semester B, 2009/10
// Tutorial 9 - Binary Trees
//

#include <stdio.h>
#include <stdlib.h>		//required by malloc() and free()

#define MAX_TREE_SIZE 64
#define INVALID '.'

typedef char TreeElement;

//define the C structure 'Tree'
typedef struct _tree {
	TreeElement data[MAX_TREE_SIZE];
} Tree;

//To initialize the tree to empty tree
void Tree_init(Tree *t) {
	int i;
	for (i = 0; i < MAX_TREE_SIZE; i++)
		t->data[i] = INVALID;
}

//To destroy the tree content, and reset back to empty tree
void Tree_destroy(Tree *t) {
	int i;
	for (i = 0; i < MAX_TREE_SIZE; i++)
		t->data[i] = INVALID;
}

int countNodesWithDegree2(TreeElement data[], int index) {
	//Task A
	int left, right, degree = 0;
	//base case
	if (index >= MAX_TREE_SIZE || index < 0 || data[index] == INVALID) return 0;
	//general case
	left = 2*index + 1;
	right = left + 1;
	if (left < MAX_TREE_SIZE && data[left] != INVALID) degree++;
	if (right < MAX_TREE_SIZE && data[right] != INVALID) degree++;
	return(countNodesWithDegree2(data, left) + countNodesWithDegree2(data, right) + (degree == 2));
}

int countNodesWithDegree1(TreeElement data[], int index) {
	//Task B
	int left, right, degree = 0;
	//base case
	if (index >= MAX_TREE_SIZE || index < 0 || data[index] == INVALID) return 0;
	//general case
	left = 2*index + 1;
	right = left + 1;
	if (left < MAX_TREE_SIZE && data[left] != INVALID) degree++;
	if (right < MAX_TREE_SIZE && data[right] != INVALID) degree++;
	return(countNodesWithDegree1(data, left) + countNodesWithDegree1(data, right) + (degree == 1));
}

int countNodesWithDegree0(TreeElement data[], int index) {
	//Task C
	int left, right, degree = 0;
	//base case
	if (index >= MAX_TREE_SIZE || index < 0 || data[index] == INVALID) return 0;
	//general case
	left = 2*index + 1;
	right = left + 1;
	if (left < MAX_TREE_SIZE && data[left] != INVALID) degree++;
	if (right < MAX_TREE_SIZE && data[right] != INVALID) degree++;
	return(countNodesWithDegree0(data, left) + countNodesWithDegree0(data, right) + (degree == 0));
}

int main(int argc, char * argv[]) {
	FILE *fp;
	char filename[64];
	int i;
	char c;
	Tree t;
	int n2, n1, n0;

	Tree_init(&t);
	printf("Enter the file name for testing: ");
	scanf("%s", filename);
	fp = fopen(filename, "rt");
	if (fp == NULL) {
		printf("Error: file open error\n");
		return 1;	//to indicate different error to OS
	}

	printf("The array tree is: [");
	i = 0;
	while (i < MAX_TREE_SIZE && (c = getc(fp)) != '\n' && c != EOF) {
		t.data[i++] = c;
		printf("%c", c);
	}
	fclose(fp);

	printf("]\n");
	printf("\n");

	n2 = countNodesWithDegree2(t.data, 0);
	n1 = countNodesWithDegree1(t.data, 0);
	n0 = countNodesWithDegree0(t.data, 0);
	printf("The number of nodes with degree 2 = %d\n", n2);
	printf("The number of nodes with degree 1 = %d\n", n1);
	printf("The number of nodes with degree 0 = %d\n", n0);
	if (n0 == n2 + 1)
		printf("\"n0 = n2 + 1\" is correct!\n");
	else
		printf("\"n0 = n2 + 1\" is wrong!\n");
	Tree_destroy(&t);
	return 0;	//return 0 to operating system upon successful completion of program
}
