#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

vector<int> nextGreaterElement(vector<int> arr) // returns next greater element 
{
    stack<int> s;
    int i;
    vector<int> ans;
    for(i = arr.size() - 1; i > -1; i--)
    {
        if(s.empty())
        ans.push_back(-1);
        else if(s.top() > arr[i]) ans.push_back(s.top());
        else 
        {
            while(!s.empty() && s.top() < arr[i])
                s.pop();
            if(s.empty())
                ans.push_back(-1);
            else 
                ans.push_back(s.top());
        }

        s.push(arr[i]);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr;
    int i, tmp;
    for(i = 0; i < n; i ++)
    {
        cin>>tmp;
        arr.push_back(tmp);
    }
    vector<int> ans;

    ans = nextGreaterElement(arr);
    for(i = 0; i < ans.size(); i ++)
    cout<<ans[i]<<' ';

    cout<<'\n';

}