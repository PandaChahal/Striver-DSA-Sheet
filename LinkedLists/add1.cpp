#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data ;
    Node* next;
    Node(int value)
    {
        data = value;
        next = nullptr;
    }
    Node(int value,Node * next1)
    {
        data = value;
        next = next1;
    }
};

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

Node* sum(Node* head)
{
    Node * nhead = reverseRecursive(head);
    int carry = 1;
    Node* temp = nhead;
    while(temp != nullptr)
    {
        temp->data = temp->data + carry ;
        if(temp->data < 10)
        {
            carry = 0;
            break;
        }
        else
        {
            temp->data = 0;
            carry = 1;
        }
        temp = temp->next;
    }
    if(carry == 1 )
    {
        Node* newnode = new Node(1);
        temp->next = newnode;
        
        
    }
    Node* newhead = reverseRecursive(nhead);
    return newhead;
}
void printLList(Node* n) 
{
    while (n != nullptr) 
    {
        cout << n->data<<" ";
        n = n->next;
    }
    cout<<endl;
}

int main()
{
    Node* n1 = new Node(9);
    Node* n2 = new Node(5);
    Node* n3 = new Node(6);
    n1->next = n2;
    n2->next = n3;
    cout<<"original LL is ";
    printLList(n1);
    Node* s = sum(n1);
    cout<<"sum is ";
    printLList(s);
    return 0;
}