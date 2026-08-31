class Solution {
   public:
    int ans = 0;

    void backtrack(vector<int>& nums, int index, int xorValue) {
        if (index == nums.size()) {
            ans += xorValue;
            return;
        }

        backtrack(nums, index + 1, xorValue ^ nums[index]);

        backtrack(nums, index + 1, xorValue);
    }

    int subsetXORSum(vector<int>& nums) {
        backtrack(nums, 0, 0);
        return ans;
    }
};