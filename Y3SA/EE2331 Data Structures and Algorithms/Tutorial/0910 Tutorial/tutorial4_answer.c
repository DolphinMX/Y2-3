// SID: <Type your student ID here>
// Name: <Type your student name here>
//
// EE 2331 Data Structures and Algorithms,
// Semester B, 2009/10
// Tutorial 4 - Maximal Sublist of a Linked List
//

#include <stdio.h>
#include <stdlib.h>		//required by malloc() and free()

//define the C structure '_node' for linked list
struct _node {
	int data;
	struct _node *next;
};

//rename the C structure 'struct _node' to 'Node'
typedef struct _node Node;

//To print out the content of a circular linked list
//Preconditions: the list has dummy header and the list is circular linked list
//Postcondition: the content of the linked list has been printed to console
void printout_circular(Node *head) {
	Node *p;
	printf("Dummy -> ");
	p = head->next;
	while (p != head) {
		printf("%d -> ", p->data);
		p = p->next;
	}
	printf("Dummy\n");
}

//To print out the content of the sublist of linked list
//Precondition: the 'start' and 'end' pointers are valid
//Postcondition: the content in between the 'start' and 'end' of the linked list has been printed to console
void printout_sublist(Node *start, Node *end) {
	Node *p = start;
	while (p != end) {
		printf("%d -> ", p->data);
		p = p->next;
	}
	printf("%d\n", p->data);
}

//To test if the linked list pointed by head is empty or not
//Output: return 1 if the list is empty, otherwise 0.
//Precondition: 'head' is the head of the linked list and the list has dummy header
int is_empty(Node *head) {
	return (head->next == NULL);
}

//To create a node with data field equals node_data
//Precondition: none
//Postcondition: p has been initialized properly. Its 'data' equals 'node_data' and 'next' equals NULL.
Node* create_node(int node_data) {
	Node *p;

	p = (Node*)malloc(sizeof(Node));
	if (p == NULL) {
		printf("Error: cannot allocate memory!\n");
		exit(1);
	}

	p->data = node_data;
	p->next = NULL;
	return p;
}

//To delete and release the memory of the whole linked list pointed by 'p'
//Precondition: the list is a circular linked list
//Postcondition: the memory pointed by 'p' and its all successors have been released
void free_nodes_circular(Node *p) {
	//Task C
	Node *m, *head;
	head = p;
	while (p != head) {
		m = p;
		p = p->next;
		free(m);
	}
}

//To find the largest sublist of integers, and return the value of the sublist
//Note that the sequence may contain negative values.
//Preconditions: 'head' points to the dummy head of a circular linked list, and the list is non-empty
int find_max_sublist(Node *head) {
	//Task A
	int sum, max;
	Node *p, *m;

	p = head->next;
	max = p->data;	//max is undefined if the list is empty list
	
	while (p != head) {
		sum = 0;
		m = p;
		while (m != head) {
			sum += m->data;
			if (sum > max)
				max = sum;
			m = m->next;
		}
		p = p->next;
	}
	return max;
}

//To find the largest sublist of integers, and return the value of the sublist
//Also determine the start and end pointers of the maximal sublist
//'start' is the pointer of the first node of the maximal sublist
//'end' is the pointer of the last node of the maximal sublist
//Note that the sequence may contain negative values.
//Preconditions: 'head' points to the dummy head of a circular linked list, and the list is non-empty
int find_max_sublist2(Node *head, Node **start, Node **end) {
	//Task B
	int sum, max;
	Node *p, *m;

	p = head->next;
	max = p->data;	//max is undefined if the list is empty list
	*start = p;
	*end = p;
	
	while (p != head) {
		sum = 0;
		m = p;
		while (m != head) {
			sum += m->data;
			if (sum > max) {
				max = sum;
				*start = p;
				*end = m;
			}
			m = m->next;
		}
		p = p->next;
	}
	return max;
}

int main() {
	FILE *fp;
	char filename[20];
	Node *head, *p, *start, *end;
	int i, n, node_data, max_value, action;


	printf("Enter the file name for testing: ");
	scanf("%s", filename);

	fp = fopen(filename, "rt");
	if (fp == NULL) {
		printf("Error: file open error\n");
		return 1;	//to indicate different error to OS
	}

	head = create_node(-1);	//create a dummy header first
	p = head;
	
	//read in the sequence from a data file
	fscanf(fp, "%d", &n);
	for (i = 0; i < n; i++) {
		fscanf(fp, "%d", &node_data);
		p->next = create_node(node_data);
		p = p->next;
	}
	p->next = head;	//point back to the dummy header since it is a circular linked list
	fclose(fp);	//close the file when finished reading it
	
	printf("The linked list is : ");
	printout_circular(head);
	
	printf("Please enter your action ( 1) task a, 2) task b ): ");
	scanf("%d", &action);
	printf("\n");
	
	switch(action) {
		case 1:
			//Task A
			max_value = find_max_sublist(head);
			printf("The maximal sublist value = %d\n", max_value);
			printf("The final linked list is : ");
			printout_circular(head);
			break;
		case 2:
			//Task B
			max_value = find_max_sublist2(head, &start, &end);
			printf("The maximal sublist = ");
			printout_sublist(start, end);
			printf("The maximal sublist value = %d\n", max_value);
			printf("The final linked list is : ");
			printout_circular(head);
			break;
		default:
			printf("Invalid input.\n");
	}
	//Task C
	free_nodes_circular(head);
	return 0;
}

