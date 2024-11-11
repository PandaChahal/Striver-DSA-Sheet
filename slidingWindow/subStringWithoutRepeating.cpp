#include<bits/stdc++.h>
using namespace std;

int longestSubstring(string s)
{
    int l=0,r=0;
    int len , maxL = 0;
    vector<int> hash(256,-1);
    while(r < s.length())
    {
        if(hash[s[r]] != -1)
        {
            if(hash[s[r]] >= l)
            {
                l = hash[s[r]]+1;
            }
        }
        len = r-l+1;
        maxL = max(len,maxL);
        hash[s[r]] = r;
        r++;
    }
    return maxL;
}
int main()
{
    string s = "abcabcbb";
    cout<<longestSubstring(s);
    return 0;
}