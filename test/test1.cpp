#include<bits/stdc++.h>
using namespace std;
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