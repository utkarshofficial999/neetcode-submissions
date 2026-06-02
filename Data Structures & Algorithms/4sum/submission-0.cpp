class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        
        // 1. Sort the array to group duplicates and enable the two-pointer technique
        sort(nums.begin(), nums.end()); 
        
        // 2. Outer loop for the first number
        for (int i = 0; i < n; i++) {
            // Skip duplicate values for the first position
            if (i > 0 && nums[i] == nums[i - 1]) continue; 
            
            // 3. Inner loop for the second number
            for (int j = i + 1; j < n; j++) {
                // Skip duplicate values for the second position
                if (j > i + 1 && nums[j] == nums[j - 1]) continue; 
                
                // 4. Initialize the remaining two pointers
                int left = j + 1;
                int right = n - 1;
                
                // 5. Move pointers inward to find pairs matching the remaining target
                while (left < right) {
                    // Use long long casting to prevent 32-bit integer overflow
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    
                    if (sum == target) {
                        // Found a valid unique quadruplet!
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        
                        // Move both pointers inward
                        left++;
                        right--;
                        
                        // Skip duplicate values for the left and right elements
                        while (left < right && nums[left] == nums[left - 1]) left++;
                        while (left < right && nums[right] == nums[right + 1]) right--;
                        
                    } else if (sum < target) {
                        // The sum is too small; move the left pointer rightward to increase it
                        left++;
                    } else {
                        // The sum is too big; move the right pointer leftward to decrease it
                        right--;
                    }
                }
            }
        }
        return res;
    }
};