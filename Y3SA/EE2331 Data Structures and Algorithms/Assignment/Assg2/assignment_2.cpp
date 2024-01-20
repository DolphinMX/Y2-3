/*
*
* EE2331 Data Structures and Algorithms
* Assignment 2 - Word Puzzle Solver
*
* You do not need to modify this file. All your work should be done in solver.h.
*
*/

#define _SCL_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <fstream> 
#include <string>
#include <list>
#include "solver.h"

using namespace std;


/*
* Test your implemetation with this driver.
*/
int main() {
	
	/* set up the puzzle as follow:
	*
	*	m m g
	*	e u s
	*	k d e
	*
	*/
	Solver solver("dictionary.txt");
	solver.loadPuzzle("mmgeuskde");
	solver.print();

	cout << endl << "Following words of dictionary are present" << endl;
	list<string> results;
	solver.solve(results);
	for (list<string>::iterator it = results.begin(); it != results.end(); ++it)
		cout << *it << endl;

	system("pause");
	return 0;
}
