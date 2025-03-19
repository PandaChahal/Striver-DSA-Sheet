#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *right;
    Node *left;
    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};

Node *searchBST(Node *root, int key)
{
    while (root != NULL && root->data != key)
    {
        if (root->data < key)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return root;
}

void InOrder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

int main()
{
    Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(10);

    cout << "Binary Search Tree: " ;
    InOrder(root);
    cout << endl;

    int x = 6;
    Node *result = searchBST(root, x);

    return 0;
}
