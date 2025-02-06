#include<bits/stdc++.h>
using namespace std;

struct  Node
{
    int data;
    Node* left;
    Node * right;
    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};

void flatten(Node *root)
{
    if (root == nullptr)
        return;

    Node *cur = root;
    while (cur != nullptr)
    {
        if (cur->left != nullptr)
        {
            Node *prev = cur->left;

            // Find the rightmost node of left subtree
            while (prev->right != nullptr)
            {
                prev = prev->right;
            }

            // Connect rightmost node to current right subtree
            prev->right = cur->right;

            // Move left subtree to right
            cur->right = cur->left;
            cur->left = nullptr; // Ensure left is null
        }
        cur = cur->right; // Move to the next right node
    }
}

void inorder(Node * root)
{
    if(root == NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main()
{
    Node * root = new Node(1);
    root->left = new Node(2);
    root->left->left= new Node(3);
    root->left->right = new Node(4);
    root->right = new Node(5);
    root->right->right= new Node(6);
    root->right->right->left= new Node(7);
    flatten(root);
    inorder(root);
    return 0;
}