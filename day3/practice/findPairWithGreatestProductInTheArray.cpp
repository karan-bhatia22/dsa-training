#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
 
using namespace std;

pair<int, int> pairWithGreatestProduct(vector<int> arr)
{
    int i, j;
    unordered_map <int, bool> m;
    int max_product = INT_MIN;
    pair<int, int> max_pair;
    for(i = 0; i < arr.size(); i ++)
    {
        if(m.find(arr[i]) == m.end()) // if element not in the map then insert it
        {
            m.insert(make_pair(arr[i], 1));
        }
    }

    for(i = 0; i < arr.size() - 1; i ++)
    {
        for(j = i + 1; j < arr.size(); j++)
        {
            if(m.find(arr[i] * arr[j]) != m.end()) // if the product of two is present in the array
            {
                max_product = max(arr[i] * arr[j], max_product);
                if(max_product == arr[i]*arr[j])
                {
                    max_pair.first = arr[i];
                    max_pair.second = arr[j];
                }
            }
        }
    }

    if(max_product == INT_MIN) return make_pair(INT_MIN, INT_MIN); // if no max product within the array exists then return invalid pair
    return max_pair; // if max product within the array exists then return max_pair
}
int main()
{
    int n;
    cin>>n; //size of the array

    vector<int> arr; 
    int tmp, i;
    for(i = 0; i < n; i ++)
    {
        cin>>tmp;
        arr.push_back(tmp);
    }

    pair<int, int> p; 
    p = pairWithGreatestProduct(arr);

    if(p.first != INT_MIN && p.second != INT_MIN)
    cout<<"Pair with the greatest product is: " << p.first<<" "<<p.second<<'\n';
    else
    cout<<"Such pair does not exist!\n";
    return 0;
}