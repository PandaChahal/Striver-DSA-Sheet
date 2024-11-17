#include <bits/stdc++.h>
using namespace std;

int KDistinct(vector<int> arr, int k)
{
    map<int, int> mp;
    int l = 0, r = 0, count = 0;
    while (r < arr.size())
    {
        mp[arr[r]]++;
        while (mp.size() > k)
        {
            mp[arr[l]]--;
            if (mp[arr[l]] == 0)
            {
                mp.erase(arr[l]);
            }
            l++;
        }
        if (mp.size() <= k)
        {
            count += (r - l + 1);
        }
        r++;
    }
    return count;
}
int main()
{
    vector<int> arr = {1, 2, 1, 2, 3};
    cout << (KDistinct(arr, 2) - KDistinct(arr, 1));
    return 0;
}