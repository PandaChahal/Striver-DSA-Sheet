#include <iostream>
#include<vector>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};
vector<vector<int>>pairSum(Node* head,int k)
{
    Node* left = head;
    Node* right = head;
    vector<vector<int>>ans;
    while(right->next!=nullptr)
    {
        right=right->next;
    }
    while(left->data < right->data)
    {
        if((left->data+right->data)==k)
        {
            vector<int>temp;
            temp.push_back(left->data);
            temp.push_back(right->data);
            ans.push_back(temp);
            left=left->next;
            right=right->prev;
        }
        else if((left->data+right->data)<k)
        {
            left = left->next;
        }
        else
        {
            right= right->prev;
        }
    }
    return ans;
}
void printLL(Node* head)
{
    Node* current = head;
    while(current!=nullptr)
    {
        cout<<current->data<<" ";
        current=current->next;
    }
    cout<<endl;
}
int main()
{
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(9);

    n1->next = n2;
    n2->prev = n1;
    n2->next = n3;
    n3->prev = n2;
    n3->next = n4;
    n4->prev = n3;
    n4->next = n5;
    n5->prev = n4;

    vector<vector<int>>ans = pairSum(n1,5);

    for(int i=0;i<ans.size();i++)
    {
        cout<<"[";
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<"]";
    }
    return 0;
}