#include<bits/stdc++.h>
using namespace std;
// class Node
// {
//     public:
//     int data;
//     Node * next;
//     Node (int value)
//     {
//         data = value;
//         next = nullptr;
//     }
//     Node(int value,Node* next1)
//     {
//         data = value;
//         next = next1;
//     }
// };

class Node
{
    public:
    int data ;
    Node * next;
    Node * prev;
    Node (int value)
    {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
    Node (int value,Node * next1,Node* prev1)
    {
        data = value;
        next = next1;
        prev = prev1;
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

// int main()
// {
//     Node * n1 = new Node(5);
//     n1->next = new Node(4);
//     n1->next->next = new Node(9);
//     cout<<"original LL is ";
//     printLL(n1);
//     n1 = sum1(n1);
//     cout<<"now the LL is ";
//     printLL(n1);
//     return 0;
// }

// add 2 numbers using LL
Node * sum2(Node * n1,Node * n2)
{
    Node* temp1 = reverse(n1);
    Node * temp2 = reverse(n2);
    Node * dummy = new Node(-1);
    Node * current = dummy;
    int carry = 0;
    while(temp1 != nullptr || temp2 != nullptr)
    {
        int sum = carry;
        if(temp1)
        {
            sum += temp1->data;
        }
        if(temp2)
        {
            sum += temp2->data;
        }
        Node * newNode = new Node(sum%10);
        carry = sum/10;
        current->next = newNode;
        current = current->next;
        if(temp1)
        {
            temp1 = temp1->next;
        } 
        if(temp2)
        {
            temp2 = temp2->next;
        }
    }
    if(carry)
    {
        Node * newNode = new Node(carry);
        current->next = newNode;
    }
    Node * finalHead = reverse(dummy->next);
    return finalHead;
}
// int main()
// {
//     Node * n1 = new Node(2);
//     n1->next = new Node(4);
//     n1->next->next = new Node(2);
//     Node * n2 = new Node(5);
//     n2->next = new Node(6);
//     n2->next->next = new Node(8);
//     cout<<"LL1 is ";
//     printLL(n1);
//     cout<<"LL2 is ";
//     printLL(n2);
//     n1 = sum2(n1,n2);
//     cout<<"their sum is ";
//     printLL(n1);
//     return 0;
// }

//sort 0,1,2
// Node * sort(Node * head)
// {
//     if(head == NULL || head->next == NULL)
//     {
//         return head;
//     }
//     Node * temp = head;
//     Node * zeroHead = new Node(-1);
//     Node * oneHead = new Node(-1);
//     Node * twoHead = new Node(-1);
//     Node * zero = zeroHead;
//     Node * one = oneHead;
//     Node * two = twoHead;
//     while(temp != NULL)
//     {
//         if(temp->data == 0)
//         {
//             zero->next = temp;
//             zero = temp;
//         }
//         else if(temp->data == 1)
//         {
//             one->next = temp;
//             one = temp;
//         }
//         else
//         {
//             two->next = temp;
//             two = temp;
//         }
//         temp = temp->next;
//     }
//     zero->next = (oneHead->next) ? oneHead->next : twoHead->next;
//     one->next = twoHead->next;
//     two->next = NULL;
//     Node * newHead = zeroHead->next;
//     return newHead;
// }

// int main()
// {
//     Node* n1 = new Node (0);
//     Node* n2 = new Node (2);
//     Node* n3 = new Node (1);
//     Node* n4 = new Node (2);
//     Node* n5 = new Node (1);
//     Node* n6 = new Node (0);
//     n1->next = n2;
//     n2->next = n3;
//     n3->next = n4;
//     n4->next = n5;
//     n5->next = n6;
//     cout<<"original LL is ";
//     printLL(n1);
//     n1 = sort(n1);
//     cout<<"now the LL is ";
//     printLL(n1);
//     return 0;
// }

Node* deleteKeys(Node* head,int key)
{
    Node * nextNode = head;
    Node * prevNode = nullptr;
    Node * temp = head;
    while(temp != nullptr)
    {
        if(temp->data == key)
        {
            if(temp == head)
            {
                head = head->next;
            }
            nextNode = temp->next;
            prevNode = temp->prev;
            if(nextNode)
            {
                nextNode->prev = prevNode;
            }
            if(prevNode)
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
int main()
{
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(1);
    Node* n5 = new Node(1);
    Node* n6 = new Node(4);
    Node* n7 = new Node(10);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n2->prev = n1;
    n3->prev = n2;
    n4->prev = n3;
    n5->prev = n4;
    n6->prev = n5;
    n7->prev = n6;
    cout<<"original LL is ";
    printLL(n1);
    n1 = deleteKeys(n1,1);
    cout<<"now the LL is ";
    printLL(n1);
    return 0;
}