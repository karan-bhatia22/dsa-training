#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

void reverse_queue(queue<int> &q)
{
    if(q.empty()) return;
    int temp = q.front();
    q.pop();
    reverse_queue(q);
    q.push(temp);
}
int main()
{
    int n; //number of elements in the queue
    cin>>n;
    int x; // temporary variable to get input
    int i;
    queue<int> q; //initialize the queue
    for(i = 0; i < n; i++)
    {
        cin>>x;
        q.push(x);
    }
    reverse_queue(q);

    while(!q.empty())
    {
        cout<<q.front()<<' ';
        q.pop();
    }
    cout<<'\n';
}   