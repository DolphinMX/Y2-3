#include <stdio.h>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
using namespace std;

void merge(vector<int> &arr, int first, int mid, int last)
{
    int n1 = mid - first + 1;
    int n2 = last - mid;
    vector<int> left(n1);
    vector<int> right(n2);
    for (int i = 0; i < n1; i++)
    {
        left[i] = arr[first + i];
    }
    for (int j = 0; j < n2; j++)
    {
        right[j] = arr[mid + 1 + j];
    }
    int i = 0;
    int j = 0;
    int k = first;
    while (i < n1 && j < n2)
    {
        if (left[i] >= right[j])
        { // Change to >= for descending order
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}
void merge_sort(vector<int> &v1, int st, int ed)
{
    if (st < ed)
    {
        int mid = (st + ed) / 2;
        merge_sort(v1, st, mid);
        merge_sort(v1, mid + 1, ed);
        merge(v1, st, mid, ed);
    }
}
vector<int> arr;
int main()
{
    srand(time(0));
    int n;
    printf("Please input N:\n");
    scanf("%d", &n);
    arr.clear();
    for (int i = 0; i < n; i++)
    {
        int tmp = rand() % (n * 2);
        arr.push_back(tmp);
    }
    printf("The random array is: \n");
    printf("First five: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
    puts("");
    printf("Last five: ");
    for (int i = n - 5; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    puts("");
    merge_sort(arr, 0, n - 1);
    printf("The sorted array is: \n");
    printf("First five: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
    puts("");
    printf("Last five: ");
    for (int i = n - 5; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    puts("");
    return 0;
}