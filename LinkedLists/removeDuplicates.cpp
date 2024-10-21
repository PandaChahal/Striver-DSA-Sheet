#include <iostream>
#include<vector>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int val)
    {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};
Node* removeDuplicates(Node* head) 
{
    Node* temp = head;
    while(temp!=nullptr && temp->next !=nullptr)
    {
        Node* nextnode = temp->next;
        while(nextnode!=nullptr && nextnode->data == temp->data)
        {
            Node* duplicate = nextnode;
            nextnode=nextnode->next;
            free(duplicate);
        }
        temp->next = nextnode;
        if(nextnode)
        {
            nextnode->prev =temp;
        }
        temp = temp->next;
    }
    return head;
}

void printLL(Node* head)
{
    Node* current = head;
    while(current!=nullptr)
    {
        cout<<current->data<<" ";
        current=current->next;
    }
    cout<<endl;
}

int main()
{
    Node* n1 = new Node(1);
    Node* n2 = new Node(1);
    Node* n3 = new Node(1);
    Node* n4 = new Node(2);
    Node* n5 = new Node(3);
    Node* n6 = new Node(3);
    Node* n7 = new Node(4);

    n1->next = n2;
    n2->prev = n1;
    n2->next = n3;
    n3->prev = n2;
    n3->next = n4;
    n4->prev = n3;
    n4->next = n5;
    n5->prev = n4;
    n5->next = n6;
    n6->prev = n5;
    n6->next = n7;
    n7->prev = n6;
    printLL(n1);
    Node* head = removeDuplicates(n1);
    printLL(head);
    return 0;
}