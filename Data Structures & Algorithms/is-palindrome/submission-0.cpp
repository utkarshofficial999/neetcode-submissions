class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;
        
        while (left < right) {
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            // FIX 1: Change right++ to right--
            while (left < right && !isalnum(s[right])) {
                right--; 
            }
            
            // FIX 2: Correct the parentheses syntax
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            
            left++;
            right--;
        } 
        
        // FIX 3: Return true if no mismatches are found
        return true;
    }
};