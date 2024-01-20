//   test driver for heap, ignores index 0

#include <iostream>
#include <math.h>
#include <ctime>
#include <stdlib.h>
#include <vector>

using namespace std;

// short integer random number generator from stdlib
int rand(void);

void heapinsert(vector<int> &arr, int key)
{
  int heapsize = arr[0] + 1; // H[0] stores the size of the heap
  int i = heapsize;
  while (i > 1 && arr[i / 2] < key)
  {
    arr[i] = arr[i / 2];
    i = i / 2;
  }
  arr[i] = key;
  arr[0] = heapsize;
}

void heapify(vector<int> &arr, int i)
{
  cout << "H " << i << endl;

  int heapsize = (sizeof(arr) / sizeof(int)) + 1;
  int left = i * 2;
  int right = (i * 2) + 1;
  int largest;
  if (left <= heapsize && arr[left] > arr[i])
  {
    largest = left;
  }
  else
  {
    largest = i;
  }
  if (right <= heapsize && arr[right] > arr[largest])
  {
    largest = right;
  }
  if (largest != i)
  {
    swap(arr[i], arr[largest]);
    heapify(arr, largest);
  }
}

int main()
{
  int size;

  cout << endl
       << "How many elements in the input array ";
  cin >> size;
  vector<int> dataArray(size + 1); // get array of right size (with invisible 0th element)
  vector<int> dataArray2(size + 1);

  // fill array -- fill 0th element but don't show it.
  for (int k = 0; k < size + 1; k++)
  {
    dataArray2[k] = dataArray[k] = rand() % 100;
  }
  cout << "Input array:\n";
  for (int k = 1; k < size + 1; k++)
    cout << dataArray[k] << " ";
  cout << endl;

  // ============= implement your code here or call it as a function======
  vector<int> dataArray3(size + 1);
  vector<int> dataArray4(size + 1);
  // build a heap for dataArray using insertion
  for (int k = 0; k < size; k++)
  {
    heapinsert(dataArray3, dataArray[k + 1]);
  }

  // show heap
  cout << "Heap built from the input array using insertion:\n";
  for (int k = 1; k < size + 1; k++)
    cout << dataArray3[k] << " ";
  cout << endl;

  // build a heap for dataArray2 using heapify

  // Heapify(dataArray2, size+1);
  for (int k = 1; k < size + 1; k++)
    heapify(dataArray2, k);
  cout << endl;
  // show heap here
  cout << "Heap built from the input array using heapify:\n";
  for (int k = 1; k < size + 1; k++)
    cout << dataArray2[k] << " ";
  cout << endl;
}