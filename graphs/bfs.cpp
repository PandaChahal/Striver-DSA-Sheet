#include <bits/stdc++.h>
#include<vector>
using namespace std;
vector<int>bfs(vector<vector<int>> arr,int n)
{
    vector<int>ans;
    vector<int>vis(n+1,0);
    queue<int>q;
    q.push(1);
    vis[1]=1;
    while(!q.empty()){
        int node = q.front();
        ans.push_back(node);
        q.pop();
        for(auto it: arr[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
                
            }
        }
    }
    return ans;
}
int main() {
    vector<vector<int>> arr(6);
    arr[1] = {2,5};
    arr[2] = {1,3};
    arr[3] = {2,4,5};
    arr[4] = {3,5};
    arr[5] = {1,3,4};
    vector<int>ans = bfs(arr,5);
    
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}