#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
 
using namespace std;

stack<int> sortStack(stack<int> input)
{
    stack<int> tmpStack;
 
    while (!input.empty())
    {
        // pop out the first element
        int tmp = input.top();
        input.pop();
 
        // while temporary stack is not empty
        // and top of stack is smaller than temp
        while (!tmpStack.empty() && tmpStack.top() < tmp)
        {
            // pop from temporary stack and
            // push it to the input stack
            input.push(tmpStack.top());
            tmpStack.pop();
        }
 
        // push temp in temporary of stack
        tmpStack.push(tmp);
    }
 
    return tmpStack;
}
void sort_arr(vector<int> &arr)
{
    stack<int> s;
    int i;
    for(i = 0; i < arr.size(); i++)
    {
        s.push(arr[i]);
    }
    s = sortStack(s);
    i = 0;
    while(!s.empty())
    {
        arr[i++] = s.top();
        s.pop();
    }
}
int main()
{
    int n; // number of elements in arr
    cin>>n;
    int tmp, i;
    vector<int> arr;
    for(i = 0; i < n; i ++)
    {
        cin>>tmp;
        arr.push_back(tmp);
    }
    
    sort_arr(arr);

    for(i = 0; i < n; i ++)
    cout<<arr[i] <<" ";

    cout<<'\n';
    return 0;
}