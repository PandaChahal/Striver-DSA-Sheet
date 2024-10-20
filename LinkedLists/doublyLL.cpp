#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data ;
    Node* next;
    Node* prev;

    Node(int value)
    {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
    Node(int value,Node* next1,Node* prev1)
    {
        data = value;
        next = next1;
        prev = prev1;
    }
};

void printDLL(Node* head)
{
    while(head != nullptr)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

Node* insertNode(int value,Node* head)
{
    Node* a = new Node(value);
    a->next = head;
    return a;
}
Node* deleteNode(Node* head)
{
    Node* a = head;      
    head = head->next;    
    head->prev = nullptr;   
    a->next = nullptr;  
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
    n2->prev = n1;
    n3->prev = n2;
    n4->prev = n3;
    printDLL(n1);
    //inserting a new node at head
    n1 = insertNode(50,n1);
    printDLL(n1);
    //deleting head node
    n1 = deleteNode(n1);
    printDLL(n1);
    return 0;
}