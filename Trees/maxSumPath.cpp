#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node * right;
    Node * left;

    Node(int value)
    {
        data = value;
        right = left = NULL;
    }
};

int MaxSum(Node* root , int &maxS)
{
    if(root == NULL) return 0;
    int lh = MaxSum(root->left, maxS);
    int rh = MaxSum(root->right, maxS);
    maxS = max(maxS,lh+rh+ root->data);
    return max(lh, rh) + root->data;
}

int maxPathSum(Node* root) 
{
    int maxS = INT_MIN; 
    MaxSum(root, maxS);
    return maxS; 
}

int main()
{
    Node * root = new Node(-10);
    root->left = new Node(8);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);
    cout<<"maximum sum = "<<maxPathSum(root);
    return 0;
}