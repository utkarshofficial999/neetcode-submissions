class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        vector<int> freq(26, 0);

        // Count tasks
        for(char c : tasks) {
            freq[c - 'A']++;
        }

        // Find maximum frequency
        int mx = 0;
        for(int x : freq) {
            mx = max(mx, x);
        }

        // Count tasks having maximum frequency
        int count = 0;
        for(int x : freq) {
            if(x == mx) {
                count++;
            }
        }

        // Calculate minimum intervals
        int ans = (mx - 1) * (n + 1) + count;

        // We cannot have fewer intervals than tasks
        return max(ans, (int)tasks.size());
    }
};