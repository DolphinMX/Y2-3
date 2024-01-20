/* 
 * Student name:
 * Student ID  :
 *
 * You are asked to implement the functions isProductNaive() and isProductSmart() as specified below.
 * Test cases are defined in the main() function and input.txt. No modification is needed.
 * 
 */

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

#define M 9999       // the max allowed value in input array


//-------------------------- functions to be implemented by you

/*
 * Given an array arr[] of positive integers ranging from 0 to M, check whether 
 * there are two numbers present with given product p.
 * 
 * Naive approach O(n2) is to apply brute force search to test all possible pairs. 
 * For every pair, check if product is equal to p or not. Returns true if there is 
 * a pair in arr[0..n-1] with product equal to p. Otherwise, return false.
 */
bool isProductNaive(int arr[], int n, int p) {
    
    // consider all possible pairs and check for every pair.
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] * arr[j] == p)
                return true;

    return false;
}

/*
 * Given an array arr[] of positive integers ranging from 0 to M, check whether 
 * there are two numbers present with given product p.
 * 
 * Improve the algorithm such that its time complexity is O(n). 
 * Returns true if there is a pair in arr[0..n-1] with product equal to p. Otherwise, return false.
 */
bool isProductSmart(int arr[], int n, int p) {
    if (n < 2)
        return false;

    // create an empty array with all zeros
    // arr[i] <= min(M,p)
    bool lookuptable[min(M,p)] = {};

    // traverse all elements
    for (int i = 0; i < n; i++) {
        // 0 case must be handles explicitly as
        // p % 0 is undefined behaviour in C++
        if (arr[i] == 0) {
            if (p == 0)
                return true;
            else
                continue;
        }

        // if p/arr[i] exists in table, then we found a pair
        if (p % arr[i] == 0) {
            if (lookuptable[(p / arr[i])])
                return true;

            // mark position arr[i] as true
            lookuptable[arr[i]] = true;
        }
    }
    return false;
}

//-------------------------- functions prepared for you

/*
 * Driver program to test above functions against test cases in input.txt.
 */
int main(int argc, char** argv) {
    
    ifstream fin("t3_input.txt");
    if(!fin) {
        cout << "Input file not found.";
        exit(1);
    }
    
    int testcase = 0;
    fin >> testcase;
    
    for(int i=0; i<testcase; i++) {
        int n, p;
        fin >> n >> p;
        int* arr = new int[n];
        for(int j=0; j<n; j++) 
            fin >> arr[j];
        
        cout << "Case " << i << endl;
        cout << "Naive Answer: " << (isProductNaive(arr, n, p) ? "Yes\n" : "No\n");
        cout << "Smart Answer: " << (isProductSmart(arr, n, p) ? "Yes\n" : "No\n");
        cout << endl;
    }

    return 0;
}

