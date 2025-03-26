#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ,m;
    cout<<"enter the number of edges : ";
    cin>>n;
    cout<<"enter the number of nodes : ";
    cin>>m;
    int adj[m][m];
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cout<<"enter first number : ";
        cin>>u;
        cout<<"enter second number : ";
        cin>>v;
        adj[u][v] = 1;
        adj[v][u] = 1  ;
    }
    return 0;
}