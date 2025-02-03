#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data ;
    Node * left;
    Node * right;
    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};

void markParent(Node* root , unordered_map<Node*,Node*> parentTracker)
{
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node * node = q.front();
        q.pop();
        if(node->left) 
        {
            parentTracker[node->left] = node;
            q.push(node->left);
        }
        if(node->right) 
        {
            parentTracker[node->right] = node;
            q.push(node->right);
        }
    }
}

int timeToBurn(Node* root,Node* target)
{
    queue<Node*> q;
    unordered_map<Node*,Node*> parentTracker;
    markParent(root,parentTracker);
    unordered_map<Node*,bool> visited;
    q.push(target);
    visited[target] = 1;
    int count = 0;
    while(!q.empty())
    {
        for(int i=0;i<q.size();i++)
        {
            Node * node = q.front();
            q.pop();
            if(node->left && !visited[node->left])
            {
                q.push(node->left);
                visited[node->left] = 1;
            }
            if(node->right && !visited[node->right])
            {
                q.push(node->right);
                visited[node->right] = 1;
            }
            if(parentTracker[node] && !visited[parentTracker[node]])
            {
                q.push(parentTracker[node]);
                visited[parentTracker[node]];
            }
            count++;
        }
        

    }
    return count;
}
int main()
{
    Node *root = new Node(1);
    root->right = new Node(3);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);
    Node* target = root->left->right->left ->right;
    target = new Node(9);
    cout<<timeToBurn(root,target);
    return 0;
}