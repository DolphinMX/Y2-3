// SID: <Type your student ID here>
// Name: <Type your student name here>
//
// EE 2331 Data Structures and Algorithms,
// Semester B, 2009/10
// Tutorial 12 - Binary Search Trees
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_SIZE 64

typedef char TreeElement;

//define the C structure 'TreeNode' for tree
typedef struct _treenode {
	TreeElement data;
	struct _treenode *left, *right;
} TreeNode;

//define the C structure 'Tree'
typedef struct _tree {
	struct _treenode *root;
} Tree;

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
	printf("%c", p->data);
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
	TreeNode *p;
	//base cases
	if (index >= size) return NULL;
	if (a[index] == '.') return NULL;
	//general case
	p = (TreeNode*)malloc(sizeof(TreeNode));
	if (p == NULL) {
		printf("Cannot allocate memory!\n");
		exit(1);
	}
	p->data = a[index];
	p->left = arrayToLinkedTree(a, 2*index+1, size);		//recursion
	p->right = arrayToLinkedTree(a, 2*index+2, size);		//recursion
	return p;
}

//The supporting function to create a tree node
//parameters:
//	e: the value of the tree node to be created
//return value:
//	p: the pointer of the newly created node with value equal to e
TreeNode* Tree_createNode(TreeElement e) {
	TreeNode *p;
	p = (TreeNode*)malloc(sizeof(TreeNode));
	if (p == NULL) {
		printf("Error: cannot allocate memory!\n");
		exit(1);
	}
	p->data = e;
	p->left = p->right = NULL;
	return p;
}

//The iterative function to insert a node into the tree
//parameters:
//	t: the pointer to the tree structure
//	e: the value of the tree node to be inserted
//return value:
//	return 1 for successful insertion. return 0 for unsuccessful insertion (i.e. duplicated nodes)
int insert(Tree *t, TreeElement e) {
	//Task A
	TreeNode *p, *parent = NULL;
	p = t->root;
	while (p != NULL) {
		if (e == p->data) {			//e already exists
			return 0;				//unsuccesful insertion
		} else if (e < p->data) {	//e should be in the left subtree
			parent = p;				//parent points to the parent of p
			p = p->left;
		} else {					//e should be in the right subtree
			parent = p;				//parent points to the parent of p
			p = p->right;
		}
	}
	if (parent == NULL)					//empty tree
		t->root = Tree_createNode(e);
	else {
		if (e < parent->data)
			parent->left = Tree_createNode(e);
		else	//e > m->data
			parent->right = Tree_createNode(e);
	}
	return 1;						//successful insertion
}

//The iterative function to delete a node from the tree
//parameters:
//	t: the pointer to the tree structure
//	e: the value of the tree node to be deleted
//return value:
//	return 1 for successful deletion. return 0 for unsuccessful deletion (i.e. node not exists)
int delete(Tree *t, TreeElement e) {
	//Task B
	TreeNode *p, *parent = NULL, *minNode, *minNodeParent;
	int found = 0, isLeftChild, degree;
	p = t->root;

	if (p == NULL) return 0;		//empty tree
	while(p != NULL && !found) {
		if (e == p->data) {
			found = 1;
		} else if (e < p->data) {
			parent = p;
			p = p->left;
		} else {
			parent = p;
			p = p->right;
		}
	}
	//p points to the node to be deleted
	//parent points to the parent of p
	if (p == NULL)
		return 0;	//the node does not exist
	else {			//found == 1
		if (parent != NULL)
			isLeftChild = e < parent->data? 1: 0;
		degree = 0;
		if (p->left != NULL) degree++;
		if (p->right != NULL) degree++;
		switch (degree) {
			case 0:							//leaf node
				if (parent == NULL)			//special case: the node to be deleted is the root
					t->root = NULL;
				else if (isLeftChild)		//p is the left child
					parent->left = NULL;
				else						//p is the right child
					parent->right = NULL;
				free(p);
				break;
			case 1:							//one child
				if (parent == NULL)			//special case: the node to be deleted is the root
					t->root = p->left != NULL? p->left: p->right;
				else if (isLeftChild)		//p is the left child
					parent->left = p->left != NULL? p->left: p->right;
				else						//p is the right child
					parent->right = p->left != NULL? p->left: p->right;
				free(p);
				break;
			case 2:							//two children
				minNodeParent = p;
				minNode = p->right;			//assert: minNode != NULL
				while(minNode->left != NULL) {
					minNodeParent = minNode;
					minNode = minNode->left;
				}
				if (minNodeParent != p) {
					//"delete" the min node first
					degree = 0;
					if (minNode->left != NULL) degree++;
					if (minNode->right != NULL) degree++;
					switch (degree) {
						case 0:							//minNode is a leaf node
							minNodeParent->left = NULL;	//minNode is always the left child
							break;
						case 1:							//minNode has one child
							minNodeParent->left = minNode->left != NULL? minNode->left: minNode->right;
							break;						//minNode is always the left child
						default:						//should never enter here
							break;
					}
				}

				//delete p
				minNode->left = p->left;
				if (p->right != minNode) minNode->right = p->right;
				if (parent == NULL)				//special case: the node to be deleted is the root
					t->root = minNode;
				else if (isLeftChild)			//p is the left child
					parent->left = minNode;
				else							//p is the right child
					parent->right = minNode;
				free(p);
				break;
			default:	//should never enter here
				break;
		}
		return 1;
	}
}

//The recursive function to delete a node from the tree
//parameters:
//	p: the pointer to a tree node
//	e: the value of the tree node to be deleted
//return value:
//	return 1 for successful deletion. return 0 for unsuccessful deletion (i.e. node not exists)
int delete_recur(TreeNode **p, TreeElement e) {
	//Task C
	int degree;
	TreeNode *temp, *minNode;

	if (*p == NULL)
		return 0;	//the node does not exist, or empty tree
	else if (e == (*p)->data) {
		degree = 0;
		if ((*p)->left != NULL) degree++;
		if ((*p)->right != NULL) degree++;
		switch (degree) {
			case 0:							//leaf node
				free(*p);
				*p = NULL;
				break;
			case 1:							//one child
				temp = (*p)->left != NULL? (*p)->left: (*p)->right;
				free(*p);
				*p = temp;
				break;
			case 2:							//two children
				minNode = (*p)->right;		//assert: minNode != NULL
				while(minNode->left != NULL) {
					minNode = minNode->left;
				}
				temp = (TreeNode*)malloc(sizeof(TreeNode));
				if (temp == NULL) {
					printf("Error: Cannot allocate memory!\n");
					exit(1);
				}
				temp->data = minNode->data;
				temp->left = (*p)->left;
				temp->right = (*p)->right;
				free(*p);
				*p = temp;
				delete_recur(&((*p)->right), minNode->data);
				break;
			default:	//should never enter here
				break;
		}
	} else if (e < (*p)->data)
		delete_recur(&((*p)->left), e);
	else	//e > (*p)->data
		delete_recur(&((*p)->right), e);
}

int main(int argc, char * argv[]) {
	FILE *fp;
	char filename[64];
	char c;
	TreeElement arrayTree[MAX_TREE_SIZE];
	Tree t;
	int i, action = 1;

	printf("Enter the file name for testing: ");
	scanf("%s", filename);
	printf("\n");
	fp = fopen(filename, "rt");
	if (fp == NULL) {
		printf("Error: file open error\n");
		return 1;	//to indicate different error to OS
	}

	i = 0;
	while (i < MAX_TREE_SIZE && (c = getc(fp)) != '\n' && c != EOF)
		arrayTree[i++] = c;
	arrayTree[i] = '\0';

	printf("The array tree is: [%s]\n", arrayTree);

	Tree_init(&t);
	t.root = arrayToLinkedTree(arrayTree, 0, i);

	printf("The linked list tree is:\n");
	print_inorder_tree(t.root, 1);

	while (action >= 1 && action <= 3) {
		printf("Enter your action ( 1) Insert, 2) Delete, 3) Delete (recursion), 4) Quit ): ");
		scanf("%d", &action);
		scanf("%c", &c);			//to clear the extra newline character
		switch(action) {
			case 1:
				printf("Enter the node value: ");
				scanf("%c", &c);
				if (insert(&t, c))
					print_inorder_tree(t.root, 1);
				else
					printf("Unsuccessful insertion: node %c already exists!\n", c);
				break;
			case 2:
				printf("Enter the node value: ");
				scanf("%c", &c);
				if (delete(&t, c))					//iteration
					print_inorder_tree(t.root, 1);
				else
					printf("Unsuccessful deletion: node %c does not exist!\n", c);
				break;
			case 3:
				printf("Enter the node value: ");
				scanf("%c", &c);
				if (delete_recur(&t.root, c))		//recursion
					print_inorder_tree(t.root, 1);
				else
					printf("Unsuccessful deletion: node %c does not exist!\n", c);
				break;
			case 4:
				break;
			default:
				printf("Error: Invalid input!\n");
		}
	}
	Tree_destroy(&t);
	return 0;	//return 0 to operating system upon successful completion of program
}
