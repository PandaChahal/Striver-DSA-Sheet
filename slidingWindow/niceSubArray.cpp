#include<bits/stdc++.h>
using namespace std;

int niceSubArray(vector<int> arr,int k)
{
    int n = arr.size();
    int l=0,r=0,sum=0,count=0;
    while(r < n)
    {
        sum += (arr[r]%2);
        while(sum > k)
        {
            sum -= (arr[l]%2);
            l++;
        }
        count += (r-l+1);
        r++;
    }
    return count;
}
int main()
{
    vector <int> arr = {1,1,2,1,1};
    int g2 = niceSubArray(arr,3);
    int g1 = niceSubArray(arr,2);
    cout<<"number of subArrays is "<<(g2-g1);
    return 0;
}