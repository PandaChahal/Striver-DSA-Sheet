#include<bits/stdc++.h>
using namespace std;

class Node{
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
}
/*
int main()
{
    Node* y = new Node(10);
    Node* x = new Node(20,y);
    cout<<y<<endl;
    cout<<y->data<<endl;
    cout<<x<<endl;
    cout<<x->data <<endl;
    return 0;
}
*/
Node* insertNode(int value , Node* head)
{
    Node* current = new Node(value,head);
    return current;
}

int nodeCounter(Node* head)
{
    Node* a = head;
    int count = 0;
    while(a != nullptr)
    {
        a = a->next;
        count++;
    }
    return count;
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
    cout<<endl;
    //inserting a node
    n1 = insertNode(25,n1);
    printLList(n1);
    cout<<endl;
    //counting number of nodes
    cout<<"number of nodes are "<<nodeCounter(n1);
    return 0;
}
