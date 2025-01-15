#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};

int height(Node *root, int &maxd)
{
    if (root == NULL)
    {
        return 0;
    }
    int lh = height(root->left, maxd);
    int rh = height(root->right, maxd);
    maxd = max(lh + rh, maxd);
    return max(lh, rh) + 1;
}
int diameterOfBinaryTree(Node *root)
{
    int maxd = 0;
    height(root, maxd);
    return maxd;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    int height = diameterOfBinaryTree(root);
    cout<<"diameter = "<<height;
    return 0;
}