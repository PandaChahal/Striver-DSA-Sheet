#include<bits/stdc++.h>
using namespace std;
vector<int> sorted(vector<int> arr,int n)
{
    vector<int> newArray(n,0);
    //count for 0,count for 1 ,count for 2  
    int a = 0 ,b = 0,c = 0;
    
    for(int i =0;i<n;i++)
    {
        if(arr[i]==0)
        {
            a++;
        }
        else if(arr[i]==1)
        {
            b++;
        }
        else if(arr[i]==2)
        {
            c++;
        }
        else 
        {
            return arr;
        }
    }//a,b,c = 2
    for(int i = 0;i<a;i++)
    {
        newArray[i] = 0;
    }
    for(int i = a;i<a+b;i++)
    {
        newArray[i] = 1;
    }
    for(int i = a+b;i<n;i++)
    {
        newArray[i] = 2;
    }
    return newArray;
}
int main()
{
    vector<int> arr = {2,0,2,1,1,0};
    int n = arr.size();
    vector<int> array = sorted(arr,n);
    for(int i =0;i<array.size();i++)
    {
        cout<<array[i]<<" ";
    }
    return 0;
}