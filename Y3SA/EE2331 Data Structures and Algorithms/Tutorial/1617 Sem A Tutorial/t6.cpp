/* 
 * Student name:
 * Student ID  :
 *
 * You are asked to implement the functions reverseList() and rotateList() as specified below.
 * Your implementation cannot use any c++ built-in data structures or algorithms.
 * Test cases are defined in the main() function. No modification is needed.
 * 
 */

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>

using namespace std;

/* Linked list node */
struct node {
    int data;
    node* next;
};

//-------------------------- functions to be implemented by you

/*
 * The function reverses the input linked list, i.e. re-linking the nodes in 
 * reverse order, and returns its new head. 
 * 
 * Precondition: 
 * - input list is singly-linked, non-circular, with no header node.
 */
node* reverseList(node* head) {

    
    
    
}

/*
 * This function rotates the input linked list counter-clockwisely by k nodes
 * and returns its new head. 
 * 
 * Precondition: 
 * - input list is singly-linked, non-circular, with no header node.
 * - k is not greater than the length of the input list
 */
node* rotateList(node* head, int k) {


    
    
}

//-------------------------- functions prepared for you

/*
 * Helper class for creating/printing a list from an array.
 */
class ListHelper {
public:
    // new a list based on array input

    static node* newList(int* arr, int n) {
        node* dummy = newNode(n); // put the size n
        node* head = dummy;
        for (int i = 0; i < n; i++) {
            dummy->next = newNode(arr[i]);
            dummy = dummy->next;
        }
        //return head;          // with dummy header
        return head->next; // without dummy header
    }

    // new one single node

    static node* newNode(int data) {
        return new node({data, NULL});
    }

    //print nodes in a given linked list

    static void printList(node *list) {
        while (list != NULL) {
            printf("%d ", list->data);
            list = list->next;
        }
    }

    //print nodes in a given linked list

    static void deleteList(node *list) {
        node* temp;
        while (list != NULL) {
            temp = list;
            list = list->next;
            delete temp;
        }
    }
};

/*
 * Driver program to test above functions against default test cases.
 */
int main(int argc, char** argv) {

    ifstream fin("t6_input.txt");
    if (!fin) {
        cout << "Input file not found.";
        exit(1);
    }

    int testcase = 0;
    fin >> testcase;

    for (int i = 0; i < testcase; i++) {

        int n1, k;
        fin >> n1 >> k;
        int* arr1 = new int[n1];
        for (int j = 0; j < n1; j++)
            fin >> arr1[j];

        cout << "Case " << i << endl;
        node* list1 = ListHelper::newList(arr1, n1);
        cout << "list: ";
        ListHelper::printList(list1);
        cout << endl;

        cout << "reverse list: ";
        node* result = reverseList(list1);
        ListHelper::printList(result);
        cout << endl;

        cout << "rotate list by " << k << " nodes: ";
        result = rotateList(result, k);
        ListHelper::printList(result);
        cout << endl << endl;

        ListHelper::deleteList(result);
    }

    return 0;
}

