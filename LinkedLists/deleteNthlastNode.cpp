#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data ;
    Node* next;

    Node(int value , Node* next1)
    {
        data = value;
        next = next1;
    }
    
    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

void printLList(Node* n) 
{
    while (n != nullptr) 
    {
        cout << n->data<<" ";
        n = n->next;
    }
    cout<<endl;
}

Node* reverseRecursive(Node* head)
{
    if(head == nullptr || head->next == nullptr)
    {
        return head;
    }
    Node* newhead = reverseRecursive(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = nullptr;
    return newhead;
}
Node* deleteNode(Node* head, int n)
{   
    int count = n;
    Node *a = head;
    Node * b;
    while(count != 1)
    {
        b = a;
        a = a->next;
        count--;
    }
    b->next = b->next->next;
    delete a;
    return head;
}
int main()
{
    Node* n1 = new Node(10);
    Node* n2 = new Node(20);
    Node* n3 = new Node(30);
    Node* n4 = new Node(40);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    int x ;
    cout<<"enter the node to be deleted : " ;
    cin>>x;
    cout<<"original LL :";
    printLList(n1);
    n1 = reverseRecursive(n1);
    n1 = deleteNode(n1,x);
    n1 = reverseRecursive(n1);
    cout<<"modified LL :";
    printLList(n1);
    return 0;
}