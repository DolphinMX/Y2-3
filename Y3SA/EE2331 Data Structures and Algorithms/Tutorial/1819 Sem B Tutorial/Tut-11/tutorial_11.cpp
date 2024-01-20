//Student name: 
//Studnet ID  : 

/*
	Submission deadline: Thursday, 11 April 2019, 2 pm.

	Part-1: Tower of Hanoi
			Implement a non-recursive function to print the sequence of moves.
			**  You can reference the non-recursive algorithm to traverse a binary tree in inorder.

	Part-2: Binary tree
			Implement a function max() to find the max value of a non-empty tree.
			**  Precondition: the tree is NOT empty.

			Implement a function average() to compute the average value of the data stored in the tree.
			**  The tree may be empty.
			**  You may use other supporting function(s) in your answer.
			**  It is also possible to compute the average value using one single recursive function.
			**  Your design should not use any global variable.

			Implement a function isWeightBalanced() to determine if a tree is weight-balanced.		
			**  Weight of a tree is equal to the number of nodes in the tree.
			**  An empty binary tree is weight-balanced.
			**  A non-empty binary tree is weight-balanced if 
				1. weight of the left subtree and weight of the right subtree differ by no more than 1; and				   
				2. the left and right subtrees are weight-balanced.

			**  No other container (array, linked list, stack, queue, etc.) is allowed in your implementation.
			**  Your answer should contain only 1 single function for this part.	
			**  Computation complexity of your algorithm should be O(n).

			You need to add your statements in part_2() to call the functions
			max(), average(), and isWeightBalanced().
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <stack>
using namespace std;

// Recursive function to solve the Tower of Hanoi problem
void towerOfHanoi(int N, char F, char U, char T)
{
	if (N > 0)
	{
		towerOfHanoi(N-1, F, T, U);
		cout << F << " -> " << T << endl;
		towerOfHanoi(N-1, U, F, T);
	}
}

// ------------------------------------------------------------------
// Part-1: non-recursive function to solve the Tower of Hanoi problem

struct moveRequest
{
	int N;
	char F, U, T;
};


void towerOfHanoi_stack(int N, char F, char U, char T)
{
	stack<moveRequest> S;

	// Your codes

}

// ------------------------------------------------------------------
// Part-2 : Binary tree

struct treeNode
{
	int info;
	treeNode *left, *right;
};


// ** Define and implement your functions max(), average(), and isWeightBalanced()
// ** You need to design the function interface.




// ------------------------------------------ functions given to you

void part_1()  // Part-1: Tower of Hanoi
{
	cout << "Part-1: Solving the Tower of Hanoi problem using recursion and stack" << endl << endl;

	for (int N = 1; N <= 4; N *= 2)
	{
		cout << "Sequence of moves for N = " << N << " (recursion)" << endl;
		towerOfHanoi(N, 'L', 'M', 'R');

		cout << "\nSequence of moves for N = " << N << " (stack)" << endl;
		towerOfHanoi_stack(N, 'L', 'M', 'R');
		cout << endl;
	}
}


void printTree(treeNode *p, int indent)
{
	if (p != NULL)
	{
		printTree(p->right, indent+4);
		cout << setw(indent) << p->info << endl;
		printTree(p->left, indent+4);
	}
}

treeNode* buildTreeFromArray(int *a, int n, int i, int nullSymbol)
{
	treeNode *p = nullptr;

	if (i < n && a[i] != nullSymbol)
	{
		p = new treeNode;
		p->info = a[i];
		p->left = buildTreeFromArray(a, n, 2*i+1, nullSymbol);
		p->right = buildTreeFromArray(a, n, 2*(i+1), nullSymbol);
	}

	return p;
}

void part_2()
{
	cout << "\n--------------------------------------------------------\n\n";
	cout << "Part-2: Binary tree" << endl << endl;

	// the value -1 represents the nullSymbol in the test data
	int a[] = {25, 11, 73, 64, 19, 33, 57, -1, 16, -1, -1, 46, 81};
	int n = 13;

	treeNode* tree1 = buildTreeFromArray(a, n, 0, -1);
	cout << "tree1" << endl << endl;
	printTree(tree1, 4);
	cout << endl << endl;

	int maxValue = 0; 
	double avgValue = 0;

	// ** Your statements to find out maxValue and avgValue of tree1


	cout << "max(tree1) = " << maxValue  << endl << endl;
	cout << "average(tree1) = " << avgValue << endl << endl;

	treeNode *tree2 = nullptr;
	cout << "Test average() with empty tree\n";

	// ** Your statements to find out avgValue of tree2

	cout << "average(tree2) = " << avgValue << endl << endl;

	bool weightBalanced = false;

	// ** Your statements to find out if tree1 is weightBalanced


	if (weightBalanced)
		cout << "tree1 is weight-balanced" << endl;
	else
		cout << "tree1 is NOT weight-balanced" << endl;

	int m = 12;
	tree2 = buildTreeFromArray(a, m, 0, -1);
	cout << endl << "---------------------------------\n";
	cout << "tree2" << endl << endl;
	printTree(tree2, 4);
	cout << endl;

	weightBalanced = false;

	// ** Your statements to find out if tree2 is weightBalanced


	if (weightBalanced)
		cout << "tree2 is weight-balanced" << endl;
	else
		cout << "tree2 is NOT weight-balanced" << endl;
	cout << endl;
}

int main() 
{
	part_1();
	part_2();

	system("pause");
	return 0;
}

