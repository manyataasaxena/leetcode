#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longestStreak = 0;

        for (int num : numSet) {
            // Only initiate a count if 'num' is the start of a sequence
            if (!numSet.count(num - 1)) {
                int currentNum = num;
                int currentStreak = 1;

                while (numSet.count(currentNum + 1)) {
                    currentNum++;
                    currentStreak++;
                }

                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
};