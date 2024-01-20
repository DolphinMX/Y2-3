//Student name:
//Studnet ID  :

/*
 Your tasks:
 
 1. Implement the function isSublist() in this file.
 The function isSublist() determines if a given list (list B) is a sublist of another given list (list A).
 Return true, if it's a sublist. Othervise return false.
 
 2. Implement the function duplicate() in this file.
 The function dublicates the list contents. E.g. [4,6,1,5] becomes [4,6,1,5,4,6,1,5]
 
 */

#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;

//------------------------------------------- linked list structure and functions prepared for you

struct node {
    int info;
    struct node *link;
};

node* createNode(int info) {
    node *p;

    p = new node;
    if (p == NULL) {
        exit(1); 		// error
    }
    p->info = info;
    p->link = NULL;
    return p;
}

void printList(node *list) {
    node *p;

    p = list;
    while (p != NULL) {
        printf("[%d]-> ", p->info);
        p = p->link;
    }
    printf("NULL\n");
}

//---------------------------------------------- function to be implemented by you


bool isSublist(node* listA, node* listB) {

    return false;
}


void duplicate(node* list) {
	
}


//------------------------------------------- main function prepared for you


int main() {
	
    node *listA, *listB, *p;
    int k, len, sublen;
    
    srand((unsigned)time(NULL));
    
    // create listA
    cout << "Enter length of list A (>= 0): ";
	cin >> len;
	
	listA = NULL;
	if (len > 0)
	{
		listA = createNode(rand() % 4 + 1);
		p = listA;	
		for (int i = 1; i < len; i++) {
			k = rand() % 4 + 1;
			p->link = createNode(k);
			p = p->link;
		}
	}

	cout << "List A: ";
	printList(listA);

	// create listB
	cout << "\nEnter length of list B (> 0): ";
	cin >> sublen;

	cout << "Enter content of the list B (separated by space): ";
	cin >> k;
	listB = createNode(k);
	p = listB;
	for (int i = 1; i < sublen; i++) {
		cin >> k;
		p->link = createNode(k);
        p = p->link;
	}
	
	cout << "List B: ";
	printList(listB);
	cout << endl;
	
	
	if (isSublist(listA, listB)) {
		cout << "List B is a sublist of list A!" << endl; 
	} else {
		cout << "List B is not a sublist of list A!" << endl; 
	}

	cout << "\nDuplicate list A: " << endl;
	duplicate(listA);
	printList(listA);

	system("pause");
	return 0;
}

