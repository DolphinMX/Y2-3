/* 
 * Student name:
 * Student ID  :
 *
 * You are asked to implement the functions printAllPermutations() and printAllResults24() as specified below.
 * 
 * User inputs are obtained in the main() function. A helper function eval() is also implemented for you. You
 * do not need to modify them.
 * 
 * After you completed and demonstrated the program. Discuss the following items:
 * (1) How to generalize the permutation function for any numbers of input? (N is fixed to 4 in this exercise)
 * (2) How to evaluate multiplication/division prior to addition/subtraction? 
 * 
 */

#include <cstdlib>
#include <iostream>
#define N 4                 // number of inputs

using namespace std;

// forward declaration
float eval(float operand1, char op, float operand2);


//-------------------------- functions to be implemented by you

/*
 * The input array contains 4 integer numbers. This function prints all 
 * possible permutations of these 4 numbers. For example, if the inputs 
 * are 1, 2, 3 and 4, then the 24 permutations are as follows:
 * 
            1 2 3 4
            1 2 4 3
            1 3 2 4
            ...
            4 3 1 2
            4 3 2 1
 * 
 */
void printAllPermutations(int num[]) {

    // print all permutations of 4 numbers
    for (int i = 0; i < N; i++) {
        
        for (int j = 0; j < N; j++) {
            if (j == i) continue;
            
            for (int k = 0; k < N; k++) {
                if ((k == j) || (k == i)) continue;
                
                for (int l = 0; l < N; l++) {
                    if ((l == i) || (l == j) || (l == k)) continue;

                    printf("%d %d %d %d\n", num[i], num[j], num[k], num[l]);
                }
            }
        }
    }
}


void printAllPermutationsV2(int num[]) {

    // print all permutations of 4 numbers
    for (int i = 0; i < N; i++) {
        swap(num[0], num[i]);
        for (int j = 1; j < N; j++) {
            swap(num[1], num[j]);
            for (int k = 2; k < N; k++) {
                swap(num[2], num[k]);
                for (int l = 3; l < N; l++) {
                    printf("%d %d %d %d\n", num[0], num[1], num[2], num[3]);
                }
                swap(num[2], num[k]);
            }
            swap(num[1], num[j]);
        }
        swap(num[0], num[i]);
    }
}

/*
 * The input array contains 4 integer numbers. This function prints all possible ways 
 * to manipulate the four numbers so that the end result is 24. To simplify the calculations,
 * only addition, subtraction, multiplication and division are considered. The arithmetic 
 * expression is evaluated from left to right, precedence of operators are ignored. For example,
 * there are 4 expressions result in 24 for number 3, 4, 5, and 6.
 * 
        3 - 4 + 5 * 6 = 24
        3 + 5 - 4 * 6 = 24
        5 + 3 - 4 * 6 = 24
        5 - 4 + 3 * 6 = 24
 */
void printAllResults24(int num[]) {
    
    char op[] = {'+','-','*','/'};
    float result = 0;
    
    // permutate operands
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (j == i) continue;
            for (int k = 0; k < N; k++) {
                if ((k == j) || (k == i)) continue;
                for (int l = 0; l < N; l++) {
                    if ((l == i) || (l == j) || (l == k)) continue;

                    // all combinations of operators
                    for(int p = 0; p < N; p++) {
                        for(int q = 0; q < N; q++) {
                            for(int r = 0; r < N; r++) {
                                result = eval(eval(eval(num[i], op[p], num[j]), op[q], num[k]), op[r], num[l]);
                                if(result == 24)
                                     printf("%d %c %d %c %d %c %d = %.0f\n", num[i], op[p], num[j], op[q], num[k], op[r], num[l], result);
                            }
                        }
                    } 
                }
            }
        }
    }
}

//-------------------------- functions prepared for you

/*
 * Helper function to evaluate basic arithmetic operations
 */
float eval(float operand1, char op, float operand2) {
    switch(op) {
        case '+' : return operand1 + operand2;
        case '-' : return operand1 - operand2;
        case '*' : return operand1 * operand2;
        case '/' : return operand1 / operand2;
    }
}

/* 
 * Driver program to test above functions 
 */
int main(int argc, char** argv) {

    int num[N];
    cout << "Enter 4 numbers separated by spaces: ";
    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }
    printf("\nInputs: [%d][%d][%d][%d]\n", num[0], num[1], num[2], num[3]);

    cout << "All permutations of these 4 numbers:" << endl;
    printAllPermutationsV2(num);
    
    cout << endl << "All results of 24:" << endl;
    printAllResults24(num);
    
    return 0;
}

