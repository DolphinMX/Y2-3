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

/*void quick_sort(int* data, int p, int r)
{int pcount=0; int rcount=0;
    if (p < r) {
        int p = partition(data, p, r);pcount++;
        quick_sort(data, p, p - 1); //return pcount;
        quick_sort(data, p + 1, r);  rcount++;
    }
    cout<<"quicksort(data,"<<p<<","<<r<<")"<<endl;
    cout<<"p ="<<pcount<<" "; cout<<"r ="<<rcount<<" "<<endl;
    //return pcount;return rcount;
}
*/
void quick_sort(int* data, int p, int r)
{
    int pcount=0; int rcount=0;

    if (p < r) {
        int p = partition(data, p, r);
        quick_sort(data, p, p - 1); pcount++;
        quick_sort(data, p + 1, r); rcount++;
    }
    cout<<"quicksort(data,"<<p<<","<<r<<")"<<endl;
    cout<<"p ="<<pcount<<" "; cout<<"r ="<<rcount<<" "<<endl;

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

    quick_sort(data,0,size-1);

    cout << "List after sort: "<<endl;
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }

    input.close();
}
