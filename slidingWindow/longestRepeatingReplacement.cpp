#include <bits/stdc++.h>
using namespace std;

int maxLength(string s, int k)
{
    vector<int> hash(26, 0);
    int r = 0, l = 0;
    int maxF = 0, maxl = 0;
    while (r < s.length())
    {
        hash[s[r] - 'a']++;
        maxF = max(maxF, hash[s[r] - 'a']);
        while (((r - l + 1) - maxF) > k)
        {
            hash[s[l]]--;
            maxF = 0;
        }
        if (((r - l + 1) - maxF) <= k)
        {
            maxl = max(maxl, (r - l + 1));
        }
        r++;
    }
    return maxl;
}
int main()
{
    string s = "abab";
    cout << maxLength(s, 2);
    return 0;
}