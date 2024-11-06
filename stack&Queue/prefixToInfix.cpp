#include<iostream>
#include<stack>
using namespace std;

void pretoinfix(string s)
{
    stack<string> st;
    for(int i= s.length()-1;i>=0;i--)
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
            string result = '(' + s1 +c+ s2 + ')';
            st.push(result);
        }
    }
    cout<<st.top();
}
int main()
{
    string s = "*-A/BC-/AKL";
    pretoinfix(s);
    return 0;
}