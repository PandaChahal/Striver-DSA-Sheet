#include<bits/stdc++.h>
using namespace std;

int linearSearch(vector<int> arr ,int n)
{
    for(int i =0;i<arr.size();i++)
    {
        if(arr[i]==n)
        {
            return i;
            break;
        }
    }
    return -1;
}
int main()
{
    vector<int> arr ={1,2,3,4,5};
    int n = 4 ;//element to be searched in the array
    cout<<"index of the given element is "<< linearSearch(arr,n);
    return 0;
}