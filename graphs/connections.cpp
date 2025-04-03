#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> arr,vector<int> &visited,int node)
{
    visited[node] = 1;
    for(auto it:arr[node])
    {
        if(!visited[it])
        {
            dfs(arr,visited,it);
        }
    }
}

int cnxns(vector<vector<int>> arr)
{
    int cnt =0;
    int n = arr.size();
    vector<int> vis(n+1,0);
    for(int i=1;i<n;i++)
    {
        if(!vis[i])
        {
            cnt++;
            dfs(arr,vis,i);
        }
        
    }
    return cnt;
}
int main()
{
    vector<vector<int>> arr(10) ;
    arr[1]={2};
    arr[2]={1,3};
    arr[3]={2,4};
    arr[4]={3};
    arr[5]={6,7};
    arr[6]={5,7};
    arr[7]={5,6};
    arr[8]={9};
    arr[9]={8};
    cout<<cnxns(arr);
    return 0;
}