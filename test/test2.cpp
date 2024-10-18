#include<bits/stdc++.h>
#include<vector>
using namespace std;

//union of two arrays
vector <int> unionArr(vector<int> arr1,vector<int> arr2) 
{
    int n = arr1.size();
    int m = arr2.size();
    int i = 0;
    int j = 0;
    vector<int> ans;
    while (i < n && j < m)
    {
        if (arr1[i] <= arr2[j]) 
        {
            if (ans.size() == 0 || ans.back() != arr1[i])
            {
                ans.push_back(arr1[i]);
            }
            i++;
        }
        else 
        {
            if (ans.size() == 0 || ans.back() != arr2[j])
            {
                ans.push_back(arr2[j]);
            }
            j++;
        }
    }
    while (i < n) 
    {
        if (ans.back() != arr1[i])
        {
            ans.push_back(arr1[i]);
        }
        i++;
    }
    while (j < m) 
    {
        if (ans.back() != arr2[j])
        {
            ans.push_back(arr2[j]);
        }
        j++;
    }
    return ans;
}

int main()
{
    vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> arr2 = {2, 3, 4, 4, 5, 11, 12};
    vector<int> Union = unionArr(arr1, arr2);
    cout << "Union : " << endl;
    for (int i=0;i<Union.size();i++)
    {
        cout<<Union[i]<<" ";
    }
    return 0;
}
