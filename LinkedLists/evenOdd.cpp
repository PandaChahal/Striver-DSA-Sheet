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

Node* evenOdd(Node* head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }    
    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = even;
    while(even != nullptr && even->next != nullptr)
    {
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
        odd->next = evenHead;
    }
    
    return head;
}
int main()
{
    Node* n1 = new Node (1);
    Node* n2 = new Node (2);
    Node* n3 = new Node (3);
    Node* n4 = new Node (4);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    printLList(n1);
    n1 = evenOdd(n1);
    printLList(n1);
    return 0;
}