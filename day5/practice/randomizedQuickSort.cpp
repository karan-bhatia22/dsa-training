#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <random>
#include <random>
using namespace std;
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
 
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
int partition_r(vector<int> &arr, int low, int high)
{
    srand(time(NULL));
    int random = low + rand() % (high - low);
    swap(arr[random], arr[high]);
    return partition(arr, low, high);
}
void randomized_quick_sort(vector<int> &arr, int low, int high)
{
    if (low < high) {
        int pivot = partition_r(arr, low, high);
        randomized_quick_sort(arr, low, pivot - 1);
        randomized_quick_sort(arr, pivot + 1, high);
    }
}
int main()
{
    int n; // number of elements in the array
    cin>>n;

    vector<int> arr; // array
    int i, tmp;
    for(i = 0; i < n; i ++)
    {
        cin>>tmp;
        arr.push_back(tmp);
    }

    randomized_quick_sort(arr, 0, n - 1);

    cout<<"Array after randomized quick sorting\n";
    for(i = 0; i < n; i += 1)
    {
        cout<<arr[i]<<' ';
    }
    cout<<'\n';
    return 0;
}