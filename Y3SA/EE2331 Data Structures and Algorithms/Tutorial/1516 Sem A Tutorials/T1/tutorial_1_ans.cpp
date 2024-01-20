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

	min = A[0]; // initialize with the first element
	max = A[0];

	for( int i = 1; i < n; i++ ) // iterate the array
	{
		if ( min > A[i] ) // update min
		{
			min = A[i];
		}
		else if ( max < A[i] ) // update max
		{
			max = A[i];
		}
	}
}


// Find repeated blocks in array A[] and print them. n is the number of elements in A[]. E.g. for
// A = [2, 6, 6, 6, 4, 2, 7, 7,] the function should print
// 6 6 6 and 7 7. Use printSeq() for printing.
// If a repeated block if found, the return value should be 1, otherwise zero.
int findRepeatedBlocks( int A[] , int n) {
	int found = 0;

	int i = 0;
	while (i < n) { // iterating throught the whole array
		int count = 1;
		for(int j = i + 1; j < n && A[j] == A[i]; j++ ) // iterating a block
			count ++;
		
		// end of block

		if(count > 1) {  // print if block size is bigger that one
			printSeq(A, i, i + count - 1);
			found = 1; // set return value
		}

		i += count;  // unconditional update
	}
	return found;
}




// Find the most repeated number in the array A[]. n is the number of elements in A[]. Return value is the number itself
// and number of occurences is set a reference parameter value (occurences).
int findMostRepeated(int A[], int n, int& occurences)  {
	occurences = 0;
	int noCurrent = 0; // currently found most occurences
	int mostFrequent = 0; // value of the current most frequent

	for( int i = 0; i < n; i++)  {
		noCurrent = 1;

		for( int j = i+1; j < n; j++) // to avoid dublicate we only consider the rest of the array
			if( A[j] == A[i]) 
				noCurrent++; // increase occurence

		if(noCurrent > occurences) { // update the current max values 
			occurences = noCurrent;
			mostFrequent = A[i];
		}
	}
	return mostFrequent;
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
		cout << "No repeat block in array!\n" << endl << endl;
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
