#include<bits/stdc++.h>
#include<vector>
using namespace std;

//rearrange 012 array
vector<int> rearrange(vector<int> &arr)
{
    int n = arr.size();
    int a =0,b=0,c=0;
    for(int i =0;i<n;i++)
    {
        if(arr[i] == 0)
        {
            a++;
        }
        else if(arr[i] == 1)
        {
            b++;
        }
        else
        {
            c++;
        }
    }
    for(int i=0;i<a;i++)
    {
        arr[i] = 0;
    }
    for(int i=a;i<a+b;i++)
    {
        arr[i] = 1;
    }
    for(int i=a+b;i<a+b+c;i++)
    {
        arr[i] = 2;
    }
    return arr;
}
int main()
{
    vector<int> arr = {2,0,2,1,1,0};
    vector<int> final = rearrange(arr);
    for(int i=0;i<final.size();i++)
    {
        cout<<final[i]<<" ";
    }
    return 0;
}

//deleting a node
// class Node
// {
//     public:
//     int data ;
//     Node* next;

//     Node (int value)
//     {
//         data = value;
//         next = nullptr;
//     }

//     Node (int value, Node* next1)
//     {
//         data = value;
//         next = next1;
//     }
// };
// void printLL(Node* head)
// {
//     while (head != nullptr)
//     {
//         cout<<head->data<<" ";
//         head = head->next;
//     }
//     cout<<endl;
// }
// Node* deleteNode(Node* head)
// {
//     Node* a = head;
//     head = head->next;
//     delete a;
//     return head;
// }
// int main()
// {
//     Node* n1 = new Node(10);
//     Node* n2 = new Node(20);
//     Node* n3 = new Node(30);
//     Node* n4 = new Node(40);
//     n1->next = n2;
//     n2->next = n3;
//     n3->next = n4;
//     printLL(n1);
//     n1 = deleteNode(n1);
//     cout<<"after deletion : ";
//     printLL(n1);
//     return 0;
// }

//deleting duplicates
// int main()
// {
//     vector<int> arr = {1,1,1,2,2,3,3,3,3,4,4};
//     vector<int> result;
//     int i =0;
//     int n = arr.size();
//     int element = 0;
//     while(i<n)
//     {
//         if(arr[i] == element)
//         {
//             i++;
//         }
//         else
//         {
//             element = arr[i];
//             result.push_back(element);
//             i++;
//         }
//     }
//     for(int i =0;i<result.size();i++)
//     {
//         cout<<result[i]<<" ";
//     }
//     cout<<endl;
//     cout<<result.size()<<endl;
//     return 0;
// }