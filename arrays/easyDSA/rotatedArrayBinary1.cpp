#include<bits/stdc++.h>
using namespace std;
int search(vector<int>& arr, int n, int k)
{
    int l = 0;
    int r = n-1;
    while(l<=r)
    {
        int mid = (l+r)/2;
        if(arr[mid] == k)
        {
            return mid;
        }
        if(arr[l] <= arr[mid])
        {
            if(arr[l] <= k && k<=arr[mid])
            {
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        else
        {
            if(arr[mid] <= k &&  k<=arr[r])
            {
                l = mid+1;
            }
            else
            {
                r = mid-1;
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {4,5,6,7,0,1,2,3};
    cout<<search(arr,arr.size(),2);
    return 0;
}