#include <bits/stdc++.h>
using namespace std;

vector<int> printLeaders(vector<int> nums)
{
  vector<int> ans;
  int n = nums.size();
  ans.push_back(nums[n - 1]);
  int maxi = nums[n - 1];

  for (int i = n - 2; i >= 0; i--)
  {
    if (nums[i] > maxi)
    {
      ans.push_back(nums[i]);
      maxi = nums[i];
    }
  }

  reverse(ans.begin(), ans.end());
  return ans;
}

int main()
{
	vector<int> nums = {10, 22, 12, 3, 0, 6};
	vector<int> ans = printLeaders(nums);
	for(int i = ans.size()-1; i>=0; i--)
	{
		cout<<ans[i]<<" ";
	}

	cout<<endl;
	return 0;
}
