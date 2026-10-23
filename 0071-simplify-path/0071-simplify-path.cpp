class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        stringstream ss(path);
        string part;

        while (getline(ss, part, '/')) {
            if (part.empty() || part == ".") continue;

            if (part == "..") {
                if (!st.empty()) st.pop_back();
            } else {
                st.push_back(part);
            }
        }

        string ans = "";
        for (string& dir : st)
            ans += "/" + dir;

        return ans.empty() ? "/" : ans;
    }
};