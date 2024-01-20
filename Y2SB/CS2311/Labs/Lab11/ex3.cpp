#include <iostream>

using namespace std;

int main() {
	int digits[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int *p1 = digits;
	int *p2 = digits + 9;
	while (p1 <= p2) {
		cout << p1 << " " << p2 << " " << *p1 << " " << *p2 << endl;
		p1 = p1 + 2;
	}
	return 0;
}
