#include <bits/stdc++.h>
using namespace std;
int check(vector<int> arr)
{
    int n = arr.size();
    int max = *max_element(arr.begin(),arr.end());
    int size = max + 1;
    vector<int> hash(size,0);
    for(int i =0;i<n;i++)
    {
        hash[arr[i]]++;
    }
    for(int i=0;i<size;i++)
    {
        if(hash[i]==1)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    vector<int> arr ={4,1,2,1,2};
    cout<<check(arr);
    return 0;
}