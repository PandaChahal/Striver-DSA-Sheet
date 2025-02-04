#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data ;
    Node * left;
    Node * right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

int leftheight(Node * root)
{
    if(root == NULL)return 0;
    int h=0;
    while(root != NULL)
    {
        h++;
        root = root->left;
    }
    return h;
}

int rightheight(Node * root)
{
    if(root == NULL)return 0;
    int h=0;
    while(root != NULL)
    {
        h++;
        root = root->right;
    }
    return h;
}

int count(Node * root)
{
    if(root == NULL) return 0;
    int lh = leftheight(root);
    int rh = rightheight(root);
    if(lh == rh) return ((1<<lh)-1);
    else
    {
        return 1+count(root->left)+count(root->right);
    }
}
int main()
{
    Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    cout<<"Number of nodes in the given binary tree are : "<<count(root);
    return 0;
}