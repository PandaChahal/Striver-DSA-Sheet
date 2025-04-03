#include<bits/stdc++.h>
using namespace std;

vector<int> dfs(vector<vector<int>> arr,vector<int> &visited,vector<int> &ans,int node)
{
    visited[node] = 1;
    ans.push_back(node);
    for(auto it:arr[node])
    {
        if(!visited[it])
        {
            dfs(arr,visited,ans,it);
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> arr(6);
    arr[1] = {2,5};
    arr[2] = {1,3};
    arr[3] = {2,4,5};
    arr[4] = {3,5};
    arr[5] = {1,3,4};
    vector<int> visited(6,0);
    vector<int> ans;
    vector<int> dfsss = dfs(arr,visited,ans,1);
    for(auto i:dfsss)
    {
        cout<<i<<" ";
    }
    return 0;
}