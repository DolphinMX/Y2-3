//Student name:
//Student ID  :

#ifndef MYLIST_H
#define MYLIST_H

#include "linkedListType.h"

template <class Type>
class myList : public linkedListType<Type>
{

public:

	// Recursive search, wrapper for recursive_search. Returns true if the value is found.
	bool search_r(Type value)
	{
		return recursive_search(value, first);
	}

	// Recursive remove, wrapper for recursive_remove. Removes first occurance of value. Returns true if the value is found and removed.
	bool remove_r(Type value)
	{
		// handle two bounary cases separately without using recursion
		if (first == NULL)
			return false;
		else if (first->info == value)
		{
			nodeType<Type>* deleteNode = first;
			if (first == last)
				first = last = NULL;
			else
				first = first->link;

			delete deleteNode;
			count--;
			return true;
		}
		else
			return recursive_remove(value, first);
	}


//----------------------------------------- Your implementation:

private:

	bool recursive_search(Type value, nodeType<Type>* p) 
	{
		if( p != NULL ) {
		
			if (p->info == value) { 
				return true;
			}
			return recursive_search(value, p->link);
		} 
		return false;
	}


	bool recursive_remove(Type value, nodeType<Type>* p)
	{
		if (p->link == NULL)
			return false;
		else if (p->link->info == value) // Next node is to one to be removed
		{
			nodeType<Type>* deleteNode = p->link;   // Save ptr to next
			p->link = deleteNode->link;			// Reassign current->link ptr

			if (deleteNode == last) 	// If deleting last node, update last ptr
				last = p;			

			delete deleteNode;          // Delete the node
			count--;
			return true;
		}
		else
			return recursive_remove(value, p->link); // Proceed to next node
	}

};

#endif