#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> stockSpan(vector<int> arr)
{
    // We find the nearest greater element to the left. Store the indices of elements instead of elements itself.

    vector<int> ans(arr.size());
    int i;
    stack<int> s;
    for(i = 0; i < arr.size(); i++)
    {
        if(s.empty()) ans[i] = 1;
        
        else if(arr[s.top()] > arr[i]) ans[i] = 1;

        else
        {
            int count = 0;
            while(!s.empty() && arr[s.top()] <= arr[i])
            {
                count+= ans[s.top()];
                s.pop();
            }

            ans[i] = count + 1;
        }
        s.push(i);
    }

    return ans;
}

int main()
{
    int n; //number of stock records
    cin>>n;

    vector<int> arr; //array of stock prices

    int tmp, i; 
    for(i = 0; i < n; i ++)
    {
        cin>>tmp;
        arr.push_back(tmp);
    }

    vector<int> stock_span_arr;
    stock_span_arr = stockSpan(arr);

    for(i = 0; i < n; i ++)
    {
        cout<<stock_span_arr[i]<<" ";
    }
    cout<<'\n';
}