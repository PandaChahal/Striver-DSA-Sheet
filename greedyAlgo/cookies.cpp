#include<bits/stdc++.h>
using namespace std;
int cookieDistributer(vector<int> g,vector<int> s)
{
    int count=0,l=0,r=0;
    sort(g.begin(),g.end());
    sort(s.begin(),s.end());
    while( l < g.size() && r < s.size())
    {
        if( g[l] <= s[r])
        {
            count++;
            l++;
        }
        r++;
    }
    return count;
}
int main()
{
    vector<int> g = {1, 5, 3, 3, 4};
    vector<int> s = {4, 2, 1, 2, 1, 3};
    cout<<cookieDistributer(g,s);
    return 0;
}