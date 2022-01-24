#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int search(vector<int> arr, int value_to_search) //returns first index of the value if found otherwise returns -1
{

    /* Time Complexity O(N) */
    
    int i;
    for(i = 0; i < arr.size(); i ++)
    {
        if(arr[i] == value_to_search) return i;
    }
    return -1;
}
int main()
{
    int n, i;
    cin>>n;
    int tmp; // tmp variable to get user input
    vector<int> arr;

    for(i = 0; i < n; i ++)
    {
        cin>>tmp;
        arr.push_back(tmp);
    }

    int value_to_search; // value to search in the array
    cin>>value_to_search; 

    int index_of_val;

    index_of_val = search(arr, value_to_search);

    if(index_of_val > 0)
    cout<<"Found at index: "<<index_of_val<<'\n';

    else
    cout<<"Value:" << value_to_search << " not found in the array!\n";
}