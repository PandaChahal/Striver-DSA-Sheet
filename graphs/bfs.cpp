#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<int> bfs(vector<vector<int>> arr, int n)
{
    vector<int> ans;
    vector<int> vis(n + 1, 0);
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    while (!q.empty())
    {
        int node = q.front();
        ans.push_back(node);
        q.pop();
        for (auto it : arr[node])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> arr(6);
    arr[1] = {2, 5};
    arr[2] = {1, 3};
    arr[3] = {2, 4, 5};
    arr[4] = {3, 5};
    arr[5] = {1, 3, 4};
    vector<int> ans = bfs(arr, 5);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        int n = adj.size();
        queue<int> q;
        vector<int> vis(n+1,0);
        q.push(0);
        vis[0] = 1;
        vector<int> ans;
        while(!q.empty())
        {
            int node = q.front();
            ans.push_back(node);
            q.pop();
            for(auto it : adj[node])
            {
                if(!vis[it])
                {
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

// int main() {
//     int tc;
//     cin >> tc;
//     cin.ignore();
//     while (tc--) {
//         int V;
//         cin >> V;
//         cin.ignore();
//         // Use vector of vectors instead of array of vectors.
//         vector<vector<int>> adj(V);

//         for (int i = 0; i < V; i++) {
//             string input;
//             getline(cin, input);
//             int num;
//             vector<int> node;
//             stringstream ss(input);
//             while (ss >> num) {
//                 node.push_back(num);
//             }
//             adj[i] = node;
//         }

//         Solution obj;
//         vector<int> ans = obj.bfs(adj);
//         for (int i = 0; i < ans.size(); i++) {
//             cout << ans[i] << " ";
//         }
//         cout << endl;
//         cout << "~" << endl;
//     }
//     return 0;
// }

// } Driver Code Ends