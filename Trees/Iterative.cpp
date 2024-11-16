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

vector<int> postOrder(Node* root) 
{
    vector<int> postorder;

    if(root == NULL){
        return postorder;
    }

    stack<Node*> st1, st2;
    st1.push(root);
    while(!st1.empty())
    {
        root = st1.top();
        st1.pop();
        st2.push(root);
        if(root->left != NULL){
            st1.push(root->left);
        }
        if(root->right != NULL){
            st1.push(root->right);
        }
    }

    while(!st2.empty())
    {
        postorder.push_back(st2.top()->data);
        st2.pop();
    }
    return postorder;
}


int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    vector<int> ans = preOrder(root);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    vector<int> ans2 = postOrder(root);
    for(int i=0;i<ans2.size();i++)
    {
        cout<<ans2[i]<<" ";
    }
    return 0;
}