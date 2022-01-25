#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <string.h>
using namespace std;

vector<int> getMax(vector<string> queries) //returns the maximum value queries
{
    stack<int> s;
    int maxElement = INT_MIN; //initialized to INT_MIN 
    int i;

    vector<int> ans;
    // We need to keep track of the maximum element in O(1) time and O(1) space.
    // We store x if x is smaller than maxElement otherwise we store 2*x - maxElement
    // While popping if the removed element y is less than maxElement we just remove otherwise we remove it and set the new maxElement to 2*maxElement - y

    for(i = 0; i < queries.size(); i ++)
    {
        int query_type = queries[i][0] - '0';
        if(query_type == 1) // if the first character of query is '1' then element x has to be pushed in the stack
        {
            string number = queries[i].substr(2); //number will be substring after 2 characters in query
            int element = stoi(number); // converting string to number
            if(s.empty())
            {
                maxElement = element;
                s.push(element);
            }
            else if(element < maxElement)
                s.push(element);
            else 
            {
                maxElement = element;
                s.push(2*element - maxElement);
            }
        }
        else if(query_type == 2) // if first character is '2' then top has to be popped from the stack
        {
            if(s.empty())
            {
                cout<<"Invalid query! Stack is empty\n";
                return ans;
            }

            else if(s.top() < maxElement)
            {
                s.pop();
            }
            else 
            {
                maxElement = 2*maxElement - s.top();
                s.pop();
            }
        }
        else if (query_type == 3)  // if first character is '3' then max has to be returned
        {
            if(s.empty()) 
            {
                cout<<"Invalid query! Stack is empty\n";
                return ans;
            }
            else
            ans.push_back(maxElement);
        }
    }
    return ans;
}
int main()
{
    int q; // number of queries
    cin>>q;
    vector<string> queries;
    int i;
    string query;
    for(i = 0; i < q; i++)
    {
        getline(cin >> ws, query); // using getline for spaced string input. 
        queries.push_back(query);
    }
    vector<int> maximum_values;
    maximum_values = getMax(queries);

    for(i = 0; i < maximum_values.size(); i++)
    {
        cout<<maximum_values[i]<<'\n';
    }
}