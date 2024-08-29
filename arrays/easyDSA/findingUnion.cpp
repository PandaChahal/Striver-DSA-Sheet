#include<bits/stdc++.h>
using namespace std;
vector<int> unionOfArray(vector<int>arr1,vector<int>arr2,int n,int m)
{
    int max1 = *max_element(arr1.begin(),arr1.end());
    int max2 = *max_element(arr2.begin(),arr2.end());
    int length = max(max1,max2);
    vector<int> hash(length+1,0);
    for(int i=0;i<n;i++)
    {
        hash[arr1[i]]++;
    }
    for(int i=0;i<m;i++)
    {
        hash[arr2[i]]++;
    }
    vector<int> arr;
    for(int i=0;i<hash.size();i++)
    {
        if(hash[i]>0)
        {
            arr.push_back(i);
        }
    }
    return arr;
}
int main()
{
    vector<int> arr1 = {1,2,3,4,5,6,7,8,9,10}; //n = size
    vector<int> arr2 = {2,3,4,4,5,11,12}; // m = size
    int n = arr1.size(),m = arr2.size();
    vector<int> arr = unionOfArray(arr1,arr2,n,m);
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}