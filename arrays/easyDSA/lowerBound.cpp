#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> arr, int k)
{
    int n = arr.size();
    int l = 0;
    int r = n - 1;
    int index = n;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] >= k)
        {
            index = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return index;
}

int main()
{
    vector<int> arr = {3, 5, 8, 15, 19};
    int x = 9;
    int ind = binarySearch(arr, x);
    cout <<"index : "<<ind;
    return 0;
}