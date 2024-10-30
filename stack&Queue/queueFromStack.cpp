#include <bits/stdc++.h>
using namespace std;

class Queue 
{
  public:
  stack < int > input, output;

  Queue() 
  {

  }

  void push(int x) 
  {
    input.push(x);
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
    return (output.size() + input.size()); 
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