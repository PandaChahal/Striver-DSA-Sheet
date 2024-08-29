#include<bits/stdc++.h>
using namespace std;
int length(vector<int> &arr)
{
    int n = arr.size();
    int i =0;
    for(int j=i+1;j<n;j++)
    {
        if(arr[i]!=arr[j])
        {
            i++;
            arr[i] = arr[j];
        }
    }
    return (i+1);
}
int main()
{
    vector<int> arr = {1,1,2,2,3};
    cout<<length(arr);
    return 0;
}