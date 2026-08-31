class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void backtrack(vector<int>& nums, int index) {
        // Base case
        if (index == nums.size()) {
            ans.push_back(temp);
            return;
        }

        // Take nums[index]
        temp.push_back(nums[index]);
        backtrack(nums, index + 1);

        // Don't take nums[index]
        temp.pop_back();
        backtrack(nums, index + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums, 0);
        return ans;
    }
};