#include <bits/stdc++.h>
using namespace std;

//brute force
/*vector<vector<int>> triplet( vector<int> &arr,int target)
{
    int n = arr.size();
    vector<vector<int>> ans;
    for(int i = 0; i <= n-3; i++)
    {
        for(int j = i+1; j <= n-2; j++)
        {
            for(int k = j+1; k <=n-1; k++)
            {
                for(int l = k+1;l<n;l++)

                {
                    if((arr[i] + arr[j] + arr[k]+arr[l]) == target)
                {
                    vector<int> temp;
                    temp.push_back(arr[i]);
                    temp.push_back(arr[j]);
                    temp.push_back(arr[k]);
                    temp.push_back(arr[l]);
                    ans.push_back(temp);
                }}
            }
        }
    }
    return ans;
}*/

//optimal 
vector<vector<int>> Quad(vector<int>& arr, int target)
{
    int n = arr.size(); 
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) 
    {
        if (i > 0 && arr[i] == arr[i - 1]) 
        {
            continue;
        }
        for (int j = i + 1; j < n; j++) 
        {
            if (j > i + 1 && arr[j] == arr[j - 1]) 
            {
                continue;
            }
            int k = j + 1;
            int l = n - 1;
            while (k < l) 
            {
                int sum = arr[i] + arr[j]+arr[k]+arr[l];
                if(sum > target)
                {
                    l--;
                }
                else if(sum < target)
                {
                    k++;
                }
                else
                {
                    vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                    ans.push_back(temp);
                    k++; l--;
                    while (k < l && arr[k] == arr[k - 1]) k++;
                    while (k < l && arr[l] == arr[l + 1]) l--;
                }
            }
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = { 4,3,3,4,4,2,1,2,1,1};
    int target = 9;
    int n = arr.size();
    vector<vector<int>> ans = Quad( arr,target);
    for (int i =0;i<ans.size();i++) 
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

