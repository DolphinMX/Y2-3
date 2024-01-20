/*
	Main program 
	
	Include some test cases for testing your implementation of record

*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "record.h"

using namespace std;


//-------------------------------------------main functions prepared for you
// This is just a sample made for you. You will need to set up 
// more test cases for verifying your implementation in record.h
// *** You DON'T need to submit this file ***
int main()
{

	record jumper1("N123", "john", 98);		
	jumper1.addResult(60);		
	jumper1.addResult(100);		
	
	record jumper2("N124", "peter", 210);		
	jumper2.addResult(160);		
	jumper2.addResult(100);	
	jumper2.addResult(120);	
	jumper2.addResult(130);	

	cout << "jumper1 = ";
	cout << jumper1 << endl;	
	cout << "jumper1's max result = ";
	cout << jumper1.getMax() << endl << endl;	
	
	cout << "jumper2 = ";
	cout << jumper2 << endl;	
	cout << "jumper2's max result = ";
	cout << jumper2.getMax() << endl << endl;	
	
	if(jumper1.compare(jumper2) == 0)
		cout << "They have the same rank." << endl << endl;
	else if(jumper1.compare(jumper2) > 0)
		cout << jumper1.getName() << " has a higher rank." << endl << endl;
	else 
		cout << jumper2.getName() << " has a higher rank." << endl << endl;

	record team = jumper1.createTeam(jumper2);
	cout << "team = ";
	cout << team << endl;

	system("pause");
	return 0;
}
