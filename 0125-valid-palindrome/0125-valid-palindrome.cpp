#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;
        
        while (left < right) {
            // Skip non-alphanumeric characters from the left
            while (left < right && !isalnum(static_cast<unsigned char>(s[left]))) {
                left++;
            }
            // Skip non-alphanumeric characters from the right
            while (left < right && !isalnum(static_cast<unsigned char>(s[right]))) {
                right--;
            }
            
            if (tolower(static_cast<unsigned char>(s[left])) != 
                tolower(static_cast<unsigned char>(s[right]))) {
                return false;
            }
            
            left++;
            right--;
        }
        
        return true;
    }
};