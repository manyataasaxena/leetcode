#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1 = INT_MIN, sell1 = 0;
        int buy2 = INT_MIN, sell2 = 0;
        
        for (int price : prices) {
            buy1 = max(buy1, -price);          // Max money left after 1st buy
            sell1 = max(sell1, buy1 + price);  // Max profit after 1st sell
            buy2 = max(buy2, sell1 - price);   // Max money left after 2nd buy
            sell2 = max(sell2, buy2 + price);  // Max profit after 2nd sell
        }
        
        return sell2;
    }
};