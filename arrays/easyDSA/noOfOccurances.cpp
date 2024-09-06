#include<bits/stdc++.h>
using namespace std;
int counter(vector<int> arr,int k)
{
    int n = arr.size();
    int l =0;
    int r=n-1;
    int lastIndex = -1;
    int firstIndex = -1;
    int count;
    while (l<=r)
    {
        int mid = (l+r)/2;
        if(arr[mid] == k)
        {
            lastIndex = mid;
            l = mid+1;
        }
        else if(arr[mid] > k)
        {
            r =mid-1;
        }
        else
        {
            l =mid+1;
        }
    }
    l = 0;
    r = n-1;
    while(l<=r)
    {
        int mid = (l+r)/2;
        if(arr[mid]==k)
        {
            firstIndex = mid;
            r = mid-1;
        }
        else if(arr[mid] < k)
        {
            l = mid+1;
        }
        else
        {
            r = mid-1;
        }
    }
    if (firstIndex == -1 || lastIndex == -1) 
    {
        return 0;
    }
    count = lastIndex - firstIndex +1;
    return count;
   
}
int main()
{
    vector<int> arr ={1, 1, 2, 2, 2, 2, 2, 3};
    cout<<counter(arr,2);
    return 0;
}