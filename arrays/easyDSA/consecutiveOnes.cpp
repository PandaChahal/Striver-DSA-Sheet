#include<iostream>
#include<vector>
using namespace std;
int checkOnes(vector<int> arr)
{
    int n = arr.size();
    if(n == 1)
    {
        return arr[0];
    }
    int count = 0;
    int maxCount = 0;
    for(int i =0;i<n;i++)
    {
        if(arr[i]==1)
        {
            count++;
            maxCount = max(maxCount,count);
        }
        else
        {
            count =0;
        }
    }
    return maxCount;
}
int main()
{
    vector<int> arr ={0};
    cout<<checkOnes(arr);
    return 0;
}