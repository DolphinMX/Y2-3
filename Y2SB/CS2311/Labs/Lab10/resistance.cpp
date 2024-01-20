#include <iostream>
#include <iomanip>
using namespace std;

void getInput( /* Write the parameters here */ ) {
	
	cout << "Please enter two values: ";
	
	//TODO: read voltage and current and pass them back using call by reference
	//REWRITE: read voltage and current and pass them back using call by pointer
}

double toResistance( /* Write the parameters here */ ) {
	
	//TODO return the resistance based on the voltage and current
}

void swap( /* Write the parameters here */ ) {
	//TODO swap the values of V and I using call by reference
	//REWRITE: swap the values of V and I using call by pointer
}

int main(){
	double voltage, current;
	
	getInput(/* Write the parameters here */);
	cout << "The value of one resistance is ";
	cout << fixed << setprecision(2) << toResistance(/* Write the parameters here */) << endl;
	
	swap(/* Write the parameters here */);
	
	cout << "The value of the other resistance is ";
	cout << fixed << setprecision(2) << toResistance(/* Write the parameters here */) << endl;
	return 0;
}


