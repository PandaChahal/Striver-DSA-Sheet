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
Node* reverseIterative(Node* head)
{
    Node* current = head;
    Node* prev = nullptr;
    Node* next = nullptr;
    while (current != nullptr) 
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
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
int main()
{
    Node* n1 = new Node(10);
    Node* n2 = new Node(20);
    Node* n3 = new Node(30);
    Node* n4 = new Node(40);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    printLList(n1);
    //iterative reverse
    //n1 = reverseIterative(n1);
    //printLList(n1);
    //recursive reverse
    n1 = reverseRecursive(n1);
    printLList(n1);
    return 0;
}