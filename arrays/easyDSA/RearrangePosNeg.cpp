#include <bits/stdc++.h>
using namespace std;
vector<int> modifier(vector<int> arr)
{
    int n = arr.size();
    vector<int> pos;
    vector<int> neg;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
        {
            pos.push_back(arr[i]);
        }
        else
        {
            neg.push_back(arr[i]);
        }
    }
    int k = 0;
    int i = 0;
    int j = 0;
    while (k < n)
    {
        if (i < pos.size())
        {
            arr[k] = pos[i];
            k++;
            i++;
        }
        if (j < neg.size())
        {
            arr[k] = neg[j];
            k++;
            j++;
        }
    }
    return arr;
}
int main()
{
    vector<int> arr = {1, 2, -4, -5};
    vector<int> finalArray = modifier(arr);
    for (int i = 0; i < finalArray.size(); i++)
    {
        cout << finalArray[i] << " ";
    }
    return 0;
}