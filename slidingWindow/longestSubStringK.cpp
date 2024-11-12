#include<bits/stdc++.h>
using namespace std;

int maxLength(string s , int k)
{
    int l=0,r=0,maxL=0,length=0;
    map<char,int> mp;
    while (r<s.length())
    {
        mp[s[r]]++;
        while(mp.size() > k)
        {
            mp[s[l]]--;
            if(mp[s[l]] == 0)
            {
                mp.erase(s[l]);
            }
            l++;
        }
        if(mp.size() <= k)
        {
            length = (r-l+1);
            maxL = max(maxL,length);
        }
        r++;
    }
    return maxL;
}
int main()
{
    string s = "aaabbccd";
    cout<<maxLength(s,2);
    return 0;
}