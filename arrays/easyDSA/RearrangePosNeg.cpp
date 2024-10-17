#include <bits/stdc++.h>
using namespace std;
/*vector<int> modifier(vector<int> arr)
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
}*/
vector<int> modifier(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ans(n,0);
    int pos = 0;
    int neg = 1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<0)
        {
            ans[neg] = arr[i];
            neg += 2;
        }
        else
        {
            ans[pos] = arr[i];
            pos += 2;
        }
    }
    return ans;
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