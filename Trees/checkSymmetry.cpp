#include<bits/stdc++.h>
using namespace std ;

struct Node
{
    int data ;
    Node* left;
    Node* right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

bool checkSymmetry(Node* root1, Node* root2)
{
    if(root1 == NULL || root2 == NULL) return root1==root2;
    if(root1->data != root2->data)return false;
    return checkSymmetry(root1->left,root2->right) && checkSymmetry(root1->right,root2->left);
}
bool symmetry(Node* root)
{
    if(root == NULL)return true;
    return checkSymmetry(root->left,root->right);
}
int main()
{
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(2);
    root -> left -> left = new Node(3);
    root -> left -> right = new Node(4);
    root -> right -> left = new Node(4);
    root -> right -> right = new Node(3);
    cout<<symmetry(root);
    return 0;
}