#include<bits/stdc++.h>
using namespace std;

int fruitInBasket(vector<int> arr,int k)
{
    map<int,int> mp;
    int r=0,l=0;
    int maxL = 0;
    while(r < arr.size())
    {
        mp[arr[r]]++;
        while(k >mp.size())
        {
            mp[arr[l]]--;
            if(mp[arr[l]] == 0)
            {
                mp.erase(arr[l]);
            }
            l++;
        }
        maxL = max(maxL,(r-l+1));
        r++;
    }
    return maxL;
}
int main()
{
    vector<int> arr = {3,3,3,1,2,1,1,2,3,3,4};
    cout<<fruitInBasket(arr,2);
    return 0;
}