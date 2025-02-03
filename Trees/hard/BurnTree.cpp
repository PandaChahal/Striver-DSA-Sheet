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
    root->left->right->left ->right = new Node(9);
    return 0;
}