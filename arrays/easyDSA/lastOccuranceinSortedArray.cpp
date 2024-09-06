#include<bits/stdc++.h>
using namespace std;
int indexFinder(vector<int> arr,int k)
{
    int n = arr.size();
    int l =0;
    int r=n-1;
    int index = -1;
    while (l<=r)
    {
        int mid = (l+r)/2;
        if(arr[mid] == k)
        {
            index = mid;
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
    return index;
}
int main()
{
    vector<int> arr ={3,4,13,13,13,20,40};
    cout<<indexFinder(arr,13);
    return 0;
}