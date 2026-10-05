class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int m = words.size(), len = words[0].size();
        int total = m * len;

        if (total > s.size()) return ans;

        unordered_map<string, int> need;
        for (auto& w : words) need[w]++;

        for (int start = 0; start < len; start++) {
            unordered_map<string, int> have;
            int left = start, count = 0;

            for (int right = start; right + len <= s.size(); right += len) {
                string w = s.substr(right, len);

                if (!need.count(w)) {
                    have.clear();
                    count = 0;
                    left = right + len;
                    continue;
                }

                have[w]++;
                count++;

                while (have[w] > need[w]) {
                    string x = s.substr(left, len);
                    have[x]--;
                    left += len;
                    count--;
                }

                if (count == m) {
                    ans.push_back(left);

                    string x = s.substr(left, len);
                    have[x]--;
                    left += len;
                    count--;
                }
            }
        }

        return ans;
    }
};