//Student name:
//Student ID  :

/*
* EE2331 Data Structures and Algorithms
* Assignment 2 - Sudoku Solver
*
* Your task is to implement these 3 member functions:
*      print()
*      checkDigit()
*      solvePuzzle()
*/

#ifndef SOLVER_H
#define SOLVER_H

#include <iostream>

#define ROW 9
#define COL 9

using namespace std;

class Solver {

private:

	// the sudoku puzzle represented in row-major order
	int puzzle[ROW * COL];

	/*
	* Check if a digit can be put in position n such that the digit is unique in
	* its row, column, and 3x3-sub-grid.
	*
	* digit        the filling number ranging from 1 to 9
	* n            the grid position ranging from 0 to 80
	*
	* return       true if the digit does not conflict with other numbers; otherwise false
	*/
	bool checkDigit(int digit, int n);

	/*
	* Solve the sudoku puzzle recursively using backtracking alogrithm. Each call
	* tries to solve a number in position n and progresses to the next position by
	* recursion until all 81 positions have been filled with numbers.
	*
	* n            the grid position ranging from 0 to 80
	*
	* return       true if the puzzle is solved; otherwise false
	*/
	bool solvePuzzle(int n);

public:

	/*
	* Print puzzle[] to screen. Sub-grids should be separated by a space horizontally 
	* and by a blank line vertically.
	*/
	void print();
	
	// Copy data[] to puzzle[]. The sudoku puzzle in data[] is represented in row-major order.
	void read(int data[]) {
		int length = ROW * COL;
		for(int i=0; i<length; i++) {
			puzzle[i] = data[i];
		}
	}

	// Driver function for the recursive solvePuzzle()
	bool solve() {
		return solvePuzzle(0);
	}

};

// -------------------------------------------------------------------your implementation here













#endif