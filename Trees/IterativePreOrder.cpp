#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node * right ;
    Node * left;
    Node(int value)
    {
        right = left = nullptr;
        data = value ;
    }
};

vector<int> preOrder(Node *root)
{
    vector<int> preOrder;
    if (root == nullptr)
    {
        return preOrder;
    }
    stack<Node *> st;
    st.push(root);
    while (!st.empty())
    {
        root = st.top();
        st.pop();
        preOrder.push_back(root->data);
        if (root->right)
        {
            st.push(root->right);
        }
        if (root->left)
        {
            st.push(root->left);
        }
    }
    return preOrder;
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    vector<int> ans = preOrder(root);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}