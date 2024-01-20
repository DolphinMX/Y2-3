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
		if (count == 0)
			return 0;

		Type max = first->info;			// max sum of subsequences
		Type curMax = first->info;		// sum of current subsequence

		nodeType<Type> *p = first->link;

		while (p != NULL)
		{
			curMax = (curMax > 0) ? (curMax + p->info) : p->info;
			max = (curMax > max) ? curMax : max;

			p = p->link;
		}
		return max;
	}

    
private:
   
	Type recursive_maxSubSeq(Type curMax, nodeType<Type> *p)
	{
		Type tempMax;

		if (p == NULL)
			return curMax;
		else if (curMax > 0)		
			tempMax = recursive_maxSubSeq(curMax + p->info, p->link);
		else
			tempMax = recursive_maxSubSeq(p->info, p->link);

		if (tempMax > curMax)
			return tempMax;
		else
			return curMax;

	}
    
};

#endif