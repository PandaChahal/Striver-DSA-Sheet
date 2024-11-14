#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node * right ;
    Node * left;
    Node(int value)
    {
        right = left = nullptr;
        data = value ;
    }
};

void preOrder(Node* root)
{
    if(root == nullptr)
    {
        return ;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
int main()
{
    Node * root = new Node(4);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->left->right = new Node(9);
    root->left->left->right->left = new Node(1);
    root->right = new Node(5);
    root->right->left = new Node(7);
    root->right->right = new Node(6);
    root->right->right->left = new Node(8);
    preOrder(root);
    return 0;
}