#include <bits/stdc++.h>
using namespace std;

int maxLength(vector<int> arr, int k) 
{
    int n = arr.size(); 
    
    int maxLen = 0;
    for(int i=0;i<n;i++)
    {
        int sum = arr[i];
        if(arr[i] == k)
        {
            return 1;
        }
        for(int j = i+1 ; j<n;j++)
        {
            sum += arr[j];
            if(sum == k)
            {
                maxLen = max(maxLen,j-i+1);
            }
        }
    }
    return maxLen;
}

int main()
{
    vector<int> arr = { 1, 2, 1, 0, 1};
    int k = 4;
    cout << maxLength(arr,k);
    return 0;
}

