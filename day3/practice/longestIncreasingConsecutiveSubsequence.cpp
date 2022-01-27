#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
 
using namespace std;
void printLongestIncreasingConsecutiveSubsequence(vector<int> arr)
{
    int i;
    unordered_map<int, vector<int> > m;
    int max_length = 0;
    int max_sequence_id = -1;

    for(i = 0; i < arr.size(); i ++)
    {
        if(m.find(arr[i] - 1) == m.end()) // if arr[i] - 1 is not present in the map
        {
            vector<int> t;
            t.push_back(arr[i]);
            m.insert(make_pair(arr[i], t));
            max_length = max(max_length, int(t.size()));
            if(max_length == t.size())
                max_sequence_id = arr[i];
        }
        else  // if arr[i] - 1 is present in the map we take the sequence stored at the arr[i] - 1 key and push arr[i] to that sequence
        {
            vector<int> t;
            t = m[arr[i] - 1];
            t.push_back(arr[i]);
            m.insert(make_pair(arr[i], t));
            max_length = max(max_length, int(t.size()));
            if(max_length == t.size())
                max_sequence_id = arr[i];
        }
    }

    vector<int> lis;
    lis = m[max_sequence_id];

    for(i = 0; i < lis.size(); i ++)
    cout<<lis[i]<<" ";
    cout<<'\n';

}
int main()
{
    int n; 
    cin>>n; //size of the array
    int tmp, i;
    vector<int> arr;
    for(i = 0; i < n; i ++)
    {
        cin>>tmp;
        arr.push_back(tmp);
    }
    printLongestIncreasingConsecutiveSubsequence(arr);
    return 0;
}