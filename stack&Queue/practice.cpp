#include <bits/stdc++.h>
using namespace std;

int priority(char ch)
{
    if (ch == '^')
        return 3;
    if (ch == '/' || ch == '*')
        return 2;
    if (ch == '+' || ch == '-')
        return 1;
    return -1;
}

string infixToPost(string s)
{
    string ans = "";
    int i = 0;
    int n = s.size();
    stack<int> st;
    for (; i < n; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9')
        {
            ans += s[i];
        }
        else if (s[i] == '(')
            st.push('(');
        else if (s[i] == ')')
        {
            while ((!st.empty()) && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while ((!st.empty()) && priority(s[i]) < priority(st.top()))
            {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    return ans;
}

string infixToPre(string s)
{
    stack<int> st;
    string ans = "";
    int n = s.size();
    reverse(s.begin(), s.end());
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            s[i] = ')';
        else if (s[i] == ')')
            s[i] = '(';
    }
    for (int i = 0; i < n; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9')
        {
            ans += s[i];
        }
        else if (s[i] == '(')
            st.push('(');
        else if (s[i] == ')')
        {
            while ((!st.empty()) && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while ((!st.empty()) && priority(s[i]) <= priority(st.top()))
            {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

string preToInfix(string s)
{
    int n = s.size();
    stack<string> st;
    string ans="";
    for(int i=n-1;i >= 0;i--)
    {
        if (s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9')
        {
            st.push(string(1,s[i]));
        }
        else{
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string str = '('+t1+s[i]+t2+')';
            st.push(str);
        }
    }
    ans = st.top();
    return ans;
}

string postToInfix(string s)
{
    int n = s.size();
    stack<string> st;
    string ans="";
    for(int i=0;i <n;i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9')
        {
            st.push(string(1,s[i]));
        }
        else{
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string str = '('+t2+s[i]+t1+')';
            st.push(str);
        }
    }
    ans = st.top();
    return ans;
}

string postToPre(string s)
{
    int n = s.size();
    stack<string> st;
    for(int i=0;i<n;i++)
    {
        if(s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9')
        {
            st.push(string(1,s[i]));
        }
        else
        {
            string t1 =st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string result = s[i]+t2+t1;
            st.push(result);
        }
        
    }
    return st.top();
}

string preToPost(string s)
{
    int n = s.size();
    stack<string> st;
    for(int i=n-1;i>=0;i--)
    {
        if(s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9')
        {
            st.push(string(1,s[i]));
        }
        else
        {
            string t1 =st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string result = t1+t2+s[i];
            st.push(result);
        }
        
    }
    return st.top();
}
int main()
{
    string s = "(a+b)*c-d+e";
    cout << "infixToPost : " << infixToPost(s) << endl;
    cout << "infixToPre : " << infixToPre(s) << endl;
    string a = "-*+abc+de";//prefix
    string b = "ab+c*de+-";//postfix
    cout<< "preToInfix : " << preToInfix(a)<<endl;
    cout<< "postToInfix : "<<postToInfix(b)<<endl;
    cout<< "postToPrefix : "<<postToPre(b)<<endl;
    cout<< "preToPostfix : "<<preToPost(a)<<endl;
    return 0;
}