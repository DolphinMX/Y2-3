// SID: <Type your student ID here>
// Name: <Type your student name here>
//
// EE 2331 Data Structures and Algorithms,
// Semester B, 2009/10
// Tutorial 13 - Sorting
//

#include <stdio.h>
#include <stdlib.h>

typedef int StackElement;
typedef int QueueElement;

//define the C structure 'StackNode' for stack
typedef struct _stacknode {
	StackElement data;
	struct _stacknode *next;
} StackNode;

//define the C structure 'Stack'
typedef struct _stack {
	StackNode *top;
} Stack;

//define the C structure 'QueueNode' for queue
typedef struct _queuenode {
	QueueElement data;
	struct _queuenode *next;
} QueueNode;

//define the C structure 'Queue'
typedef struct _queue {
    QueueNode *front;
	QueueNode *rear;
} Queue;

//To allocate memory for a node (for stack use)
//Precondition: none
//Postcondition: p has been initialized. Its data equals value e and next equals NULL.
StackNode* create_stacknode(StackElement e) {
	StackNode *p;
	p = (StackNode*)malloc(sizeof(StackNode));
	if (p == NULL) {
		printf("Cannot allocate memory!\n");
		exit(1);
	}
	p->data = e;
	p->next = NULL;
	return p;
}

//To initialize the stack to empty state
void Stack_init(Stack *s) {
	s->top = NULL;
}

//To clear the stack and release its allocated memory, if any
void Stack_destroy(Stack *s) {
	StackNode *p;
	while (s->top != NULL) {
		p = s->top;
		s->top = s->top->next;
		free(p);
	}
}

//To test if the stack is empty
//Output: return 1 if the stack is empty, otherwise 0.
int Stack_isEmpty(Stack *s) {
	return (s->top == NULL);
}

//To push a node that contains integer value e onto the stack
//Postcondition: a new node with value equals e has been inserted as the new top node
void push(Stack *s, int e) {
	StackNode *p;

	p = create_stacknode(e);//create a new node with value equals e
	p->next = s->top;		//set p as the new top node
	s->top = p;				//update the top pointer
}

//To pop top node from the stack if the stack is non-empty
//Output: the integer value of the top node
//Precondition: the stack is non-empty
//Postcondition: the top node has been deleted
int pop(Stack *s) {
	StackNode *p;
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

//To allocate memory for a node (for queue use)
//Precondition: none
//Postcondition: p has been initialized. Its data equals value e and next equals NULL.
QueueNode* create_queuenode(QueueElement e) {
	QueueNode *p;
	p = (QueueNode*)malloc(sizeof(QueueNode));
	if (p == NULL) {
		printf("Cannot allocate memory!\n");
		exit(1);
	}
	p->data = e;
	p->next = NULL;
	return p;
}

//To initialize the queue to empty state
void Queue_init(Queue *q) {
    q->front = q->rear = NULL;
}

//To clear the queue and release its allocated memory, if any
void Queue_destroy(Queue *q) {
	QueueNode *p;
	while (q->front != NULL) {
		p = q->front;
		q->front = q->front->next;
		free(p);
	}
	q->rear = NULL;
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
QueueElement dequeue(Queue *q) {
    QueueNode *p;
	QueueElement e;

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
void enqueue(Queue *q, QueueElement e) {
    QueueNode *p;

	p = create_queuenode(e);
	if (q->rear != NULL) q->rear->next = p;
    q->rear = p;

    //extreme case: the original queue is empty (update front as well)
	if (q->front == NULL) q->front = q->rear;
}

//To printout the content of stack (from top to bottom)
void Stack_printout(Stack *s) {
	StackNode *p;
	p = s->top;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
}

//To printout the content of queue (from front to rear)
void Queue_printout(Queue *q) {
	QueueNode *p;
	p = q->front;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
}

//To return the topmost element of stack s (supporting function for task a)
//Precondition: the stack is non-empty
//Postcondition: the top most element has been returned, but the content of the stack remains unchanged
int top(Stack *s) {
	if (Stack_isEmpty(s)) {
		printf("Error: stack underflow!\n");
		exit(1);
	}
	return s->top->data;
}

//The function to sort the input data using insertion sort
//Parameter:
//	q: the integer data are stored in the queue
//Postcondition: the data in q has been sorted in ascending order
void insertionSort(Queue *q) {
	//Task A
	Stack s, t;
	int e, i = 0;
	Stack_init(&s);
	Stack_init(&t);

	while (!Queue_isEmpty(q)) {
		e = dequeue(q);
		while (!Stack_isEmpty(&s) && top(&s) < e)
			push(&t, pop(&s));
		push(&s, e);
		while (!Stack_isEmpty(&t))
			push(&s, pop(&t));
		
		if (i > 0) {
			//call Stack_printout(&s) and Queue_printout(q) to print out the sequence after each pass
			printf("The sequence after %d pass: ", i);
			Stack_printout(&s);
			Queue_printout(q);
			printf("\n");
		}
		i++;
	}
	while (!Stack_isEmpty(&s))
		enqueue(q, pop(&s));

	Stack_destroy(&s);
	Stack_destroy(&t);
}

//To return the power (supporting function for task b)
int power(int base, int exponent) {
	int answer = 1;
	while (exponent-- > 0)
		answer *= base;
	return answer;
}

//To return the max value of the queue (supporting function for task b)
//Precondition: the queue is non-empty
//Postcondition: the max element has been returned, but the content of the queue remains unchanged
QueueElement Queue_max(Queue *q) {
	QueueNode *p;
	QueueElement e;
	p = q->front;
	if (p != NULL) e = p->data;		//initially take first data as max
	while (p != NULL) {
		if (p->data > e) e = p->data;
		p = p->next;
	}
	return e;	//e is undefined if the queue is empty
}

//The function to sort the input data using radix sort
//Parameter:
//	q: the integer data are stored in the queue
//Postcondition: the data in q has been sorted in ascending order
void radixSort(Queue *q) {
	//Task B
	//Create 10 queues here
	Queue bucket[10];
	int e, digit, i, j, k = 1, max;

	//Initialize the 10 queues here
	for (i = 0; i < 10; i++)
		Queue_init(&bucket[i]);

	max = Queue_max(q);
	while ((max /= 10) > 0) k++;
	for (i = 1; i <= k; i++) {
		while (!Queue_isEmpty(q)) {
			e = dequeue(q);
			digit = e / power(10, i - 1) % 10;
			enqueue(&bucket[digit], e);
		}
		for (j = 0; j < 10; j++)
			while (!Queue_isEmpty(&bucket[j]))
				enqueue(q, dequeue(&bucket[j]));

		//call Queue_printout(q) to print out the sequence after each pass
		printf("The sequence after %d pass: ", i);
		Queue_printout(q);
		printf("\n");
	}

	//Finally destroy the queues before finishing the function
	for (i = 0; i < 10; i++)
		Queue_destroy(&bucket[i]);
}

int main(int argc, char * argv[]) {
	FILE *fp;
	char filename[64];
	int action, e;
	Queue q;

	printf("Enter the file name for testing: ");
	scanf("%s", filename);
	fp = fopen(filename, "rt");
	if (fp == NULL) {
		printf("Error: file open error\n");
		return 1;	//to indicate different error to OS
	}

	printf("Enter your action ( 1) insertion sort, 2) radix sort ): ");
	scanf("%d", &action);
	printf("\n");

	Queue_init(&q);
	while (fscanf(fp, "%d ", &e) > 0)
		enqueue(&q, e);

	printf("The input sequence is: ");
	Queue_printout(&q);
	printf("\n");

	switch(action) {
		case 1:
			//Task A
			insertionSort(&q);
			printf("The sorted sequence is: ");
			Queue_printout(&q);
			printf("\n");
			break;
		case 2:
			//Task B
			radixSort(&q);
			printf("The sorted sequence is: ");
			Queue_printout(&q);
			printf("\n");
			break;
		default:
			printf("Invalid input.\n");
	}

	Queue_destroy(&q);
	return 0;	//return 0 to operating system upon successful completion of program
}
