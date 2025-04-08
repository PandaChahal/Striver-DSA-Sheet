#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "this is a random string";
    cout << "Before reversing the string is : " << s;
    s += " ";
    stack<string> st;
    int i;
    string str = "";
    for (i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            st.push(str);
            str = "";
        }
        else
        {
            str += s[i];
        }
    }
    string ans = "";
    while (st.size() != 1)
    {
        ans += st.top() + " ";
        st.pop();
    }
    ans += st.top();
    cout << "After reversal : " << endl;
    cout << ans;
    return 0;
}