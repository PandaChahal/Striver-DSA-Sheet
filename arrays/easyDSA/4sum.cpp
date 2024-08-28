#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> triplet( vector<int> &arr,int target)
{
    int n = arr.size();
    vector<vector<int>> ans;
    for(int i = 0; i <= n-3; i++)
    {
        for(int j = i+1; j <= n-2; j++)
        {
            for(int k = j+1; k <=n-1; k++)
            {
                for(int l = k+1;l<n;l++)

                {
                    if((arr[i] + arr[j] + arr[k]+arr[l]) == target)
                {
                    vector<int> temp;
                    temp.push_back(arr[i]);
                    temp.push_back(arr[j]);
                    temp.push_back(arr[k]);
                    temp.push_back(arr[l]);
                    ans.push_back(temp);
                }}
            }
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = { 4,3,3,4,4,2,1,2,1,1};
    int target = 9;
    int n = arr.size();
    vector<vector<int>> ans = triplet( arr,target);
    for (int i =0;i<ans.size();i++) 
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}

