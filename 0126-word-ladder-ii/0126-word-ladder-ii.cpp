#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
private:
    unordered_map<string, vector<string>> parents;
    vector<vector<string>> result;
    vector<string> currentPath;

    void backtrack(const string& word, const string& beginWord) {
        if (word == beginWord) {
            vector<string> path = currentPath;
            reverse(path.begin(), path.end());
            result.push_back(path);
            return;
        }
        for (const string& parent : parents[word]) {
            currentPath.push_back(parent);
            backtrack(parent, beginWord);
            currentPath.pop_back();
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return {};

        dict.erase(beginWord);
        unordered_set<string> currentLevel{beginWord};
        bool found = false;

        while (!currentLevel.empty() && !found) {
            unordered_set<string> nextLevel;
            
            for (const string& word : currentLevel) {
                string temp = word;
                for (int i = 0; i < temp.size(); ++i) {
                    char originalChar = temp[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == originalChar) continue;
                        temp[i] = c;
                        if (dict.count(temp)) {
                            parents[temp].push_back(word);
                            nextLevel.insert(temp);
                            if (temp == endWord) found = true;
                        }
                    }
                    temp[i] = originalChar;
                }
            }
            
            // Erase visited words only after the entire level completes
            for (const string& word : nextLevel) {
                dict.erase(word);
            }
            currentLevel = move(nextLevel);
        }

        if (found) {
            currentPath.push_back(endWord);
            backtrack(endWord, beginWord);
        }

        return result;
    }
};