class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> phone = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> ans = {""};

        for (char digit : digits) {
            vector<string> temp;

            for (string &s : ans) {
                for (char ch : phone[digit - '0']) {
                    temp.push_back(s + ch);
                }
            }

            ans = move(temp);
        }

        return ans;
    }
};