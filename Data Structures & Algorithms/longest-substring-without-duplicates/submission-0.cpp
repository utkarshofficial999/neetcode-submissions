class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        int l=0;
       int max_length=0;
       for (int r = 0; r < s.length(); r++) {
        while (charSet.find(s[r]) != charSet.end()) {
                charSet.erase(s[l]); // 1. Remove the leftmost character from our memory
                l++;                 // 2. Shrink the window by moving 'l' to the right
            }
            charSet.insert(s[r]);
            max_length=max(max_length,r-l+1);
       }
     return max_length;
    }
};
