#include<bits/stdc++.h>
using namespace std;
int floor(vector<int> arr,int k)
{
    int n = arr.size();
    int l = 0;
    int r = n - 1;
    int index = n;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] <= k)
        {
            index = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return arr[index];
}
int ceil(vector<int> arr,int k)
{
    int n = arr.size();
    int l = 0;
    int r = n - 1;
    int index = n;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if(arr[mid] >= k)
        {
            index = mid;
            r = mid -1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return arr[index];
}
int main()
{
    vector<int> arr = {3,4,4,7,8,10};
    cout<<"floor element : "<<floor(arr,5)<<endl;;
    cout<<"ceil element : "<<ceil(arr,5);
    return 0;
}