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
class Solution 
{
    public:
    Node* addTwoNumbers(Node* l1, Node* l2) 
    {
        Node* dummy = new Node(0); 
        Node* temp = dummy; 
        int carry = 0;
        while( (l1 != NULL || l2 != NULL) || carry) 
        {
            int sum = 0; 
            if(l1 != NULL)
            {
                sum += l1->data; 
                l1 = l1 -> next; 
            }
            
            if(l2 != NULL) 
            {
                sum += l2 ->data; 
                l2 = l2 ->next; 
            }
            sum += carry; 
            carry = sum / 10; 
            Node* node = new Node(sum % 10); 
            temp -> next = node; 
            temp = temp -> next; 
        }
        return dummy -> next; 
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
    Solution solution;
    Node* result = solution.addTwoNumbers(l1, l2);
    cout << "Resultant Linked List after adding: ";
    printLList(result);
    return 0;
}