#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data ;
    Node* next;
    Node* prev;
    Node(int value)
    {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
    Node(int value,Node * next1,Node* prev1)
    {
        data = value;
        next = next1;
        prev = prev1;
    }
};

Node *deleteOccurances(Node *head, int key)
{
    Node * nextNode = head;
    Node * prevNode = nullptr;
    Node * temp = head;
    while (temp != nullptr)
    {
        if (temp->data == key)
        {
            if (temp == head)
            {
                head = head->next;
            }
            nextNode = temp->next;
            prevNode = temp->prev;
            if (nextNode)
            {
                nextNode->prev = prevNode;
            }
            if (prevNode)
            {
                prevNode->next = nextNode;
            }
            free(temp);
            temp = nextNode;
        }
        else
        {
            temp = temp->next;
        }
    }
    return head;
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
    Node* n1 = new Node(10);
    Node* n2 = new Node(20);
    Node* n3 = new Node(10);
    Node* n4 = new Node(40);
    Node* n5 = new Node(50);
    Node* n6 = new Node(60);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n2->prev = n1;
    n3->prev = n2;
    n4->prev = n3;
    n5->prev = n4;
    n6->prev = n5;
    printLList(n1);
    n1 = deleteOccurances(n1,10);
    printLList(n1);
    return 0;
}