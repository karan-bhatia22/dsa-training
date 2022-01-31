#include <iostream>
#include <vector> 
#include <queue> 
#include <algorithm>
using namespace std;

#define max_heap  priority_queue<int> 
#define min_heap priority_queue<int, vector<int>, greater<int> > 

void printKLargestElements(vector<int> arr, int k)
{
    min_heap q; // using min heap for this.

    int i;
    for(i = 0; i < arr.size(); i++) // element at the top of the heap will always be the minimum element. following that there 
    // will be elements in ascending order
    {
        q.push(arr[i]); // push in the heap 
        if(q.size() > k) q.pop(); // if the size is over k then we pop the element since it will never be the candidate 
        // belonging to the k largest ones.
    }
    // once the array is traversed completely we know that the k largest elements are present in the min heap
    while(!q.empty()) // we pop all the elements from the heap and print them
    {
        cout<<q.top()<<" ";
        q.pop();
    }

    cout<<'\n';
    return;

}
int main()
{
    int n;
    cin>>n; // number of elements in the array
    vector<int> arr; 
    int i, x; 
    for(i = 0; i < n; i ++)
    {
        cin>>x;
        arr.push_back(x);
    }

    int k;
    cin>>k;
    printKLargestElements(arr, k);
}