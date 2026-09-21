class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k), dp(k);

        for (int num : nums) {
            vector<long long> next(k);
            int x = num % k;

            // Start a new subarray
            next[x] = 1;

            // Extend previous subarrays
            for (int r = 0; r < k; r++) {
                next[(r * x) % k] += dp[r];
            }

            // Add to answer
            for (int r = 0; r < k; r++)
                ans[r] += next[r];

            dp = next;
        }

        return ans;
    }
};