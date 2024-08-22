#include <bits/stdc++.h>
using namespace std;

int maxLength(vector<int> arr, int k) 
{
    int n = arr.size(); 
    int l = 0, r = 0; 
    int sum = arr[0];
    int maxLen = 0;
    while (r < n) 
    {
        while (l <= r && sum > k) 
        {
            sum -= arr[l];
            l++;
        }
        if(sum == k) 
        {
            maxLen = max(maxLen, r-l+1);
        }
        r++;
        if (r < n) 
        {
            sum += arr[r];
        }
    }
    return maxLen;
}

int main()
{
    vector<int> arr = {2, 3, 5, 1, 9};
    int k = 10;
    cout << maxLength;
    return 0;
}

