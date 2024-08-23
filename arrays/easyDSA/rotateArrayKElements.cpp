#include <iostream>
#include <vector>
using namespace std;
void rotateLeft(vector<int> arr, int k)
{
    int n = arr.size();
    for(int i =0;i<k;i++)
    {
        int temp = arr[0];
        for (int i = 0; i < n; i++)
        {
            arr[i] = arr[i + 1];
        }
        arr[n - 1] = temp;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 2;
    rotateLeft(arr, k);
    return 0;
}