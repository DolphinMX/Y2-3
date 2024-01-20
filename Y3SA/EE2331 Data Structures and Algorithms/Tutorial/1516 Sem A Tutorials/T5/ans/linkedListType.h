//Student name:
//Student ID  :

// Complete the implementation of the member function removeDuplicates() for the class linkedListType.
// The function is defined at the bottom.


#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <ostream>			// use cout in the print() function

using namespace std;

//----------------------------------------- nodeType

template<class Type>  //definition of node
struct nodeType
{
	Type info;
	nodeType<Type> *link;
};

//----------------------------------------- Iterator

template<class Type>     //The functions are simple, hence,
class linkedListIterator //they are included in the class definition
{
private:
	nodeType<Type> *current;

public:
	linkedListIterator() 
	{  current = NULL;  }

	linkedListIterator(nodeType<Type> *ptr)
	{  current = ptr;   }

	Type operator*() 
	{  return current->info;  }

	linkedListIterator<Type> operator++()  //pre-increment operator
	{
		current = current->link;
		return *this;
	}

	bool hasNext()
	{
		return current != NULL;
	}

	bool operator==(const linkedListIterator<Type>& other)
	{  return current == other.current;  }

	bool operator!=(const linkedListIterator<Type>& other)
	{  return current != other.current;  }
};

//----------------------------------------- linkedList

template<class Type>  
class linkedListType
{
protected:
	int count;              // no. of elements in the list
	nodeType<Type> *first;  // pointer to the first node
	nodeType<Type> *last;   // pointer to the last node

public:
	linkedListType(); //default constructor

	//copy constructor, 
	//it is used when an object is passed to a function by value
	linkedListType(const linkedListType<Type>& other);
	
	~linkedListType(); //destructor

	const linkedListType<Type>& operator=(const linkedListType<Type>& other);

	void initializeList();
	bool isEmptyList() const;
	void print() const;
	int length() const;
	void destroyList(); //clear the list
	virtual bool search(const Type& x) const; 
	virtual void insert(const Type& x); 
	void removeDuplicates();

	Type remove_front(); //remove front node and return the data value
	//the list must be non-empty

	linkedListIterator<Type> begin();
	linkedListIterator<Type> end();

	//There can be additional member functions, but to simplify
	//the discussion, we will only consider the above functions.

private:
	void copyList(const linkedListType<Type>& other);
	//private function used in the copy constructor and operator=
};

//---------------------------------------- Implementations of member functions

template<class Type>
linkedListType<Type>::linkedListType()
{
	count = 0;
	first = last = NULL;
}


template<class Type>
void linkedListType<Type>::destroyList()
{  //clear the list, free the storage occupied by the nodes

	nodeType<Type> *temp;

	while (first != NULL)
	{
		temp = first;
		first = first->link;
		delete temp;      
	}
	count = 0;
	last = NULL;  //first == NULL, guaranteed by the while-loop
}


template<class Type>
linkedListType<Type>::~linkedListType()
{
	destroyList();
}

template<class Type>
void linkedListType<Type>::copyList(const linkedListType<Type>& other)
{
	if (first != NULL)
		destroyList(); //clear the old contents of the list

	if (other.first == NULL) // the other list is empty
		return; 

	//copy the first node
	first = new nodeType<Type>;
	first->info = other.first->info;
	first->link = NULL;
	last = first;

	//copy the remaining nodes
	nodeType<Type> *p = other.first->link; 

	while (p != NULL) 
	{
		last->link = new nodeType<Type>;
		last = last->link;
		last->info = p->info;
		p = p->link;
	}
	last->link = NULL;
	count = other.count;
}


template<class Type>
void linkedListType<Type>::initializeList()
{
	count = 0;
	first = last = NULL;
}


template<class Type>
linkedListType<Type>::linkedListType(const linkedListType<Type>& other)
{
	initializeList();
	copyList(other);   
}


template<class Type>
const linkedListType<Type>& linkedListType<Type>::
	operator=(const linkedListType<Type>& other)
{
	if (this != &other) //avoid self-copy   
		copyList(other);

	return *this;
}


template<class Type>
bool linkedListType<Type>::isEmptyList() const
{
	return count == 0; // or return first == NULL;
}

template<class Type>
void linkedListType<Type>::print() const
{
	nodeType<Type> *p;
	p = first;
	while (p != NULL)
	{
		cout << p->info << " ";
		p = p->link;
	}
	cout << endl;
}


template<class Type>
int linkedListType<Type>::length() const
{
	return count;
}


template<class Type>
bool linkedListType<Type>::search(const Type& x) const
{
	nodeType<Type> *p;

	p = first;
	while (p != NULL && p->info != x)
	{
		p = p->link;
	}
	return p != NULL;
}


template<class Type>
void linkedListType<Type>::insert(const Type& x) 
{   //append at the end of the list

	nodeType<Type> *p = new nodeType<Type>;
	p->info = x;
	p->link = NULL;

	if (first == NULL)
		first = last = p;
	else
	{  
		last->link = p;
		last = p;
	}
	count++;
}


template<class Type>
Type linkedListType<Type>::remove_front() 
{   //Remove the front node and return the data value.
	//Precondition: the list must be non-empty.

	nodeType<Type> *p;
	Type x;

	p = first;
	x = first->info;  //Null-pointer exception occurs
	                  //if the list is empty

	if (first == last)
		first = last = NULL;
	else
		first = first->link;

	delete p;
	count--;

	return x;
}


template<class Type>
linkedListIterator<Type> linkedListType<Type>::begin() 
{
	linkedListIterator<Type> temp(first);
	//create an iterator that references the beginning of the list

	return temp;
}


template<class Type>
linkedListIterator<Type> linkedListType<Type>::end() 
{
	linkedListIterator<Type> temp(NULL);
	return temp;
}


//---------------------------------------------- function to be implemented by you
template<class Type>
void linkedListType<Type>::removeDuplicates()
{
	nodeType<Type> *p, *q, *dup;
	p = first;

	// Handle elements one by one. Node p is the pivot.
	while(p != NULL)  
	{
		q = p;

		// Compare the pivot element with rest of the elements.
		// Node q is the predecessor of the element under consideration.
		while(q->link != NULL)
		{
			if(p->info == q->link->info) // Duplicate found, remove
			{

				dup = q->link;
				q->link = dup->link;  // Skip dup node

				if (dup == last)  // If removing last node, update tail
					last = q;

				delete dup; // Deallocate memory
				count--;	
			}
			else        
				q = q->link; // Proceed to next element

		}
		p = p->link; // Pick next pivot
	}
}


#endif  //end of the file linkedListType.h