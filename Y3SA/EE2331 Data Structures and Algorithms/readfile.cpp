#include <iostream>
#include <cassert>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <chrono>
#include <ctime>
#include<fstream>
using namespace std;

int partition(int* data, int low, int high)
{
    int pivot = data[low];
    int i = low + 1;
    int j = high;

    while (true) {
        while (i <= j && data[i] >= pivot)
            i++;
        while (i <= j && data[j] < pivot)
            j--;
        if (i >= j)
            break;
        swap(data[i], data[j]);
    }

    swap(data[low], data[j]);
    return j;
}

void quickSort(int* data, int low, int high)
{
    if (low < high) {
        int p = partition(data, low, high);
        quickSort(data, low, p - 1);
        quickSort(data, p + 1, high);
    }
}
int main()
{
        int size;
        int* data = new int[size];

    //int data[50] = { };
    // read integers from file and create an array
    ifstream input("test1.txt");
    if (!input.is_open()) 
    {
        cout << "Error: cannot open data file" << endl;
        exit(0); //terminate the program
    }
    cout << "Number of elements: ";
    input >> size;
    cout << size << endl;
    cout<<"List before sort:"<<endl;
    for (int i = 0; i < size; i++) 
    {
        input >> data[i];
        //int data=data[i];
        cout << data[i] << " ";
    }
    cout<<endl<<endl;

    quickSort(data,0,size-1);

    cout << "List after sort: "<<endl;
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }

    input.close();
}
