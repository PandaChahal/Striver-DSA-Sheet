#include <bits/stdc++.h>
using namespace std;

// brute force
/*vector<vector<int>> triplet( vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> ans;
    for(int i = 0; i <= n-2; i++)
    {
        for(int j = i+1; j <= n-1; j++)
        {
            for(int k = j+1; k < n; k++)
            {
                if((arr[i] + arr[j] + arr[k]) == 0)
                {
                    vector<int> temp;
                    temp.push_back(arr[i]);
                    temp.push_back(arr[j]);
                    temp.push_back(arr[k]);
                    ans.push_back(temp);
                }
            }
        }
    }
    return ans;
}*/

// optimal
vector<vector<int>> triplet(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        int j = i + 1;
        int k = n - 1;
        if (i != 0 && arr[i] == arr[i - 1])
        {
            continue;
        }
        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < 0)
            {
                j++;
            }
            else if (sum > 0)
            {
                k--;
            }
            else
            {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                while (j < k && arr[j] == arr[j - 1])
                    j++;
                while (j < k && arr[k] == arr[k + 1])
                    k--;
            }
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    int n = arr.size();
    vector<vector<int>> ans = triplet(arr);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
