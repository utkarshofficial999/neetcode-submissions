class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;
        
        while (l < r) {
            // Fixed: Changed numbers[1] to numbers[l]
            int csum = numbers[l] + numbers[r]; 
            
            if (csum == target) {
                return {l + 1, r + 1};
            } 
            else if (csum > target) {
                r--;
            } 
            else {
                l++;
            }
        } // The while loop now properly closes here
        
        return {}; // Placed correctly inside the function block
    }
};