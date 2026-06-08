class Solution {
public:
    int characterReplacement(string s, int k) {
        int counts[26] = {0};
        int l = 0;
        int max_cnt = 0;
        int max_length = 0; // Fixed: Added 'int' data type
        
        for (int r = 0; r < s.length(); r++) { // Fixed: Corrected 'length()' typo
            
            // 1. Increment the frequency count of the current character
            counts[s[r] - 'A']++;
            
            // 2. Update max_cnt if the current character's frequency is the highest seen so far
            max_cnt = max(max_cnt, counts[s[r] - 'A']);
            
            // 3. Check if our window is invalid (needed replacements > budget k)
            // Total window size is (r - l + 1)
            if ((r - l + 1) - max_cnt > k) {
                counts[s[l] - 'A']--; // Reduce the count of the character leaving the window
                l++;                 // Move the left pointer up to shrink the window
            }
            
            // 4. Track the maximum valid window length found
            max_length = max(max_length, r - l + 1);
        }
        
        return max_length; // Return the final maximum length
    }
};