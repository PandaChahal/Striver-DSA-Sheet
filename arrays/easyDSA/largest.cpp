#include<iostream>
#include<vector>
using namespace std;

int largestElement(vector<int> arr)
{
    int max = arr[0];
    for(int i = 0;i<arr.size();i++)
    {
        if(max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}
int main()
{
    vector<int> arr = {8,10,5,7,9};
    cout<<largestElement(arr)<<" is the largest element in the array. "<<endl;
    vector<int> arr2 = {2,5,1,3,0};
    cout<<largestElement(arr2)<<" is the largest element in the array. "<<endl;
    return 0;
}