#include<bits/stdc++.h>
using namespace std;

bool cycleDetect(vector<vector<int>> grid,int n)
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
    int cnt = 0;
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
        cnt++;
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
    if(cnt == n) return false;
    return true;
}
int main()
{
    vector<vector<int>> grid {{1}, {2}, {3,4}, {}, { 1}};
    int n = grid.size();
    bool ans = cycleDetect(grid,n);
    cout<<"Is the given Graph cyclic or not : ";
    if(ans) 
    {
        cout<<"YES";
    }    
    else
    {
        cout<<"NO ";
    }
    return 0;
}