#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
 
using namespace std;
 
bool isSubset(vector<int> arr1, vector<int> arr2)
{
    unordered_map<int, bool> m; // map to keep track of whether the element is seen in the array or not.
    int i;
    if(arr1.size() < arr2.size()) // if first array is smaller than second then we check if elements of arr1 are also seen in arr2 or not
    {
        for(i = 0; i < arr2.size(); i ++)
        {
            if(m.find(arr2[i]) == m.end()) // if element is not present in the map we insert it in the map
            {
                m.insert(make_pair(arr2[i], 1));
            }
        }

        for(i = 0; i < arr1.size(); i ++)
        {
            if(m.find(arr1[i]) == m.end()) // if element is not present in the map then we know that one is not subset of another
            {
                return false;
            }
        }

        return true;
    }
    else // if second array is smaller than first then we check if elements of arr1 are also seen in arr2 or not
    {
        for(i = 0; i < arr1.size(); i ++)
        {
            if(m.find(arr1[i]) == m.end()) // if element is not present in the map we insert it in the map
            {
                m.insert(make_pair(arr1[i], 1));
            }
        }

        for(i = 0; i < arr2.size(); i ++)
        {
            if(m.find(arr2[i]) == m.end()) // if element is not present in the map then we know that one is not subset of another
            {
                return false;
            }
        }

        return true;
    }
}
int main()
{
    int n, m;
    cin>>n; // size of the first array

    vector<int> arr1, arr2;

    int tmp, i;
    for(i = 0; i < n; i ++)
    {
        cin>>tmp;
        arr1.push_back(tmp);
    }
    cin>>m; // size of the second array
    for(i = 0; i < m; i ++)
    {
        cin>>tmp;
        arr2.push_back(tmp);
    }

    isSubset(arr1, arr2) ? cout<<"One array is subset of the other. \n" : cout<<"Not a subset\n";
    return 0;
}