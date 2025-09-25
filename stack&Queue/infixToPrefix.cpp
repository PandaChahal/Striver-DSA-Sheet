#include <bits/stdc++.h>
#include <stack>
using namespace std;
int precd(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '/' || c == '*')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
void infixToPostfix(string s)
{
    stack<int> st;
    string result;
    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9')
        {
            result += c;
        }
        else if (c == ')')
        {
            st.push(')');
        }
        else if (c == '(')
        {
            while (st.top() != ')')
            {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!(st.empty()) && precd(c) < precd(st.top()))
            {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    cout << result << endl;
}
int main()
{
    string s = "(p+q)*(m-n)";
    infixToPostfix(s);
    return 0;
}