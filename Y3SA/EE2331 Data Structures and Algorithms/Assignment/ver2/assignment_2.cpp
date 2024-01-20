/*
 *
 * EE2331 Data Structures and Algorithms
 * Assignment 2 - Sudoku Solver
 *
 * You do not need to modify this file. All your work should be done in solver.h.
 *
 */

#include <string>
#include <iostream>
#include <fstream>
#include "solver.h"


/*
 * Test your implemetation with this driver.
 */
int main() {

    // read the sudoku puzzle into this 1D array in row-major order
    int puzzle[ROW * COL];
    int i, j, input;
	string file;

	cout << "Enter data file name: ";
	getline(cin, file);

	// read file into an array
	ifstream inFile(file);
	
	for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
			inFile >> input;
            puzzle[i * ROW + j] = input;
        }
    }


	// start solving the puzzle
	Solver solver;
	solver.read(puzzle);

	cout << "Sudoku Puzzle:\n";
	solver.print();

	cout << "Run the solver...\n";	    
    if (solver.solve()) {
        cout << "Puzzle is solved.\n";
        solver.print();
    }
    else
        cout << "No Solution.\n";

    system("pause");
	return 0;
}
