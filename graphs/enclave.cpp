#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &grid, vector<vector<int>> &vis, int r, int c)
{
    int n = grid.size();
    int m = grid[0].size();
    vis[r][c] = 1;
    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++)
    {
        int nrow = r + drow[i];
        int ncol = c + dcol[i];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && vis[nrow][ncol] == -1)
        {
            dfs(grid, vis, nrow, ncol);
        }
    }
}
int numEnclaves(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int cnt = 0;
    vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), -1));
    for (int i = 0; i < n; i++)
    {
        if (grid[i][0] == 1)
        {
            dfs(grid, vis, i, 0);
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (grid[n - 1][i] == 1)
        {
            dfs(grid, vis, n - 1, i);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (grid[i][m - 1] == 1)
        {
            dfs(grid, vis, i, m - 1);
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (grid[0][i] == 1)
        {
            dfs(grid, vis, 0, i);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1 && vis[i][j] == -1)
            {
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    vector<vector<int>> grid{
        {0,0,0,0},
        {1,0,1,0},
        {0,1,1,0},
        {0,0,0,0}
    };
    int n = numEnclaves(grid);
    cout<<n;
    return 0;
}