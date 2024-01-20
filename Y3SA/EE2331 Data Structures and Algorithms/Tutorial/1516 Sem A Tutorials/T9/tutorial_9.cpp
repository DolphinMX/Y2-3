/*
 * Student name:
 * Student ID  :
 
 * Tutorial 9 - Binary Tree
 *
 * Your task is to implement the function printLevel(), maxPath_recursion() and maxPath_stack().
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stack>


using namespace std;

// -----------------------------------------------------------------------------------tree structure defined for you

struct treeInfo
{
    char symb;
    int weight;
};

template<class Type>
struct treeNode
{
    Type info;
    treeNode<Type> *left;
    treeNode<Type> *right;
};

template<class Type>
void printTree(treeNode<Type> *p, int indent)
{
    if (p != NULL)
    {
        //print right subtree, root, and then left subtree
        printTree(p->right, indent + 6);
        cout << setw(indent) << p->info << endl;
        printTree(p->left, indent + 6);
    }
}

ostream& operator<< (ostream& osObject, const treeInfo& t)
{
    osObject << t.symb << "(" << t.weight << ")";
    return osObject;
}


/*
 * Convert an array representation of a binary tree to the linked representation.
 * The array representation uses a period '.' character to indicate an empty node.
 * The weight of a node is represented by the ASCII value of its symbol.
 *
 * array		array storing the symbols of the tree nodes
 * index		index of the root of the tree
 * size		length of the array
 *
 * return	a pointer to the root of the newly created tree
 */
treeNode<treeInfo>* buildTree(char *array, int index, int size)
{
    treeNode<treeInfo>* t = NULL;
    
    if (index < size && array[index] != '.')
    {
        t = new treeNode<treeInfo>;
        t->info.symb = array[index];
        t->info.weight = array[index];
        t->left = buildTree(array, 2 * index + 1, size);
        t->right = buildTree(array, 2 * index + 2, size);
    }
    return t;
}

// -----------------------------------------------------------------------------------complete the functions below

/* Print the nodes that belong to the requested level using recursion.
 * Printing order should be from left to right.
 *
 * tree         a pointer to the root of a tree
 * req_level    requested level
 *
 */

void printLevel(treeNode<treeInfo>* tree, unsigned int req_level)
{
	// Implement this function using recursion

}


/*
 * Find the maximum path of the given tree using recursion. 
 * The maximum path is a path from root to leaf which has the maximum sum of the weight.
 *
 * tree     a pointer to the root of a tree
 *
 * return   the weight of the maximum path
 */
int maxPath_recursion(treeNode<treeInfo>* tree)
{   
	int weight_left;   // weight of the max path on the left subtree
	int weight_right;  // weight of the max path on the right subtree
	int maxSum = 0;

	// Implement this function using recursion


	return maxSum;
}

/*
 * Find the maximum path of the given tree using a stack. 
 * The maximum path is a path from root to leaf which has the maximum sum of the weight.
 *
 * tree     a pointer to the root of a tree
 *
 * return   the weight of the maximum path
 */
int maxPath_stack(treeNode<treeInfo>* tree)
{
	struct stackItem
	{
		treeNode<treeInfo> *ptr;
		int weight_left;   // weight of the max path on the left subtree
		int weight_right;  // weight of the max path on the right subtree
	} x;

	stack<stackItem> S;
	int maxSum = 0;

	if (tree != NULL)
	{
		x.ptr = tree;
		x.weight_left = x.weight_right = -1;  // negative value represents the max path of the subtree is not yet determined
		S.push(x);
	}

	while (!S.empty())
	{
		if (S.top().weight_left < 0)
		{
			// your codes

		}
		else if (S.top().weight_right < 0)
		{
			// your codes

		}
		else  // weight_left and weight_right of S.top() have been determined
		{
			// your codes

		}		
	}

	return maxSum;
}


int main() {
    
    char arrayTree[] = "ACODEGHIBJKWV.M..P..Q...R.S";
    treeNode<treeInfo> *tree;
   
    int len = strlen(arrayTree);
    
    cout << "Array representation of the tree: " << arrayTree << endl;
    cout << "and its length = " << len << endl << endl;
    
    tree = buildTree(arrayTree, 0, len);
    printTree(tree, 0);    
    cout << endl;

    int level;
	cout << endl << "Enter the tree level: ";  // root is on level 0
	cin >> level;
    cout << "Print level: " << level << endl;
    printLevel(tree, level);
	cout << endl << endl;   

	cout << "Find the max path of the tree" << endl;
    cout <<"Max path (recursion): " << maxPath_recursion(tree) << endl; // 384
    cout <<"Max path (stack)    : " << maxPath_stack(tree) << endl << endl;
    
    system("pause");
    exit(0);
}

