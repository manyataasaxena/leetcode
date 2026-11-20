#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return 0;

        unordered_set<string> beginSet{beginWord};
        unordered_set<string> endSet{endWord};
        dict.erase(beginWord);
        dict.erase(endWord);

        int steps = 1;

        while (!beginSet.empty() && !endSet.empty()) {
            // Always expand the smaller frontier to minimize search space
            if (beginSet.size() > endSet.size()) {
                swap(beginSet, endSet);
            }

            unordered_set<string> nextSet;
            for (const string& word : beginSet) {
                string temp = word;
                for (int i = 0; i < temp.size(); ++i) {
                    char originalChar = temp[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == originalChar) continue;
                        temp[i] = c;

                        // Frontiers met: shortest path found
                        if (endSet.count(temp)) {
                            return steps + 1;
                        }

                        if (dict.count(temp)) {
                            nextSet.insert(temp);
                            dict.erase(temp);
                        }
                    }
                    temp[i] = originalChar;
                }
            }

            beginSet = move(nextSet);
            steps++;
        }

        return 0;
    }
};