#include <bits/stdc++.h>
using namespace std;
int secondLargest(vector<int> &arr, int n)
{
    int max = INT_MIN;
    int second = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            second = max;
            max = arr[i];
        }
        else if (arr[i] > second && max > arr[i])
        {
            second = arr[i];
        }
    }
    return second;
}
int main()
{
    vector<int> arr = {4, 3, 1, 2, 6};
    cout << secondLargest(arr, 5);
}