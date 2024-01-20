/*
 * Student name:
 * Student ID  :
 * 
 * Your task is to implement a check if the given binary tree is a max heap.
 * You are threfore asked to implement the functions isComplete() and isDescending() as specified below.
 * Test cases are defined in the main() function. No modification is needed.
 *
 */

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>


using namespace std;

// tree structure

template<class Type>
struct treeNode {
    Type key;
    treeNode<Type> *left;
    treeNode<Type> *right;
};

//-------------------------- functions to be implemented by you

/**
 * Check the max heap descending property. Return true if each node has equal or
 * smaller key than its parent; otherwise return false.
 */
bool isDescending(treeNode<int>* root) {
   
    
    
    
    
}

/**
 * Check the max heap complete property. You can use queue to perform level 
 * order traversal. Return true if the tree is complete; otherwise return false.
 */
bool isComplete(treeNode<int>* root) {

   
    
    
    
    
}

//-------------------------- functions prepared for you

/*
 * Print a binary tree (with -90 degree rotation).
 */
template<class Type>
void printTree(treeNode<Type> *p, int indent) {
    if (p != NULL) {
        printTree(p->right, indent + 6);
        cout << setw(indent) << '(' << p->key << ')' << endl;
        printTree(p->left, indent + 6);
    }
}

/*
 * Build a binary tree based on the array representation, where -1 represents 
 * an empty tree node.
 */
treeNode<int>* buildTree(int *array, int index, int size) {
    treeNode<int>* t = NULL;

    if (index < size && array[index] != -1) {
        t = new treeNode<int>();
        t->key = array[index];
        t->left = buildTree(array, 2 * index + 1, size);
        t->right = buildTree(array, 2 * index + 2, size);
    }
    return t;
}

/*
 * Driver program to test above functions against default test cases.
 */
int main(int argc, char** argv) {

    ifstream fin("t10_input.txt");
    if (!fin) {
        cout << "Input file not found.";
        exit(1);
    }

    int testcase = 0;
    fin >> testcase;

    for (int i = 0; i < testcase; i++) {

        int n;
        fin >> n;
        int* arr1 = new int[n];
        for (int j = 0; j < n; j++)
            fin >> arr1[j];

        printf("Case %d ----------------------------------------\n\n", i);
        treeNode<int> *tree = buildTree(arr1, 0, n);
        printTree(tree, 0);
        if (isComplete(tree) && isDescending(tree))
            cout << "\nIt's a max-heap!\n\n";
        else
            cout << "\nIt's NOT a max-heap!\n\n";
    }
}

