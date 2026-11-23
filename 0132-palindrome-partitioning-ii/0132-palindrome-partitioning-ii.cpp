#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
private:
    void expandAroundCenter(const string& s, int left, int right, vector<int>& cuts) {
        int n = s.length();
        while (left >= 0 && right < n && s[left] == s[right]) {
            int newCut = (left == 0) ? 0 : cuts[left - 1] + 1;
            cuts[right] = min(cuts[right], newCut);
            left--;
            right++;
        }
    }

public:
    int minCut(string s) {
        int n = s.length();
        if (n <= 1) return 0;

        // Worst case: every character is cut individually (0, 1, 2, ..., n - 1)
        vector<int> cuts(n);
        iota(cuts.begin(), cuts.end(), 0);

        for (int center = 0; center < n; ++center) {
            expandAroundCenter(s, center, center, cuts);      // Odd-length palindromes
            expandAroundCenter(s, center, center + 1, cuts);  // Even-length palindromes
        }

        return cuts[n - 1];
    }
};