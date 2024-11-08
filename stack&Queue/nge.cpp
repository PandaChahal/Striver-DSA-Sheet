#include<bits/stdc++.h>
using namespace std;
void findingNge(vector<int> arr)
{
    stack<int> st;
    int n = arr.size();
    int ans[n];
    for(int i =n-1;i>=0;i--)
    {
        while((!st.empty()) && (st.top()<=arr[i]))
        {
            st.pop();
        }
        if(st.empty())
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = st.top();
        }
        st.push(arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
}
int main()
{
    vector<int> arr = {3,10,4,2,1,2,6,1,7,2,9};
    findingNge(arr);
    return 0;
}