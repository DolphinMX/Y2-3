#include <iostream>
#include <cassert>
#include <math.h>
#include <stdlib.h>
#include <vector>

//===== add needed functions here such as <vector>=========

using namespace std;

// short integer random number generator from stdlib
int rand(void); 


int main()
{ 
  int size;

  

  cout << endl << " ----- quicksort/mergesort/insertion comparison ----- " << endl;
  cout << endl << "How many elements to sort: - ";  cin >> size;
  vector<int> quickArray;   // get array of right size
  vector<int> mergeArray;   // to hold a copy of random ints
  vector<int> insertArray;   // to hold a copy of random ints


  //  initialize the three vectors with size "size".


  //  ============ quicksort random integers  ===================
  // generate random numbers for quickArray. You can use mod function to limit its maximum value
   

  // copy the array for later use by mergesort and insterion sort
  for (int k=0; k< size ; k++){
	  mergeArray[k] = quickArray[k];
	  insertArray[k] = quickArray[k];
  }
  
  cout << endl << "Quicksort of Integer data initially in random order" << endl;

  
  // implement your quicksort here or call it as a function
  // ===================== Quicksort ======================
  

  cout << "First five sorted elts:  ";
  for ( int k=0; k<5; k++)  cout << quickArray[k] << ", " ;
  cout << endl;
  cout << "Last five sorted elts:  ";
  for ( int k=5; k>0; k--)  cout << quickArray[size-k] << ", " ;
  cout << endl << endl;

  //  ============ mergesort random integers  ===================

  cout << endl << "Mergesort of Integer data initially in random order" << endl;

  
  // implement your mergesort here or call it as a function
  // ===================== Mergesort ======================
  

  cout << "First five sorted elts:  ";
  for ( int k=0; k<5; k++)  cout << mergeArray[k] << ", " ;
  cout << endl;
  cout << "Last five sorted elts:  ";
  for ( int k=5; k>0; k--)  cout << mergeArray[size-k] << ", " ;
  cout << endl << endl;
  
  
  //  ============ insertion sort random integers  ===================

  cout << endl << "Insertion sort of Integer data initially in random order" << endl;

  
  // implement your insertion sort here or call it as a function
  //   ===================== Insertion Sort ===============
  
  cout << "First five sorted elts:  ";
  for ( int k=0; k<5; k++)  cout << insertArray[k] << ", " ;
  cout << endl;
  cout << "Last five sorted elts:  ";
  for ( int k=5; k>0; k--)  cout << insertArray[size-k] << ", " ;
  cout << endl << endl;

   
}







