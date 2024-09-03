#include <bits/stdc++.h>
using namespace std;
int zeroes(vector<vector<int>> arr)
{
    int count = 0;
    int n = arr.size();
    int m = arr[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                count++;
            }
        }
    }
    return count;
}
vector<int> index(vector<vector<int>> arr)
{
    vector<int> index;
    int n = arr.size();
    int m = arr[0].size();
    int count = zeroes(arr);
    for (int k = 0; k < count; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] == 0)
                {
                    index.push_back(i);
                    index.push_back(j);
                }
                return index;
            }
        }
    }

}
int main()
{
    vector<vector<int>> arr = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int n = arr.size();
    int m = arr[0].size();
    cout << "initial matrix : " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    vector<int> idx = index(arr);
    int a = idx[0];
    int b = idx[1];
    for (int i = 0; i < n; i++)
    {
        arr[i][a] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        arr[b][i] = 0;
    }
    cout << "modified matrix : " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}