/* 
 * Student name:
 * Student ID  :
 *
 * You are asked to implement the function solve() and define the values in xMove[] and yMove[] as specified below.
 * Test cases are defined in the main() function. No modification is needed.
 * 
 */

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <iomanip>

#define N 5

using namespace std;

/* 
 * Define next move of knight in xMove[] and yMove[] based on the 8 positions
 * marked below.
 * 
 * xMove[] is for next value of x coordinate.
 * yMove[] is for next value of y coordinate.
 * 
        . . . . . . . 
        . . M . M . . 
        . M . . . M . 
        . . . K . . .   where K is at (0,0)
        . M . . . M . 
        . . M . M . . 
        . . . . . . . 
 * 
 */
const int xMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
const int yMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};

void printSolution(int sol[N][N]);

/* 
 * A knight's tour is a sequence of moves of a knight on a chessboard such that 
 * the knight visits every square only once. 
 * 
 * This recursive function solves the Knight Tour problem using backtracking. It 
 * returns false if no complete tour is possible, otherwise return true and prints 
 * the tour. The argument (x,y) indicates the current position of knight. The 
 * argument 'step' is a counter to track the progress of backtracking. The sol[][]
 * matrix is the chessboard. The argument 'solCount' is used to save the number
 * of solutions found. 
 * 
 * Please note that there may be more than one solutions, this function prints 
 * one of the feasible solutions only.  
 */
void solve(int x, int y, int step, int sol[N][N], int& solCount) {
    int k, nx, ny;

    // based case - path closed
    if (step == N * N) {
        solCount++;
        cout << solCount << endl;
        printSolution(sol);
        cout << endl;
        return;
    }

    /* Try all next moves from the current coordinate x, y */
    for (k = 0; k < 8; k++) {
        nx = x + xMove[k];
        ny = y + yMove[k];

        // check if i,j are valid indexes for N*N chessboard 
        if (nx >= 0 && nx < N && ny >= 0 && ny < N && sol[nx][ny] == -1) {
            sol[nx][ny] = step;
            solve(nx, ny, step + 1, sol, solCount);
            sol[nx][ny] = -1; // backtracking
        }
    }
}

//-------------------------- functions prepared for you

/* 
 * A utility function to print solution matrix sol[N][N] 
 */
void printSolution(int sol[N][N]) {
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++)
            cout << setw(3) << sol[x][y];
        cout << endl;
    }
}

/*
 * Driver program to test above functions.
 */
int main(int argc, char** argv) {

    // number of solutions
    int solCount = 0;       
    
    // initialize chessboard
    int sol[N][N];
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            sol[x][y] = -1;

    // set the knight to its initial position
    sol[0][0] = 0;
    
    // tour starts from (0,0)
    solve(0, 0, 1, sol, solCount);

    return 0;
}
