// Student name: 
// Student ID  : 

// Submission deadling: Thursday, 4 April 2019, 2 pm

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stack>
#include <queue>

using namespace std;

struct Coordinate
{
	int x, y;  // x is the row-index, y is the col-index
};

ostream& operator<<(ostream& osObject, const Coordinate& d)
{
	osObject << "(" << d.x << ", " << d.y << ")";
	return osObject;
}

//----------------------------------------------- function to be implemented by student

void findShortestPath(char **A, int row, int col, stack<Coordinate>& s)
{
	// A[][] represents the maze of size row x col.

	// The array offset[4] allows you to find out the coordinates of the 
	// 4 neighboring points of a given point using a for-loop.

	Coordinate offset[4];    
	offset[0].x = offset[1].x = 0;
	offset[0].y = -1;
	offset[1].y = 1;
	offset[2].y = offset[3].y = 0;
	offset[2].x = -1;
	offset[3].x = 1;

	int **d;  // d[][] is used for finding the distances of other points from the start-point
	d = new int*[row];
	for (int i = 0; i < row; i++)
		d[i] = new int[col];

	queue<Coordinate> q;  
	// q.front() return the front element in the queue
	// q.push(e) add element e to the queue
	// q.pop()   remove the front element from the queue


	// Your codes


}

//---------------------------------------------------- functions prepared for student

char** readFile(const char filename[], int& row, int& col)
{
	ifstream inFile(filename);
	if (!inFile.is_open())
	{
		cout << "Cannot open data file " << filename << endl;
		system("pause");
		exit(1);
	}

	inFile >> row >> col;  // read the values of row and col

	//create the 2D array A[row][col]
	char **A;
	A = new char*[row];
	for (int i = 0; i < row; i++)	
		A[i] = new char[col];
	
	//read in the contents of A[][]
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			inFile >> A[i][j];

	inFile.close();
	return A;
}

void printArray(char **A, int row, int col)
{
	Coordinate startPoint, endPoint;

	cout << "Array[" << row << "][" << col << "]" << endl << endl;
	for (int i = 0; i < row; i++)	
	{
		for (int j = 0; j < col; j++)
		{
			cout << A[i][j];
			if (A[i][j] == 'S')
			{
				startPoint.x = i;
				startPoint.y = j;
			}
			else if (A[i][j] == 'E')
			{
				endPoint.x = i;
				endPoint.y = j;
			}			
		}
		cout << endl;
	}
	
	cout << endl;
	cout << "start-point : " << startPoint << endl;
	cout << "end-point : " << endPoint << endl;
	cout << endl;
}


int main()
{	
	const char *files[] = {"T10-data-1.txt", "T10-data-2.txt", "T10-data-3.txt"};
	char **A;
	int row, col;

	for (int i = 0; i < 3; i++)
	{
		cout << "\n------------------------------------------\n\n";
		cout << "Test file : " << files[i] << endl << endl;

		A = readFile(files[i], row, col);
		printArray(A, row, col);

		stack<Coordinate> s;
		findShortestPath(A, row, col, s);

		if (!s.empty())
		{
			cout << "\nShortest path from start-point to end-point:\n";

			cout << s.top();
			s.pop();

			int count = 1;
			while (!s.empty())
			{
				cout << " -> ";
				if (count % 5 == 0)
					cout << endl;

				cout << s.top(); 
				s.pop();				
				count++;
			}
			cout << endl;
		}
		else
			cout << "DO NOT find any path from start-point to end-point\n";

		for (int j = 0; j < row; j++)
			delete[] A[j];
		delete[] A;  // return the memory space to the OS
	}

	system("pause");
	return 0;
}