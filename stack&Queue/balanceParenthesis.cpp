#include<bits/stdc++.h>
#include<iostream>
using namespace std;
bool balanceParenthesis(string s)
{
    stack<int> st;
    for(int i=0;i<s.length();i++)
    {
        char c = s[i];
        if(c == '(' || c == '{' || c == '[')
        {
            st.push(c);
        }
        else if(c == ')' && st.top() == '(')
        {
            st.pop();
        }
       
        else if(c == '}' && st.top() == '{')
        {
            st.pop();
        }
       
        
        else if(c == ']' && st.top() == '[')
        {
           st.pop();
        }
        
    }
    if(st.empty())
    {
        return true;
    }
    return false;
}
int main(){
    string s1="({[]})";
    string s2="([]{)";
    cout<<balanceParenthesis(s1)<<endl;
    cout<<balanceParenthesis(s2)<<endl;
    return 0;
}