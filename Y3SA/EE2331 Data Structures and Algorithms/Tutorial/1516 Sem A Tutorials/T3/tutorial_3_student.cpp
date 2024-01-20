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

	
	
	return 0;
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
	
	
	
	return 0;
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
