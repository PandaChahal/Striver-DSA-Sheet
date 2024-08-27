#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> triplet(int n, vector<int> &arr)
{
    vector<vector<int>> ans;
    for(int i =0;i<=n-2;i++)
    {
        for(int j = i+1;j<=n-1;j++)
        {
            for(int k =j+1;j<=n;k++)
            {
                if(arr[i]+arr[j]+arr[k] == 0)
                {
                    vector<int> temp ;
                    temp.push_back(arr[i]);
                    temp.push_back(arr[j]);
                    temp.push_back(arr[k]);
                    ans.push_back(temp);
                }
            }
        }
    }
    return ans;
}



int main()
{
    vector<int> arr = { -1, 0, 1, 2, -1, -4};
    int n = arr.size();
    vector<vector<int>> ans = triplet(n, arr);
    for (int i =0;i<ans.size();i++) 
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
    }
    return 0;
}

