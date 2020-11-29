#include <bits/stdc++.h>
using namespace std;

// Merge Sort
// Time complexity: O(NlogN)

// cut in half and merge sort recursively
void merge(vector<int>& arr, int low, int mid, int high)
{
	//low为第1有序区的第1个元素，i指向第1个元素, mid为第1有序区的最后1个元素
    int i = low, j = mid + 1, k = 0;  //mid+1为第2有序区第1个元素，j指向第1个元素
    int *temp = new int[high - low + 1]; //temp数组暂存合并的有序序列
    while (i <= mid && j <= high){
        if(arr[i] <= arr[j]) //较小的先存入temp中
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i <= mid)//若比较完之后，第一个有序区仍有剩余，则直接复制到t数组中
        temp[k++] = arr[i++];
    while (j <= high)//同上
        temp[k++] = arr[j++];
    for (i=low, k=0; i<=high; i++, k++)//将排好序的存回arr中low到high这区间
    	arr[i] = temp[k];
    delete [] temp;//释放内存，由于指向的是数组，必须用delete [] 
}

void mergeSort(vector<int>& arr, int l, int r)
{
	if (l >= r) return;
	int m = (l + r)/2;
	mergeSort(arr, l, m);
	mergeSort(arr, m + 1, r);
	merge(arr, l, m, r);
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
    mergeSort(arr, 0, arr.size());
    printArray(arr);  
  
    return 0;  
} 
