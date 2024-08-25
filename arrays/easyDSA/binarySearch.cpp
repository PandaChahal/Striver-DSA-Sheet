#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> arr, int k)
{
    int n = arr.size();
    int l = 0;
    int r = n - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] == k)
        {
            return mid;
        }
        else if (arr[mid] < k)
        {   
            l = mid + 1;
        }
        else
        {
           r = mid - 1;
        }
    }
    return -1;
}
int main()
{
    vector<int> arr = {3, 4, 6, 7, 9, 12, 16, 17};
    int k = 6;
    cout << "index of element is " << binarySearch(arr, k);
    return 0;
}