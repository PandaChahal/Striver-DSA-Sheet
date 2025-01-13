#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data ;
    Node* right;
    Node* left;
    Node(int value)
    {
        data = value;
        right = left = NULL;
    }
};

int heightOfBinaryTree(Node *root)
{
    if(root==NULL)return 0;
    int lh = heightOfBinaryTree(root->left);
    int rh = heightOfBinaryTree(root->right);
    return 1+max(lh,rh);
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    int height = heightOfBinaryTree(root);
    cout<<"height = "<<height;
    return 0;
}