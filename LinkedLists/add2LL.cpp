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
    Node(int value, Node *next1)
    {
        data = value;
        next = next1;
    }
};

Node *sum(Node *l1, Node *l2)
{
    Node *temp1 = l1;
    Node *temp2 = l2;
    Node *dummynode = new Node(-1);
    Node *current = dummynode;
    int carry = 0;
    while (temp1 != nullptr || temp2 != nullptr)
    {
        int sum = carry;
        if (temp1)
        {
            sum = sum + temp1->data;
        }
        if (temp2)
        {
            sum = sum + temp2->data;
        }
        Node *newnode = new Node(sum % 10);
        carry = sum / 10;
        current->next = newnode;
        current = current->next;
        if (temp1)
        {
            temp1 = temp1->next;
        }
        if (temp2)
        {
            temp2 = temp2->next;
        }
    }
    if (carry)
    {
        Node *newnode = new Node(carry);
        current->next = newnode;
    }
    return dummynode->next;
}
void printLList(Node *n)
{
    while (n != nullptr)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

int main()
{
    Node *l1 = new Node(2);
    Node *l11 = new Node(4);
    Node *l12 = new Node(3);
    l1->next = l11;
    l11->next = l12;
    Node *l2 = new Node(5);
    Node *l21 = new Node(6);
    Node *l22 = new Node(7);
    l2->next = l21;
    l21->next = l22;
    cout << "first LL is ";
    printLList(l1);
    cout << "second LL is ";
    printLList(l2);
    Node *s1 = sum(l1, l2);
    cout << "sum is ";
    printLList(s1);
    return 0;
}