#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
 
using namespace std;


// comparator function to be put in the sort function. decides how pairs will get sorted.
bool comparator(const pair<int, int> &a, const pair<int, int> & b)
{
    return a.first + a.second < b.first + b.second;
}
int minTimeTaken(vector<pair<int, int> > customers)
{
    sort(customers.begin(), customers.end(), comparator); //sort the customers based on their finish times.
    vector<int> wait_times;
    int i, total = 0;
    for(i = 0; i < customers.size(); i ++)
    {
        if(wait_times.empty())
        {
            wait_times.push_back(customers[i].second);
            total += wait_times.back();
        }
        else
        {
            if(customers[i].first < customers[i - 1].first + customers[i - 1].second) // if the customer's arrival time is less than the finish time of previous customer
            {
                total += customers[i].second + wait_times.back() - customers[i].first + customers[i - 1].first;
                wait_times.push_back(customers[i].second + wait_times.back() - customers[i].first + customers[i - 1].first);
            }
            else // else if the customer's arrival happens after the previous customer is gone then there is no waiting time of previous customer
            {
                total += customers[i].second;
                wait_times.push_back(customers[i].second);
            }
        }
    }
    return total/customers.size();
}
int main()
{
    int N;
    cin>>N;
    vector<pair<int, int> > customers; // getting customer arrival time and cooking times as pair
    int i, x, y;
    for(i = 0; i < N; i ++)
    {
        cin>>x>>y;
        customers.push_back(make_pair(x, y));
    }
    cout<<"The minimum average time taken : " <<minTimeTaken(customers)<<'\n';
    return 0;
}