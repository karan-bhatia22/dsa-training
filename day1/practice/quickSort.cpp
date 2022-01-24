#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int partition (vector<int> &arr, int low, int high) 
{ 
    int pivot = arr[high]; // pivot 
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
  
    for (int j = low; j <= high - 1; j++) 
    { 
        // If current element is smaller than the pivot 
        if (arr[j] < pivot) 
        { 
            i++; // increment index of smaller element 
            swap(arr[i], arr[j]); 
        } 
    } 
    swap(arr[i + 1], arr[high]); 
    return (i + 1); 
} 

void quickSort(vector<int> &arr, int low, int high)
{
    if(low < high)
    {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int main()
{
    int i;
    int n;
    cin>>n;
    vector<int> arr;
    int tmp;
    for(i = 0; i < n; i ++)
    {
        cin>>tmp;
        arr.push_back(tmp);
    }
    quickSort(arr, 0, arr.size() - 1);

    cout<<"\n\n=========================================================\n";
    cout<<"Sorted array: ";
    for(i = 0; i < n; i ++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n=========================================================\n";
}
