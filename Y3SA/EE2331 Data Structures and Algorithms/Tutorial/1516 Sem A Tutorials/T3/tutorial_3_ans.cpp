// Student name:
// Student ID  :

// This tutorial is about efficency and asymptotic analysis

#include <iostream>
#include <iomanip>  //setw()
#include <cstdlib>
#include <ctime>

using namespace std;


//----------------------------------------------- functions to be implemented by you


// Given a sorted array of integers containing 2 values, x and y, where x < y.
// Determine the number of the smaller integer x (numX) in the array. You can assume
// numX > 0. Return value is numX.

// Simple solution using sequential processing will require O(n) time.
// Implement an improved solution that is based on binary search. It should solve the problem in
// O(log n) time.
int findNumberOfSmallerInteger(int n, int* A) {
	int low = 0;
	int high = n-1;
	int mid = 0;

	// Implementation 1
	// Loop invariant: A[0..low-1] <= A[0] and A[(high+1)..(n-1)] > A[0]
	while (low <= high)
	{
	    mid = (low + high) / 2;

	    if (A[mid] > A[0]){ 	// move to left
	        high = mid - 1;
	    } else { 				// move to right
	        low = mid + 1;
	    }
	}
	// postcondition: ( low == high+1 ) and ( A[0..high] <= A[0] and A[(high+1)..(n-1)] > A[0] )
	// hence numX = low
	return low;

	
	// Implementation 2
	/*
	// Loop invariant: A[0..low] <= A[0] and A[(high+1)..(n-1)] > A[0]
	while (low < high-1)
	{
		mid = (low + high) / 2;
		if (A[mid] <= A[0])
			low = mid;   // no progress if initially mid and low are pointing to the same element
		else
			high = mid - 1;
	}
	// postcondition: ( low == high or low == high-1 ) and ( A[0..low] <= A[0] and A[(high+1)..(n-1)] > A[0])	
	// if low == high-1, we need to test the value of A[high] to obtain the final answer
	if (A[high] == A[low])
		return high + 1;
	else
		return low + 1;
	
	*/
}


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


// Given an array with positive numbers, find the maximum subarray of given length.
// If subarray size is not valid, return -1.
// Input:  arr[] = {1, 12, 5, 6, 55, 3}, k = 4
// Result: Maximum subarray of length 4 begins at index 1.
// Maximum subarray is 12 + 5 + 6 + 55 = 78
//
// Efficiency requirement: time consumption should be O(n) and memory consumption should be O(1)
// (i.e. no auxiliary space is used)
int findMaxSubarray(int* A, int n, int subarraySize, int& max_sum) {
	// Check if subarraySize is valid
	if (subarraySize > n || subarraySize < 0 || n < 1)
		return -1;

	// Compute sum of first subarraySize elements
	int sum = A[0];
	for (int i = 1; i < subarraySize; i++)
		sum += A[i];

	max_sum = sum;
	int max_end = subarraySize-1;

	// Compute sum of remaining subarrays
	for (int i = subarraySize; i < n; i++) {
		sum = sum + A[i] - A[i-subarraySize];
		if (sum > max_sum) {
			max_sum = sum;
			max_end = i;
		}
	}

	// Return starting index
	return max_end - subarraySize + 1;
}

//----------------------------------------------- functions prepared for you

void initArrayOrdered(int* A, int n) {
	int x = rand() % 10;
	int y = x + rand() % 10 + 1;
	int numX = rand() % n + 1;

	int i = 0;
	while(i < n) {
		if(i < numX) {
			A[i]= x;
		} else {
			A[i]= y;
		}
		i++;
	}

	cout <<"A: x="<< x <<" y=" << y <<" number of X: " << numX << " number of Y: " << n-numX  << endl;
}


void initRandomArray(int* A, int n) {
	int c = 0;

	int i = 0;
	while(i < n) {
		c = rand() % 10 + 1;
		A[i]= c;
		i++;
	}
}

void printArray(int* A, int n) {
	int i=0;
	for (i = 0; i < n-1; i++) {
		cout << setw(3) << A[i] << ",";
	}
	if (n > 0) {
		cout << setw(3) << A[i] << endl;
	}
	cout << endl;
}

int main() {

	cout << "Exercise on efficiency and asymptotic analysis" << endl << endl;
	srand((unsigned)time(NULL));

	cout << "Part-1" << endl;
	int sizeA = 1;
	int* A = new int[sizeA];
	cout << "CASE 1: Array A is initialized with 1 element" << endl;
	initArrayOrdered(A, sizeA);
	cout << "Number of x in array A is  " << findNumberOfSmallerInteger(sizeA, A) << endl << endl;
	
	sizeA = 10000;
	A = new int[sizeA];	
	cout << "CASE 2: Array A is initialized with 10k elements" << endl;
	initArrayOrdered(A, sizeA);
	cout << "Number of x in array A is  " << findNumberOfSmallerInteger(sizeA, A) << endl << endl;

	cout << "Part-2" << endl;
	int sizeB;
	cout << "Enter number of elements in array B: ";
	cin >> sizeB;

	int* B = new int[sizeB];
	initRandomArray(B, sizeB);
	cout << "B: " ;
	printArray(B, sizeB);

	int subArraySize = 0;
	int max_sum = 0;
	cout << "Enter subarray size for B: ";
	cin >> subArraySize;
	int subArrayStart = findMaxSubarray(B, sizeB, subArraySize, max_sum);
	cout << "Maximum subarray begins at index: " << subArrayStart << ", max_sum = " << max_sum << endl;

	system("pause");
	return 0;

}
