#include<bits/stdc++.h>
using namespace std;
int binaryGoal(vector<int> arr,int goal)
{
    int l =0 ,r =0;
    int count = 0,sum =0;
    while(r<arr.size())
    {
        sum += arr[r];
        while(sum > goal)
        {
            sum -= arr[l];
            l++;
        }
        count += (r-l+1);
        r++;
    }
    return count;
}
int main()
{
    vector<int> arr = {1,0,1,0,1};
    int goal2 = binaryGoal(arr,2);
    int goal1 = binaryGoal(arr,1);
    cout<<"number of subarrays is "<<goal2-goal1<<endl;
    return 0;
}