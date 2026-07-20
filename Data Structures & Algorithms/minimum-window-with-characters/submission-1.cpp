class Solution {
public:
    string minWindow(string s, string t) {

        // Step 1: Store frequency of characters in t
        unordered_map<char, int> need;
        for (char c : t) {
            need[c]++;
        }

        // Step 2: Store frequency of current window
        unordered_map<char, int> window;

        int left = 0;
        int right = 0;

        // Number of unique characters whose required frequency is satisfied
        int formed = 0;

        // Total unique characters required
        int required = need.size();

        // Variables to store the answer
        int minLen = INT_MAX;
        int start = 0;

        while (right < s.size()) {

            char c = s[right];

            // Add current character to window
            window[c]++;

            // If current character satisfies its required frequency
            if (need.count(c) && window[c] == need[c]) {
                formed++;
            }

            // Try to shrink the window while it is valid
            while (formed == required) {

                // Update minimum window
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                // Remove left character
                char ch = s[left];
                window[ch]--;

                // If removing it makes window invalid
                if (need.count(ch) && window[ch] < need[ch]) {
                    formed--;
                }

                left++;
            }

            right++;
        }

        if (minLen == INT_MAX)
            return "";

        return s.substr(start, minLen);
    }
};