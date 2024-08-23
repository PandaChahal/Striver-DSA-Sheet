#include<bits/stdc++.h>
using namespace std;
int Profit(vector<int> arr)
{
    int n = arr.size();
    int maxProfit = 0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]>arr[i])
            {
                int diff = arr[j]-arr[i];
                maxProfit = max(maxProfit,diff);
            }
        }
    }
    return maxProfit;
}
int main()
{
    vector<int> arr ={7,1,5,3,6,4};
    cout<<Profit(arr);
    return 0;
}