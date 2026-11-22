#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    void backtrack(const string& s, int start, const vector<vector<bool>>& isPal,
                   vector<string>& currentPath, vector<vector<string>>& result) {
        if (start == s.length()) {
            result.push_back(currentPath);
            return;
        }
        
        for (int end = start; end < s.length(); ++end) {
            if (isPal[start][end]) {
                currentPath.push_back(s.substr(start, end - start + 1));
                backtrack(s, end + 1, isPal, currentPath, result);
                currentPath.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        
        // Precompute palindrome substrings in O(N^2)
        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                if (s[i] == s[j] && (len <= 2 || isPal[i + 1][j - 1])) {
                    isPal[i][j] = true;
                }
            }
        }
        
        vector<vector<string>> result;
        vector<string> currentPath;
        backtrack(s, 0, isPal, currentPath, result);
        return result;
    }
};