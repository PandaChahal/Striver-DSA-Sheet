#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> v) 
{ 
	int n = v.size();
	int e = v[0];
	int count =1;
	for (int i=1;i<n;i++)
	{
		if(v[i] == e)
		{
			count++;
		}
		else if (v[i]!=0)
		{
			count--;
		}
		if(count == 0)
		{
			e = v[i];
			count = 1;
		}
	}
	int cnt = 0;
    for (int i = 0; i < n; i++) 
	{
        if (v[i] == e) 
		{
			cnt++;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(cnt > (n/2))
		{
			return e;
		}
	}
	return -1;
}
int main()
{
    vector<int> v = {4,4,2,4,3,4,4,3,2,4};
    cout<<"majority element in the above given array is "<<majorityElement(v);
    return 0;
}