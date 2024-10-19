#include<bits/stdc++.h>
#include<vector>
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

Node* sortLL(Node* head)
{
    vector<int> arr;
    Node* n = head;
    while(n!= nullptr)
    {
        arr.push_back(n->data);
        n = n->next;
    }
    sort(arr.begin(),arr.end());
    int i =0;
    n = head;
    while (n != nullptr)
    {
        n->data = arr[i];
        n = n->next;
        i++;
    }
    return head;
}
int main()
{
    Node* n1 = new Node (5);
    Node* n2 = new Node (2);
    Node* n3 = new Node (8);
    Node* n4 = new Node (1);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    printLList(n1);
    n1 = sortLL(n1);
    printLList(n1);
    return 0;
}