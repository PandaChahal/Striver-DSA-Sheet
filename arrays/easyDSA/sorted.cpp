#include<iostream>
#include<vector>
using namespace std;
int checkSorted(vector<int> arr)
{
    int n = arr.size();
    for(int i =0;i<n;i++)
    {
        if(arr[i+1]<arr[i])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    vector<int> arr ={1, 2, 3, 4, 5,3,2,1};
    cout<<checkSorted(arr);
    return 0;
}