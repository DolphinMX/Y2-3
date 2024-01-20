//Student name:
//Studnet ID  :

/*
    Your tasks:

	1. Define and implement the function isSublist() in this file.
		The function isSublist() determines if a given list (sublist) is a sublist of the given list (list).
		Return true, if it's a sublist. Otherwise return false.

    2. Implement the member function removeDuplicates() for the class linkedListType<Type>, which 
	   is defined at the bottom of the file linkedListType.h.
	   The function removes duplicated values from the list. E.g. [2,5,7,3,4,2,5,4] becomes [2,5,7,3,4]

*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "linkedListType.h"

using namespace std;


//---------------------------------------------- function to be implemented by you
template<class Type>
bool isSublist(linkedListType<Type>& list, linkedListType<Type>& sublist)
{
    linkedListIterator<int> iter = list.begin();
   
    linkedListIterator<int> eol = list.end();
    
    linkedListIterator<int> eolsub = sublist.end();
    
    int resListLen = list.length();
    // residue length of list not yet processed
  
    int subListLen = sublist.length();
    
    while (resListLen >= subListLen) 
    {
        linkedListIterator<int> itersub = sublist.begin();
        linkedListIterator<int> itertemp = iter; // set starting point
        
        while (itersub != eolsub && *itertemp == *itersub)
        {
            ++itertemp;
            ++itersub;            
        }

		if(itersub == eolsub) // this test should be placed outside the while-loop
            return true;
            
        ++iter;
        resListLen--;
    } // we cloud stop if remaining elements are less than size of sublist..
    
    return false;
}

//------------------------------------------- main function prepared for you

int main()
{
	linkedListType<int> listA;
	int len;
	int k;
	cout << "Enter length of list: ";
	cin >> len;

	srand((unsigned)time(NULL));
	for (int i = 0; i < len; i++)
	{
		int k = rand() % 4 + 1;
		listA.insert(k);
	}
	
	cout << "Contents of the linked list A: " << endl;
	listA.print();

	linkedListType<int> listB;
	int sublen;

	// create listB
	cout << "\nEnter length of list B (> 0): ";
	cin >> sublen;

	cout << "Enter content of the list B (separated by space): ";

	for (int i = 0; i < sublen; i++) {
		cin >> k;
		listB.insert(k);
	}
	
	cout << "Contents of list B: " << endl;
	listB.print();

	if (isSublist(listA, listB)) {
		cout << "List B is a sublist of list A!" << endl; 
	} else {
		cout << "List B is not a sublist of list A!" << endl; 
	}

	cout << "Contents of the list A after removing duplicates: " << endl; 
	listA.removeDuplicates();
	listA.print();
		
	system("pause");
	return 0;
}
