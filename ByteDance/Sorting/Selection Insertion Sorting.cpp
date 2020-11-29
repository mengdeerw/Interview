#include <bits/stdc++.h>
using namespace std;

// insertion sort
// Time complexity: O(n^2)
/*
similar to the way we sort playing cards in hands
-从数组的第二个元素作为key开始遍历
-每次将key元素与其前面的元素相比较；一旦发现前面的元素比key大，则将其向后移一位，并继续用key向前比较
-直到前面的元素比key小，更新key的值
*/
void insertionSort(vector<int>& arr)
{
	int i, j, key;
	for (i = 1; i < arr.size(); i++)
	{
		key = arr[i];
		j = i - 1;
		// move elements in range [0, i -1] that are greater than key
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j]; //no need to swap, just replace with previous element
			j--;
		}
		// update key
		arr[j + 1] = key;
	}
}

// Selection sort
// Time complexity: O(n^2)
/*
- 将数组分为sorted及unsorted两部分
- 每次都从unsorted部分中寻找最小的元素，并与unsorted第一个元素进行交换
*/
void selectionSort(vector<int>& arr)
{
	for (int i = 0; i < arr.size() - 1; i++)
	{
		int min_idx = i;
		for (int j = i + 1; j < arr.size(); j++)
		{
			if (arr[j] < arr[min_idx]) min_idx = j;
		}
		// swap with the beginning of unsorted array
		int temp = arr[min_idx];
		arr[min_idx] = arr[i];
		arr[i] = temp;
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
  
    //insertionSort(arr);  
    selectionSort(arr);
    printArray(arr);  
  
    return 0;  
} 
