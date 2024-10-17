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

bool detectCycle(Node* head)
{
    Node* h = head;
    Node* r = head;
    while(r != nullptr && r->next != nullptr)
    {
        h = h->next->next;
        r = r->next;
        if(h == r)
        {
            return true;
        }
    }
    return false;
}

Node* startingPoint(Node* head)
{
    Node* h = head;
    Node* r = head;
    while(r != nullptr && r->next != nullptr)
    {
        h = h->next->next;
        r = r->next;
        if(h == r)
        {
            h = head;
            while(h!=r)
            {
                h = h->next;
                r = r->next;
            }
            return h;
        }
    }
    return NULL;
}

int findLength(Node* slow, Node* fast)
{
    int count = 1;
    fast = fast->next;
    while(slow!=fast)
    {
        count++;
        fast = fast->next;
    }
    return count;
}
int lengthofcycle(Node* head)
{
    Node* h = head;
    Node* r = head;
    while(r != nullptr && r->next != nullptr)
    {
        h = h->next->next;
        r = r->next;
        if(h == r)
        {
            return findLength(h,r);
        }
    }
    return 0;
}

void printLList(Node* n) 
{
    while (n != nullptr) 
    {
        cout << n->data<<" ";
        n = n->next;
    }
}
int main()
{
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n3;
    bool k = detectCycle(n1);
    if(k)
    {
        cout<<"cycle detected"<<endl;
    }
    else
    {
        cout<<"no cycle detected"<<endl;
    }
    Node* h = startingPoint(n1);
    cout<<"starting Node is "<<h->data<<endl;
    cout<<lengthofcycle(n1)<<endl;
    return 0;
}