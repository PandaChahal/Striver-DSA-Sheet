#include <bits/stdc++.h>
using namespace std;
int MinElementFinder(vector<int> arr) 
{
    int n = arr.size();
    int l = 0;
    int r = n - 1;
    int ans = INT_MAX;
    while (l <= r) 
    {
        int mid = (l + r) / 2;
        if (arr[l] <= arr[r]) 
        {
            ans = min(ans, arr[l]);
            break;
        }
        if (arr[l] <= arr[mid]) 
        {
            ans = min(ans, arr[l]);
            l = mid + 1;
        }
        else 
        { 
            ans = min(ans, arr[mid]);
            r = mid - 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    cout << MinElementFinder(arr);
    return 0;
}

