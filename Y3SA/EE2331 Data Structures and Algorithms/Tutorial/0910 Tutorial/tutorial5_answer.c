// SID: <Type your student ID here>
// Name: <Type your student name here>
//
// EE 2331 Data Structures and Algorithms,
// Semester B, 2009/10
// Tutorial 5 - Stacks
//

#include <stdio.h>
#include <stdlib.h>		//required by malloc() and free()

//define the C structure '_node' for doubly linked list
struct _node {
	int data;
	struct _node *prev;
	struct _node *next;
};

//rename the C structure 'struct _node' to 'Node'
typedef struct _node Node;

//define the C structure '_stack'
struct _stack {
	Node *top;
};

//rename the C structure 'struct _stack' to 'Stack'
typedef struct _stack Stack;

//To create a node with data field initialize to node_data
//Precondition: none
//Postconditions: p has been initialized. Its data equals value v and prev, next equal to NULL.
Node* create_node(int node_data) {
	Node *p;

	p = (Node*)malloc(sizeof(Node));
	if (p == NULL) {
		printf("Error: cannot allocate memory!\n");
		exit(1);
	}

	p->data = node_data;
	p->prev = NULL;
	p->next = NULL;
	return p;
}  

//To delete and release the memory of the whole linked list pointed by 'p'
//Precondition: the list is a linear linked list
//Postconditions: the memory pointed by 'p' and its all successors have been released
void free_nodes(Node *p) {
	Node *m;
	while (p != NULL) {
		m = p;
		p = p->next;
		free(m);
	}
}

//To test if the stack is empty or not
//Output: return 1 if the stack is empty, otherwise 0.
//Precondition: the list has dummy header
int Stack_isEmpty(Stack *s) {
	return (s->top->next == NULL);
}

void Stack_init(Stack *s) {
	s->top = create_node(-1);	//create a dummy header;
}

void Stack_destroy(Stack *s) {
	free_nodes(s->top);
	s->top = NULL;
}

//To push a node that contains integer value e onto the stack
//Precondition: the list has dummy header
//Postcondition: a new node with value equals e has been inserted as the new top node
void push(Stack *s, int e) {
	//Task A
	Node *p;

	p = create_node(e);			//create a new node with value equals e
	p->prev = NULL;
	p->next = s->top->next;		//set p as the new top node
	if (s->top->next != NULL)	//set the old top node's prev to the new top node
		s->top->next->prev = p;
	s->top->next = p;			//update the top pointer
}

//To pop top node from the stack if the stack is non-empty
//Output: the integer value of the top node
//Precondition: the stack is non-empty
//Postcondition: the top node has been deleted
int pop(Stack *s) {
	//Task B
	Node *p;
	int e;
	
	if (Stack_isEmpty(s)) {
		printf("Error: Stack underflow!\n");
		exit(1);
	}	
	p = s->top->next;			//p points to the top node
	s->top->next = p->next;		//advance the top pointer
	if (s->top->next != NULL)	//set the new top node's prev to NULL
		s->top->next->prev = NULL;
	e = p->data;				//get the data
	free(p);					//delete the node
	return e;
}

//To convert the number a from decimal to radix r
//Output: the converted number
//Precondition: a > 0, 1 < r < 10
int convert(int a, int r) {
	//Task C
	int digit, number;
	Stack s;

	Stack_init(&s);				//initialize the stack to empty state
	while (a > 0) {				//check the quotient is non-zero
		digit = a % r;			//obtain the remainder
		a /= r;					//obtain the quotient
		push(&s, digit);		//push the remainder into the stack
	}
	number = 0;
	while (!Stack_isEmpty(&s))	//to reverse the remainders
		number = number*10 + pop(&s);
	Stack_destroy(&s);			//destroy the stack after finished using it
	return number;
}

int main() {
	int a, r;

	printf("Enter the number a: ");
	scanf("%d", &a);
	printf("Enter the new radix r: ");
	scanf("%d", &r);
	printf("Answer: %d\n", convert(a, r));

	return 0;	//return 0 to operating system upon successful completion of program
}