// SID: <Type your student ID here>
// Name: <Type your student name here>
//
// EE 2331 Data Structures and Algorithms,
// Semester B, 2009/10
// Tutorial 7 - Linked Lists Reversion
//

#include <stdio.h>
#include <stdlib.h>		//required by malloc() and free()

//define the C structure 'Node' for linked lists
typedef struct _node {
	int data;
	struct _node *next;
} Node;

//To print the content of linked list
//Precondition: 'head' is the head of linear linked list with dummy header
//Postcondition: the content of the linked list has been printed to the console
void printout(Node *head) {
	Node *p = head;
	while (p != NULL) {
		printf("[%d] -> ", p->data);
		p = p->next;
	}
	printf("NULL\n");
}

//To create a node with data field initialize to node_data
//Precondition: none
//Postcondition: p has been initialized. Its data equals value node_data and next equals to NULL.
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

//To delete and release the memory of the linked list pointed by 'node'
//Precondition: none
//Postcondition: the memory pointed by 'node' and its successors have been released
void free_nodes(Node *node) {
	Node *p;

	while (node != NULL) {
		p = node;
		node = node->next;
		free(p);
	}
}  

//To reverse the linked list by recursion
//The function should return the tail pointer
//Postcondition: the sub list starting from p to the end has been reversed
Node * reverse_by_recur(Node *p) {
	//Task A
	//the linked list at the beginning:
	// [p] -> [f -> ... -> r] -> NULL
	//
	//call recursion:
	// [r -> ... -> f] (the sub list starting from f to r has been reversed in recursion)
	//
	//the resultant linked list:
	// [r -> ... -> f] -> [p] -> NULL
	
	Node *f, *r;
	if (p == NULL) return NULL;		//error case: p is NULL ptr

	if (p->next == NULL) return p;	//base case: p is the last node

	f = p->next;					//general case: p is not the last node
	r = reverse_by_recur(f);
	f->next = p;
	p->next = NULL;
	return r;
}

//To reverse the linked list (with 2 nodes as a group) by recursion
//The function should return the tail pointer
//Postcondition: the sub list starting from p to the end has been reversed
Node * reverse_group_by_recur(Node *p) {
	//Task B
	//the linked list at the beginning:
	// [p -> p2] -> [f1 -> f2 -> ... -> r] -> NULL
	//
	//call recursion:
	// [r -> ... -> f1 -> f2] (the sub list starting from f to r has been reversed in recursion)
	//
	//the resultant linked list:
	// [r -> ... -> f1 -> f2] -> [p -> p2] -> NULL
	
	Node *p2, *f1, *f2, *r;
	if (p == NULL) return NULL;		//error case: p is NULL ptr

	if (p->next == NULL) return p;	//base case: p is the last node
	p2 = p->next;
	if (p2->next == NULL) return p;	//base case: p2 is the last node (also return p)

	f1 = p2->next;					//general case: p, p2 are not the last node
	f2 = f1->next;
	r = reverse_group_by_recur(f1);
	if (f2 == NULL)
		f1->next = p;
	else
		f2->next = p;
	p2->next = NULL;
	return r;
}

int main() {
	int i, n, action;
	Node *head, *p;

	printf("Enter the number of nodes: ");
	scanf("%d", &n);
	if (n < 0) {
		printf("Error: n cannot be a negative integer\n");
		exit(2);
	}

	head = NULL;							//no dummy header
	if (n > 0) {
		head = create_node(1);
		p = head;
		for (i = 2; i <= n; i++) {
			p->next = create_node(i);
			p = p->next;							
		}
	}

	printf("Enter the action ( 1) task a, 2) task b): ");
	scanf("%d", &action);
	
	printf("\n");
	printf("The original linked list:\n");
	printout(head);
	switch(action) {
		case 1:
			printf("\n");
			printf("The reversed linked list:\n");
			head = reverse_by_recur(head);
			printout(head);
			printf("\n");
			printf("Reverse again:\n");
			head = reverse_by_recur(head);
			printout(head);
			break;
		case 2:
			printf("\n");
			printf("The reversed linked list:\n");
			head = reverse_group_by_recur(head);
			printout(head);
			printf("\n");
			printf("Reverse again:\n");
			head = reverse_group_by_recur(head);
			printout(head);
			break;
		default:
			printf("Error: Invalid input.\n");
	}
	free_nodes(head);
	return 0;	//return 0 to operating system upon successful completion of program
}