#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int value)
    {
        val = value;
        left = right = NULL;
    }
};

void markParents(Node *root, unordered_map<Node *, Node *> &parentTrack)
{
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();

        if (node->left)
        {
            parentTrack[node->left] = node;
            q.push(node->left);
        }
        if (node->right)
        {
            parentTrack[node->right] = node;
            q.push(node->right);
        }
    }
}
vector<int> distanceK(Node *root, Node *target, int k)
{
    unordered_map<Node *, Node *> parentTrack;
    markParents(root, parentTrack);
    unordered_map<Node *, bool> visited;
    queue<Node *> q;
    q.push(target);
    visited[target] = true;

    int currDist = 0;
    while (!q.empty())
    {
        int size = q.size();
        if (currDist == k)
            break;
        currDist++;

        for (int i = 0; i < size; i++)
        {
            Node *node = q.front();
            q.pop();

            if (node->left && !visited[node->left])
            {
                q.push(node->left);
                visited[node->left] = true;
            }

            if (node->right && !visited[node->right])
            {
                q.push(node->right);
                visited[node->right] = true;
            }
            if (parentTrack.count(node) && !visited[parentTrack[node]])
            {
                q.push(parentTrack[node]);
                visited[parentTrack[node]] = true;
            }
        }
    }

    vector<int> result;
    while (!q.empty())
    {
        result.push_back(q.front()->val);
        q.pop();
    }
    return result;
}

int main()
{
    Node *root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);
    root->right->left = new Node(0);
    root->right->right = new Node(8);

    Node *target = root->left;
    int k = 2;

    vector<int> result = distanceK(root, target, k);

    cout << "Nodes at distance " << k << " from target: ";
    for (int val : result)
    {
        cout << val << " ";
    }
    return 0;
}
