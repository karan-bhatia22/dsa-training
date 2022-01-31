#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>

#define max_heap priority_queue<pair<int, int> > 
using namespace std;

vector<int> kClosestToX(vector<int> arr, int k, int x)
{
    if(arr.size() < k) return {}; // if the size of arr is less than k then there cannot be k elements which are closest to x

    vector<int> ans;
    max_heap q;
    int i;
    for(i = 0; i < arr.size(); i ++)
    {
        q.push(make_pair(abs(arr[i] - x), arr[i])); // push the pair (absolute difference b/w arr[i] and x, arr[i])
        if(q.size() > k) // if size of heap exceeds k we remove the top element
        {
            q.pop();
        }
    }
    while(!q.empty())
    {
        ans.push_back(q.top().second);
        q.pop();
    }
    
    return ans;
}
int main()
{
    int n;
    cin >> n; // number of elements in the array

    vector<int> arr; 
    int i, tmp;
    for(i = 0; i < n; i ++ )
    {
        cin>>tmp;
        arr.push_back(tmp);
    }
    int k, x; 
    // need to return k numbers who are closest to x
    cin>>k >> x;

    vector<int> ans; 
    ans = kClosestToX(arr, k, x);

    for(i = 0; i < ans.size(); i ++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<'\n';
    return 0;
}