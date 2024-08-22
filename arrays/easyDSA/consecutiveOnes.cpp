#include<iostream>
#include<vector>
using namespace std;
int checkOnes(vector<int> arr)
{
    int n = arr.size();
    int count = 0;
    int maxCount = 0;
    for(int i =0;i<n;i++)
    {
        if(arr[i]==1)
        {
            count++;
        }
        else
        {
            count =0;
        }
    }
    maxCount = max(maxCount,count);
    return maxCount;
}
int main()
{
    vector<int> arr ={1,1,0,1,1,1,1};
    cout<<checkOnes(arr);
    return 0;
}