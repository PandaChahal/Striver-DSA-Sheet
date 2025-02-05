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