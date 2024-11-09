#include<bits/stdc++.h>
#include<stack>
using namespace std;

// void postToInfix(string s)
// {
//     stack<string> st;
//     for(int i=0;i<s.length();i++)
//     {
//         char c = s[i];
//         if(c>='a' && c<='z' || c>='A' && c<='Z' || c>='0' && c<='9')
//         {
//             st.push(string(1,c));
//         }
//         else
//         {
//             string s1 = st.top();
//             st.pop();
//             string s2 = st.top();
//             st.pop();
//             string result = '('+s2+c+s1+')';
//             st.push(result);
//         }
//     }
//     cout<<st.top();
// }
// int main()
// {
//     string s = "AB+CD-*";
//     postToInfix(s);
//     return 0;
// }

// int consectiveOnes(vector<int> arr,int k)
// {
//     int r=0,l=0;
//     int maxlength;
//     int maxE = INT_MIN,z = 0;
//     while (r<arr.size())
//     {
//         if(arr[r] == 0)
//         {
//             z++;
//         }
//         if(z > k)
//         {
//             if(arr[l] == 0)
//             {
//                 z--;
//             }
//             l++;
//         }
//         if(z<=k)
//         {
//             maxlength = r-l+1;
//             maxE = max(maxE,maxlength);
//         }
//         r++;
//     }
//     return maxE;    
// }
// int main()
// {
//     vector<int> arr = {1, 0, 1, 1, 0, 0, 1, 0, 1, 1};
//     int k = 2;
//     cout<<consectiveOnes(arr,k);
//     return 0;
// }

int maxPointsFromCards(vector<int> arr,int k)
{
    int lsum =0, rsum = 0;
    int maxSum = INT_MIN;
    int l=0 , r = (arr.size()-1);
    while(l<k)
    {
        lsum += arr[l];
        maxSum = max(maxSum,lsum);
        l++;
    }
    while (l>=0)
    {
        lsum -= arr[l];
        rsum += arr[r];
        r--;
        l--;
        maxSum = max(maxSum,(lsum+rsum));
        
    }
    return maxSum;
}
int main()
{
    vector<int> arr = {100, 45, 7, 89, 23, 56, 38, 90, 14, 67};
    int k = 3;
    cout<<maxPointsFromCards(arr,k);
    return 0;
}