#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data ;
    Node* right;
    Node* left;
    Node(int value)
    {
        data = value;
        left = right = nullptr;
    }
};

vector<int> getPostOrderTraversal(Node* root)
{
    vector<int> ans;
    if(root == NULL) return ans;
    stack<Node*> st1,st2;
    st1.push(root);
    while(!st1.empty())
    {
        Node* dummy = st1.top() ;
        st1.pop();
        st2.push(dummy);
        if(dummy->left)
        {
            st1.push(dummy->left);
        }
        if(dummy->right)
        {
            st1.push(dummy->right);
        }
    }
    while(!st2.empty())
    {
        ans.push_back(st2.top()->data);
        st2.pop();
    }
    return ans;
}
int main()
{
    Node * root = new Node(1);
    root->right = new Node(3);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    vector<int> arr = getPostOrderTraversal(root);
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}