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

Node *insertBST(Node *root, int key)
{
    if(root == NULL)return new Node(key);
    Node* current = root;
    while(true)
    {
        if(current->data <= key)
        {
            if(current->right != NULL) current = current->right;
            else
            {
                current->right = new Node(key);
                break;
            }
        }
        else
        {
            if(current->left != NULL) current = current->left;
            else{
                current->left = new Node(key);
                break;
            }
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

    cout<<"Before insertion ---- ";
    cout << "Binary Search Tree: " ;
    InOrder(root);
    cout << endl;

    int x = 20;
    Node *result = insertBST(root, x);

    cout<<"After insertion ---- ";
    cout << "Binary Search Tree: " ;
    InOrder(root);
    cout << endl;

    int y = 1;
    Node* entry = insertBST(root,y);
    cout<<"After another insertion ---- ";
    cout << "Binary Search Tree: " ;
    InOrder(root);
    cout << endl;

    return 0;
}
