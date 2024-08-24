#include <bits/stdc++.h>
using namespace std;
int count(vector<int> arr,int k)
{
    int n = arr.size();
    int count =0;
    for(int i =0;i<n;i++)
    {
        int sum = arr[i];
        if(sum == k)
        {
            count++;
        }
        for(int j=i+1;j<n;j++)
        {
            sum += arr[j];
            if(sum == k)
            {
                count++;
            }
        }
    }
    return count;
}
int main()
{
    vector<int> arr = {3, 1, 2, 4};
    int k = 3;
    cout<<count(arr,k);
    return 0;
}