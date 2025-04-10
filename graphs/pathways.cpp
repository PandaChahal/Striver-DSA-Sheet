#include<iostream>
#include<vector>
using namespace std;
void dfs(vector<vector<int> > &arr,int node,vector<int> &vis,int dst,int &count)
{
    vis[node] = 1;
    for(auto it : arr[node])
    {
        if(it == dst)count++;
        if(!vis[it])
        {
            dfs(arr,it,vis,dst,count);
        }
    }
}
int findWays(vector<vector<int> >&matrix){
    int n = matrix.size();
    vector<vector<int> > arr(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<matrix[0].size();j++)
        {
            if(i==j)continue;
            else{
                if(matrix[i][j] == 1)
                {
                    arr[i].push_back(j);
                }
            }
        }
    }
    int count = 0;
    int src=0;
    int dst=3;
    vector<int> vis(dst+1,0);
    dfs(arr,src,vis,dst,count);
    return count;
}
int main()
{
    vector<vector<int> >matrix={{1,1,0,1},{0,1,1,0},{0,0,1,1},{0,0,0,1}};
    cout<<findWays(matrix);
 return 0;
}