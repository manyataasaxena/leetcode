class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        if (a.size() > b.size())
            return findMedianSortedArrays(b, a);

        int n = a.size(), m = b.size();
        int low = 0, high = n;

        while (low <= high) {
            int cutA = (low + high) / 2;
            int cutB = (n + m + 1) / 2 - cutA;

            int leftA  = cutA ? a[cutA - 1] : INT_MIN;
            int rightA = cutA < n ? a[cutA] : INT_MAX;
            int leftB  = cutB ? b[cutB - 1] : INT_MIN;
            int rightB = cutB < m ? b[cutB] : INT_MAX;

            if (leftA <= rightB && leftB <= rightA) {
                if ((n + m) % 2)
                    return max(leftA, leftB);

                return (max(leftA, leftB) + min(rightA, rightB)) / 2.0;
            }

            if (leftA > rightB)
                high = cutA - 1;
            else
                low = cutA + 1;
        }

        return 0.0;
    }
};