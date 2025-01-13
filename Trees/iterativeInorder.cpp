#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data ;
    Node* right;
    Node* left;

    Node(int value)
    {
        right = left = NULL;
        data = value;
    }
};

vector<int> getInOrderTraversal(Node *root)
{
    vector<int >ans;
    if(root==NULL)return ans;
    stack<Node*>st;
    Node* dummy = root;
    while(true){
        if(dummy!=NULL){
            st.push(dummy);
            dummy=dummy->left;
        }
        else{
            if(st.empty())
            {
                break;
            }
            else
            {
                dummy = st.top();
                ans.push_back(dummy->data);
                st.pop();
                dummy=dummy->right;
            }

        }
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
    vector<int> arr = getInOrderTraversal(root);
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}