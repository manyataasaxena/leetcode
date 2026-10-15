class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, maxi = nums[0];

        for (int x : nums) {
            sum += x;
            maxi = max(maxi, sum);
            if (sum < 0) sum = 0;
        }

        return maxi;
    }
};