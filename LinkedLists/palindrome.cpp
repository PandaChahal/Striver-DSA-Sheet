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
Node* reverseLL(Node* head)
{
    if(head == nullptr || head->next == nullptr)
    {
        return head;
    }
    Node* newhead = reverseLL(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = nullptr;
    return newhead;
}

bool palindromeCheck(Node* head)
{
    if(head == nullptr || head->next == nullptr)
    {
        return head;
    }
    Node* slow = head;
    Node* fast = head;
    while(fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* newhead = reverseLL(slow->next);
    Node* first = head;
    Node* second = newhead;
    while(second != NULL)
    {
        if(first->data != second->data)
        {
            reverseLL(newhead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reverseLL(newhead);
    return true;
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
    Node* n1 = new Node(1);
    Node* n2 = new Node(5);
    Node* n3 = new Node(2);
    Node* n4 = new Node(5);
    Node* n5 = new Node(1);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    cout<<"linked list is ";
    printLList(n1);
    bool k = palindromeCheck(n1);
    if(k){
        cout<<"given LL is a palindrome";
    }
    else{
        cout<<"its not a palindrome ";
    }
    return 0;
}