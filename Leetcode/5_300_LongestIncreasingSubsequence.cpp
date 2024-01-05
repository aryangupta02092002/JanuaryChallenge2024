class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int sz = nums.size();
        int ans = 1;
        if(sz == 0){
            return 0;
        }
        vector<int> dp(sz, 1);
        
        for(int i=1; i<sz; i++){
            for(int j=0; j<i; j++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], 1+dp[j]);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
