class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        
        // 1. Sort the array so we can use two-pointers and handle duplicates
        sort(nums.begin(), nums.end());
        
        // 2. Loop through the array fixing the first element 'i'
        for (int i = 0; i < nums.size(); i++) {
            
            // Optimization: If the current number is greater than 0, 
            // no three numbers can ever sum to 0 anymore.
            if (nums[i] > 0) break;
            
            // Skip duplicate values for 'i' to prevent duplicate triplets
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            // 3. Initialize the two pointers on the remaining elements
            int j = i + 1;
            int k = nums.size() - 1;
            
            // 4. Slide the two pointers inward to find pairs that match
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                
                if (sum > 0) {
                    k--; // Sum too big, move the right pointer to smaller numbers
                } 
                else if (sum < 0) {
                    j++; // Sum too small, move the left pointer to larger numbers
                } 
                else {
                    // Perfect match! Add to our results
                    res.push_back({nums[i], nums[j], nums[k]});
                    
                    // Shift pointers inward
                    j++;
                    k--;
                    
                    // Skip duplicates for the 'j' pointer to avoid duplicate triplets
                    while (j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }
                }
            }
        } // The main for loop now properly closes here!
        
        return res;
    }
};