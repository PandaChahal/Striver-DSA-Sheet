#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &matrix, int sr, int sc, int prevColor, int color, vector<vector<int>> &vis)
{
    int n = matrix.size();
    int m = matrix[0].size();
    matrix[sr][sc] = color;
    vis[sr][sc] = 1;
    int drow[4] = {1, 0, -1, 0};
    int dcol[4] = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++)
    {
        int nrow = sr + drow[i];
        int ncol = sc + dcol[i];

        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
            matrix[nrow][ncol] == prevColor && vis[nrow][ncol] == -1)
        {
            dfs(matrix, nrow, ncol, prevColor, color, vis);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    vector<vector<int>> vis(image.size(), vector<int>(image[0].size(), -1));
    vector<vector<int>> matrix = image;
    int prevColor = image[sr][sc];
    dfs(matrix, sr, sc, prevColor, color, vis);

    return matrix;
}

int main()
{
    vector<vector<int>> image{{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    vector<vector<int>> ans = floodFill(image, 1, 1, 2);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}