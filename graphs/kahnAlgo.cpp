#include<bits/stdc++.h>
using namespace std;

vector<int> topoSort(vector<vector<int>> grid,int n)
{
    vector<int> indegree(n,0);
    for(int i=0;i<n;i++)
    {
        for(auto it : grid[i])
        {
            indegree[it]++;
        }
    }
    vector<int> topo;
    queue<int> q;
    for(int i=0;i<n;i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto it:grid[node])
        {
            indegree[it]--;
            if(indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    return topo;
}
int main()
{
    vector<vector<int>> grid {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
    int n = grid.size();
    vector<int> ans = topoSort(grid,n);
    cout<<"topoSort sequence using Kahn's algo :";
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    return 0;
}