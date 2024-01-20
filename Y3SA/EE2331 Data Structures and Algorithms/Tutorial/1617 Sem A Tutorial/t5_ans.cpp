/* 
 * Student name:
 * Student ID  :
 *
 * You are asked to implement the function mergeSortedList() as specified below.
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
 * The function takes two lists, each of which is sorted in ascending order, and 
 * merges them into one list with ascending order. The head of the merged list is
 * returned. 
 * 
 * Time complexity: O(n)
 * Space complexity: O(1)
 * 
 * Precondition: all lists are singly-linked, non-circular, with no header node.
 */
node* mergeSortedList(node* list1, node* list2) {
    node* dummy = new node({0, NULL});
    node* head = dummy;

    if (list1 == NULL || list2 == NULL)
        return list1 ? list1 : list2;

    while (list1 != NULL && list2 != NULL) {
        if (list1->data < list2->data) {
            dummy->next = list1;
            list1 = list1->next;
        } else {
            dummy->next = list2;
            list2 = list2->next;
        }
        dummy = dummy->next;
    }

    if (list1 != NULL)
        dummy->next = list1;
    if (list2 != NULL)
        dummy->next = list2;

    return head->next;
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

    ifstream fin("t5_input.txt");
    if (!fin) {
        cout << "Input file not found.";
        exit(1);
    }

    int testcase = 0;
    fin >> testcase;

    for (int i = 0; i < testcase; i++) {

        int n1, n2;
        fin >> n1 >> n2;
        int* arr1 = new int[n1];
        for (int j = 0; j < n1; j++)
            fin >> arr1[j];

        int* arr2 = new int[n2];
        for (int j = 0; j < n2; j++)
            fin >> arr2[j];

        cout << "Case " << i << endl;
        node* list1 = ListHelper::newList(arr1, n1);
        cout << "list 1: ";
        ListHelper::printList(list1);
        cout << endl;

        cout << "list 2: ";
        node* list2 = ListHelper::newList(arr2, n2);
        ListHelper::printList(list2);
        cout << endl;

        cout << "merged list: ";
        node* result = mergeSortedList(list1, list2);
        ListHelper::printList(result);
        cout << endl << endl;

        ListHelper::deleteList(result);
    }

    return 0;
}

