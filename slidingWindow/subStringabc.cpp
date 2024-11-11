#include<bits/stdc++.h>
using namespace std;

int substringabc(string s)
{
    vector<int> hash(3, -1);
    int count = 0; 

    for (int i = 0; i < s.length(); i++)
    {
        hash[s[i] - 'a'] = i;

        if (hash[0] != -1 && hash[1] != -1 && hash[2] != -1)
        {
            count = count + min({hash[0], hash[1], hash[2]}) + 1;
        }
    }
    return count;
}

int main()
{
    string s = "abcabc";
    cout << substringabc(s);
    return 0;
}
