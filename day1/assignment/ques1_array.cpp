#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> reverseArray(vector<int> P)
{
    if(P.size() == 0) return P; // if no element present return P straightaway
    
    int i, j; // two pointers

    i = 0, j = P.size() - 1;

    while(i < P.size() && j > -1 && i < j)
    {
        swap(P[i], P[j]); // swap elements from beginning and end
        i++;
        j--;
    }

    return P;
}
int main()
{
    int Q; // size of array P
    cin >> Q; // user input

    vector<int> P (Q); // array P of size Q

    int i;
    for(i = 0; i < Q; i ++) //array input
        cin>>P[i];

    vector<int> ans(Q); // captures the returned reverse array

    ans = reverseArray(P);

    //Output
    for(i = 0 ; i < Q; i ++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<'\n';
    
}