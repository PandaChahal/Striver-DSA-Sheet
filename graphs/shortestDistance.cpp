#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<vector<int>> &edges, int N, int M)
{
    vector<int> ans(N, INT_MAX);
    vector<vector<int>> adj(N);

    for (int i = 0; i < M; i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]); 
    }

    queue<pair<int, int>> q;
    q.push({0, 0});
    ans[0] = 0;

    while (!q.empty())
    {
        int node = q.front().first;
        int dist = q.front().second;
        q.pop();

        for (auto it : adj[node])
        {
            if (ans[it] > dist + 1)
            {
                ans[it] = dist + 1;
                q.push({it, dist + 1});
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (ans[i] == INT_MAX)
            ans[i] = -1;
    }

    return ans;
}
int main()
{
    vector<vector<int>> edges{
        {0,1},{0,3},{3,4},{4,5},{5, 6},{1,2},{2,6},{6,7},{7,8},{6,8}
    };
    vector<int> ans = shortestPath(edges,9,10);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}