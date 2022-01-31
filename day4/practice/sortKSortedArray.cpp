// Given a k-sorted array sort the array

// k-sorted array : when the position of the element say 2 is not more than k places away from the position of element in the sorted array.
// suppose position of 2 in the sorted array is at index 2 then the position in the k-sorted array will be in the range (2 - k, 2 + k)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>

#define min_heap priority_queue<int, vector<int>, greater<int> >
using namespace std;
void kSort(vector<int> & arr, int k) // time complexity O(nlogk) where n is the input size
{
    min_heap q; // initializing a min-heap
    int i, j = 0;
    for(i = 0; i < arr.size(); i ++)
    {
        q.push(arr[i]); // push the element in the min heap
        if(q.size() > k) // if the size of the min heap is greater than k then we know that this will be the smallest element 
        // within the range (j - k, j + k) hence we push it at position j which is the right position
        {
            arr[j++] = q.top();
            q.pop(); // we pop the element to maintain a size of k for the min heap
        }
    }
    while(!q.empty()) // while there are still elements left in the min heap we pop them and add to their positions
    {
        arr[j++] = q.top();
        q.pop();
    }
}
int main()
{
    int n;
    cin>>n;
    int x, i;
    vector<int> arr;

    for(i = 0; i < n; i ++)
    {
        cin>>x;
        arr.push_back(x);
    }

    int k;
    cin>>k;
    kSort(arr, k);

    cout<<"\nSorted array after sorting the k-sorted array with k = " << k << '\n';
    for(i = 0 ; i < n; i ++)
    {
        cout<<arr[i] << " ";
    }
    cout<<'\n';
    return 0;
}