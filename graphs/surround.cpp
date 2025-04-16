#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>> &board, vector<vector<int>> &vis, int r, int c)
{
    int n = board.size();
    int m = board[0].size();
    vis[r][c] = 1;
    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++)
    {
        int nrow = r + drow[i];
        int ncol = c + dcol[i];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == -1 && board[nrow][ncol] == 'O')
        {
            dfs(board, vis, nrow, ncol);
        }
    }
}

void solve(vector<vector<char>> &board)
{
    vector<vector<int>> vis(board.size(), vector<int>(board[0].size(), -1));
    int n = board.size();
    int m = board[0].size();
    for (int i = 0; i < n; i++)
    {
        if (board[i][0] == 'O')
        {
            dfs(board, vis, i, 0);
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (board[n - 1][i] == 'O')
        {
            dfs(board, vis, n - 1, i);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (board[i][m - 1] == 'O')
        {
            dfs(board, vis, i, m - 1);
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (board[0][i] == 'O')
        {
            dfs(board, vis, 0, i);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] == -1)
            {
                board[i][j] = 'X';
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout<<board[i][j]<< " ";
        }
        cout<<endl;
    }
}

int main()
{
    vector<vector<char>> mat{
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'O', 'X', 'X'},
        {'X', 'X', 'O', 'O'}};
    solve(mat);
    return 0;
}