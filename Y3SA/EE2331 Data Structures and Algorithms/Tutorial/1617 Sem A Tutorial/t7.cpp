/* 
 * Student name:
 * Student ID  :
 *
 * You are asked to implement the functions infix2postfix() and evaluatePostfix() as specified below.
 * Your implementation can use c++ STL built-in stack.
 * Test cases are defined in the main() function. No modification is needed.
 * 
 */

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <stack>

#define MAX_LENGTH 100      // max input length

using namespace std;

bool isHigherPrecedence(char op1, char op2);

//-------------------------- functions to be implemented by you

/*
 * Convert infix to postfix expression, where both are represented as c-string 
 * that must be ended with '\0' character. The postfix argument initially points 
 * to an empty char[] for you to store the output postfix c-string.
 * 
 * Precondition:
 * - operand and operator, both must be single character.
 * - only +, -, * and / operators are expected. 
 */
void infix2postfix(char* infix, char* postfix) {

   
    
    
}

/*
 * Evaluate and return the result for a given postfix expression that is 
 * represented in the form of c-string.
 * 
 * Precondition:
 * - operand and operator, both must be single character.
 * - only +, -, * and / operators are expected. 
 */
double evaluatePostfix(char* postfix) {
    
    
    
    
}

//-------------------------- functions prepared for you

/*
 * Compare precedence of +, -, *, / and return true if op1 has higher 
 * precedence than op2. Otherwise return false.
 */
bool isHigherPrecedence(char op1, char op2) {
    if (op1 == '+' || op1 == '-')
        return false;
    else if (op2 == '+' || op2 == '-')
        return true;
    else
        return false;
}

/*
 * Driver program to test above functions against default test cases.
 */
int main(int argc, char** argv) {

    ifstream fin("t7_input.txt");
    if (!fin) {
        cout << "Input file not found.";
        exit(1);
    }

    int testcase = 0;
    fin >> testcase;
    fin.ignore(1); // skip the newline char

    // the infix/postfix expressions are represented as c-string 
    char infix[MAX_LENGTH];
    char postfix[MAX_LENGTH];
    
    for (int i = 0; i < testcase; i++) {
        fin.getline(infix, MAX_LENGTH);
        cout << "Case " << i << endl;
        cout << "Infix expression: " << infix << endl;
        infix2postfix(infix, postfix);
        cout << "Postfix expression: " << postfix << endl;
        double result = evaluatePostfix(postfix);
        cout << "Result = " << result << endl;
        cout << endl;
    }

    return 0;
}

