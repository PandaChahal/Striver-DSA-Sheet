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

int minimum(Node* root)
{
    if(root == NULL)
    {
        cout<<"ERROR , your tree is empty , there exists no min value ."<<endl;
        return -1;
    }
    Node* current = root;
    while(current->left != NULL)
    {
        current = current->left;
    }
    return current->data;
}

int maximum(Node* root)
{
    if(root == NULL)
    {
        cout<<"ERROR , your tree is empty , there exists no max value ."<<endl;
        return -1;
    }
    Node* current = root;
    while(current->right != NULL)
    {
        current = current->right;
    }
    return current->data;
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
    cout<<"maximum number out of all entries in the given BST is "<<maximum(root)<<endl;
    cout<<"minimum number out of all entries in the given BST is "<<minimum(root)<<endl;
    return 0;
}
