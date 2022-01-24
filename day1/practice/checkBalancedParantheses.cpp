#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

bool checkBalancedParantheses(string s)
{
    int i;
    stack<char> st;
    for(i = 0; i < s.length(); i ++)
    {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
        st.push(s[i]);
        else 
        {
            if(st.top() == '(' && s[i] == ')' || st.top() == '{' && s[i] == '}' || st.top() == '[' && s[i] == ']')
            st.pop();
            else return false;
        }
    }
    if(st.empty()) return true;
    else return false;
}
int main()
{
    string s;
    cout<<"Enter the parantheses sequence to check: ";
    cin>>s;
    bool valid = checkBalancedParantheses(s);
    if(valid) cout<<"Sequence balanced! \n";
    else cout<<"Invalid\n";
}