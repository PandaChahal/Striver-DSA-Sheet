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

Node* middleNodeDeletion(Node* head)
{
    Node* slow = head;
    Node* fast = head;
    Node* temp;
    while(fast != NULL && fast->next != NULL)
    {
        temp = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    temp ->next = temp->next->next;
    delete slow;
    return head;
}
int main()
{
    Node* n1 = new Node (1);
    Node* n2 = new Node (2);
    Node* n3 = new Node (3);
    Node* n4 = new Node (4);
    Node* n5 = new Node (5);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    cout<<"original LL : " ;
    printLList(n1);
    n1 = middleNodeDeletion(n1);
    cout<<"after deletion LL : ";
    printLList(n1);
    return 0;
}