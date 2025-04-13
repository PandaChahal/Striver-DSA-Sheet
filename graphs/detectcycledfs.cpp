#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int parent, int vis[], vector<int> arr[])
{
    vis[node] = 1;
    for (auto it : arr[node])
    {
        if (!vis[it])
        {
            if (dfs(it, node, vis, arr) == true)return true;
        }
        else if (it != parent)return true;
    }
    return false;
}

bool isCycle(int V, vector<int> arr[])
{
    int vis[V] = {0};
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, -1, vis, arr) == true)return true;
        }
    }
    return false;
}

int main()
{
    vector<int> arr[] = {{}, {2,5}, {1,3}, {2,4},{3,6},{1,6,7},{4,5,8},{5},{6}};
    bool ans = isCycle(8, arr);
    if (ans)
        cout << "yes\n";
    else
        cout << "no\n";
    return 0;
}