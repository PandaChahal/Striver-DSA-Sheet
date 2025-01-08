#include<bits/stdc++.h>
#include<queue>
using namespace std;

struct Node
{
    int data ;
    Node* left ;
    Node* right ;

    Node(int value)
    {
        data = value ;
        left = right = nullptr;
    }
};

void levelOrder(Node * root)
{
    vector<int> ans;
    if(root == nullptr)
    {
        return;
    }
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty())
    {
        Node* current = q.front();
        q.pop();
        ans.push_back(current->data);
        if(current->left != nullptr)
        {
            q.push(current->left);
        }
        if(current->right != nullptr)
        {
            q.push(current->right);
        }
    }
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}
int main()
{
    Node* root = new Node(1);
    root->right = new Node(3);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    levelOrder(root);
    return 0;
}