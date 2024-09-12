// #include<bits/stdc++.h>
// using namespace std;
// int maxLengthofSubArray(vector<int> arr)
// {
//     int maxlength = 0;
//     int length = 0;
//     int sum ;
//     int n = arr.size();
//     for(int i=0;i<n-1;i++)
//     {
//         sum = arr[i];
//         if(sum == 0)
//         {
//             return 1;
//         }
//         for(int j=i+1;j<n;j++)
//         {
//             sum += arr[j];
//             if(sum == 0)
//             {
//                 length = j+1;
//             }
//             maxlength = max(length,maxlength);
//         }
//     }
//     return maxlength;
// }
// int main()
// {
//     vector<int> arr ={1, 0, -5};
//     cout<<maxLengthofSubArray(arr);
//     return 0;
// }





#include <bits/stdc++.h>
using namespace std;

vector<int> generateRow(int row) {
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1); //inserting the 1st element

    //calculate the rest of the elements:
    for (int col = 1; col < row; col++) {
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}

vector<vector<int>> pascalTriangle(int n) {
    vector<vector<int>> ans;

    //store the entire pascal's triangle:
    for (int row = 1; row <= n; row++) {
        ans.push_back(generateRow(row));
    }
    return ans;
}

int main()
{
    int n = 5;
    vector<vector<int>> ans = pascalTriangle(n);
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "n";
    }
    return 0;
}
