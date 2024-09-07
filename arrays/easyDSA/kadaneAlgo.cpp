#include<bits/stdc++.h>
using namespace std;
int kadaneSum(vector<int> arr)
{
    int n = arr.size();
    int sum = 0;
    int maxSum = INT_MIN;
    for(int i=0;i<n;i++)
    {
        sum += arr[i];
        maxSum = max(sum,maxSum);
        if(sum <0)
        {
            sum = 0;
        }
    }
    return maxSum;
}
int main()
{
    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
    cout<<kadaneSum(arr);
    return 0;
}