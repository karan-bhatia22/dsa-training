#include <iostream>
#include <string>
#include <vector>
#include <stack>
 
using namespace std;

void printReverseIndividualWords(string s)
{
    stack<char> st;
    int i;
    string ans = "";
    for(i = 0; i < s.length(); i++)
    {
        if(s[i]!=' ')
        st.push(s[i]);
        else
        {
            while(!st.empty())
            {
                ans+= st.top();
                st.pop();
            }
            ans += ' ';
        }
    }
    while(!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    cout<<ans<<'\n';
}
int main()
{
    string s;
    getline(cin>>ws, s); //space separated string input

    printReverseIndividualWords(s);
    return 0;   
}