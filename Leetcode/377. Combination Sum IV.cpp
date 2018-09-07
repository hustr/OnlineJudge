int dp[100005];

class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {
		int result = 0;
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for (int i = 0; i <= target; ++i) {
			for (int j = 0; j < nums.size(); ++j) {
				if (i >= nums[j]) {
					dp[i] += dp[i - nums[j]];
				}
			}
		}
		
		return dp[target];
	}
};
