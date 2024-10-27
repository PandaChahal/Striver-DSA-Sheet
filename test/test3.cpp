#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node * next;
    Node (int value)
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
void printLL(Node* head)
{
    Node * n = head;
    while(n != nullptr)
    {
        cout<<n->data<<" ";
        n = n->next;
    }
    cout<<endl;
}

//add 1 to a LL
Node* reverse(Node* head)
{
    if(head == nullptr || head->next == nullptr)
    {
        return head;
    }
    Node* newhead = reverse(head->next);
    Node * front = head->next;
    front->next = head;
    head->next = nullptr;
    return newhead;
}
Node* sum1(Node* head)
{
    Node * n1 = reverse(head);
    int carry = 1;
    Node * temp = n1;
    while(temp != nullptr)
    {
        temp->data += carry;
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
    if(carry)
    {
        Node * newNode = new Node(1);
        temp->next = newNode;
    }
    Node * newHead = reverse(n1);
    return newHead;
}
int main()
{
    Node * n1 = new Node(5);
    n1->next = new Node(4);
    n1->next->next = new Node(9);
    cout<<"original LL is ";
    printLL(n1);
    n1 = sum1(n1);
    cout<<"now the LL is ";
    printLL(n1);
    return 0;
}