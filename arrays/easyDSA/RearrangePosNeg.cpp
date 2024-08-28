#include <bits/stdc++.h>
using namespace std;
vector<int> rearrange(vector<int> &arr)
{
    int n = arr.size();
    vector<int> arr1;
    vector<int> arr2;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
        {
            arr1.push_back(arr[i]);
        }
        else
        {
            arr2.push_back(arr[i]);
        }
    }
    int i = 0;
    int j = 0, k = 0;
    while (i < n)
    {

        arr[i] = arr1[j];
        i++;
        j++;
        arr[i] = arr2[k];
        i++;
        k++;
    }
    return arr;
}
int main()
{
    vector<int> arr = {1, 2, -4, -5};
    vector<int> finalArray = rearrange(arr);
    for (int i = 0; i < finalArray.size(); i++)
    {
        cout << finalArray[i] << " ";
    }
    return 0;
}