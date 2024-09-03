#include<bits/stdc++.h>
using namespace std;
int maxLengthofSubArray(vector<int> arr)
{
    int maxlength = 0;
    int length = 0;
    int sum ;
    int n = arr.size();
    for(int i=0;i<n-1;i++)
    {
        sum = arr[i];
        if(sum == 0)
        {
            return 1;
        }
        for(int j=i+1;j<n;j++)
        {
            sum += arr[j];
            if(sum == 0)
            {
                length = j+1;
            }
            maxlength = max(length,maxlength);
        }
    }
    return maxlength;
}
int main()
{
    vector<int> arr ={1, 0, -5};
    cout<<maxLengthofSubArray(arr);
    return 0;
}