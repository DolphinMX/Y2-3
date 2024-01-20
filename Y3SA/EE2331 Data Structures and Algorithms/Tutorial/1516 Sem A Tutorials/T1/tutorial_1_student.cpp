// Student name:
// Student ID  :

/*
An array of integers is generated in the main() function.
The array is unordered, and may contain duplicated values.

You are asked to implement the functions findMaxMin() findRepeatedBlocks(), and findMostRepeated().
*/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
void printSeq(int A[], int s, int e);

//---------------------------------------------- functions to be implemented by you

//
// Find the maximun and minimum numbers in the array A[]. n is the number of elements in A[].
// Maximun and minimun are set as reference parameter values (max, min).
// precondition:  A[] is non-empty
void findMaxMin(int A[], int n, int& max, int& min) {

}

// Find repeated block in array A[] and print them. n is the number of elements in A[]. E.g. for
// A = [2, 6, 6, 6, 4, 2, 7, 7,] the function should print
// 6 6 6 and 7 7. Use printSeq() for printing.
// If a repeated block if found, the return value should be 1, otherwise zero.
int findRepeatedBlocks( int A[] , int n) {

	return 0;
}


// Find the most repeated number in the array A[]. n is the number of elements in A[]. Return value is the number itself
// and number of occurences is set a reference parameter value (occurences).
int findMostRepeated(int A[], int n, int& occurences)  {

	return 0;
}



//-------------------------------------------- functions prepared for you

void printSeq(int A[], int s, int e)
{
	int i = s;
	while (i < e)
		cout << A[i++] << ", ";
	cout << A[i] << endl;
}

int main()
{
	int size;

	cout << "Enter size of array: ";
	cin >> size;

	int *A = new int[size];

	srand(time(NULL));

	for (int i = 0; i < size; i++)
		A[i] = rand() % 5 + 1;

	cout << endl << "Contents of array:" << endl;
	printSeq(A, 0, size-1);

	int max = 0;
	int min = 0;

	findMaxMin(A, size, max, min);
	cout << "max number = " << max << " min number = " << min << endl << endl;


	if( findRepeatedBlocks(A, size) ) {
		cout << "Found repeated block(s) in array!\n" << endl << endl;
	} else {
		cout << "No repeated block in array!\n" << endl << endl;
	}

	int occurences = 0;
	int mostFrequent = findMostRepeated(A, size, occurences);
	cout << "Most frequent number: ";
	cout << mostFrequent;
	cout << " Occurences: ";
	cout << occurences << endl << endl;

	system("pause");
	return 0;
}
