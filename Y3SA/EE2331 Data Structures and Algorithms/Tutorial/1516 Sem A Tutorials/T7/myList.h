//Student name:
//Student ID  :

#ifndef MYLIST_H
#define MYLIST_H

#include "linkedListType.h"

template <class Type>
class myList : public linkedListType<Type>
{
    
public:
    
	void toNegative()
	{
		nodeType<Type> *p = first;
		while (p != NULL)
		{
			if (p->info > 0)
				p->info *= -1;
			p = p->link;
		}
	}

	// Recursively find the max subsequence of the list, wrapper for recursive_maxSubSeq()
	Type maxSubSeq_r()
	{
		if (count == 0)
			return 0;
		else if (count == 1)
			return first->info;
		else
			return recursive_maxSubSeq(first->info, first->link);
	}


	// ---------------------------------------------------------- Your implementation:

	// Find the max subsequence of the list, non-recursive implementation 
	Type maxSubSeq()
	{
		
				
		
		return 0;
	}

    
private:
    
	Type recursive_maxSubSeq(Type curMax, nodeType<Type> *p)
	{
		
		
		
		return 0;
	}  
    
};

#endif