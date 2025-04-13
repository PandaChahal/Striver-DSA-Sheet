#include <bits/stdc++.h>
using namespace std;

bool detect(int src, vector<int> arr[], int vis[])
{
    vis[src] = 1;
    queue<pair<int, int>> q;
    q.push({src, -1});
    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto it : arr[node])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                q.push({it, node});
            }
            else if (parent != it)
            {
                return true;
            }
        }
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
            if (detect(i, arr, vis))return true;
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