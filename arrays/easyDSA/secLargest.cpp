#include <iostream>
#include <vector>
using namespace std;
int secondLargest(vector<int> arr)
{
    int max = arr[0];
    int secondMax = 0;
    if (arr.size() == 1)
    {
        return -1;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > max)
        {
            secondMax = max;
            max = arr[i];
        }
        if (arr[i] > secondMax && arr[i] < max)
        {
            secondMax = arr[i];
        }
    }
    return secondMax;
}

int secondSmallest(vector<int> arr)
{
    int min = arr[0];
    int secondMin ;
    if (arr.size() == 1)
    {
        return -1;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < min)
        {
            secondMin = min;
            min = arr[i];
        }
        if (arr[i] < secondMin && arr[i] > min)
        {
            secondMin = arr[i];
        }
    }
    return secondMin;
}
int main()
{
    vector<int> arr = {1, 2, 4, 7, 7, 5};
    cout << secondLargest(arr) << " is the second largest element in the array "<<endl;
    cout << secondSmallest(arr) << " is the second smallest element in the array ";
    return 0;
}