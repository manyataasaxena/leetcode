class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, len = 0;

        for (int i = 0; i < s.size(); i++) {
            expand(s, i, i, start, len);       // odd
            expand(s, i, i + 1, start, len);   // even
        }

        return s.substr(start, len);
    }

private:
    void expand(string& s, int l, int r, int& start, int& len) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            if (r - l + 1 > len) {
                start = l;
                len = r - l + 1;
            }
            l--;
            r++;
        }
    }
};