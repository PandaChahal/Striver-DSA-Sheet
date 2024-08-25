#include<bits/stdc++.h>
using namespace std;
int majorityElement(vector<int> v) 
{ 
	int n = v.size();
	int max = *max_element(v.begin(),v.end());
	vector<int> hash(max+1,0);
	for(int i =0;i<n;i++)
	{
		hash[v[i]]++;
	} 
	for(int i =0;i<max+1;i++)
	{
		if(hash[i]>(n/2))
		{
			return i;
		}
	}
	return-1;
}
int main()
{
    vector<int> v = {4,4,2,4,3,4,4,3,2,4};
    cout<<majorityElement(v);
    return 0;
}