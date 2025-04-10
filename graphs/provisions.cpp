#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> arr[], vector<int> &vis)
{
    vis[node] = 1;
    for (auto it : arr[node])
    {
        if (!vis[it])
        {
            dfs(it, arr, vis);
        }
    }
}

int numProvinces(vector<vector<int>> matrix)
{
    int n = matrix.size();
    vector<int> arr[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if(i==j) continue;
            else
            {
                if(matrix[i][j] == 1)
                {
                    arr[i].push_back(j);
                    arr[j].push_back(i);
                }
            }
        }
    }
    vector<int> vis(n+1,0);
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            cnt++;
            dfs(i, arr, vis);
        }
    }
    return cnt;
}

int main()
{

    vector<vector<int>> adj{ {1, 0, 1},{1, 0, 0},{1, 0, 1}};
    cout<< numProvinces(adj) ;

    return 0;
}