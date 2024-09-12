#include <bits/stdc++.h>
using namespace std;
int numofRotattions(vector<int> arr) 
{
    int n = arr.size();
    int l = 0;
    int r = n - 1;
    int ans = INT_MAX;
    int rotations;
    while (l <= r) 
    {
        int mid = (l + r) / 2;
        if (arr[l] <= arr[r]) 
        {
            ans = min(ans, arr[l]);
            rotations = l;
            break;
        }
        if (arr[l] <= arr[mid]) 
        {
            ans = min(ans, arr[l]);
            rotations = l;
            l = mid + 1;
        }
        else 
        { 
            ans = min(ans, arr[mid]);
            rotations = mid;
            r = mid - 1;
        }
    }
    return rotations;
}

int main()
{
    vector<int> arr = {4, 5, 6, 7,8, -1,0,1, 2, 3};
    cout <<"number of rotations are "<<numofRotattions(arr);
    return 0;
}