#include <iostream>
#include <cstdlib>
#include <ctime>
#include "myList.h"


// Implement a recursive and a non-recursive function in myList.h to find the max subsequence of the list.

using namespace std;

int main()
{
    srand((unsigned)time(NULL));
    
    myList<int> list1;
    
    int len = 5 + rand() % 9;
    
    for (int i = 0; i < len; i++)
    {
        int k = rand() % 9 + 1;
		if (rand() % 3 == 0)
			k *= -1;

        list1.insert(k);
    }
    
    cout << "list: " << endl;
    list1.print();

	cout << "maxSubSeq = " << list1.maxSubSeq() << " (non-recursive)" << endl;
	cout << "maxSubSeq = " << list1.maxSubSeq_r() << " (recursive)" << endl;
	

	cout << endl << "--- list with all negative values ---" << endl;
	list1.toNegative();

	cout << "list: " << endl;
    list1.print();
	cout << "maxSubSeq = " << list1.maxSubSeq() << " (non-recursive)" << endl;
	cout << "maxSubSeq = " << list1.maxSubSeq_r() << " (recursive)" << endl;    
    
    cout << endl;
    
    system("pause");
    exit(0);
    
}