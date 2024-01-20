/* 
 * Student name:
 * Student ID  :
 *
 * You are asked to implement the functions findMaxSubarray() as specified below.
 * 
 * Three test cases are defined in the main() function. A helper function printArray() is also implemented for you. You
 * do not need to modify them.
 * 
 * 
 */

#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;

//-------------------------- functions to be implemented by you
/*
 * Find the subsequence with largest sum of elements in the input array. The 2nd and 3rd arguments, s and e,
 * provide the starting and ending indexes for the input array ranges. When the function completes, the maximum sum
 * of the subarray will be returned, and s and e will be set to the starting and ending indexes of the subarray. 
 * Your implementation must be a linear time algorithm O(n).
 * 
 * Precondition: input array is not empty and e >= s
 * 
 * For example,
 * 
            Case 1: [5, 2, -8, 1, 8]
            Max subarray is: [1, 8] = 9

            Case 2: [5, 4, -8, 1, 8]
            Max subarray is: [5, 4, -8, 1, 8] = 10

            Case 3: [-5, -4, -8, -1, -8]
            Max subarray is: [-1] = -1
 *
 */
int findMaxSubarray(int array[], int& s, int& e) {
    int start = s; // copy start and end indexes
    int end = e;
    // set the current max/submax to the first element
    int max = array[start];
    int submax = array[start]; // submax is the max sum for the subarray in the current ending position
    int substart = start; // start of subarray
    e = s; // they are output arguments; set to the first element

    for (int subend = start + 1; subend <= end; subend++) { // move end of subarray forward

        if (submax > 0)
            submax += array[subend]; // previous subarray is +ve, then add next element
        else {
            submax = array[subend]; // previous subarray is -ve, then start over the subarray
            substart = subend;
        }
        if (submax > max) {
            max = submax;
            s = substart;
            e = subend;
        }
    }
    return max;
}

//-------------------------- functions prepared for you

/*
 * Helper function.
 * Print elements of input array from index s to index e
 * Precondition: array is not empty and e >= s
 */
void printArray(int array[], int s, int e) {
    cout << "[" << array[s];
    for (int i = s + 1; i <= e; i++) {
        cout << ", " << array[i];
    }
    cout << "]";
}

/*
 * Driver program to test above functions against three default test cases.
 */
int main(int argc, char** argv) {

    cout << "Find the maximum sum subarray: " << endl;

    int case1[] = {5, 2, -8, 1, 8};
    int case2[] = {5, 4, -8, 1, 8};
    int case3[] = {-5, -4, -8, -1, -8};

    int* inputs[] = {case1, case2, case3};

    for (int i = 0; i < 3; i++) {
        printf("Case %d: ", i+1);
        int s = 0, e = 4;
        printArray(inputs[i], s, e);
        cout << endl;

        int sum = findMaxSubarray(inputs[i], s, e);
        cout << "Max subarray is: ";
        printArray(inputs[i], s, e);
        cout << " = " << sum << endl << endl;
    }
    
    system("pause");
    return 0;
}

