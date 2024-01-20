/*
 * Student name:
 * Student ID  :
 
 * Tutorial 10 - Heap
 *
 * Your task is to implement a check if the given binary tree is a heap. isHeap is implemented with two functions: 
 * isComplete and isDecending to check the heap properties.
 * You can choose to implement recursive version of isComplete or alternatively implement iterative version
 * with queue. Or both!
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>


using namespace std;

// -----------------------------------------------------------------------------------tree structure defined for you

struct treeInfo
{
    char symb;
    int key;
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
    osObject << t.symb << "(" << t.key << ")";
    return osObject;
}


/*
 * Convert an array representation of a binary tree to the linked representation.
 * The array representation uses a period '.' character to indicate an empty node.
 * The key of a node is represented by the ASCII value of its symbol.
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
        t->info.key = array[index];
        t->left = buildTree(array, 2 * index + 1, size);
        t->right = buildTree(array, 2 * index + 2, size);
    }
    return t;
}

// ------------------------------------------------- complete the functions below

/**
 * Function checks if the tree is complete using level order traversal and queue.
 *
 * tree         a pointer to the root of a tree
 *
 */
bool isComplete_queue(treeNode<treeInfo>* root)
{
    struct queueItem
    {
        treeNode<treeInfo> *ptr;
        int index;
    } x;

    queue<queueItem> Q;

    if (root != NULL)
    {
        x.ptr = root;
        x.index = 0;
        Q.push(x);
    }    
    
    int nextIndex = 0;
    bool isComplete = true;

    while(!Q.empty() && isComplete)
    {
        x = Q.front();
        Q.pop();

        int curIndex = x.index;
        treeNode<treeInfo> *p = x.ptr;

        if (curIndex != nextIndex)
            isComplete = false;

        if (p->left != NULL)
        {
            x.ptr = p->left;
            x.index = curIndex * 2 + 1;
            Q.push(x);
        }
        
        if (p->right != NULL)
        {
            x.ptr = p->right;
            x.index = curIndex * 2 + 2;
            Q.push(x);
        }

        nextIndex++;
    }
    
    return isComplete;
}


/**
 * A recursive function to check if the tree is complete.
 *
 * tree         a pointer to the root of a tree
 * index        index of the current node
 * node_count   number of nodes
 *
 */
bool isComplete_rec(treeNode<treeInfo>* root, unsigned int index,
                    unsigned int count)
{
    // An empty tree is complete
    if (root == NULL)
        return true;
    
    // If index assigned to current node is more than
    // number of nodes in tree, then tree is not complete
    if (index >= count)
        return false;
    
    // Recursively check left and right subtrees. Assign index to lext and right child.
    return (isComplete_rec(root->left, 2*index + 1, count) &&
            isComplete_rec(root->right, 2*index + 2, count));
}

/**
 * Function checks the heap decending property in the tree.
 *
 * tree         a pointer to the root of a tree
 *
 */
bool isDescending(treeNode<treeInfo>* root)
{    
    if (root == NULL)
        return true;
    
    bool descend = true;
    if (root->left != NULL)
        descend = (root->info.key >= root->left->info.key) && isDescending(root->left);
    if (descend && root->right != NULL)
        descend = (root->info.key >= root->right->info.key) && isDescending(root->right);

    return descend;
}


unsigned int nodeCount(treeNode<treeInfo>* root)
{
	if (root == NULL)
		return 0;

	return 1 + nodeCount(root->left) + nodeCount(root->right);
}


/**
 * Function checks if the given tree is a max-heap.
 *
 * tree         a pointer to the root of a tree
 * node_count   number of nodes
 *
 */
bool isMaxHeap(treeNode<treeInfo>* root)
{   
    // Implement this function.

    // You need to check 2 properties in this function
    // 1. the tree is complete
    // 2. the tree is deccending

    // You shall need to implement 2 supporting functions isComplete()
    // and isDescending(). 
    // You need to define the function interface yourself.

    // Answer 1:

    //return isComplete_queue(root) && isDescending(root);


    
    // Answer 2:

    unsigned int count = nodeCount(root);
    return isComplete_rec(root, 0, count) && isDescending(root);

    
}


int main() {
    
    char arrayTree1[] = "HGFEDBCA";
    treeNode<treeInfo> *tree1;
    
    int len = strlen(arrayTree1);
    
    cout << "Array representation of the tree: " << arrayTree1 << endl;
    cout << "and its length = " << len << endl << endl;
    
    tree1 = buildTree(arrayTree1, 0, len);
    printTree(tree1, 0);
    cout << endl;
    
    if(isMaxHeap(tree1)) {
        cout << "It's a max-heap!"  << endl;
    } else {
        cout << "It's not a max-heap! "  << endl;
        
    }
    
    char arrayTree2[] = "HGFEKBCA";
    treeNode<treeInfo> *tree2;
    
    len = strlen(arrayTree2);
    
	cout << endl << "----------------------------------------\n";
    cout << "Array representation of the tree: " << arrayTree2 << endl;
    cout << "and its length = " << len << endl << endl;
    
    tree2 = buildTree(arrayTree2, 0, len);
    printTree(tree2, 0);
    cout << endl;
    
    if(isMaxHeap(tree2)) {
        cout << "It's a max-heap!"  << endl;
    } else {
        cout << "It's not a max-heap! "  << endl;
        
    }

    char arrayTree3[] = "HGFEDBC..AB";
    treeNode<treeInfo> *tree3;
    
    len = strlen(arrayTree3);
    
	cout << endl << "----------------------------------------\n";
    cout << "Array representation of the tree: " << arrayTree3 << endl;
    cout << "and its length = " << len << endl << endl;
    
    tree3 = buildTree(arrayTree3, 0, len);
    printTree(tree3, 0);
    cout << endl;
    
    if(isMaxHeap(tree3)) {
        cout << "It's a max-heap!"  << endl;
    } else {
        cout << "It's not a max-heap! "  << endl;
        
    }    
    
    system("pause");
    exit(0);
}

