#include<bits/stdc++.h>
using namespace std;

void nge2(vector<int> arr)
{
    int n = arr.size();
    int ans[n];
    stack<int> st;
    for(int i= 2*(n)-1;i>=0;i--)
    {
        while((!st.empty()) && (st.top() <= arr[i%n]))
        {
            st.pop();
        }
        if(i<n)
        {
            if(st.empty())
            {
                ans[i] = -1;
            }
            else
            {
                ans[i] = st.top();
            }
        }
        st.push(arr[i%n]);
    }
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
}
int main()
{
    vector<int> arr = {5,7,1,2,6,0};
    nge2(arr);
    return 0;
}