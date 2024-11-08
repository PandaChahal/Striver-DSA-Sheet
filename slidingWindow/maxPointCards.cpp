#include<bits/stdc++.h>
using namespace std;
int maxSumFromCards(vector<int> arr,int k)
{
    int lsum =0,rsum =0;
    int maxSum = INT_MIN;
    int l ;
    int r = arr.size()-1;
    for(l=0;l<k;l++)
    {
        lsum += arr[l];
        maxSum = max(lsum,maxSum);
    }
    for(l=k-1;l>=0;l--)
    {
        lsum -= arr[l];
        rsum += arr[r];
        r--;
        maxSum = max(maxSum,lsum+rsum);
    }
    return maxSum;
}
int main()
{
    vector<int> arr = {1,2,3,4,5,6,1};
    int k = 3;
    cout<<maxSumFromCards(arr,3);
    return 0;
}