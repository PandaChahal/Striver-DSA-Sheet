#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data ;
    Node * left;
    Node * right;
    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};

int main()
{
    Node * root = new Node(1);
    return 0;
}