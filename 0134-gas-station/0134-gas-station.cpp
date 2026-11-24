#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalTank = 0;
        int currentTank = 0;
        int startStation = 0;

        for (int i = 0; i < gas.size(); ++i) {
            int netGain = gas[i] - cost[i];
            totalTank += netGain;
            currentTank += netGain;

            // Cannot reach station i + 1 from current startStation
            if (currentTank < 0) {
                startStation = i + 1;
                currentTank = 0;
            }
        }

        return (totalTank >= 0) ? startStation : -1;
    }
};