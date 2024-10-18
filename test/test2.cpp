#include<bits/stdc++.h>
#include<vector>
using namespace std;

//union of two arrays

// vector <int> unionArr(vector<int> arr1,vector<int> arr2) 
// {
//     int n = arr1.size();
//     int m = arr2.size();
//     int i = 0;
//     int j = 0;
//     vector<int> ans;
//     while (i < n && j < m)
//     {
//         if (arr1[i] <= arr2[j]) 
//         {
//             if (ans.size() == 0 || ans.back() != arr1[i])
//             {
//                 ans.push_back(arr1[i]);
//             }
//             i++;
//         }
//         else 
//         {
//             if (ans.size() == 0 || ans.back() != arr2[j])
//             {
//                 ans.push_back(arr2[j]);
//             }
//             j++;
//         }
//     }
//     while (i < n) 
//     {
//         if (ans.back() != arr1[i])
//         {
//             ans.push_back(arr1[i]);
//         }
//         i++;
//     }
//     while (j < m) 
//     {
//         if (ans.back() != arr2[j])
//         {
//             ans.push_back(arr2[j]);
//         }
//         j++;
//     }
//     return ans;
// }

// int main()
// {
//     vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     vector<int> arr2 = {2, 3, 4, 4, 5, 11, 12};
//     vector<int> Union = unionArr(arr1, arr2);
//     cout << "Union : " << endl;
//     for (int i=0;i<Union.size();i++)
//     {
//         cout<<Union[i]<<" ";
//     }
//     return 0;
// }

//kadane algo
// int maxSumofArray(vector<int> arr)
// {
//     int n = arr.size();
//     int sum = 0;
//     int maxSum = INT_MIN;
//     if(n == 1)
//     {
//         return arr[0];
//     }
//     for(int i=0;i<n;i++)
//     {
//         sum += arr[i];
//         maxSum = max(sum , maxSum);
//         if(sum < 0)
//         {
//             sum = 0 ;
//         }
//     }
//     return maxSum;
// }
// int main()
// {
//     vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
//     cout<<"max sum out of the given array is "<<maxSumofArray(arr);
//     return 0;
// }

//reverse a LL - recursive

// class Node
// {
//     public:
//     int data;
//     Node* next;

//     Node(int value)
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

// Node* reverseRecursive(Node* n)
// {
//     if(n == nullptr || n->next == nullptr)
//     {
//         return n;
//     }
//     Node* newhead = reverseRecursive(n->next);
//     Node* front = n->next;
//     front->next = n;
//     n->next = nullptr;
//     return newhead;
// }
// void printLList(Node* n) 
// {
//     while (n != nullptr) 
//     {
//         cout << n->data<<" ";
//         n = n->next;
//     }
//     cout<<endl;
// }
// int main()
// {
//     Node* n1 = new Node(1);
//     Node* n2 = new Node(2);
//     Node* n3 = new Node(3);
//     Node* n4 = new Node(4);
//     Node* n5 = new Node(5);
//     n1->next = n2;
//     n2->next = n3;
//     n3->next = n4;
//     n4->next = n5;
//     printLList(n1);
//     n1 = reverseRecursive(n1);
//     printLList(n1);
//     return 0;
// }

//reverse DLL
class Node
{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int value)
    {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
    Node(int value,Node* next1,Node* prev1)
    {
        data = value;
        next = next1;
        prev = prev1;
    }
};

void printDLL(Node* head)
{
    while(head != nullptr)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

Node* reverseDLL(Node* head)
{
    Node* current = head;
    Node* temp = NULL;
    while(current != nullptr)
    {
        temp = current -> prev;
        current -> prev = current -> next;
        current-> next = temp;
        current = current->prev;
    }
    return temp->prev;
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
    n2->prev = n1;
    n3->prev = n2;
    n4->prev = n3;
    printDLL(n1);
    n1 = reverseDLL(n1);
    printDLL(n1);
    return 0;
}