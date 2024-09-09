
#include <bits/stdc++.h>
using namespace std;

int maxArraySum(int arr[], int n) 
{
    int maxi = LONG_MIN;
    int sum = 0;

    int start = 0;
    int ansStart = -1;
    int ansEnd = -1;
    for (int i = 0; i < n; i++) 
    {
        if (sum == 0) start = i;
        sum += arr[i];
        if (sum > maxi) 
        {
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }
        if (sum < 0) 
        {
            sum = 0;
        }
    }
    cout << "The subarray : ";
    for (int i = ansStart; i <= ansEnd; i++) 
    {
        cout << arr[i] << " ";
    }
    cout<<endl;
    return maxi;
}

int main()
{
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    long long maxSum = maxArraySum(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}

