#include<bits/stdc++.h>
using namespace std;
class MinStack{
    stack<pair<int,int>> st;
    public:
    void push(int value)
    {
        int minE;
        if(st.empty())
        {
            minE = value;
        }
        else
        {
            minE = min(value,st.top().second);
        }
        st.push({value,minE});
    }
    void pop()
    {
        st.pop();
    }
    int top()
    {
        return st.top().first;
    }
    int minElement()
    {
        return st.top().second;
    }
};
int main()
{
    MinStack ms;
    ms.push(10);
    ms.push(25);
    ms.push(5);
    ms.push(58);
    ms.push(180);
    cout<<ms.minElement()<<endl;
    return 0;
}