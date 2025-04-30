#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
{
    vector<int> ans(N, INT_MAX);
    vector<vector<pair<int, int>>> adj(N);

    for (int i = 0; i < M; i++)
    {
        adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
    }

    queue<pair<int, int>> q;
    q.push({0, 0});
    ans[0] = 0;

    while (!q.empty())
    {
        int dist = q.front().first;
        int node = q.front().second;
        q.pop();

        for (auto it : adj[node])
        {
            int nexNode = it.first;
            int nextWt = it.second;
            if (ans[nexNode] > dist + nextWt)
            {
                ans[nexNode] = dist + nextWt;
                q.push({dist + nextWt, nexNode});
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (ans[i] == INT_MAX)
        {
            ans[i] = -1;
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> edges{
        {0, 1, 2},
        {0, 4, 1},
        {4, 5, 4},
        {4, 2, 2},
        {1, 2, 3},
        {2, 3, 6},
        {5, 3, 1}};
    vector<int> ans = shortestPath(6, 7, edges);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}