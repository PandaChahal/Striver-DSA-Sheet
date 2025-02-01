#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data ;
    Node* right;
    Node* left;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

void changeTree(Node* root)
{
    if(root == NULL) return;
    int child = 0;
    if(root->left) child += root->left->data;
    if(root->right) child += root->right->data;
    if(child >= root->data)
    {
        root->data = child;
    }
    else
    {
        if(root->left) 
        {
            root->left->data = root->data;
        }
        else if (root->right)
        {
            root->right->data = root->data;
        }
    }
    changeTree(root->left);
    changeTree(root->right);
    int tot = 0;
    if(root->left) tot+=root->left->data;
    if(root->right) tot += root->right->data;
    if(root->right or root->left) root->data = tot;
}

void inorder(Node* root)
{
    if(root == NULL) return ;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}
int main()
{
    Node* root = new Node(50);
    root->left = new Node(7);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->left = new Node(1);
    root->right->right = new Node(30);
    changeTree(root);
    inorder(root);
    return 0;
}