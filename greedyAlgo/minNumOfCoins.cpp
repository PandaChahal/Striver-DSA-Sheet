#include<bits/stdc++.h>
using namespace std;

vector<int> minNumberOfCoins(vector<int> arr,int n)
{
    vector<int> coins;
    int size = arr.size();
    for(int i = size-1;i>=0;i--)
    {
        if(arr[i] <= n)
        {
            coins.push_back(arr[i]);
            n -= arr[i];
            if( n == 0)
            {
                return coins;
            }
        }
    }
    return coins;
}

int main()
{
    int n;
    vector<int> arr = {1,2,5,10,20,50,100,500,1000};
    cout<<"enter your amount : ";
    cin>>n;
    vector<int> ans = minNumberOfCoins(arr,n);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}