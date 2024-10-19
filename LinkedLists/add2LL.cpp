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
int sum(Node* l1,Node*l2)
{
    int a = l1->data;
    int b = l2->data;
    Node* current1 = l1->next;
    Node* current2 = l2->next;
    while(current1 != NULL)
    {
        a = a*10;
        a = a + current1->data;
        current1 = current1->next;
    }
    while(current2 != NULL)
    {
        b = b*10;
        b = b + current2->data;
        current2 = current2->next;
    }
    return (a+b);
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
    Node* l1 = new Node(2);
    Node* l11 = new Node(4);
    Node* l12 = new Node(3);
    l1->next = l11;
    l11->next = l12;
    Node* l2 = new Node(5);
    Node* l21 = new Node(6);
    Node* l22 = new Node(7);
    l2->next = l21;
    l21->next = l22;
    cout<<"first LL is ";
    printLList(l1);
    cout<<"second LL is ";
    printLList(l2);
    cout<<"sum is "<<sum(l1,l2);
    return 0;
}