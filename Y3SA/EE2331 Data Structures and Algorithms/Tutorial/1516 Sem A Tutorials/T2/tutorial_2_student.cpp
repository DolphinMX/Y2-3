// Student name:
// Student ID  :

// This tutorial is about merging and splitting arrays

#include <iostream>
#include <iomanip>  //setw()
#include <cstdlib>
#include <ctime>

using namespace std;


//----------------------------------------------- functions to be implemented by you

// Merge two given ordered arrays, A and B. Store the resulting merged numbers into ordered array C. Array A contains
// m elements and array B contains n elements. Thus, the size of array C is m+n. (If there are duplicates, they will
// also appear in array C.)
void mergeSortedArrays(int m, int n, int* A, int* B, int* C) {   
	
    
}

// Split array A into two subarrays oddArray and evenArray, such that even number goes to evenArray and odd numbers goes to oddArray.
// m is the number of elements in array A. 
// Number of even elements is returned via the reference parameter even.
// Number of odd values is returned via the reference parameter odd.
// The two subarrays, oddArray and evenArray, are to be created by your function. 
// The size of the array is equal to the number of elements to be stored in the array.
// NOTE: You need to use pointer syntax. You are not allowed to use array subscript [] to index elements.
void splitToEvenAndOdd(int m, int* A, int*& oddArray, int*& evenArray, int& odd, int& even) {
    
	
}


//----------------------------------------------- functions prepared for you

void initArrayOrdered(int* A, int n)
{
    // Initialize the array A[n] ascendingly such that
    // A[i] < A[i+1] for 0 <= i < n-1.
    
    int c = rand() % 10;
    
    int i = 0;
    while(i < n) {
        c += rand() % 5 + 1;
        A[i]= c;
        i++;
    }
}

void printArray(int* A, int n)
{
    int i=0;
    for (i = 0; i < n-1; i++) {
        cout << setw(3) << A[i] << ",";
    }
    if (n > 0) {
        cout << setw(3) << A[i] << endl;
    }
	cout << endl;
}

int main()
{
    cout << "Exercise on merging sorted arrays" << endl << endl;
    
    int sizeA;
    cout << "Enter number of elements in array A: ";
    cin >> sizeA;
    
    int sizeB;
    cout << "Enter number of elements in array B: ";
    cin >> sizeB;
    
	int sizeC = sizeA + sizeB;
    int* A = new int[sizeA];
    int* B = new int[sizeB];
    int* C = new int[sizeC];
    
	srand(time(NULL));

    initArrayOrdered(A, sizeA);
	cout << endl;
    cout << "A: " << endl;
    printArray(A, sizeA);
    
	initArrayOrdered(B, sizeB);
    cout << "B: " << endl;
    printArray(B, sizeB);
    
    mergeSortedArrays( sizeA, sizeB,  A, B, C);
    cout << "C: " << endl;
    printArray(C, sizeC);

	int *D, *E, sizeD, sizeE;
	// array D and array E are to be created inside your function
    splitToEvenAndOdd(sizeC, C, D, E, sizeD, sizeE);
	cout << "D (Odds): " << endl;
    printArray(D, sizeD); 
    cout << "E (Evens): " << endl;
    printArray(E, sizeE);       
    
    system("pause");
    return 0;
}