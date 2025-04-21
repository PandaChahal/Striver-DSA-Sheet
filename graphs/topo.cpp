#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> adj, vector<int> &vis, int node, stack<int> &st)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(adj, vis, it, st);
        }
    }
    st.push(node);
}

void topo(vector<vector<int>> adj, int n)
{
    vector<int> vis(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(adj, vis, i, st);
        }
    }

    cout << "Topological Order: ";
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main()
{
    vector<vector<int>> adj {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
    int n = adj.size();
    topo(adj, n);
    return 0;
}