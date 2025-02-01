#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data ;
    Node * right;
    Node * left;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

int getMaxW(Node * root)
{
    if(root == NULL) return 0;
    int ans;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    while(!q.empty())
    {
        int size = q.size();
        int min = q.front().second;
        int f,l;
        for(int i=0;i<size;i++)
        {
            int cur_id = q.front().second - min;
            Node* dummy = q.front().first;
            q.pop();
            if(i==0) f = cur_id;
            if(i==size-1) l = cur_id;
            if(dummy -> left)
            {
                q.push({dummy->left,cur_id*2+1});
            }
            if(dummy->right)
            {
                q.push({dummy->right,cur_id*2+2});
            }
            ans = max(ans,l-f+1);
        }
    }
    return ans;
}
int main()
{
    Node * root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->left->left = new Node(4);
    root->right = new Node(5);
    root->right->right = new Node(6);
    root->right->right->right = new Node(7);
    cout<<getMaxW(root);
    return 0;
}