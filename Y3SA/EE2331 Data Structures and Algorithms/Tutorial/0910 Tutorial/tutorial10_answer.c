// SID: <Type your student ID here>
// Name: <Type your student name here>
//
// EE 2331 Data Structures and Algorithms,
// Semester B, 2009/10
// Tutorial 10 - Binary Trees
//

#include <stdio.h>
#include <stdlib.h>		//required by malloc() and free()

#define MAX_TREE_SIZE 64

typedef char TreeElement;
typedef struct _treenode * QueueElement;

//define the C structure 'TreeNode' for tree
typedef struct _treenode {
	TreeElement data;
	struct _treenode *left, *right;
} TreeNode;

//define the C structure 'Tree'
typedef struct _tree {
	struct _treenode *root;
} Tree;

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

//To initialize the tree to empty tree
void Tree_init(Tree *t) {
    t->root = NULL;
}

//To delete and release the memory of the tree
//Precondition: none
//Postcondition: the memory pointed by 'p' and its children have been released
void delete_tree_node(TreeNode *p) {
	if (p == NULL) return;
	delete_tree_node(p->left);
	delete_tree_node(p->right);
	free(p);
} 

//To destroy the tree by deallocating all its nodes, and reset back to empty tree
void Tree_destroy(Tree *t) {
    delete_tree_node(t->root);
    t->root = NULL;
}

//To allocate memory for a node (for tree use)
//Precondition: none
//Postcondition: p has been initialized. Its data equals value e and left, right equals NULL.
TreeNode* create_treenode(int node_value) {
    TreeNode *p;

    p = (TreeNode*)malloc(sizeof(TreeNode));
    if (p == NULL) {
		printf("Error: cannot allocate memory!\n");
		exit(1);
	}

    p->data = node_value;
    p->left = p->right = NULL;
    return p;
}

//To allocate memory for a node (for queue use)
//Precondition: none
//Postcondition: p has been initialized. Its data equals value e and next equals NULL.
QueueNode* create_queuenode(QueueElement e) {
	QueueNode *p;
	p = (QueueNode*)malloc(sizeof(QueueNode));
	if (p == NULL) {
		printf("Error: cannot allocate memory!\n");
		exit(1);
	}
	p->data = e;
	p->next = NULL;
	return p;
}

//To delete and release the memory of the linked list pointed by 'node' (for queue use)
//Precondition: none
//Postcondition: the memory pointed by 'node' and its successors have been released
void free_queuenodes(QueueNode *node) {
	QueueNode *p;

	while (node != NULL) {
		p = node;
		node = node->next;
		free(p);
	}
} 

//To initialize the queue to empty state
void Queue_init(Queue *q) {
    q->front = q->rear = NULL;
}

//To clear the queue and release its allocated memory, if any
void Queue_destroy(Queue *q) {
	free_queuenodes(q->front);
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

//Recursive function to print the inorder tree structure
void print_inorder_tree(TreeNode *p, int indent) {
	if (p == NULL) return;
	print_inorder_tree(p->right, indent + 2);	//print right subtree first (for easy reading only)
	printf("%*c\n", indent, p->data);
	print_inorder_tree(p->left, indent + 2);
}

//Recursive function to print the inorder tree traversal sequence
void print_inorder_sequence(TreeNode *p) {
	if (p == NULL) return;
	print_inorder_sequence(p->left);
	printf("%c ", p->data);
	print_inorder_sequence(p->right);
}

//The recursive function to convert a tree in an implicit array representation to linked list representation
//parameters:
//	a[]: the array tree
//	index: the current index of array element
//	size: the maximum size of the array
//return value:
//	p: the pointer of a node structure representing a[index] in the tree
TreeNode* arrayToLinkedTree(TreeElement a[], int index, int size) {
	//Task A
	TreeNode *p;
	//base cases
	if (index >= size) return NULL;
	if (a[index] == '.') return NULL;
	//general case
	p = create_treenode(a[index]);
	p->left = arrayToLinkedTree(a, 2*index+1, size);		//recursion
	p->right = arrayToLinkedTree(a, 2*index+2, size);		//recursion
	return p;
}

//Recursive function to print the double-order tree traversal sequence
void print_double_order_sequence(TreeNode *p) {
	//Task B
	if (p == NULL) return;
	printf("%c ", p->data);
	print_double_order_sequence(p->left);
	printf("%c ", p->data);
	print_double_order_sequence(p->right);
}

//To print the level-order tree traversal sequence using queue
void print_level_order_sequence(Tree *t) {
	//Task C
	Queue q;
	TreeNode *p = t->root;

	Queue_init(&q);

	if (p != NULL) enqueue(&q, p);
	while (!Queue_isEmpty(&q)) {
		p = dequeue(&q);
		printf("%c ", p->data);
		if (p->left != NULL)
			enqueue(&q, p->left);
		if (p->right != NULL)
			enqueue(&q, p->right);
	}
	printf("\n");
	Queue_destroy(&q);
}

int main(int argc, char * argv[]) {
	FILE *fp;
	char filename[64];
	int i, action;
	char c;
	TreeElement arrayTree[MAX_TREE_SIZE];
	Tree t;

	printf("Enter the file name for testing: ");
	scanf("%s", filename);
	fp = fopen(filename, "rt");
	if (fp == NULL) {
		printf("Error: file open error\n");
		return 1;	//to indicate different error to OS
	}

	i = 0;
	while (i < MAX_TREE_SIZE && (c = getc(fp)) != '\n' && c != EOF)
		arrayTree[i++] = c;
	arrayTree[i] = '\0';
	fclose(fp);

	printf("The array tree is: [%s]\n", arrayTree);

	printf("Please enter your action ( 1) task a, 2) task b, 3) task c ): ");
	scanf("%d", &action);
	printf("\n");

	//Task A
	Tree_init(&t);
	t.root = arrayToLinkedTree(arrayTree, 0, i);	
	
	switch(action) {
		case 1:
			printf("The linked list tree is:\n");
			print_inorder_tree(t.root, 1);
			break;
		case 2:
			//Task B
			printf("The double-order sequence is: ");
			print_double_order_sequence(t.root);
			break;
		case 3:
			//Task C
			printf("The level-order sequence is: ");
			print_level_order_sequence(&t);
			break;
		default:
			printf("Invalid input.\n");
	}
	Tree_destroy(&t);
	return 0;	//return 0 to operating system upon successful completion of program
}
