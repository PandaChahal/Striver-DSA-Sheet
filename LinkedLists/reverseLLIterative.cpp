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
Node* reverse(Node* head)
{
    Node* current = head->next;
    Node* temp = head;
    Node* prev = nullptr;
    while(current != nullptr)
    {
        temp -> next = prev;
        prev = temp;
        temp = current;
        current = current->next;
    }
    return temp;
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
    n1 = reverse(n1);
    printLList(n1);
    return 0;
}