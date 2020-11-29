#include <bits/stdc++.h>
using namespace std;

// Quick Sort
// Time complexity: worst~O(N^2); average~(NlogN)

/*
The key process in quickSort is partition(). 
Given an array and an element x of array as pivot, put x at its correct position in sorted array 
and put all smaller elements (smaller than x) before x, and put all greater elements (greater than x) after x. 
All this should be done in linear time.
*/
/* This function takes last element as pivot, 
places the pivot element at its correct position in sorted array, 
and places all smaller (smaller than pivot) to left of pivot and all greater elements to right of pivot */
int partition(vector<int>& arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1; //index of smaller element
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            // swap arr[i], arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // swap arr[i + 1], pivot (arr[high])
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1; // return new index of pivot
}

void quickSort(vector<int>& arr, int low, int high)
{
    if (low < high)
    {
        int partition_idx = partition(arr, low, high);
        quickSort(arr, low, partition_idx - 1);
        quickSort(arr, partition_idx + 1, high);
    }
}

void printArray(vector<int>& arr)  
{  
    int i;  
    for (i = 0; i < arr.size(); i++)  
        cout << arr[i] << " ";  
    cout << endl; 
} 

int main()  
{  
    vector<int> arr = { 12, 11, 13, 5, 6 };  
    // take last element as pivot
    quickSort(arr, 0, arr.size() - 1);
    printArray(arr);  
    return 0;  
} 
