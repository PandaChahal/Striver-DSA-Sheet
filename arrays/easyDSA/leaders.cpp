//print all the leaders in array -means print all the numbers which are greater than all the elements in the right - i/p [3,4 5,2, 3,1,0] O/p - 5 and 3 because they are greater than number on their right side 
#include<iostream>
#include<vector>
using namespace std;

void leaderFinder(vector<int> arr)
{
    int i =0;
    int n = arr.size();
    int j = n-1;
    int element;
    while(i != j)
    {
        if(arr[j]>arr[i])
        {
            i++;
            element = arr[j];
            cout<<element<<" ";
            i = i+2;
            j = n-1;
        }  
        else
        {
            j--;
        }     
    }
    
}
int main()
{
    vector<int> arr = {3,4,5,2,3,1,0};
    leaderFinder(arr);
    return 0;
}