#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        right = left = NULL;
        data = val;
    }
};

vector<vector<int>> allInOne(Node *root)
{
    stack<pair<Node *, int>> st;
    st.push({root, 1});
    vector<int> pre, in, post;
    if (root == NULL)
        return {};

    while (!st.empty())
    {
        auto i = st.top();
        st.pop();

        // Preorder
        if (i.second == 1)
        {
            pre.push_back(i.first->data);
            i.second++;
            st.push(i);

            if (i.first->left != NULL)
            {
                st.push({i.first->left, 1});
            }
        }
        // Inorder
        else if (i.second == 2)
        {
            in.push_back(i.first->data);
            i.second++;
            st.push(i);

            if (i.first->right != NULL)
            {
                st.push({i.first->right, 1});
            }
        }
        // Postorder
        else
        {
            post.push_back(i.first->data);
        }
    }

    return {pre, in, post};
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<vector<int>> result = allInOne(root);
    cout << "Preorder: ";
    for (int val : result[0])
        cout << val << " ";
    cout << endl;

    cout << "Inorder: ";
    for (int val : result[1])
        cout << val << " ";
    cout << endl;

    cout << "Postorder: ";
    for (int val : result[2])
        cout << val << " ";
    cout << endl;

    return 0;
}
