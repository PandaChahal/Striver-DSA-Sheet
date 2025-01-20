// #include <bits/stdc++.h>
// using namespace std;

// struct Node
// {
//     int data;
//     Node *right;
//     Node *left;
//     Node(int value)
//     {
//         data = value;
//         left = right = NULL;
//     }
// };

// bool isleaf(Node *root)
// {
//     if (root->left == NULL && root->right == NULL)
//     {
//         return true;
//     }
//     return false;
// }

// void leftTraversal(Node *root, vector<int> &ans1)
// {
//     if (!isleaf)
//     {
//         ans1.push_back(root->data);
//     }
//     if (left)
//     {
//         leftTraversal(root->left, ans1);
//     }
//     if (right)
//     {
//         leftTraversal(root->right, ans1);
//     }
// }

// void boundaryTraversal(Node *root, vector<int> &ans2)
// {
//     if (isleaf)
//     {
//         ans2.push_back(root->data);
//     }
//     if (left)
//     {
//         boundaryTraversal(root->left, ans2);
//     }
//     if (right)
//     {
//         boundaryTraversal(root->right, ans2);
//     }
// }

// void rightTraversal(Node *root, vector<int> &ans3)
// {
//     vector<int> temp;
//     if (!isleaf)
//     {
//         temp.push_back(root->data);
//     }
//     if (left)
//     {
//         rightTraversal(root->left, temp);
//     }
//     if (right)
//     {
//         rightTraversal(root->right, temp);
//     }
//     for (int i = temp.size() - 1; i >= 0; --i)
//     {
//         ans3.push_back(temp[i]);
//     }
// }
// int main()
// {
//     Node *root = new Node(1);
//     root->left = new Node(2);
//     root->right = new Node(3);
//     root->left->left = new Node(4);
//     root->left->right = new Node(5);
//     root->right->left = new Node(6);
//     root->right->right = new Node(7);
//     vector<int> ans1, ans2, ans3;
//     leftTraversal(root, ans1);
//     boundaryTraversal(root, ans2);
//     rightTraversal(root->right, ans3);
//     for (int i = 0; i < ans1.size(); i++)
//     {
//         cout << ans1[i] << " ";
//     }
//     for (int i = ans1.size(); i < (ans1.size() + ans2.size()); i++)
//     {
//         cout << ans2[ans1.size() - i] << " ";
//     }
//     for (int i = (ans1.size() + ans2.size()); i < (ans1.size() + ans2.size() + ans3.size()); i++)
//     {
//         cout << ans3[(ans1.size() + ans2.size()) - i] << " ";
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};

bool isLeaf(Node *root)
{
    return (root->left == NULL && root->right == NULL);
}

void leftTraversal(Node *root, vector<int> &ans)
{
    Node *curr = root->left; 
    while (curr)
    {
        if (!isLeaf(curr))
        {
            ans.push_back(curr->data);
        }
        if (curr->left)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
}

void leafTraversal(Node *root, vector<int> &ans)
{
    if (root == NULL)
        return;

    if (isLeaf(root))
    {
        ans.push_back(root->data);
        return;
    }

    leafTraversal(root->left, ans);
    leafTraversal(root->right, ans);
}

void rightTraversal(Node *root, vector<int> &ans)
{
    Node *curr = root->right; 
    vector<int> temp;
    while (curr)
    {
        if (!isLeaf(curr))
        {
            temp.push_back(curr->data);
        }
        if (curr->right)
        {
            curr = curr->right;
        }
        else
        {
            curr = curr->left;
        }
    }
    reverse(temp.begin(), temp.end());
    ans.insert(ans.end(), temp.begin(), temp.end());
}

void boundaryTraversal(Node *root)
{
    if (root == NULL)
        return;

    vector<int> ans;

    if (!isLeaf(root))
    { 
        ans.push_back(root->data);
    }

    leftTraversal(root, ans);
    leafTraversal(root, ans);
    rightTraversal(root, ans);
    for (int val : ans)
    {
        cout << val << " ";
    }
    cout << endl;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    boundaryTraversal(root);

    return 0;
}
