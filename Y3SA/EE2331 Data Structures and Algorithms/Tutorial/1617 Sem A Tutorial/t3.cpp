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
    
   


}

/*
 * Given an array arr[] of positive integers ranging from 0 to M, check whether 
 * there are two numbers present with given product p.
 * 
 * Improve the algorithm such that its time complexity is O(n). 
 * Returns true if there is a pair in arr[0..n-1] with product equal to p. Otherwise, return false.
 */
bool isProductSmart(int arr[], int n, int p) {
    
    
    
    
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

