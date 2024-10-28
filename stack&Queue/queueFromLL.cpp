#include <iostream>
using namespace std;

class StackNode
{
public:
    int data;
    StackNode *next;

    StackNode(int val)
    {
        data = val;
        next = nullptr;
    }
};
class Stack
{
    StackNode *top;
    int size;

    public:
    Stack()
    {
        top = nullptr;
        size = 0;
    }
    void push(int val)
    {
        StackNode *ele = new StackNode(val);
        ele->next = top;
        top = ele;
        cout << "Element added" << endl;
        size++;
    }
    void pop()
    {
        if (top == nullptr)
        {
            cout << "The stack is empty" << endl;
        }
        StackNode *temp = top;
        top = top->next;
        delete temp;
        size--;
    }
    int Top()
    {
        int topData = top->data;
        return topData;
    }
    int StackSize()
    {
        return size;
    }
};

int main()
{
    Stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    cout << s1.Top() << " ";
    s1.pop();
    cout << s1.Top() << " ";
    s1.pop();
    cout << s1.Top() << " ";
    s1.pop();
    cout << s1.StackSize() << " ";
    s1.pop();
    cout << s1.StackSize() << " ";
    return 0;
}