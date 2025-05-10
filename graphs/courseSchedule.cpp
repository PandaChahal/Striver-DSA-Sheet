#include <bits/stdc++.h>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<int> indegree(numCourses, 0);
    vector<vector<int>> adj(numCourses);
    for (auto it : prerequisites)
    {
        adj[it[1]].push_back(it[0]);
    }
    for (int i = 0; i < numCourses; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }
    queue<int> q;
    vector<int> topo;
    for (int i = 0; i < numCourses; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    if (topo.size() == numCourses)
    {
        return true;
    }
    return false;
}

int main()
{
    vector<vector<int>> prerequisites;
    int N = 4;
    prerequisites.push_back({1, 0});
    prerequisites.push_back({2, 1});
    prerequisites.push_back({3, 2});

    bool ans = canFinish(N, prerequisites);

    if (ans)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    cout << endl;

    return 0;
}