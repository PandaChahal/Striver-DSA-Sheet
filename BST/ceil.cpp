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

int ceil(Node *root, int key)
{
    int ceil = -1;
    while (root != NULL)
    {
        if (root->data == key)
        {
            ceil = root->data;
            return ceil;
        }
        if (key > root->data)
        {
            root = root->right;
        }
        else
        {
            ceil = root->data;
            root = root->left;
        }
    }
    return ceil;
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

    cout << "Binary Search Tree: ";
    InOrder(root);
    cout << endl;

    int x;
    cout << "enter your value :";
    cin >> x;
    cout << "your ceil value for given BST is : " << ceil(root, x);
    return 0;
}
