#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};

int height(Node* root)
{
    if (root == NULL) 
    {
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    return max(lh,rh)+1;
}

bool BalancedTree(Node* root)
{
    if(root==NULL)
    {
        return true;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    if(abs(lh-rh)<=1 && BalancedTree(root->left) && BalancedTree(root->right))
    {
        return true;
    }
    return false;
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);
    cout<<BalancedTree(root)<<endl;
    return 0;
}