#include <iostream>
#include <queue>
using namespace std;
class Stack
{
    queue<int> q;

public:
    void push(int val)
    {
        int size = q.size();
        q.push(val);
        for (int i = 0; i < size; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }
    void pop()
    {
        q.pop();
    }
    int top()
    {
        return q.front();
    }
};
int main()
{
    Stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    cout << s1.top() << " ";
    s1.pop();
    cout << s1.top() << " ";
    s1.pop();
    cout << s1.top() << " ";
    s1.pop();
    cout << s1.top() << " ";
    s1.pop();
    return 0;
}