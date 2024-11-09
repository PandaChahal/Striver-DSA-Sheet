#include<bits/stdc++.h>
using namespace std;
int squareRoot(int n)
{
    int l = 1;
    int r = n;
    while(l<=r)
    {
        int mid = (l+r)/2;
        int sq = mid*mid;
        if (sq <= n)
        {
            l = mid+1;
        }
        else
        {
            r = mid-1;
        }
    }
    return r;
}
int main()
{
    int n = 5;
    cout<<squareRoot(n);
    return 0;
}