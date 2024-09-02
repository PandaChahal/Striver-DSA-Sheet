#include<bits/stdc++.h>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int> a) 
{
    vector<int> ans;
    int repeating;
    int n = a.size();
    vector<int> hash(n+1,0);
    for(int i=0;i<n;i++)
    {
        hash[a[i]]++;
    }
    for(int i=0;i<n+1;i++)
    {
        if(hash[i] > 1)
        {
            repeating = i;
            ans.push_back(repeating);
        }
    }
    int missing;
    int actualSum = (n*(n+1))/2;
    int seriesSum = 0;
    for(int i=0;i<n;i++)
    {
        seriesSum += a[i];
    }
    missing = actualSum - seriesSum + repeating;
    ans.push_back(missing);
    return ans;
}

int main()
{
    vector<int> arr = {3,1,2,5,4,6,7,5};
    vector<int> answer = findMissingRepeatingNumbers(arr);
    for(int i=0;i<answer.size();i++)
    {
        cout<<answer[i]<<" ";
    }
    return 0;
}