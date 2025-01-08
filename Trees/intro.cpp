#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *right;
    Node *left;
    Node(int value)
    {
        right = left = nullptr;
        data = value;
    }
};

void preOrder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->left->right = new Node(4);
    root->left->left->right->left = new Node(8);
    root->right = new Node(5);
    root->right->left = new Node(9);
    root->right->right = new Node(6);
    root->right->right->left = new Node(7);
    cout<<"preOrder : ";
    preOrder(root);
    cout << endl;
    cout<<"postOrder : ";
    postOrder(root);
    cout << endl;
    cout<<"inOrder : ";
    inOrder(root);
    cout << endl;
    return 0;
}