#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &grid, vector<vector<int>> &vis, int r, int c)
{
    vis[r][c] = 1;
    queue<pair<int, int>> q;
    q.push({r, c});
    int n = grid.size();
    int m = grid[0].size();
    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && !vis[nrow][ncol])
            {
                vis[nrow][ncol] = 1;
                q.push({nrow, ncol});
            }
        }
    }
}

int numIslands(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && grid[i][j] == 1)
            {
                cnt++;
                bfs(grid, vis, i, j);
            }
        }
    }
    return cnt;
}

int main()
{
    vector<vector<int>> grid {
        {0,1,1,0},
        {0,1,1,0},
        {0,0,1,0},
        {0,0,0,0},
        {1,1,0,1}
    };
    for(int i=0;i<grid.size();i++)
    {
        for(int j=0;j<grid[0].size();j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    int ans = numIslands(grid);
    cout<<"number of islands in the given grid are "<<ans<<endl;
    return 0;
}