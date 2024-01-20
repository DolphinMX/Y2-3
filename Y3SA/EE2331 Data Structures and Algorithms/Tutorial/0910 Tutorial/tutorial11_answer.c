// SID: <Type your student ID here>
// Name: <Type your student name here>
//
// EE 2331 Data Structures and Algorithms,
// Semester B, 2009/10
// Tutorial 11 - Reconstruction of Binary Trees
//

#include <stdio.h>
#include <stdlib.h>		//required by malloc() and free()

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

//The recursive function to reconstruct the tree by consider the inorder and postorder traversal sequences
//parameters:
//	inorder: the array storing the inorder traversal sequence
//	in_lo, in_hi: the starting and ending indices for inorder array
//	postorder: the array storing the postorder traversal sequence
//	post_lo, post_hi: the starting and ending indices for postorder array
//return value:
//	p: the pointer of a node structure representing the root of a subtree of inorder[in_lo ... in_hi]
TreeNode* reconstructTreeUsingInPost(TreeElement inorder[], int in_lo, int in_hi, TreeElement postorder[], int post_lo, int post_hi) {
	//Task A
	int i, index, leftsize;
	TreeNode *p;
	TreeElement e;

	//base case
	if ((in_lo > in_hi) || (post_lo > post_hi)) return NULL;

	//general case
	e = postorder[post_hi];		//the last node in postorder[] is the root node of the current subtree
	p = create_treenode(e);

	//to search for the index of the root of the current subtree in inorder[]
	index = -1;
	for (i = in_lo; i <= in_hi && index == -1; i++)
		if (inorder[i] == e) index = i;
	if (index == -1) {
		printf("Error: incorrect traversal sequence!\n");
		exit(1);
	}
	leftsize = index - in_lo;
	//rightsize = in_hi - index;
	p->left = reconstructTreeUsingInPost(inorder, in_lo, index - 1, postorder, post_lo, post_lo + leftsize - 1);
	p->right = reconstructTreeUsingInPost(inorder, index + 1, in_hi, postorder, post_lo + leftsize, post_hi - 1);
	return p;
}

int main(int argc, char * argv[]) {
	FILE *fp;
	char filename[64];
	char c;
	TreeElement postorder[MAX_TREE_SIZE], inorder[MAX_TREE_SIZE];
	Tree t;
	int i, size;

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
		inorder[i++] = c;
	inorder[i] = '\0';
	size = i;

	i = 0;
	while (i < MAX_TREE_SIZE && (c = getc(fp)) != '\n' && c != EOF)
		postorder[i++] = c;
	postorder[i] = '\0';
	fclose(fp);
	if (size != i) {
		printf("Error: incorrect file format!\n");
		return 2;
	}

	printf("The inorder sequence is: %s\n", inorder);
	printf("The postorder sequence is: %s\n", postorder);

	Tree_init(&t);
	t.root = reconstructTreeUsingInPost(inorder, 0, size - 1, postorder, 0, size - 1);

	printf("The linked list tree is:\n");
	print_inorder_tree(t.root, 1);

	printf("The inorder sequence is: ");
	print_inorder_sequence(t.root);
	printf("\n");

	Tree_destroy(&t);
	return 0;	//return 0 to operating system upon successful completion of program
}
