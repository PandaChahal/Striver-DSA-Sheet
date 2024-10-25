#include <bits/stdc++.h>
using namespace std;
vector<int> sort(vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    return arr;
}
vector<int> twoSum(vector<int> Arr, int k)
{
    int n = Arr.size();
    vector<int> answer;
    int i = 0;
    int j = n - 1;
    while (i != j)
    {
        if ((Arr[i] + Arr[j]) == k)
        {
            answer.push_back(i);
            answer.push_back(j);
            break;
        }
        else if ((Arr[i] + Arr[j]) < k)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return answer;
}
int main()
{
    vector<int> arr = {2, 6, 5, 8, 11};
    vector<int> sortedArr = sort(arr);
    int k = 14;
    vector<int> index = twoSum(sortedArr, k);
    for (int i = 0; i < index.size(); i++)
    {
        cout << index[i] << " ";
    }
    return 0;
}