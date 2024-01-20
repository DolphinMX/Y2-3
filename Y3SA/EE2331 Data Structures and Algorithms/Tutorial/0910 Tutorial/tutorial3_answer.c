// SID: <Type your student ID here>
// Name: <Type your student name here>
//
// EE 2331 Data Structures and Algorithms,
// Semester B, 2009/10
// Tutorial 3 - Linked Lists
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

//To print out the content of the linked list p
//Precondition: p is the head of the linked list and the list has dummy header
//Postcondition: the content of the linked list has been printed to console
void printout(Node *p) {
	//Task D
	p = p->next;
	while (p != NULL) {
		printf("%d -> ", p->data);
		p = p->next;
	}
	printf("NULL\n");
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
//Precondition: none
//Postcondition: the memory pointed by 'p' and its all successors have been released
void free_nodes(Node *p) {
	Node *m;

	while (p != NULL) {
		m = p;
		p = p->next;
		free(m);
	}
}

//To search for node that contains integer value x
//Output: return the pointer that point to the node containing x if exists, otherwise NULL
//Precondition: 'head' is the head of the linked list and the list has dummy header
Node* search(Node *head, int x, int *count) {
	//Task A
	Node *p, *m = NULL;

	*count = 0;
	p = head->next;		//to skip the dummy header
	while (p != NULL) {
		if (p->data == x) {
			if (*count == 0) m = p;		//set m to the first searched node
			(*count)++;
		}
		p = p->next;
	}
	return m;	//cannot find x, so return NULL
}

//To insert a node of integer value x into the end of list if the node containing x does not exist
//Precondition: 'head' is the head of the linked list and the list has dummy header
//Postcondition: a node of integer value x has been inserted to the end of list if the node containing x does not exist
void insert(Node *head, int x) {
	//Task B
	Node *p;
	
	p = head;
	while (p->next != NULL && p->next->data != x)
		p = p->next;
	
	//=> p->next == NULL || p->next->data == x
	//=> p is pointing to the last node OR x exist in the list
	if (p->next == NULL)
		//p is pointing to the last node, insert x to the end of list
		p->next = create_node(x);
	//else => p->next->data == x, do nothing
}

//To delete all nodes containing integer value x from the list
//Precondition: 'head' is the head of the linked list and the list has dummy header
//Postcondition: all nodes containing integer value x has been deleted from the list
int delete(Node *head, int x) {
	//Task C
	Node *p, *m;
	int num = 0;

	p = head;
	while (p->next != NULL)
		if (p->next->data == x) {
			//The next node contains x, delete the next node from the list
			m = p->next;	//m points to the node to be deleted
			p->next = m->next;
			free(m);		//free the next node
			num++;			//increase the number of deleted node by 1
							//note: need NOT advance p, since p->next has been updated already
		} else {
			p = p->next;	//the next node does not contain x, so advance to next node
		}
	return num;				//return the total number of deleted nodes
}

int main() {
	FILE *fp;
	char filename[20];
	int n, node_data;
	Node *head, *p;
	int i, action, x, count;

	printf("Enter the file name for testing: ");
	scanf("%s", filename);
	fp = fopen(filename, "rt");
	if (fp == NULL) {
		printf("Error: file open error\n");
		return 1;	//to indicate different error to OS
	}

	head = create_node(-1);	//create a dummy header first
	p = head;

	//read in integers
	fscanf(fp, "%d", &n);
	for (i = 0; i < n; i++) {
		fscanf(fp, "%d", &node_data);
		p->next = create_node(node_data);
		p = p->next;
	}
	fclose(fp);

	printf("The linked list is : ");
	printout(head);

	printf("Please enter your action ( 1) search, 2) insert, 3) delete ): ");
	scanf("%d", &action);
	printf("Please enter the value of x: ");
	scanf("%d", &x);
	printf("\n");

	switch(action) {
		case 1:
			//Task A
			p = search(head, x, &count);
			if (p != NULL)
				printf("The searched node is : %d\n", p->data);
			else
				printf("The searched node is : not found\n");
			printf("The number of nodes containing x is: %d\n", count);
			printf("The final linked list is : ");
			printout(head);
			break;
		case 2:
			//Task B
			insert(head, x);
			printf("The final linked list is : ");
			printout(head);
			break;
		case 3:
			//Task C
			printf("Number of deleted nodes is : %d\n", delete(head, x));
			printf("The final linked list is : ");
			printout(head);
			break;
		default:
			printf("Invalid input.\n");
	}

	free_nodes(head);	//free all nodes before completion of program
	return 0;	//return 0 to operating system upon successful completion of program
}