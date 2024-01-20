/* 
 * Student name:
 * Student ID  :
 *
 * You are asked to implement the functions reversedPrint() and sortedInsert() as specified below.
 * Your implementation can use c++ STL built-in stack.
 * Test cases are defined in the main() function. No modification is needed.
 * 
 */

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <stack>

using namespace std;


//-------------------------- functions to be implemented by you

/*
 * Insert item x to stack s in ascending order using recursion.
 */
void sortedInsert(stack<int>& s, int x) {

    if (s.empty() || x >= s.top()) {
        s.push(x);
        return;
    }

    int temp = s.top();
    s.pop();
    sortedInsert(s, x);

    s.push(temp);
}

/*
 * Print stack s from bottom to top using recursion.
 * 
 * Postcondition:
 * - stack s must be unchanged after execution
 */
void reversedPrint(stack<int>& s) {

    if (s.empty())
        return;
    else {
        int temp = s.top();
        s.pop();
        reversedPrint(s);
        cout << temp << " ";
        s.push(temp);
    }
}

//-------------------------- functions prepared for you

/*
 * Helper function. 
 * Pop all items from stack s and insert to stack d in sorted way.
 */
void sortStack(stack<int>& s, stack<int>& d) {
    while (!s.empty()) {
        // Push the top item from s to d 
        sortedInsert(d, s.top());
        s.pop();
    }
}

/*
 * Driver program to test above functions against default test cases.
 */
int main(int argc, char** argv) {

    ifstream fin("t8_input.txt");
    if (!fin) {
        cout << "Input file not found.";
        exit(1);
    }

    int testcase = 0;
    fin >> testcase;

    for (int i = 0; i < testcase; i++) {

        int n, e;
        fin >> n;
        stack<int> s;
        stack<int> d;
        for (int j = 0; j < n; j++) {
            fin >> e;
            s.push(e);
        }

        cout << "Case " << i << endl;
        cout << "stack: ";
        reversedPrint(s);
        cout << endl;
        cout << "sorted stack: ";
        sortStack(s, d);
        reversedPrint(d);
        cout << endl << endl;
    }

    return 0;
}

