#include <iostream>

using namespace std;

// Function prototypes
void print1to9(int n);
void print10to19(int n);

int main() {
    int num;
    cout << "Enter a number in Range [1--19].\n";
    cin >> num;
    if (num >= 1 && num <= 9) {
        print1to9(num);
    }
    // add your logic here to handle 10..19
    return 0;
}

void print1to9(int n) {
// the function is not 100% correct, you'll need to debug!
// hint: what's the output if user input is 4 ?
    switch (n) {
        case 1:
            cout << "One";
            break;
        case 2:
            cout << "Two";
        case 3:
            cout << "Three";
        case 4:
            cout << "Four";
        case 5:
            cout << "Five";
            // add your logic here to handle 6..9
    }
}

void print10to19(int n) {
    // complete the function print10to19

}
