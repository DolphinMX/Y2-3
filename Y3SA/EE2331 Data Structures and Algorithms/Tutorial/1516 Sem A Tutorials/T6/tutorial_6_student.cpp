#include <iostream>
#include <cstdlib>
#include <ctime>
#include "myList.h"

// Your task:
// Implement two recursive functions in myList.h, search_r and remove_r


using namespace std;

int main()
{
	srand((unsigned)time(NULL));

	myList<int> list1;

	int len = rand() % 9;

	for (int i = 0; i < len; i++)
	{
		int k = rand() % 9;
		list1.insert(k);
	}

	cout << "list1: " << endl;
	list1.print();
	cout << endl;

	int value;
	cout << "Input value to be searched: " << endl;
	cin >> value;

	if(list1.search_r(value)) {
		cout << "Value: " << value <<" was found!"<< endl;
	} else {
		cout << "Value: " << value <<" was not found!"<< endl;

	}

	cout << endl;
	cout << "Input value to be removed: " << endl;
	cin >> value;

	if(list1.remove_r(value)) {
		cout << "Value: " << value <<" was removed!"<< endl;
	} else {
		cout << "Value: " << value <<" was not found!"<< endl;
	}

	list1.print();
	cout << endl;

	system("pause");
	exit(0);	
}