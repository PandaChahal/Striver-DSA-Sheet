class Solution {
    private:
     bool dfs(vector<int> adj[],vector<int> &vis,vector<int> &pathVis,int node)
     {
         vis[node] =1;
         pathVis[node] =1 ;
         for(auto it:adj[node])
         {
             if(!vis[it])
             {
                 if(dfs(adj,vis,pathVis,it)) return true;
             }
             else if(pathVis[it])
             {
                 return true;
             }
         }
         pathVis[node] = 0;
         return false;
     }
    public:
     bool isCyclic(int N, vector<int> adj[]) {
         vector<int> vis(N,0);
         vector<int> pathVis(N,0);
         for(int i=0;i<N;i++)
         {
             if(!vis[i])
             {
                 return dfs(adj,vis,pathVis,i);
             }
         }
     }
 };
 