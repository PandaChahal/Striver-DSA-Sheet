#include <bits/stdc++.h>
using namespace std;

class Queue 
{
  public:
  int n;
  stack < int > input, output;

  Queue() 
  {
    n=0;
  }

  void push(int x) 
  {
    input.push(x);
    n++;
  }

  int pop()
  {    
    if (output.empty())
    {
      while (input.size())
      {
        output.push(input.top()), input.pop();
      }
    }    
    int x = output.top();
    output.pop();
    n--;
    return x;
  }

  int top() {
    if (output.empty())
    {
      while (input.size())
      {
        output.push(input.top()), input.pop();
      }
    }
    return output.top();
  }

  int size() {
    return (n); 
  }

};
int main() {
  Queue q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  q.push(5);
  cout << "The top of the queue is " << q.top() << endl;
  q.pop();
  cout<<"now the top element is "<<q.top()<<endl;
  cout << "The size of the queue is " << q.size() << endl;
}