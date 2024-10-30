#include <bits/stdc++.h>
using namespace std;
class stack1
{
    int n;
    queue<int> q1;
    queue<int> q2;

public:
    stack1()
    {
        n = 0;
    }
    void push(int val)
    {
        q2.push(val);
        n++;
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }
    void pop()
    {
        q1.pop();
        n--;
    }
    int top()
    {
        return q1.front();
    }
    int size()
    {
        return n;
    }
};
int main()
{
    stack1 q3;
    q3.push(1);
    q3.push(2);
    q3.push(3);
    q3.push(4);
    cout << q3.top() << endl;
    q3.pop();
    cout << q3.top() << endl;
    q3.pop();
    cout << q3.top() << endl;
    q3.pop();
    cout << q3.top() << endl;
    q3.pop();
    cout << "size is " <<q3.size() << endl;
    return 0;
}