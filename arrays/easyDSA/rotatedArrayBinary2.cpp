#include<bits/stdc++.h>
using namespace std;
bool binarySearch(vector<int> arr,int k)
{
    int n = arr.size();
    int l =0;
    int r = n-1;
    while(l<=r)
    {
        int mid = (l+r)/2;
        if(arr[mid] == k)
        {
            return true;
        }
        else if(arr[l] == arr[mid] == arr[r])
        {
            l++;
            r--;
        }
        else
        {
            if(arr[l] <= arr[mid])
            {
                if(arr[l] <= k && k <= arr[mid])
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
                if(arr[mid] <= k && k <= arr[r])
                {
                    l = mid-1;
                }
                else
                {
                    r = mid+1;
                }
            }
        }
    }
    return false;
}
int main()
{
    vector <int> arr = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int k = 10;
    cout<<binarySearch(arr,k);
    return 0;
}