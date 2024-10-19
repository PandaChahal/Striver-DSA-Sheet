#include<bits/stdc++.h>
#include<vector>
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
    Node(int value,Node* next1)
    {
        data = value;
        next = next1;
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

Node* sortLL(Node* head)
{
    if(head == NULL || head->next ==NULL)
    {
        return head;
    }
    Node* temp = head;
    Node * zeroHead = new Node(-1);
    Node * oneHead = new Node(-1);
    Node * twoHead = new Node(-1);
    Node * zero = zeroHead;
    Node * one = oneHead;
    Node * two = twoHead;
    while(temp != NULL)
    {
        if(temp->data == 0)
        {
            zero->next = temp;
            zero = temp;
        }
        else if(temp->data == 1)
        {
            one->next = temp;
            one = temp;
        }
        else
        {
            two->next = temp;
            two = temp;
        }
        temp = temp->next;
    }
    zero->next = (oneHead->next) ? oneHead->next : twoHead->next;
    one->next = twoHead->next;
    two->next = NULL;
    Node* newhead = zeroHead->next;
    return newhead;
}
int main()
{
    Node* n1 = new Node (0);
    Node* n2 = new Node (1);
    Node* n3 = new Node (0);
    Node* n4 = new Node (2);
    Node* n5 = new Node (1);
    Node* n6 = new Node (2);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    printLList(n1);
    n1 = sortLL(n1);
    printLList(n1);
    return 0;
}