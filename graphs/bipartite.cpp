#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int x, vector<int> &color, vector<vector<int>> &graph)
{
    color[node] = x;
    for (auto it : graph[node])
    {
        if (color[it] == -1)
        {
            if (!dfs(it, !x, color, graph))
                return false;
        }
        else if (color[it] == x)
        {
            return false;
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> color(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            if (!dfs(i, 0, color, graph))
                return false;
        }
    }
    return true;
}

int main()
{
    vector<vector<int>> grid{
        {1, 3},
        {0, 2},
        {1, 3},
        {0, 2}};
    if(isBipartite){
        cout<<"yes \n";
    }
    else{
        cout<<"no \n";
    }
    return 0;
}