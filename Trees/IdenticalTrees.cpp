#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data ;
    Node* left;
    Node* right;
    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};

bool IdenticalTree(Node* p,Node* q)
{
    if(p==NULL && q== NULL) return true;
    if(p== NULL || q == NULL) return false;
    if(p->data == q->data && IdenticalTree(q->left,q->left) && IdenticalTree(p->right,q->right))return true ;
    return false;
}
int main()
{
    Node * r1 = new Node(1);
    r1->left = new Node(2);
    r1->right = new Node(4);
    Node * r2 = new Node(1);
    r2->left = new Node(2);
    r2->right = new Node(3);
    cout<<IdenticalTree(r1,r2);
    return 0;
}