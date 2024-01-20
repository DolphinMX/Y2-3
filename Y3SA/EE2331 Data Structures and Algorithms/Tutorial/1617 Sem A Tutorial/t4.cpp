/* 
 * Student name:
 * Student ID  :
 *
 * You are asked to implement the functions findNextSmallerElementNaive() and findNextSmallerElementSmart() as specified below.
 * Your implementation cannot use any c++ built-in data structures or algorithms.
 * Test cases are defined in the main() function and input.txt. No modification is needed.
 * 
 */

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;


//-------------------------- functions to be implemented by you

/*
 * Find the next smaller element for each element in arr[]. Output -1 if it doesn't exist.
 * The "next" smaller element is defined as the nearest smaller elememt to the right of an element.
 * The function returns an array storing the outputs. For example:
 * 
 *      Input:  [5, 6, 3, 4, 1, 2]
 *      Output: [3, 3, 1, 1, -1, -1]
 * 
 * Naive approach O(n2) is to apply brute force strategy to test all possible combinations. 
 */
int* findNextSmallerElementNaive(int arr[], int n) {
    
    
    
}

/*
 * Find the next smaller element for each element in arr[]. Output -1 if it doesn't exist.
 * The "next" smaller element is defined as the nearest smaller elememt to the right of an element.
 * The function returns an array storing the outputs. For example:
 * 
 *      Input:  [5, 6, 3, 4, 1, 2]
 *      Output: [3, 3, 1, 1, -1, -1]
 * 
 * Improve the algorithm such that its time complexity is O(n). 
 * Your implementation cannot use any c++ built-in data structures or algorithms.
 */
int* findNextSmallerElementSmart(int arr[], int n) {
   
    
    
}

//-------------------------- functions prepared for you

/*
 * Helper function.
 * Print n elements of arr[] starting from index s
 */
void printArray(int arr[], int n, int s = 0) {
    
    if(n < 1) {
        cout << "[]";
        return;
    }
    
    cout << "[" << arr[s];
    for (int i = s + 1; i <= n-1; i++) {
        cout << ", " << arr[i];
    }
    cout << "]";
}

/*
 * Driver program to test above functions against test cases in input.txt.
 */
int main(int argc, char** argv) {

    ifstream fin("t4_input.txt");
    if (!fin) {
        cout << "Input file not found.";
        exit(1);
    }

    int testcase = 0;
    fin >> testcase;

    for (int i = 0; i < testcase; i++) {
        int n;
        fin >> n;
        int* arr = new int[n];
        for (int j = 0; j < n; j++)
            fin >> arr[j];

        int* result;
        cout << "Case " << i << endl;
        cout << "Input Array: ";
        printArray(arr, n);
        cout << endl;

        cout << "Naive Output: ";
        result = findNextSmallerElementNaive(arr, n);
        printArray(result, n);
        delete[] result;
        cout << endl;

        cout << "Smart Output: ";
        result = findNextSmallerElementSmart(arr, n);
        printArray(result, n);
        delete[] result;
        cout << endl << endl;
    }

    return 0;
}

