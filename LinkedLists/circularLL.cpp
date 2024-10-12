#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

void printList(Node* last)
{
    if(last == NULL) 
    {
        return;
    }
    Node* head = last->next;
    while (true) 
    {
        cout << head->data << " ";
        head = head->next;
        if (head == last->next) 
        {
            break;
        }
    }
    cout << endl;
}
int main()
{
    Node* n0 = new Node(1);
    Node* n1 = new Node(2);
    Node* n2 = new Node(3);
    Node* n3 = new Node(4);
    Node* n4 = new Node(5);
    Node* n5 = new Node(6);
    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n0;
    printList(n5);
    return 0;
}