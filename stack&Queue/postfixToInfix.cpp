#include<iostream>
#include<stack>
using namespace std;
void postToInfix(string s)
{
    stack<string> st;
    for(int i=0;i<s.length();i++)
    {
        char c = s[i];
        if(c >='a' && c<='z' || c >='A' && c<='Z' || c >='0' && c<='9')
        {
            st.push(string(1,c));
        }
        else
        {
            string s1 = st.top();
            st.pop();
            string s2 = st.top();
            st.pop();
            string result = '(' + s2 + c + s1 + ')';
            st.push(result);
        }
    }
    cout<<st.top();
}
int main()
{
    string s = "ab*c+";
    postToInfix(s);
    return 0;
}