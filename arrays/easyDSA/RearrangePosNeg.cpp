#include<bits/stdc++.h>
using namespace std;
vector<int> rearrange(vector<int> arr)
{
    int n = arr.size();
    vector<int> ans(n,0);
    int count =0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>0)
        {
            count++;
        }
    }
    for(int i=0;i<n;i++)
    {
       if(arr[i]>=0)
       {
            ans[2*i] = arr[i];
       }
       else
       {
        ans[(i)+1] = arr[i];
       }
        
    }
    return ans;
}
int main()
{
    vector<int> arr = {1,2,-4,-5};
    vector<int> finalArray = rearrange(arr);
    for(int i =0;i<finalArray.size();i++)
    {
        cout<<finalArray[i]<<" ";
    }
    return 0;
}