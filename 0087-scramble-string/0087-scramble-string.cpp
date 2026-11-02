class Solution {
    unordered_map<string, bool> memo;

    bool solve(string a, string b) {
        if (a == b) return true;
        if (a.size() != b.size()) return false;

        string key = a + "#" + b;
        if (memo.count(key)) return memo[key];

        int n = a.size();
        vector<int> freq(26, 0);

        for (int i = 0; i < n; i++) {
            freq[a[i] - 'a']++;
            freq[b[i] - 'a']--;
        }

        for (int x : freq)
            if (x != 0) return memo[key] = false;

        for (int i = 1; i < n; i++) {
            if ((solve(a.substr(0, i), b.substr(0, i)) &&
                 solve(a.substr(i), b.substr(i))) ||
                (solve(a.substr(0, i), b.substr(n - i)) &&
                 solve(a.substr(i), b.substr(0, n - i))))
                return memo[key] = true;
        }

        return memo[key] = false;
    }

public:
    bool isScramble(string s1, string s2) {
        return solve(s1, s2);
    }
};