#include<bits/stdc++.h>
using namespace std;
vector<int> moveZeros(vector<int> arr) 
{
    vector<int> final;
    int n = arr.size();
    for(int i =0;i<n;i++)
    {
        if(arr[i]>0)
        {
            final.push_back(arr[i]);
        }
    }
    for(int i =0;i<n;i++)
    {
        arr[i] = 0;
    }
    for(int i=0;i<final.size();i++)
    {
        arr[i] = final[i] ;
    }
    return arr;
}
int main()
{
    vector<int> arr = {0,2,4,0,1};
    int n = arr.size();
    vector<int> final = moveZeros(arr);
    for(int i=0;i<n;i++)
    {
        cout<<final[i]<<" ";
    }
    return 0;
}