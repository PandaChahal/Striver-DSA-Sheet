#include<bits/stdc++.h>
using namespace std;
int profitMaximixer(vector<int> arr)
{
    int n = arr.size();
    int profit =0;
    int diff;
    for(int i=0;i<n-1;i++)
    {
        for(int j =i+1;j<n;j++)
        {
            if(arr[j] > arr[i])
            {
                diff = arr[j] - arr[i];
                profit = max(profit,diff);
            }
        }
    }
    return profit;
}
int main()
{
    vector<int> arr ={7,6,4,3,1};
    cout<<"max profit from selling the stocks is "<<profitMaximixer(arr);
    return 0;
}