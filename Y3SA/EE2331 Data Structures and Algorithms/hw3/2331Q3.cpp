#include <iostream>
#include <cassert>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <chrono>
#include <ctime>

//===== add needed functions here such as <vector>=========

using namespace std;

// short integer random number generator from stdlib
int rand(void);

int partition(vector<int> &arr, int start, int end)
{
	int pivot = arr[start];
	int count = 0;

	for (int i = start + 1; i <= end; i++)
	{
		if (arr[i] <= pivot)
			count++;
	}

	// Giving pivot element its correct position
	int index = start + count;
	swap(arr[index], arr[start]);

	// Sorting left and right parts of the pivot element
	int i = start, j = end;

	while (i < index && j > index)
	{
		while (arr[i] <= pivot)
		{
			i++;
		}
		while (arr[j] > pivot)
		{
			j--;
		}
		if (i < index && j > index)
		{
			swap(arr[i++], arr[j--]);
		}
	}
	return index;
}

void merge( vector<int> &arr, int left, int middle, int right)
{
    int n1 = middle - left + 1;
    int n2 = right - middle;
     vector<int> Left(n1);
     vector<int> Right(n2);
    for (int i = 0; i < n1; i++)
        Left[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        Right[i] = arr[middle + i + 1];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (Left[i] <= Right[j])
        {
            arr[k] = Left[i];
            i++;
        }
        else
        {
            arr[k] = Right[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = Left[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = Right[j];
        j++;
        k++;
    }
}

void mergeSort( vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

void insertionSort(vector<int> &arr, int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

void quickSort( vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main()
{
	int size;
	srand(time(0));
	cout << endl
		 << " ----- quicksort/mergesort/insertion comparison ----- " << endl;
	cout << endl
		 << "How many elements to sort: - ";
	cin >> size;
	vector<int> quickArray;
	vector<int> mergeArray;
	vector<int> insertArray;
	for (int i = 0; i < size; i++)
	{
		quickArray.push_back(i);
	}
	for (int i = 0; i < size; i++)
	{
		mergeArray.push_back(i);
	}
	for (int i = 0; i < size; i++)
	{
		insertArray.push_back(i);
	}
	for (int k = 0; k < size; k++)
	{
		quickArray[k] = rand() % 100;
	}
	for (int k = 0; k < size; k++)
	{
		mergeArray[k] = quickArray[k];
		insertArray[k] = quickArray[k];
	}

  // implement your quicksort here or call it as a function
  // ===================== Quicksort ======================
  	cout << endl << "Quicksort of Integer data initially in random order" << endl;
	auto quick_start = chrono::high_resolution_clock::now();
	quickSort(quickArray, 0, size - 1);
	auto quick_end = chrono::high_resolution_clock::now();
	auto quick_duration = chrono::duration_cast<chrono::microseconds>(quick_end - quick_start).count();
	//First Five
	cout << "First five sorted elts:  ";
	for (int k = 0; k < 5; k++)
		cout << quickArray[k] << ", ";
	cout << endl;
	//Last Five
	cout << "Last five sorted elts:  ";
	for (int k = 5; k > 0; k--)
		cout << quickArray[size - k] << ", ";
	cout << endl << endl;
	cout << "The time use for quicksort is " << quick_duration << " microseconds" << endl;

	//  ============ mergesort random integers  ===================
	cout << endl << "Mergesort of Integer data initially in random order" << endl;

	// implement your mergesort here or call it as a function
	// ===================== Mergesort ======================
	auto merge_start = chrono::high_resolution_clock::now();
	mergeSort(mergeArray, 0, size - 1);
	auto merge_end = chrono::high_resolution_clock::now();
	auto merge_duration = chrono::duration_cast<chrono::microseconds>(merge_end - merge_start).count();
	//First Five
	cout << "First five sorted elts:  ";
	for (int k = 0; k < 5; k++)
		cout << mergeArray[k] << ", ";
	cout << endl;
	//Last Five
	cout << "Last five sorted elts:  ";
	for (int k = 5; k > 0; k--)
		cout << mergeArray[size - k] << ", ";
	cout << endl
		 << endl;
	cout << "The time use for mergeSort is " << merge_duration << " microseconds" << endl;

	//  ============ insertion sort random integers  ===================
	cout << endl << "Insertion sort of Integer data initially in random order" << endl;

	// implement your insertion sort here or call it as a function
	//   ===================== Insertion Sort ===============
	auto insertstart = chrono::high_resolution_clock::now();
	insertionSort(insertArray, size);
	auto insertend = chrono::high_resolution_clock::now();
	auto insertion_duration = chrono::duration_cast<chrono::microseconds>(insertend - insertstart).count();
	//First Five
	cout << "First five sorted elts:  ";
	for (int k = 0; k < 5; k++)
		cout << insertArray[k] << ", ";
	cout << endl;
	//Last Five
	cout << "Last five sorted elts:  ";
	for (int k = 5; k > 0; k--)
		cout << insertArray[size - k] << ", ";
	cout << endl
		 << endl;
	cout << "The time use for insertionSort is " << insertion_duration << " microseconds" << endl;
	cout << "\n";
}