#include <iostream>
#include <fstream>

using namespace std;

struct ListNode {
	int info;
	ListNode* link;
};

// append the new element at the end of the list
void append(ListNode*& head, int x) {
	ListNode* p = new ListNode;
	p->info = x;
	p->link = NULL;

	if (head == NULL) {
		p->link = head;
		head = p;
	}
	else {
		ListNode* prev = head;
		ListNode* cur = head->link;

		while (cur != NULL) {
			prev = cur;
			cur = cur->link;
		}

		p->link = prev->link;
		prev->link = p;
	}
}

// read file and initialize the linked list
ListNode* initialize_list(string s) {
	ListNode* head = NULL;
	ifstream inFile(s);

	if (!inFile.is_open()) {
		cout << "Error: cannot open data file" << endl;
		exit(0); //terminate the program
	}

	while (!inFile.eof()) { //not end of file
		int i;
		inFile >> i;    //read in an integer

		if (!inFile.fail())
			append(head, i); //insert into the linked list
		else
			break;
	}

	inFile.close();
	return head;
}

// print all the elements in the linked list
void print(ListNode* head) {
	ListNode* cur = head;
	while (cur != NULL) {
		cout << cur->info << " ";
		cur = cur->link;
	}
	cout << endl;
}
/************************ Do not modify the code above ***********************/


/*****************  Please implement the merge function here *****************/

ListNode* merge(ListNode* head1, ListNode* head2) {
	/* Please implement this function */
	ListNode* new_head = NULL;

	while (head1 != NULL or head2 != NULL) {
		if (head1 == NULL) {
			append(new_head, head2->info);
			head2 = head2->link;
		}
		else if (head2 == NULL) {
			append(new_head, head1->info);
			head1 = head1->link;
		}
		else {
			if (head1->info <= head2->info) {
				append(new_head, head1->info);
				head1 = head1->link;
			}
			else {
				append(new_head, head2->info);
				head2 = head2->link;
			}
		}
	}
	return new_head;
}

/*****************************************************************************/

int main() {
	ListNode* head1 = NULL;
	ListNode* head2 = NULL;
	
	head1 = initialize_list("sortA.txt");
	head2 = initialize_list("sortB.txt");

	cout << "Contents of the list 1: ";
	print(head1);
	cout << "Contents of the list 2: ";
	print(head2);

	ListNode* new_head = NULL;


	/*****************  Please implement the merge function *****************/
	new_head = merge(head1, head2);

	/************************************************************************/


	cout << "This is the output of the new list after merging:";
	print(new_head);
}

