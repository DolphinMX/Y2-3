#include <stdio.h>
#include <vector>
#include <iostream>
#include <sys/time.h>
#include <stdlib.h>
#include <time.h>
using namespace std;


void merge_sort(vector<int> & v1, int st, int ed){

  cout<<"mergeSort(data,"<<st<<","<<ed<<")\n";
  


}

vector<int> arr;

int main() {
    srand(time(0)); // set the seed of random number
    
    int n;
    printf("Please input N:\n");
    scanf("%d", &n);
    arr.clear();
    for (int i = 0;i<n;i++) {
        int tmp = rand() % (n * 2);
        arr.push_back(tmp);
    }
    printf("The random array is: \n");
    printf("First five: ");
    for (int i = 0;i<5;i++) {
        printf("%d ", arr[i]);
    }
    puts("");
    printf("Last five: ");
    for (int i = n - 5;i<n;i++) {
        printf("%d ", arr[i]);
    }
    puts("");
    merge_sort(arr, 0, n - 1);
    printf("The sorted array is: \n");
    printf("First five: ");
    for (int i = 0;i<5;i++) {
        printf("%d ", arr[i]);
    }
    puts("");
    printf("Last five: ");
    for (int i = n - 5;i<n;i++) {
        printf("%d ", arr[i]);
    }
    puts("");
    return 0;
}
