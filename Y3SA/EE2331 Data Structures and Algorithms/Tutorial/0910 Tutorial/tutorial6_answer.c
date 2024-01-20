// SID: <Type your student ID here>
// Name: <Type your student name here>
//
// EE 2331 Data Structures and Algorithms,
// Semester B, 2009/10
// Tutorial 6 - Recognizing Palindromes
//

#include <stdio.h>
#include <stdlib.h>		//required by malloc() and free()
#include <ctype.h>		//required by isalpha(), isupper(), islower(), toupper() and tolower()

#define MAXSIZE 1024

//define the C structure 'Node' for singly linked list
typedef struct _node {
	int data;
	struct _node *next;
} Node;

//define the C structure 'Stack'
typedef struct _stack {
	Node *top;
} Stack;

//define the C structure 'Queue'
typedef struct _queue {
    Node *front;
	Node *rear;
} Queue;

//To create a node with data field initialize to node_data
//Precondition: none
//Postcondition: p has been initialized. Its data equals value v and next equals to NULL.
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

//To initialize the stack to empty state
void Stack_init(Stack *s) {
	s->top = NULL;
}

//To clear the stack and release its allocated memory, if any
void Stack_destroy(Stack *s) {
	free_nodes(s->top);
	s->top = NULL;
}

//To test if the stack is empty
//Output: return 1 if the stack is empty, otherwise 0.
int Stack_isEmpty(Stack *s) {
	return (s->top == NULL);
}

//To push a node that contains integer value e onto the stack
//Postcondition: a new node with value equals e has been inserted as the new top node
void push(Stack *s, int e) {
	Node *p;

	p = create_node(e);		//create a new node with value equals e
	p->next = s->top;		//set p as the new top node
	s->top = p;				//update the top pointer
}

//To pop top node from the stack if the stack is non-empty
//Output: the integer value of the top node
//Precondition: the stack is non-empty
//Postcondition: the top node has been deleted
int pop(Stack *s) {
	Node *p;
	int e;
	
	if (s->top == NULL) {
		printf("Error: stack underflow!\n");
		exit(1);
	}	
	p = s->top;				//p points to the top node
	s->top = p->next;		//advance the top pointer
	e = p->data;			//get the data
	free(p);				//delete the node
	return e;
}

//To initialize the queue to empty state
void Queue_init(Queue *q) {
    q->front = q->rear = NULL;
}

//To clear the queue and release its allocated memory, if any
void Queue_destroy(Queue *q) {
	free_nodes(q->front);
	q->front = q->rear = NULL;
}

//To test if the queue is empty
//Output: return 1 if the queue is empty, otherwise 0.
int Queue_isEmpty(Queue *q) {
    return (q->front == NULL);
}

//To delete first node from the queue if the queue is non-empty
//Output: the value of the top node
//Precondition: the queue is non-empty
//Postcondition: the top node has been deleted
int dequeue(Queue *q) {
    Node *p;
	int e;

	if (Queue_isEmpty(q)) {
		printf("Error: queue underflow!\n");
		exit(1);
	}

	p = q->front;
    e = p->data;
    q->front = p->next;
    free(p);

	//extreme case: the original queue has just one element
	//both front and rear should point to NULL
	if (q->front == NULL) q->rear = NULL;
    return e;
}

//To insert a node that to the end of queue
//Postcondition: a new node with value equals e has been inserted as the rear node
void enqueue(Queue *q, int e) {
    Node *p;

	p = create_node(e);
	if (q->rear != NULL) q->rear->next = p;
    q->rear = p;

    //extreme case: the original queue is empty (update front as well)
	if (q->front == NULL) q->front = q->rear;
}

//The function to determine if the input string is palindrome.
//Return 1 if it is a palindrome. Otherwise return 0.
int isPalindrome(char *str) {
	//Task A, B, C
	Stack s;
	Queue q;
	int correct = 1;
	char c;

	Stack_init(&s);
	Queue_init(&q);
	while(*str != '\0') {
		if (isalpha(*str)) {
			c = isupper(*str)? tolower(*str): *str;
			push(&s, c);
			enqueue(&q, c);
		}
		str++;
	}
	while (!Stack_isEmpty(&s)) {
		if (!Queue_isEmpty(&q)) {
			if (pop(&s) != dequeue(&q)) {
				correct = 0;
				break;
			}
		}
	}
	Stack_destroy(&s);
	Queue_destroy(&q);
	return correct;
}

int main(int argc, char * argv[]) {
	char str[MAXSIZE], fname[80];
	FILE *fp;

	printf("Enter the file name for testing: ");
	scanf("%s", fname);
	fp = fopen(fname, "rt");
	if (fp == NULL) {
		printf("File open error!\n");
		exit(1);
	}
	fgets(str, MAXSIZE - 1, fp);
	fclose(fp);

	printf("The string is: %s\n", str);
	printf("Palindrome? ");
	if (isPalindrome(str))
		printf("Yes\n");
	else
		printf("No\n");

	return 0;	//return 0 to operating system upon successful completion of program
}
