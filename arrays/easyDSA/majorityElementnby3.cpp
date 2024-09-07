#include<bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> v) 
{
    int n = v.size(); 
    int cnt1 = 0, cnt2 = 0; 
    int e1 = INT_MIN; 
    int e2 = INT_MIN; 

    for (int i = 0; i < n; i++) 
    {
        if (cnt1 == 0 && e2 != v[i]) 
        {
            cnt1 = 1;
            e1 = v[i];
        }
        else if (cnt2 == 0 && e1 != v[i])
        {
            cnt2 = 1;
            e2 = v[i];
        }
        else if (v[i] == e1) 
        {
            cnt1++;
        }
        else if (v[i] == e2) 
        {
            cnt2++;
        }
        else 
        {
            cnt1--, cnt2--;
        }
    }

    vector<int> ans; 
    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) 
    {
        if (v[i] == e1) 
        {
            cnt1++;
        }
        if (v[i] == e2) 
        {
            cnt2++;
        }
    }

    int mini = int(n / 3) + 1;
    if (cnt1 >= mini) 
    {
        ans.push_back(e1);
    }
    if (cnt2 >= mini) 
    {
        ans.push_back(e2);
    }
    return ans;
}
int main()
{
    vector<int> v = {11,33,33,11,33,11};
    cout<<"majority element in the above given array is ";
    vector<int> ans = majorityElement(v);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}