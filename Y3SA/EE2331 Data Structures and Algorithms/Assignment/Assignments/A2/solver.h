//Student name:
//Student ID  :

/*
* EE2331 Data Structures and Algorithms
* Assignment 2 - Word Puzzle Solver
*
* Your task is to implement these 2 member functions:
*      contain()
*      solve()
*/

#ifndef SOLVER_H
#define SOLVER_H


#include <iostream>
#include <iomanip> 
#include <fstream> 
#include <string>
#include <list>

using namespace std;

class Solver {

private:

	char* grid;					// the word puzzle grid represented by a char array in row-major order
	int size;					// the dimension of grid e.g. 3 for 3x3
	list<string> dictionary;	// a list of "real" words to check against

public:

	// Constructor, load words from a dictionary file
	Solver(string filename) {	
		
		ifstream infile(filename);
		if (!infile)
			exit(1);

		string word;
		while (!infile.eof()) {
			infile >> word;
			dictionary.push_back(word);
		}
	}

	// A NxN grid is represented by a string that has its rows concatenated together 
	// e.g. 2x2 grid	p e		is represented by a string "pesa"
	//					s a	
	// This function converts the input string to a char array
	void loadPuzzle(string puzzle) {

		int len = puzzle.length();
		size = sqrt(len);
		grid = new char[len];
		strncpy(grid, puzzle.c_str(), len);
	}

	// Print the puzzle
	void print() {

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++)
				cout << setw(3) << grid[i * size + j];
			cout << endl;
		}
		cout << "Dictionary size: " << dictionary.size() << endl;
	}

	// Return true if the word appears at least once in the grid. Otherwise return false.
	bool contain(string word) const;

	// Find every word from the internal dictionary that appears in the grid and store them in the results list 
	void solve(list<string>& results) const;


};

// ------------------------------------------------------------------- your implementation here

bool Solver::contain(string word) const {

	/*
		Words can be formed from letters in eight adjacent positions, and must be 3 letters or longer.
		Use backtracking algorithm to verify if the input word appears in the grid.
		
		*Implement your algorithm as efficient as possible.
	*/	


	return true;
}

void Solver::solve(list<string>& results) const {

	/*
		Verify words from dictionary one by one. If it appears in the grid, put 
		it into the results list.
		
		*Implement your algorithm as efficient as possible.
	*/
	
	
	results.push_back("testing1");
	results.push_back("testing2");
	results.push_back("testing3");
}


#endif
