#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
 
using namespace std;


void insert(stack<int> &s, int temp)
{
    // base condition
    if (s.size() == 0)
    {
        s.push(temp);
        return;
    }
    int x = s.top();
    s.pop();
    insert(s, temp);
    // induction
    s.push(x);
}
void reverse_stack(stack<int> &s)
{
    // base condition
    if (s.size() == 1)
    {
        return;
    }
    int temp;
    temp = s.top();
    s.pop();
    reverse_stack(s);
    // induction
    insert(s, temp);
}

void printStack(stack<int> s)
{
    while(!s.empty())
    {
        cout<<s.top()<<'\n';
        s.pop();
    }
}
int main()
{
    stack<int> s;
    int i;
    cout<<"Enter number of elements in the stack: ";
    int n; // number of elements in the stack
    cin>>n; 
    int x; // temporary variable for taking input
    for(i = 0; i < n; i ++)
    {
        cin>>x;
        s.push(x);
    }
    cout<<"Current Stack: \n";
    printStack(s);

    cout<<"=========================================\n";

    reverse_stack(s);
    cout<<"Reverse Stack: \n";
    printStack(s);


    return 0;
}