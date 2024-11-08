#include<bits/stdc++.h>
using namespace std;

int consecutiveones(vector<int> arr,int k)
{
    int l = 0, r =0;
    int maxL ;
    int maxE = INT_MIN;
    int zeros = 0;
    while(r<arr.size())
    {
        if(arr[r] == 0)
        {
            zeros++;
        }
        if(zeros > k)
        {
            if(arr[l] == 0)
            {
                zeros--;
            }
            l++;
        }
        if(zeros <= k)
        {
            maxL = r-l+1;
            maxE = max(maxL,maxE);
        }
        r++;
    }
    return maxE;
}
int main()
{
    vector<int> arr = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    cout<<consecutiveones(arr,k);
    return 0;
}