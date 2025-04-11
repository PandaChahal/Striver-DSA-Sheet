#include<bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) 
{
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<pair<int,int>,int>> q;
    int vis[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j] == 2)
            {
                q.push({{i,j},0});
                vis[i][j] == 2;
            }
            else
            {
                vis[i][j] = 0;
            }
        }
    }  
    int tm = 0;
    int drow[] = {-1,0,1,0};
    int dcol[] = {0,1,0,-1};  
    while(!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        tm = max(t,tm);
        q.pop();
        for(int i=0;i<n;i++)
        {
            int nrow = r+drow[i];
            int ncol = c+dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol] != 2 && grid[nrow][ncol]==1)
            {
                q.push({{nrow,ncol},t+1});
                vis[nrow][ncol] = 1;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(vis[i][j] != 2 && grid[i][j] == 1)
            {
                return -1;
            }
        }
    }
    return tm;
}

int main()
{
    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    cout<<orangesRotting(grid);
    return 0;
}